#include <Timer.h>
#include <TreeRouting.h>
#include <CollectionDebugMsg.h>
/* $Id: CtpRoutingEngineP.nc,v 1.23 2010/02/04 07:31:46 gnawali Exp $ */
/*
 * "Copyright (c) 2005 The Regents of the University  of California.  
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 * 
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF
 * CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 */

/** 
 *  The TreeRoutingEngine is responsible for computing the routes for
 *  collection.  It builds a set of trees rooted at specific nodes (roots) and
 *  maintains these trees using information provided by the link estimator on
 *  the quality of one hop links.
 * 
 *  <p>Each node is part of only one tree at any given time, but there is no
 *  difference from the node's point of view of which tree it is part. In other
 *  words, a message is sent towards <i>a</i> root, but which one is not
 *  specified. It is assumed that the roots will work together to have all data
 *  aggregated later if need be.  The tree routing engine's responsibility is
 *  for each node to find the path with the least number of transmissions to
 *  any one root.
 *
 *  <p>The tree is proactively maintained by periodic beacons sent by each
 *  node. These beacons are jittered in time to prevent synchronizations in the
 *  network. All nodes maintain the same <i>average</i> beacon sending rate
 *  (defined by BEACON_INTERVAL +- 50%). The beacon contains the node's parent,
 *  the current hopcount, and the cumulative path quality metric. The metric is
 *  defined as the parent's metric plus the bidirectional quality of the link
 *  between the current node and its parent.  The metric represents the
 *  expected number of transmissions along the path to the root, and is 0 by
 *  definition at the root.
 * 
 *  <p>Every time a node receives an update from a neighbor it records the
 *  information if the node is part of the neighbor table. The neighbor table
 *  keeps the best candidates for being parents i.e., the nodes with the best
 *  path metric. The neighbor table does not store the full path metric,
 *  though. It stores the parent's path metric, and the link quality to the
 *  parent is only added when the information is needed: (i) when choosing a
 *  parent and (ii) when choosing a route. The nodes in the neighbor table are
 *  a subset of the nodes in the link estimator table, as a node is not
 *  admitted in the neighbor table with an estimate of infinity.
 * 
 *  <p>There are two uses for the neighbor table, as mentioned above. The first
 *  one is to select a parent. The parent is just the neighbor with the best
 *  path metric. It serves to define the node's own path metric and hopcount,
 *  and the set of child-parent links is what defines the tree. In a sense the
 *  tree is defined to form a coherent propagation substrate for the path
 *  metrics. The parent is (re)-selected periodically, immediately before a
 *  node sends its own beacon, in the updateRouteTask.
 *  
 *  <p>The second use is to actually choose a next hop towards any root at
 *  message forwarding time.  This need not be the current parent, even though
 *  it is currently implemented as such.
 *
 *  <p>The operation of the routing engine has two main tasks and one main
 *  event: updateRouteTask is called periodically and chooses a new parent;
 *  sendBeaconTask broadcasts the current route information to the neighbors.
 *  The main event is the receiving of a neighbor's beacon, which updates the
 *  neighbor table.
 *  
 *  <p> The interface with the ForwardingEngine occurs through the nextHop()
 *  call.
 * 
 *  <p> Any node can become a root, and routed messages from a subset of the
 *  network will be routed towards it. The RootControl interface allows
 *  setting, unsetting, and querying the root state of a node. By convention,
 *  when a node is root its hopcount and metric are 0, and the parent is
 *  itself. A root always has a valid route, to itself.
 *
 *  @author Rodrigo Fonseca
 *  @author Philip Levis (added trickle-like updates)
 *  Acknowledgment: based on MintRoute, MultiHopLQI, BVR tree construction, Berkeley's MTree
 *                           
 *  @date   $Date: 2010/02/04 07:31:46 $
 *  @see Net2-WG
 */


// -----------------------------------------------------------------------
// MN: Header
#include "CtpParentSelectionEngine.h"
// -----------------------------------------------------------------------

#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA)
#include "printf.h"
#endif


generic module CtpRoutingEngineP(uint8_t routingTableSize, uint32_t minInterval, uint32_t maxInterval) {
    provides {
        interface UnicastNameFreeRouting as Routing;
        interface RootControl;
        interface CtpInfo;
        interface StdControl;
        interface CtpRoutingPacket;
        interface Init;
    } 
    uses {
        interface AMSend as BeaconSend;
        interface Receive as BeaconReceive;
        interface LinkEstimator;
        interface AMPacket;
        interface SplitControl as RadioControl;
        interface Timer<TMilli> as BeaconTimer;
        interface Timer<TMilli> as RouteTimer;
        interface Random;
        interface CollectionDebug;
        interface CtpCongestion;

				interface CompareBit;
		
				// MN: instrumentation and parent selection inferface
				interface CtpInstrumentation;
    		interface CtpParentSelectionConfig;

				#if defined(ROUTINSTRUM_PACKET)
				interface RctpRoutInstrum;
				#endif	
    }
}


