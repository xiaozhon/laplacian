/*
 *  @author Miguel Navarro
 */
#if defined(PRINTF_ENABLED)  
#include "printf.h"
#endif

generic module CtpParentSelectionEngineP(uint8_t parentTableSize){

  provides interface CtpParentSelectionConfig;
	provides interface CtpParentSelectionHealth;
	
  uses interface Random;
}

implementation{

	#if defined(PRINTF_ENABLED)  
	bool dbg_parent_select = FALSE;		// Info about the parent selection (forwarder)
	bool dbg_parent_set    = FALSE;		// Info about the parent set
	#endif

	#ifndef MAX_PARENTSET_SIZE
	#define MAX_PARENTSET_SIZE 4
	#endif

	// Parent set information
  routing_table_entry* parentSetTable[MAX_PARENTSET_SIZE];
	nx_uint16_t parentSetPathETX[MAX_PARENTSET_SIZE];
	parentSet prntSet; 
	am_addr_t rand_prnt;

	bool parent_init_flag = FALSE;


	command void CtpParentSelectionConfig.initializeParentSet(){
		prntSet.setSize 			= 0;
		prntSet.maxPathETX 		= 0;
		prntSet.setETX 				= MAX_METRIC;
		prntSet.bestNeighbor 	= INVALID_ADDR;

		if(parent_init_flag == FALSE){
			prntSet.previousFwder = INVALID_ADDR;	
			parent_init_flag = TRUE;
		}

		rand_prnt 						= INVALID_ADDR;

		#if defined(PRINTF_ENABLED)  
		if(dbg_parent_set){
			atomic {
				printf("  PS: init setsize=%u\n", prntSet.setSize);
				printfflush();
			}
		}
		#endif	
	}


  command error_t CtpParentSelectionConfig.addParentCandidate( routing_table_entry* entry, nx_uint16_t candPathETX )
  {
		/*
			Receives candidates:
				* With a valid path to the sink
				* Not congested
				* At the same level as the current parent (Not children of the current node)

			Adds candidates within the ETX interval that defines a possible parent 
		*/

		/*
				- If not full, add the candidate
				- If full, check if the candidate is better than the current neighbors in the set
					 if new candidate is better, replace one of the members of the set
		*/
		nx_uint8_t i;

		if(prntSet.setSize < MAX_PARENTSET_SIZE){
			// The candidate can be added
			parentSetTable[prntSet.setSize] = entry;
			parentSetPathETX[prntSet.setSize] = candPathETX;
			// Update max path etx
			if(candPathETX > prntSet.maxPathETX){
				prntSet.maxPathETX = candPathETX;
				prntSet.maxPathETXPos = prntSet.setSize;
			}
			// Update the parent set ETX
			if(candPathETX < prntSet.setETX){
				prntSet.setETX = candPathETX;	
				prntSet.bestNeighbor = entry->neighbor;		
			}
			prntSet.setSize = prntSet.setSize + 1;

			#if defined(PRINTF_ENABLED)  
			if(dbg_parent_select){
				printf("  PS: added NEW cand %u etx:%u \n", 
							    entry->neighbor,candPathETX);
				//printfflush();
				printf("      setsize:%u maxETX:%u setETX:%u bestNeigh:%u\n", 
											prntSet.setSize,prntSet.maxPathETX, prntSet.setETX, prntSet.bestNeighbor);
				printfflush();
			}
			#endif
			return SUCCESS;			
		}
		else{
			// Candidate set is full
			if(candPathETX < prntSet.maxPathETX){
				// The candidate is better than one of the current members, then exchange them
				parentSetTable[prntSet.maxPathETXPos] = entry;
				parentSetPathETX[prntSet.maxPathETXPos] = candPathETX;
				// Update the max path ETX in the set
				// Update the set ETX
				prntSet.maxPathETX = 0;
				prntSet.setETX = MAX_METRIC;
				for(i=0;i<prntSet.setSize;i++){
					if(parentSetPathETX[i] >  prntSet.maxPathETX){
						prntSet.maxPathETX = parentSetPathETX[i];
						prntSet.maxPathETXPos = i;
					}
					if(parentSetPathETX[i] <  prntSet.setETX){
						prntSet.setETX = parentSetPathETX[i];
  					prntSet.bestNeighbor = parentSetTable[i]->neighbor;		
					}
				}
				#if defined(PRINTF_ENABLED)  
				if(dbg_parent_select){
				printf("  PS: added NEW cand %u etx:%u \n", 
                  entry->neighbor,candPathETX);
				//printfflush();
				printf("      setsize:%u maxETX:%u setETX:%u bestNeigh:%u\n", 
											prntSet.setSize,prntSet.maxPathETX, prntSet.setETX, prntSet.bestNeighbor);
				printfflush();
				}
				#endif		
			}	
			else{
				#if defined(PRINTF_ENABLED)  
				if(dbg_parent_select){
					printf("  PS: IGNORED cand %u etx:%u setsize:%u maxETX:%u setETX:%u\n", 
								entry->neighbor,candPathETX,prntSet.setSize,prntSet.maxPathETX,prntSet.setETX);
					printfflush();
				}
				#endif
			}	
		}

		return SUCCESS;			
	}

	//command error_t CtpParentSelectionConfig.drawRandomParent(routing_table_entry** prntEntry){
	command am_addr_t CtpParentSelectionConfig.drawRandomParent(){
		// Selects a parent randomly from the candidate set	
		uint16_t rnd;

		// Parent set is empty
		if(prntSet.setSize == 0){
			#if defined(PRINTF_ENABLED)  
				if(dbg_parent_set){
					printf("  PS: draw rand parent: set is EMPTY\n");
					printfflush();
				}			
			#endif
			//*prntEntry = &emptySetEntry;
			return INVALID_ADDR;
		}
		
		
		#if defined(PRINTF_ENABLED)  
			if(dbg_parent_set){
				printf("  PS: draw rand parent ");
				//if(*prntEntry == NULL){
				//		printf(" (NULL) ");
				//}
			}			
		#endif
		

		rnd = call Random.rand16();
		rnd = rnd % prntSet.setSize;
		//*prntEntry = parentSetTable[rnd];
		//rand_prnt = (*prntEntry)->neighbor;  
		rand_prnt = parentSetTable[rnd]->neighbor;  
		#if defined(PRINTF_ENABLED)  
			if(dbg_parent_set){
				atomic {
					printf("p:%u\n", rand_prnt);
					printfflush();
				}
			}
		#endif

		if(prntSet.setSize == 1){
			prntSet.previousFwder = INVALID_ADDR;
			return rand_prnt;
		}
		else{
			if(prntSet.previousFwder == INVALID_ADDR){
				// Set the previous forwarder flag
				prntSet.previousFwder = rand_prnt;
				return rand_prnt;
			}
			else{
				while(prntSet.previousFwder == rand_prnt){
					// Draw a new parent
					rnd = call Random.rand16();
					rnd = rnd % prntSet.setSize;
					rand_prnt = parentSetTable[rnd]->neighbor;  
				}	
				// Set the flag to the new parent
				prntSet.previousFwder = rand_prnt;
				return rand_prnt;		
			}
		}

		//return rand_prnt;

	}

	command error_t CtpParentSelectionConfig.getParentSetETX( nx_uint16_t* parentSetETX, nx_uint8_t* parentSetSize ){
		
		// Parent set is empty
		if(prntSet.setSize == 0){
			#if defined(PRINTF_ENABLED)  
				if(dbg_parent_set){
					printf("  PS: parent set is EMPTY\n");
					printfflush();
				}			
			#endif
			*parentSetETX = MAX_METRIC;
			*parentSetSize = prntSet.setSize;
			return FAIL;
		}
		else{
			#if defined(PRINTF_ENABLED)  
				if(dbg_parent_set){
					printf("  PS: parent set ETX: %u \n",prntSet.setETX);
					printfflush();
				}			
			#endif
			*parentSetETX = prntSet.setETX;
			*parentSetSize = prntSet.setSize;
			return SUCCESS;
		}
	}

	command nx_uint8_t CtpParentSelectionConfig.getParentSetSize(){
		return prntSet.setSize;
	}


	command nx_uint8_t CtpParentSelectionHealth.getCandiateSetSize(){
		#if defined(PRINTF_ENABLED)  
			if(dbg_parent_set){
				printf("  PS: parent set size: %u\n",prntSet.setSize);
				printfflush();
			}			
		#endif
		return prntSet.setSize;
	}

	command nx_uint16_t CtpParentSelectionHealth.getBestNeighborFromParentSet(){
		#if defined(PRINTF_ENABLED)  
			if(dbg_parent_set){
				printf("  PS: best neighbor: %u\n",prntSet.bestNeighbor);
				printfflush();
			}			
		#endif
		return prntSet.bestNeighbor;
	}




	/****************************** CtpInfo ****************************************/
	/*
	command error_t CtpInfo.getEtx(uint16_t *etx){
		return call ReCtpInfo.getEtx(etx);
	}

	command am_addr_t CtpInfo.getNeighborAddr(uint8_t neighbor){
		return 	call ReCtpInfo.getNeighborAddr(neighbor);
	}

	command uint16_t CtpInfo.getNeighborLinkQuality(uint8_t neighbor){
		return 	call ReCtpInfo.getNeighborLinkQuality(neighbor);
	}

	command uint16_t CtpInfo.getNeighborRouteQuality(uint8_t neighbor){
		return call ReCtpInfo.getNeighborRouteQuality(neighbor);	
	}

	command error_t CtpInfo.getParent(am_addr_t *parent){
		return call ReCtpInfo.getParent(parent);
	}

	command bool CtpInfo.isNeighborCongested(am_addr_t n){
		return call ReCtpInfo.isNeighborCongested(n);
	}

	command uint8_t CtpInfo.numNeighbors(){
		return call ReCtpInfo.numNeighbors();
	}

	command void CtpInfo.recomputeRoutes(){
		return call ReCtpInfo.recomputeRoutes();
	}

	command void CtpInfo.setNeighborCongested(am_addr_t n, bool congested){
		return call ReCtpInfo.setNeighborCongested(n, congested);
	}

	command void CtpInfo.triggerImmediateRouteUpdate(){
		return call ReCtpInfo.triggerImmediateRouteUpdate();
	}

	command void CtpInfo.triggerRouteUpdate(){
		return call ReCtpInfo.triggerRouteUpdate();
	}

	*/

	/************************ UnicastNameFreeRouting ********************************/
	/*
	command bool UnicastNameFreeRouting.hasRoute(){
		return call ReUnicastNameFreeRouting.hasRoute();	
	}

	command am_addr_t UnicastNameFreeRouting.nextHop(){
		// Returns the parent that was chosen randomly
		//#if defined(PRINTF_ENABLED)  
		//	if(dbg_parent_set){
		//		printf("   PS: sel parent from set %u\n",rand_prnt);
		//		printfflush();
		//	}
		//#endif
		//return rand_prnt;

		return call ReUnicastNameFreeRouting.nextHop();
	}

	event void ReUnicastNameFreeRouting.noRoute(){
		signal UnicastNameFreeRouting.noRoute();
	}
	
	event void ReUnicastNameFreeRouting.routeFound(){
		signal UnicastNameFreeRouting.routeFound();
	}

	*/

	/************************ CtpCongestion ***************************************/
	/*
	command bool CtpCongestion.isCongested(){
		return call ReCtpCongestion.isCongested();
	}

	command void CtpCongestion.setClientCongested(bool congested){
		return call CtpCongestion.setClientCongested(congested);
	}

	*/

	/************************ LinkEstimator ****************************************/

	/*

  command uint16_t LinkEstimator.getLinkQuality(uint16_t neighbor){
		return call ReLinkEstimator.getLinkQuality(neighbor);
	}


  command error_t LinkEstimator.insertNeighbor(am_addr_t neighbor){
		return call ReLinkEstimator.insertNeighbor(neighbor);
	}


  command error_t LinkEstimator.pinNeighbor(am_addr_t neighbor){
		return call ReLinkEstimator.pinNeighbor(neighbor);
	}


  command error_t LinkEstimator.unpinNeighbor(am_addr_t neighbor){
		return call ReLinkEstimator.unpinNeighbor(neighbor);
	}


  command error_t LinkEstimator.txAck(am_addr_t neighbor){
		return call ReLinkEstimator.txAck(neighbor);
	}


  command error_t LinkEstimator.txNoAck(am_addr_t neighbor){
		return call ReLinkEstimator.txNoAck(neighbor);
	}


  command error_t LinkEstimator.clearDLQ(am_addr_t neighbor){
		return call ReLinkEstimator.clearDLQ(neighbor);
	}

  command int8_t LinkEstimator.getLinkRssi(am_addr_t neighbor){
		return call ReLinkEstimator.getLinkRssi(neighbor);	
	}

  command error_t LinkEstimator.setLinkRssi(am_addr_t neighbor, int8_t newrssi){
		return call ReLinkEstimator.setLinkRssi(neighbor, newrssi);	
	}



  event void ReLinkEstimator.evicted(am_addr_t neighbor){
		signal LinkEstimator.evicted(neighbor);
	}

	*/
 
}