implementation {

		#if defined(PRINTF_ENABLED) || defined(PRINTF_ENABLED_COOJA)  && FALSE
		  //MN: Debug flags for printf
			bool dbg_trickle					= TRUE;			// Prints if the trickle timer was reset
			bool dbg_updateRouteTask 	= TRUE;			// Prints information from the updateRouteTask
			bool dbg_parent_set 			= TRUE;			// Prints information about the parent set 
			bool dbg_beacons 					= FALSE;     // Prints information about received and sent beacons
			bool dbg_routinstrum			= FALSE;     // Info about route instrumentation
		#endif

		// MN: Slow update phase parameter  TODO: verify
		//bool slowUpdatePhase = FALSE;


    bool ECNOff = TRUE;

    /* Keeps track of whether the radio is on. No sense updating or sending
     * beacons if radio is off */
    bool radioOn = FALSE;
    /* Controls whether the node's periodic timer will fire. The node will not
     * send any beacon, and will not update the route. Start and stop control this. */
    bool running = FALSE;
    /* Guards the beacon buffer: only one beacon being sent at a time */
    bool sending = FALSE;

    /* Tells updateNeighbor that the parent was just evicted.*/ 
    bool justEvicted = FALSE;

    route_info_t routeInfo;
    bool state_is_root;
    am_addr_t my_ll_addr;

    message_t beaconMsgBuffer;
    ctp_routing_header_t* beaconMsg;

    /* routing table -- routing info about neighbors */
    routing_table_entry routingTable[routingTableSize];
    uint8_t routingTableActive;

    /* statistics */
    //uint32_t parentChanges;			//MN: TODO: lagacy code could be removed
    /* end statistics */

    // forward declarations
    void routingTableInit();
    uint8_t routingTableFind(am_addr_t);
    error_t routingTableUpdateEntry(am_addr_t, am_addr_t , uint16_t);
    error_t routingTableEvict(am_addr_t neighbor);

    uint32_t currentInterval = minInterval;
    uint32_t t; 
    bool tHasPassed;

    void chooseAdvertiseTime() {
       t = currentInterval;
       t /= 2;
       t += call Random.rand32() % t;
       tHasPassed = FALSE;
       call BeaconTimer.stop();
       call BeaconTimer.startOneShot(t);
    }

    void resetInterval() {
      currentInterval = minInterval;
	  	chooseAdvertiseTime();
	  
			//ADD: ctp instru
			call CtpInstrumentation.ctrl_tricklereset();

			#if defined(PRINTF_ENABLED)  
			if(dbg_trickle){
				printf("\nRE: trickle RESET\n");
				printfflush();
			}
			#endif
      
    }

    void decayInterval() {
      currentInterval *= 2;
      if (currentInterval > maxInterval) {
      	currentInterval = maxInterval;
      }
      chooseAdvertiseTime();
    }

    void remainingInterval() {
       uint32_t remaining = currentInterval;
       remaining -= t;
       tHasPassed = TRUE;
       call BeaconTimer.startOneShot(remaining);
    }

    command error_t Init.init() {
    	uint8_t maxLength;

      radioOn = FALSE;
      running = FALSE;
      //parentChanges = 0;  //TODO: remove
      state_is_root = 0;
      routeInfoInit(&routeInfo);
      routingTableInit();
      my_ll_addr = call AMPacket.address();
      beaconMsg = call BeaconSend.getPayload(&beaconMsgBuffer, 
																						 call BeaconSend.maxPayloadLength());
      maxLength = call BeaconSend.maxPayloadLength();
      dbg("TreeRoutingCtl","TreeRouting initialized. (used payload:%d max payload:%d!\n", 
           sizeof(beaconMsg), maxLength);
      
			return SUCCESS;
    }

    command error_t StdControl.start() {
      //start will (re)start the sending of messages
      if (!running) {
				running = TRUE;
				resetInterval();
				call RouteTimer.startPeriodic(BEACON_INTERVAL);
				dbg("TreeRoutingCtl","%s running: %d radioOn: %d\n", __FUNCTION__, running, radioOn);
      }     
      return SUCCESS;
    }

    command error_t StdControl.stop() {
        running = FALSE;
        dbg("TreeRoutingCtl","%s running: %d radioOn: %d\n", __FUNCTION__, running, radioOn);
        return SUCCESS;
    } 

    event void RadioControl.startDone(error_t error) {
        radioOn = TRUE;
        dbg("TreeRoutingCtl","%s running: %d radioOn: %d\n", __FUNCTION__, running, radioOn);
        if (running) {
            uint16_t nextInt;
            nextInt = call Random.rand16() % BEACON_INTERVAL;
            nextInt += BEACON_INTERVAL >> 1;
            call BeaconTimer.startOneShot(nextInt);
        }
    } 

    event void RadioControl.stopDone(error_t error) {
        radioOn = FALSE;
        dbg("TreeRoutingCtl","%s running: %d radioOn: %d\n", __FUNCTION__, running, radioOn);
    }

    /* Is this quality measure better than the minimum threshold? */
    // Implemented assuming quality is EETX
    bool passLinkEtxThreshold(uint16_t etx) {
        return (etx < ETX_THRESHOLD);
    }


    /* updates the routing information, using the info that has been received
     * from neighbor beacons. Two things can cause this info to change: 
     * neighbor beacons, changes in link estimates, including neighbor eviction */
    task void updateRouteTask() {
      uint8_t i;
      routing_table_entry* entry;
      routing_table_entry* best;
      uint16_t minEtx;
      uint16_t currentEtx;
      uint16_t linkEtx, pathEtx;

			// MN: rctp 
			nx_uint16_t parentSetETX;
			nx_uint8_t parentSetSize;
			bool addedParentToSet = FALSE;
			uint8_t reportedNeighbors = 0;
			uint16_t route_instrum_petx = 0xFFFF;
			bool route_instrum_indexflag[routingTableSize];
			uint8_t route_instrum_flagpos = 0;

      if (state_is_root)
          return;
     
      best = NULL;
      /* Minimum etx found among neighbors, initially infinity */
      minEtx = MAX_METRIC;
      /* Metric through current parent, initially infinity */
      currentEtx = MAX_METRIC;

			#if defined(ROUTINSTRUM_PACKET)
				//MN:Initialize routing instrumentation
				call RctpRoutInstrum.init();

				//MN: set active entries in the routing table
				call 	RctpRoutInstrum.set_routingTableActive(routingTableActive);

				// Initialize position flags
				for(i=0;i<routingTableActive;i++){
					route_instrum_indexflag[i] = TRUE;				
				}
			#endif

      dbg("TreeRouting","%s\n",__FUNCTION__);

			// MN: Initialize parent set
			#if ( defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) ) && FALSE
			if(dbg_parent_set && TOS_NODE_ID == 6){
				printf("  RE-PS: parent set init (active: %u)\n",routingTableActive);
				printfflush();
			}
			#endif
			call CtpParentSelectionConfig.initializeParentSet();


			// MN: Update the node etx using the link ETX of the current parent
      i = routingTableFind(routeInfo.parent);
      if (i < routingTableActive) {
				entry = &routingTable[i];	// find the parent entry
				linkEtx = call LinkEstimator.getLinkQuality(entry->neighbor); // find link etx

				#if ( defined(PRINTF_ENABLED) || defined(PRINTF_ENABLED_COOJA) )  && FALSE
				if(dbg_parent_set && TOS_NODE_ID == 6){
					atomic {
						printf("  RE-PS: ParentID:%u parentETX:%u LinkETX:%u pathETX:%u \n", 
									entry->neighbor, entry->info.etx, linkEtx, entry->info.etx + linkEtx );
						printfflush();
					}
				}
				#endif

				// Ignore bad parents: 1-hop loops and bad links
        if ( entry->info.parent == INVALID_ADDR || 
						 entry->info.parent == my_ll_addr ){ 
						 // || entry->info.etx == MAX_METRIC ) {
						 // || !passLinkEtxThreshold(linkEtx) ) {
					#if ( defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(dbg_parent_set && TOS_NODE_ID == 6){
						atomic {
							printf("  RE-PS: IGNORING current CTP parent %u (%u)\n", 
											entry->neighbor, routeInfo.parent);
							printfflush();
						}
					}
					#endif	
					addedParentToSet = FALSE; // Don't build the parent set until there is a valid CTP parent					
				}
				else{
	
		      currentEtx = entry->info.etx + linkEtx; // update node etx
					// update routeInfo with parent's current info
					atomic {
						routeInfo.etx = entry->info.etx;
	         	routeInfo.congested = entry->info.congested;
					}
					#if ( defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) ) && FALSE
						if(dbg_parent_set && TOS_NODE_ID == 6){
						atomic {
							printf("  RE-PS: adding current CTP parent:%u (%u) (neigPrnt:%u)\n", 
										entry->neighbor, routeInfo.parent,entry->info.parent);
							printfflush();
						}
					}
					#endif
					// Add the current CTP parent to the parent set. This is the 
					// first neighbor to be added
					call CtpParentSelectionConfig.addParentCandidate(entry,currentEtx);
					addedParentToSet = TRUE; // There is a CTP parent, then build the parent set
				}

      }

			
			#if defined(ROUTINSTRUM_PACKET)
			// MN: First neighbor to report is the parent node (if valid)
		  if(reportedNeighbors < ROUTINSTRUM_NEIGHBORS && addedParentToSet){
				
				//call	RctpRoutInstrum.set_rctp_neighbor(reportedNeighbors, routeInfo.parent, currentEtx, entry->info.parent);
				call	RctpRoutInstrum.set_parentParent(entry->info.parent);

				/*
				#if defined(PRINTF_ENABLED)  
				if(dbg_routinstrum){
					printf("  RE: updated routInstrum: neigh:%u petx:%u parent:%u \n",
									call		RctpRoutInstrum.get_rctp_neighbor(reportedNeighbors),
									call		RctpRoutInstrum.get_rctp_neighbor_petx(reportedNeighbors),
									call		RctpRoutInstrum.get_rctp_neighbor_parent(reportedNeighbors) );
					printfflush();
				}
				#endif
				*/

				// Clear the flag of the parent node
				route_instrum_indexflag[i] = FALSE;

				//reportedNeighbors++;								// There is no need to increase the number of reported neighbors
				//route_instrum_petx = currentEtx;
			}
			#endif
			


      /* Find best path in table, other than our current */
      for (i = 0; i < routingTableActive; i++) {
      	entry = &routingTable[i];

				linkEtx = call LinkEstimator.getLinkQuality(entry->neighbor);

				#if ( defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(dbg_parent_set && TOS_NODE_ID == 6){
					atomic {
						printf("  RE-PS: trying neighbor:%u (neigPrnt:%u) (neigLink:%u)\n", 
									entry->neighbor, entry->info.parent, linkEtx);
						printfflush();
					}
				}
				#endif

				// Ignore the current parent (it is already in the parent set)
        if (entry->neighbor == routeInfo.parent) {
					continue;
				}

				// Avoid bad entries and 1-hop loops
        if (entry->info.parent == INVALID_ADDR || entry->info.parent == my_ll_addr) {
        	dbg("TreeRouting", 
               "routingTable[%d]: neighbor: [id: %d parent: %d  etx: NO ROUTE]\n",  
               i, entry->neighbor, entry->info.parent);
						
					#if ( defined(PRINTF_ENABLED) || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(dbg_parent_set && TOS_NODE_ID == 6){
						printf("  RE-PS: avoided bad entry: node:%u prnt:%u etx:%u linkETX:%u pathETX:%u\n",
										entry->neighbor,entry->info.parent,
                    entry->info.etx,linkEtx,linkEtx+entry->info.etx);
						printfflush();
					}
					#endif
          continue;
				}

				// MN: Avoid nodes with bad node ETX
        if (entry->info.etx == MAX_METRIC) {
						
					#if ( defined(PRINTF_ENABLED) || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(dbg_parent_set && TOS_NODE_ID == 6){
					printf("  RE-PS: avoided bad nodeETX: node:%u prnt:%u etx:%u linkETX:%u pathETX:%u\n", 
									entry->neighbor,entry->info.parent,
									entry->info.etx,linkEtx,linkEtx+entry->info.etx);
					printfflush();
					}
					#endif
					continue;
				}

        dbg("TreeRouting", 
            "routingTable[%d]: neighbor: [id: %d parent: %d etx: %d retx: %d]\n",  
            i, entry->neighbor, entry->info.parent, linkEtx, entry->info.etx);
     
   
				// compute the path etx using this neighbor
				pathEtx = linkEtx + entry->info.etx;


        /* Ignore links that are congested*/
        if (entry->info.congested){
					#if ( defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(dbg_parent_set && TOS_NODE_ID == 6){
						printf("  RE-PS: avoided congested node:%u prnt:%u etx:%u\n", 
										entry->neighbor,entry->info.parent,entry->info.etx);
						printfflush();
					}
					#endif
          continue;
				}

        /* Ignore links that are bad */
        if (!passLinkEtxThreshold(linkEtx)) {
        	dbg("TreeRouting", "   did not pass threshold.\n");		
					#if ( defined(PRINTF_ENABLED) || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(dbg_parent_set && TOS_NODE_ID == 6){
						printf("  RE-PS: avoided bad linkETX: node:%u prnt:%u etx:%u linkETX:%u pathETX:%u\n",
										entry->neighbor,entry->info.parent,
										entry->info.etx,linkEtx,linkEtx+entry->info.etx);
						printfflush();
					}
					#endif
          continue;
        }

				// Find the best neighbor
				if (pathEtx < minEtx) {
					dbg("TreeRouting", "   best is %d, setting to %d\n", pathEtx, entry->neighbor);
					minEtx = pathEtx;
					best = entry;
				} 

				// Don't try to add more neighbors if MAX parent set == 1 and already added the CTP parent
				//if(MAX_PARENTSET_SIZE == 1 && addedParentToSet){
				if(!addedParentToSet){
					continue;
				} 

				/* Ignore neighbors that don't satisfy the parent set condition 
			  */
        if( currentEtx == MAX_METRIC ) {
					// There is no valid parent in the pset... then add the neighbors
					#if ( defined(PRINTF_ENABLED) || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(dbg_parent_set && TOS_NODE_ID == 6){
						printf("  RE-PS: ADDING candidate: node:%u prnt:%u etx:%u linkETX:%u pathETX:%u\n", 
										entry->neighbor,entry->info.parent,
										entry->info.etx,linkEtx,linkEtx+entry->info.etx);
						printfflush();
					}
					#endif
					call CtpParentSelectionConfig.addParentCandidate(entry,pathEtx);
				}
				else{
					// There is a valid parent, then check the pset condition
					//if(entry->info.etx < routeInfo.etx + 10){ //if( pathEtx < currentEtx ) {
					if( (entry->info.etx < routeInfo.etx + 10) && (pathEtx < currentEtx + 10) ){ 
						#if ( defined(PRINTF_ENABLED) || defined(PRINTF_ENABLED_COOJA) )  && FALSE
						if(dbg_parent_set && TOS_NODE_ID == 6){
							printf("  RE-PS: ADDING candidate: node:%u prnt:%u etx:%u linkETX:%u pathETX:%u\n", 
											entry->neighbor,entry->info.parent,
											entry->info.etx,linkEtx,linkEtx+entry->info.etx);
							printfflush();
						}
						#endif
						call CtpParentSelectionConfig.addParentCandidate(entry,pathEtx);
					}
					else{
						#if ( defined(PRINTF_ENABLED) || defined(PRINTF_ENABLED_COOJA) ) && FALSE
						if(dbg_parent_set && TOS_NODE_ID == 6){
							printf("  RE-PS: IGNORED node:%u prnt:%u etx:%u linkETX:%u pathETX:%u  (currentETX:%u)\n", 
											entry->neighbor,entry->info.parent,
											entry->info.etx,linkEtx,linkEtx+entry->info.etx, routeInfo.etx);
							printfflush();
						}
						#endif
					}
				}

				/*
				if ( routeInfo.parent != INVALID_ADDR && 
						 routeInfo.parent != entry->neighbor && 
						 pathEtx >= routeInfo.etx + 10 ){					
						 // Use the ETX of the parent (don't consider nodes at the same level, only nodes with routing progress)
						 //pathEtx >= routeInfo.etx + 10 ){					
						 //pathEtx >= currentEtx + 10 ){
					#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA)
					if(dbg_parent_set && TOS_NODE_ID == 8){
						printf("  RE-PS: avoided bad pathETX: node:%u prnt:%u etx:%u linkETX:%u pathETX:%u\n",
										entry->neighbor,entry->info.parent,
										entry->info.etx,linkEtx,linkEtx+entry->info.etx);
						printfflush();
					}
					#endif
					continue;
				}
					

				// MN: add parent candidate
				#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA)
				if(dbg_parent_set && TOS_NODE_ID == 8){
					printf("  RE-PS: ADDING candidate: node:%u prnt:%u etx:%u linkETX:%u pathETX:%u\n", 
									entry->neighbor,entry->info.parent,
									entry->info.etx,linkEtx,linkEtx+entry->info.etx);
					printfflush();
				}
				#endif

				if (buildParentSet) {
					call CtpParentSelectionConfig.addParentCandidate(entry,pathEtx);
				}
				*/

      } 

			/* 	
					The parent set was created
					The current route information was updated
					The neighbor with minimum ETX (best) was chosen

					Separate the functions of the node's parent and the parent set.
					The node parent is to be used to define the topology and 
					The parent set is to be used for forwarding packets

			*/



			call CtpParentSelectionConfig.getParentSetETX(&parentSetETX,&parentSetSize);
			// MN: If pset size is 1 (and there is a best neighbor and the current parent is not a sink), then add the best neighbor
			// TODO: verify if needed !!!
/*
			if (parentSetSize == 1 && minEtx != MAX_METRIC && routeInfo.etx != 0) {
				call CtpParentSelectionConfig.addParentCandidate(best,minEtx)	;		
			}
*/
			// .....

			#if ( defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) )   && FALSE
			if(dbg_updateRouteTask && TOS_NODE_ID == 6){					
				printf("RE: prntSetETX:%u, prntSetSize:%u ",parentSetETX,parentSetSize);
				if(parentSetSize>1){
					printf("best:%u minETX:%u \n",best->neighbor,minEtx);
				}
				else{
					printf("\n");
				}
				printfflush();
			}
			#endif

			#if defined(ROUTINSTRUM_PACKET)
			// Add the rest of the neighbors
		  while(reportedNeighbors < ROUTINSTRUM_NEIGHBORS){

		  	for (i=0; i<routingTableActive; i++) {

					if(!route_instrum_indexflag[i]){
						continue;					
					}
			
	      	entry = &routingTable[i];
					//pathEtx = entry->info.etx + call LinkEstimator.getLinkQuality(entry->neighbor);
					if( entry->info.etx < route_instrum_petx){
						route_instrum_petx = entry->info.etx;
						route_instrum_flagpos = i;
						call	RctpRoutInstrum.set_rctp_neighbor(	reportedNeighbors, 
																											entry->neighbor, 
																											call LinkEstimator.getLinkQuality(entry->neighbor), entry->info.parent);
					}

				}

				route_instrum_indexflag[route_instrum_flagpos] = FALSE;
				reportedNeighbors++;
				route_instrum_petx = 0xFFFF;
			}
				#if ( defined(PRINTF_ENABLED)  ) 
				call RctpRoutInstrum.printAll();
				#endif
			#endif

		
			/*
			// MN: Retrieve the parent set size and 
			//     ETX to determine if the current parent can be evicted
			if( parentSetSize == 0 && routeInfo.parent != INVALID_ADDR){
				#if defined(PRINTF_ENABLED)  
				if(dbg_parent_set){					
					printf("RE: EVICT PARENT %u (prntSetSize:%u) (minETX:%u)\n", 
									routeInfo.parent, parentSetSize,minEtx);
					printfflush();
				}
				#endif

				call LinkEstimator.unpinNeighbor(routeInfo.parent);
				//routingTableEvict(routeInfo.parent);
				routeInfoInit(&routeInfo);
        //post updateRouteTask();

				#if defined(PRINTF_ENABLED)  
				if(dbg_parent_set){					
					printf("RE: after eviction parent:%u (parentETX:%u) \n", 
									routeInfo.parent, routeInfo.etx);
					printfflush();
				}
				#endif
			}
			*/

    	call CollectionDebug.logEventDbg(NET_C_DBG_3, routeInfo.parent, currentEtx, minEtx);  

      /* Now choose between the current parent and the best neighbor
      	 Requires that: 
          1. at least another neighbor was found with ok quality and not congested
          2. the current parent is congested and the other best route is at least as good
          3. or the current parent is not congested and the neighbor quality is better by 
             the PARENT_SWITCH_THRESHOLD.
        Note: if our parent is congested, in order to avoid forming loops, we try to select
              a node which is not a descendent of our parent. routeInfo.ext is our parent's
              etx. Any descendent will be at least that + 10 (1 hop), so we restrict the 
              selection to be less than that.
      */
      if (minEtx != MAX_METRIC) 
			{
        //if ( 	( currentEtx == MAX_METRIC ) ||
        // 			( routeInfo.congested && (minEtx < (routeInfo.etx + 10)) ) ||
        //      ( minEtx + PARENT_SWITCH_THRESHOLD < currentEtx ) || ( best->info.etx == 0 && (minEtx < currentEtx) )  )
				if ( 	( currentEtx == MAX_METRIC ) ||
        			( routeInfo.congested && (minEtx < (routeInfo.etx + 10)) ) ||
              ( minEtx < currentEtx ) || ( best->info.etx == 0 && (minEtx < currentEtx) )  )  
				{
          // routeInfo.metric will not store the composed metric.
          // since the linkMetric may change, we will compose whenever
          // we need it: i. when choosing a parent (here); 
          //            ii. when choosing a next hop
        	//parentChanges++;

					// MN: slow update phase
					//if(!slowUpdatePhase){
					//	slowUpdatePhase = TRUE;						
					//}
			
					// ADD: ctp instru
					// TODO: define how to count parent changes... in the new CTP
					call CtpInstrumentation.ctrl_parentchange();

					#if ( defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(TOS_NODE_ID == 6){
						printf("RE: CTP parent update from %u to %u\n",routeInfo.parent,best->neighbor);
						printfflush();
					}
					#endif

					dbg("TreeRouting","Changed parent. from %d to %d\n", 
							routeInfo.parent, best->neighbor);
					call CollectionDebug.logEventDbg(NET_C_TREE_NEW_PARENT, best->neighbor, 
																						best->info.etx, minEtx);

					call LinkEstimator.unpinNeighbor(routeInfo.parent);
					call LinkEstimator.pinNeighbor(best->neighbor);
					call LinkEstimator.clearDLQ(best->neighbor);

					atomic {
						routeInfo.parent = best->neighbor;
						routeInfo.etx = best->info.etx;
						routeInfo.congested = best->info.congested;
					}

					/*
					// MN: If the parent set wasn't created, then add the new CTP parent
					if(!buildParentSet){
						#if defined(PRINTF_ENABLED)  
						if(dbg_updateRouteTask){
							printf("  PS NOT BUILT. Add new ctp parent:%u prnt:%u etx:%u pathETX:%u\n", 
											best->neighbor,best->info.parent,
											best->info.etx, minEtx);
							printfflush();
						}
						#endif
						call CtpParentSelectionConfig.addParentCandidate(best,minEtx);
					}	
					else{
						#if defined(PRINTF_ENABLED)  
						if(dbg_updateRouteTask){
							printf("  PS RESET. Add new ctp parent:%u prnt:%u etx:%u pathETX:%u\n", 
											best->neighbor,best->info.parent,
											best->info.etx, minEtx);
							printfflush();
						}
						#endif
						// A set was built based on the previous parent, then use only the new parent
						call CtpParentSelectionConfig.initializeParentSet();
						call CtpParentSelectionConfig.addParentCandidate(best,minEtx);
					}
					*/

					// Rebuild the parent set
					call CtpParentSelectionConfig.initializeParentSet();
					// Add the new CTP parent
					call CtpParentSelectionConfig.addParentCandidate(best,minEtx);


      		for (i = 0; i < routingTableActive; i++) {
      			entry = &routingTable[i];
						linkEtx = call LinkEstimator.getLinkQuality(entry->neighbor);

						// Ignore the current parent (it is already in the parent set)
				    if (entry->neighbor == routeInfo.parent) {
							continue;
						}

						// Avoid bad entries and 1-hop loops
				    if (entry->info.parent == INVALID_ADDR || entry->info.parent == my_ll_addr) {
				      continue;
						}

						// MN: Avoid nodes with bad node ETX
				    if (entry->info.etx == MAX_METRIC) {
							continue;
						}     
   
						// compute the path etx using this neighbor
						pathEtx = linkEtx + entry->info.etx;

				    /* Ignore links that are congested*/
				    if (entry->info.congested){
				      continue;
						}

				    /* Ignore links that are bad */
				    if (!passLinkEtxThreshold(linkEtx)) {
				      continue;
				    }

						// There is a valid parent, then check the pset condition
						//if(entry->info.etx < routeInfo.etx + 10){ //if( pathEtx < currentEtx ) {
						if( (entry->info.etx < routeInfo.etx + 10) && (pathEtx < minEtx + 10) ){ 			//minEtx is the current ETX after update
							call CtpParentSelectionConfig.addParentCandidate(entry,pathEtx);
						}
						
					}


					#if ( defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) )  && FALSE
					if(TOS_NODE_ID == 6){
						call CtpParentSelectionConfig.getParentSetETX(&parentSetETX,&parentSetSize);			
						printf("RE: prntSetETX:%u, prntSetSize:%u \n",parentSetETX,parentSetSize);
						printfflush();
					}
					#endif

					if (currentEtx - minEtx > 20) {
						#if defined(PRINTF_ENABLED)  
						if(dbg_parent_set || dbg_updateRouteTask){
							printf("RE: Trigger route update\n");
							printfflush();
						}
						#endif
						call CtpInfo.triggerRouteUpdate();
					}
				}
      } 

			

      /* Finally, tell people what happened:  */
      /* We can only loose a route to a parent if it has been evicted. If it hasn't 
       * been just evicted then we already did not have a route */
      if (justEvicted && routeInfo.parent == INVALID_ADDR){ 
          signal Routing.noRoute();
					#if defined(PRINTF_ENABLED)  
					if(dbg_updateRouteTask){
						printf("RE: Signaled NO ROUTE (p:%u)\n",routeInfo.parent);
						printfflush();
					}
					#endif
			}
      /* On the other hand, if we didn't have a parent (no currentEtx) and now we
       * do, then we signal route found. The exception is if we just evicted the 
       * parent and immediately found a replacement route: we don't signal in this 
       * case */
      else if (!justEvicted && 
                currentEtx == MAX_METRIC &&
                minEtx != MAX_METRIC){
          signal Routing.routeFound();
					#if defined(PRINTF_ENABLED)  
					if(dbg_updateRouteTask){
						printf("RE: Signaled ROUTE FOUND (p:%u)\n",routeInfo.parent);
						printfflush();
					}
					#endif
			}
      justEvicted = FALSE; 

			#if defined(PRINTF_ENABLED)  
			if(dbg_updateRouteTask){
				printf("RE: updateRouteTask finished \n");
				printfflush();
			}
			#endif

    }

    

    /* send a beacon advertising this node's routeInfo */
    // only posted if running and radioOn
    task void sendBeaconTask() {
      error_t eval;
      if (sending) {
          return;
      }

      beaconMsg->options = 0;

      /* Congestion notification: am I congested? */
      if (call CtpCongestion.isCongested()) {
          beaconMsg->options |= CTP_OPT_ECN;
      }

      beaconMsg->parent = routeInfo.parent;
      if (state_is_root) {
          beaconMsg->etx = routeInfo.etx;
      }
      else if (routeInfo.parent == INVALID_ADDR) {
          beaconMsg->etx = routeInfo.etx;
          beaconMsg->options |= CTP_OPT_PULL;
      } else {
          beaconMsg->etx = routeInfo.etx + call LinkEstimator.getLinkQuality(routeInfo.parent);
      }

      dbg("TreeRouting", "%s parent: %d etx: %d\n",
                __FUNCTION__,
                beaconMsg->parent, 
                beaconMsg->etx);
      call CollectionDebug.logEventRoute(NET_C_TREE_SENT_BEACON, beaconMsg->parent, 0, beaconMsg->etx);

			#if defined(PRINTF_ENABLED)  
			if(dbg_beacons){
				printf("\nRE: BeaconSend: prnt:%u etx:%u opt:%u \n",
									beaconMsg->parent,beaconMsg->etx,beaconMsg->options);
				printfflush();
			}
			#endif

      eval = call BeaconSend.send(AM_BROADCAST_ADDR, 
                                  &beaconMsgBuffer, 
                                  sizeof(ctp_routing_header_t));
      if (eval == SUCCESS) {
          sending = TRUE;
      } else if (eval == EOFF) {
          radioOn = FALSE;
          dbg("TreeRoutingCtl","%s running: %d radioOn: %d\n", __FUNCTION__, running, radioOn);
      }
    }

    event void BeaconSend.sendDone(message_t* msg, error_t error) {
      if ((msg != &beaconMsgBuffer) || !sending) {
          //something smells bad around here
          return;
      }
			// ADD: ctp instru
			call CtpInstrumentation.ctrl_txpkt();
      sending = FALSE;
	  }

    event void RouteTimer.fired() {
      if (radioOn && running) {
         post updateRouteTask();
      }
    }
      
    event void BeaconTimer.fired() {
      if (radioOn && running) {
        if (!tHasPassed) {
          post updateRouteTask(); //always send the most up to date info
          post sendBeaconTask();
          dbg("RoutingTimer", "Beacon timer fired at %s\n", sim_time_string());
          remainingInterval();
        }
        else {
          decayInterval();
        }
      }
    }


    ctp_routing_header_t* getHeader(message_t* ONE m) {
      return (ctp_routing_header_t*)call BeaconSend.getPayload(m, call BeaconSend.maxPayloadLength());
    }
    
    
    /* Handle the receiving of beacon messages from the neighbors. We update the
     * table, but wait for the next route update to choose a new parent */
    event message_t* BeaconReceive.receive(message_t* msg, void* payload, uint8_t len) {
      am_addr_t from;
      ctp_routing_header_t* rcvBeacon;
      bool congested;

      // Received a beacon, but it's not from us.
      if (len != sizeof(ctp_routing_header_t)) {
        dbg("LITest", "%s, received beacon of size %hhu, expected %i\n",
                   __FUNCTION__, 
                   len,
                   (int)sizeof(ctp_routing_header_t));
				#if defined(PRINTF_ENABLED)  
				if(dbg_beacons){					
					printf("\nRE: BeaconReceived: unexpected (size:%u)\n",len);
					printfflush();
				}
				#endif
            
        return msg;
      }
      
			// ADD: ctp instru
			call CtpInstrumentation.ctrl_rxpkt();
	
      //need to get the am_addr_t of the source
      from = call AMPacket.source(msg);
      rcvBeacon = (ctp_routing_header_t*)payload;

      congested = call CtpRoutingPacket.getOption(msg, CTP_OPT_ECN);

      dbg("TreeRouting","%s from: %d  [ parent: %d etx: %d]\n",
          __FUNCTION__, from, 
          rcvBeacon->parent, rcvBeacon->etx);

			#if defined(PRINTF_ENABLED)  
			if(dbg_beacons){					
				printf("\nRE: BeaconReceived: node:%u prnt:%u etx:%u  ", 
									from,rcvBeacon->parent,rcvBeacon->etx);
				//printfflush();
			}
			#endif

      //update neighbor table
			// MN:
      if (rcvBeacon->parent != INVALID_ADDR) {

        /* If this node is a root, request a forced insert in the link
         * estimator table and pin the node. */
        if (rcvBeacon->etx == 0) {
            dbg("TreeRouting","from a root, inserting if not in table\n");
            call LinkEstimator.insertNeighbor(from);
            call LinkEstimator.pinNeighbor(from);
						#if defined(PRINTF_ENABLED)  
						if(dbg_beacons){					
							printf("(ROOT)  ");
							//printfflush();
						}
						#endif
        }
        //TODO: also, if better than my current parent's path etx, insert

        routingTableUpdateEntry(from, rcvBeacon->parent, rcvBeacon->etx);
        call CtpInfo.setNeighborCongested(from, congested);
      }

      if (call CtpRoutingPacket.getOption(msg, CTP_OPT_PULL)) {
				#if defined(PRINTF_ENABLED)  
				if(dbg_beacons){					
					printf("PULL  ",rcvBeacon->parent);
					//printfflush();
				}
				#endif
				// MN: slow update phase
				//if(!slowUpdatePhase && routeInfo.parent != INVALID_ADDR){
        resetInterval();
				//}
      }


			// MN: Update from debugging paper. Recover faster from network partitions
			if (rcvBeacon->etx > routeInfo.etx + 100){ 
				call CtpInfo.triggerRouteUpdate(); 
			}

			#if defined(PRINTF_ENABLED)  
			if(dbg_beacons){					
				printf("\n");
				printfflush();
			}
			#endif
      return msg;
    }


    /* Signals that a neighbor is no longer reachable. need special care if
     * that neighbor is our parent */
    event void LinkEstimator.evicted(am_addr_t neighbor) {
        routingTableEvict(neighbor);
        dbg("TreeRouting","%s\n",__FUNCTION__);
				#if defined(PRINTF_ENABLED)  
				if(TRUE){					
					printf("\nRE: Neighbor evicted from LE: %u\n",neighbor);
					printfflush();
				}
				#endif
        if (routeInfo.parent == neighbor) {
            routeInfoInit(&routeInfo);
            justEvicted = TRUE;
            post updateRouteTask();
        }
    }

    /* Interface UnicastNameFreeRouting */
    /* Simple implementation: return the current routeInfo */
    command am_addr_t Routing.nextHop() {
				// MN:
        //return routeInfo.parent;    
				if( call CtpParentSelectionConfig.getParentSetSize() == 0){
					return routeInfo.parent; 
				}
				else{
					return call CtpParentSelectionConfig.drawRandomParent();
				}
    }
    command bool Routing.hasRoute() {
        return (routeInfo.parent != INVALID_ADDR);
    }
   
    /* CtpInfo interface */
    command error_t CtpInfo.getParent(am_addr_t* parent) {
        if (parent == NULL) 
            return FAIL;
        if (routeInfo.parent == INVALID_ADDR)    
            return FAIL;
        *parent = routeInfo.parent;
        return SUCCESS;
    }

    command error_t CtpInfo.getEtx(uint16_t* etx) {
        if (etx == NULL) 
            return FAIL;
        if (routeInfo.parent == INVALID_ADDR)    
            return FAIL;
				if (state_is_root == 1) {
	  			*etx = 0;
				} else {
	  			*etx = routeInfo.etx + call LinkEstimator.getLinkQuality(routeInfo.parent);
				}

        return SUCCESS;
    }

    command void CtpInfo.recomputeRoutes() {
      post updateRouteTask();
    }

    command void CtpInfo.triggerRouteUpdate() {
      resetInterval();
     }

    command void CtpInfo.triggerImmediateRouteUpdate() {
      resetInterval();
    }

    command void CtpInfo.setNeighborCongested(am_addr_t n, bool congested) {
        uint8_t idx;    
        if (ECNOff)
            return;
        idx = routingTableFind(n);
        if (idx < routingTableActive) {
            routingTable[idx].info.congested = congested;
        }
        if (routeInfo.congested && !congested) 
            post updateRouteTask();
        else if (routeInfo.parent == n && congested) 
            post updateRouteTask();
    }

    command bool CtpInfo.isNeighborCongested(am_addr_t n) {
        uint8_t idx;    

        if (ECNOff) 
            return FALSE;

        idx = routingTableFind(n);
        if (idx < routingTableActive) {
            return routingTable[idx].info.congested;
        }
        return FALSE;
    }
    
    /* RootControl interface */
    /** sets the current node as a root, if not already a root */
    /*  returns FAIL if it's not possible for some reason      */
    command error_t RootControl.setRoot() {
        bool route_found = FALSE;
        route_found = (routeInfo.parent == INVALID_ADDR);
        atomic {
            state_is_root = 1;
            routeInfo.parent = my_ll_addr; //myself
            routeInfo.etx = 0;
        }
        if (route_found) 
            signal Routing.routeFound();
        dbg("TreeRouting","%s I'm a root now!\n",__FUNCTION__);
        call CollectionDebug.logEventRoute(NET_C_TREE_NEW_PARENT, routeInfo.parent, 0, routeInfo.etx);
        return SUCCESS;
    }

    command error_t RootControl.unsetRoot() {
        atomic {
            state_is_root = 0;
            routeInfoInit(&routeInfo);
        }
        dbg("TreeRouting","%s I'm not a root now!\n",__FUNCTION__);
        post updateRouteTask();
        return SUCCESS;
    }

    command bool RootControl.isRoot() {
        return state_is_root;
    }

    default event void Routing.noRoute() {
    }
    
    default event void Routing.routeFound() {
    }


  /* The link will be recommended for insertion if it is better* than some
   * link in the routing table that is not our parent.
   * We are comparing the path quality up to the node, and ignoring the link
   * quality from us to the node. This is because of a couple of things:
   *   1. we expect this call only for links with white bit set
   *   2. we are being optimistic to the nodes in the table, by ignoring the
   *      1-hop quality to them (which means we are assuming it's 1 as well)
   *      This actually sets the bar a little higher for replacement
   *   3. this is faster
   */
    event bool CompareBit.shouldInsert(message_t *msg, void* payload, uint8_t len) {
        
        bool found = FALSE;
        uint16_t pathEtx;
        uint16_t neighEtx;
        int i;
        routing_table_entry* entry;
        ctp_routing_header_t* rcvBeacon;

        if ((call AMPacket.type(msg) != AM_CTP_ROUTING) ||
            (len != sizeof(ctp_routing_header_t))) 
            return FALSE;

        /* 1.determine this packet's path quality */
        rcvBeacon = (ctp_routing_header_t*)payload;

        if (rcvBeacon->parent == INVALID_ADDR)
            return FALSE;
        /* the node is a root, recommend insertion! */
        if (rcvBeacon->etx == 0) {
            return TRUE;
        }
    
        pathEtx = rcvBeacon->etx; // + linkEtx;

        /* 2. see if we find some neighbor that is worse */
        for (i = 0; i < routingTableActive && !found; i++) {
            entry = &routingTable[i];
            //ignore parent, since we can't replace it
            if (entry->neighbor == routeInfo.parent)
                continue;
            neighEtx = entry->info.etx;
            found |= (pathEtx < neighEtx); 
        }
        return found;
    }


    /************************************************************/
    /* Routing Table Functions                                  */

    /* The routing table keeps info about neighbor's route_info,
     * and is used when choosing a parent.
     * The table is simple: 
     *   - not fragmented (all entries in 0..routingTableActive)
     *   - not ordered
     *   - no replacement: eviction follows the LinkEstimator table
     */

    void routingTableInit() {
        routingTableActive = 0;
    }

    /* Returns the index of parent in the table or
     * routingTableActive if not found */
    uint8_t routingTableFind(am_addr_t neighbor) {
        uint8_t i;
        if (neighbor == INVALID_ADDR)
            return routingTableActive;
        for (i = 0; i < routingTableActive; i++) {
            if (routingTable[i].neighbor == neighbor)
                break;
        }
        return i;
    }


    error_t routingTableUpdateEntry(am_addr_t from, am_addr_t parent, uint16_t etx)    {
        uint8_t idx;
        uint16_t  linkEtx;
        linkEtx = call LinkEstimator.getLinkQuality(from);

        idx = routingTableFind(from);
        if (idx == routingTableSize) {
            //not found and table is full
            //if (passLinkEtxThreshold(linkEtx))
                //TODO: add replacement here, replace the worst
            //}
            dbg("TreeRouting", "%s FAIL, table full\n", __FUNCTION__);
            return FAIL;
        }
        else if (idx == routingTableActive) {
            //not found and there is space
            if (passLinkEtxThreshold(linkEtx)) {
                atomic {
                    routingTable[idx].neighbor = from;
                    routingTable[idx].info.parent = parent;
                    routingTable[idx].info.etx = etx;
                    routingTable[idx].info.haveHeard = 1;
                    routingTable[idx].info.congested = FALSE;
                    routingTableActive++;
                }
                dbg("TreeRouting", "%s OK, new entry\n", __FUNCTION__);
            } else {
                dbg("TreeRouting", "%s Fail, link quality (%hu) below threshold\n", __FUNCTION__, linkEtx);
            }
        } else {
            //found, just update
            atomic {
                routingTable[idx].neighbor = from;
                routingTable[idx].info.parent = parent;
                routingTable[idx].info.etx = etx;
		        routingTable[idx].info.haveHeard = 1;
            }
            dbg("TreeRouting", "%s OK, updated entry\n", __FUNCTION__);
        }
        return SUCCESS;
    }

    /* if this gets expensive, introduce indirection through an array of pointers */
    error_t routingTableEvict(am_addr_t neighbor) {
        uint8_t idx,i;
        idx = routingTableFind(neighbor);
        if (idx == routingTableActive) 
            return FAIL;
        routingTableActive--;
        for (i = idx; i < routingTableActive; i++) {
            routingTable[i] = routingTable[i+1];    
        } 
        return SUCCESS; 
    }
    /*********** end routing table functions ***************/

    /* Default implementations for CollectionDebug calls.
     * These allow CollectionDebug not to be wired to anything if debugging
     * is not desired. */

    default command error_t CollectionDebug.logEvent(uint8_t type) {
        return SUCCESS;
    }
    default command error_t CollectionDebug.logEventSimple(uint8_t type, uint16_t arg) {
        return SUCCESS;
    }
    default command error_t CollectionDebug.logEventDbg(uint8_t type, uint16_t arg1, uint16_t arg2, uint16_t arg3) {
        return SUCCESS;
    }
    default command error_t CollectionDebug.logEventMsg(uint8_t type, uint16_t msg, am_addr_t origin, am_addr_t node) {
        return SUCCESS;
    }
    default command error_t CollectionDebug.logEventRoute(uint8_t type, am_addr_t parent, uint8_t hopcount, uint16_t etx) {
        return SUCCESS;
    }

    command bool CtpRoutingPacket.getOption(message_t* msg, ctp_options_t opt) {
      return ((getHeader(msg)->options & opt) == opt) ? TRUE : FALSE;
    }

    command void CtpRoutingPacket.setOption(message_t* msg, ctp_options_t opt) {
      getHeader(msg)->options |= opt;
    }

    command void CtpRoutingPacket.clearOption(message_t* msg, ctp_options_t opt) {
      getHeader(msg)->options &= ~opt;
    }

    command void CtpRoutingPacket.clearOptions(message_t* msg) {
      getHeader(msg)->options = 0;
    }

    
    command am_addr_t     CtpRoutingPacket.getParent(message_t* msg) {
      return getHeader(msg)->parent;
    }
    command void          CtpRoutingPacket.setParent(message_t* msg, am_addr_t addr) {
      getHeader(msg)->parent = addr;
    }
    
    command uint16_t      CtpRoutingPacket.getEtx(message_t* msg) {
      return getHeader(msg)->etx;
    }
    command void          CtpRoutingPacket.setEtx(message_t* msg, uint16_t etx) {
      getHeader(msg)->etx = etx;
    }

    command uint8_t CtpInfo.numNeighbors() {
      return routingTableActive;
    }
    command uint16_t CtpInfo.getNeighborLinkQuality(uint8_t n) {
      return (n < routingTableActive)? call LinkEstimator.getLinkQuality(routingTable[n].neighbor):0xffff;
    }
    command uint16_t CtpInfo.getNeighborRouteQuality(uint8_t n) {
      return (n < routingTableActive)? call LinkEstimator.getLinkQuality(routingTable[n].neighbor) + routingTable[n].info.etx:0xfffff;
    }
    command am_addr_t CtpInfo.getNeighborAddr(uint8_t n) {
      return (n < routingTableActive)? routingTable[n].neighbor:AM_BROADCAST_ADDR;
    }

		//MN: Get the neighbor's node ETX
		command uint16_t CtpInfo.getNeighborEtx(am_addr_t n){
			uint8_t i = routingTableFind(n);
      if (i < routingTableActive) {
				return (&routingTable[i])->info.etx;			
			}
			else{
				return MAX_METRIC;			
			}
		}
    
} 
