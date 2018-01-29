/**
* Author: Miguel Navarro
*/
#if defined(PRINTF_ENABLED)  
#include "printf.h"
#endif

generic module CtpReTxEngineP(){

	// Provided interfaces
  provides interface SendnReTx;

  uses interface Random;
	uses interface Timer<TMilli> as TimerReTx;
	uses interface PacketAcknowledgements;
	uses interface LinkEstimator;
	uses interface Packet as SubPacket;

	// ADD: ctp instrumentation
	uses interface CtpInstrumentation;
	uses interface CtpHealth;

	#if defined(PLATFORM_IRIS)
  uses interface PacketField<uint8_t> as PacketRSSI;
	#else
  //uses interface CC2420Packet;
	//uses interface PacketField<uint8_t> as PacketRSSI;
	#endif

	// Relayed interfaces
	uses interface AMSend as RealSend;
	uses interface AMPacket;

	// Selecting a new parent after some ReTxs...
  uses interface CtpParentSelectionConfig;
  uses interface CtpInfo;

}
implementation{

	#if defined(PRINTF_ENABLED)  
	bool dbg_retx = TRUE;
	#endif

	// TODO: MN: This should be removed *****  only for testing
	//bool TESTING_SEND_DONE = TRUE;

	uint8_t reTx_MAX 	= 0;
	bool busyReTx 			= FALSE;
	bool ackPending 		= FALSE;

	uint8_t reTx_current;
	message_t * currentMsg;
	am_addr_t currentAddr;
	uint8_t currentLen;

	uint8_t oneHopReTxs = 0;

	/* Same function as the forwarding engine. Used to update the header fields (health and stats) */
  ctp_data_header_t* getHeader(message_t* m) {
    return (ctp_data_header_t*)call SubPacket.getPayload(m, sizeof(ctp_data_header_t));
  }

	/* Same as the forwarding engine to control the retransmission counter 
     but uses a different counter */ 
  static void startTimerReTx(uint16_t window, uint16_t offset) {
    uint16_t r = call Random.rand16();
    r %= window;
    r += offset;
    call TimerReTx.startOneShot(r);
    dbg("Forwarder", "Rexmit timer will fire in %hu ms\n", r);
  }


	/* Commands to complete the send interface */

	command error_t SendnReTx.cancel(message_t *msg){
		// TODO:
		return FAIL;
	}

	command void * SendnReTx.getPayload(message_t *msg, uint8_t len){
		return call	RealSend.getPayload(msg, len);
	}

	command uint8_t SendnReTx.maxPayloadLength(){
		return call RealSend.maxPayloadLength();
	}




	task void reTxTask(){
		error_t result;

		// Update current reTx health and stats for the 1st hop
		ctp_data_header_t* hdr_test;
		hdr_test = getHeader(currentMsg);
		#if defined(PRINTF_ENABLED)  
		if(dbg_retx){
			printf("    ReTxE: reTxTask (retx:%u) (dest:%u)",reTx_current,currentAddr);
			printfflush();
		}
		#endif

		if(hdr_test->thl == 0){
			call CtpHealth.get_hlth_retx(&hdr_test->retx);
			//hdr_test->reTxs = reTx_current;
			hdr_test->reTxs = oneHopReTxs;	// TODO: added
			#if defined(PRINTF_ENABLED)  
			if(dbg_retx){
				printf(" (thl=0)");
			}
			#endif
		}

		#if defined(PRINTF_ENABLED)  
		if(dbg_retx){
			printf(" \n");
			printfflush();
		}
		#endif
		
		// Request ACK
		if (call PacketAcknowledgements.requestAck(currentMsg) == SUCCESS) {
			ackPending = TRUE;
		}
		else{
			ackPending = FALSE;
			#if defined(PRINTF_ENABLED)  
			if(dbg_retx){
				printf("    ReTxE: reTxTask: ERROR requesting ack\n");
				printfflush();
			}
			#endif
		}
		// Retry to send the pkt
		result = call RealSend.send(currentAddr,currentMsg, currentLen);
		#if defined(PRINTF_ENABLED)  
		if(dbg_retx){
			printf("    ReTxE: realsend ");
		}
		#endif

		if( result != SUCCESS ){
			#if defined(PRINTF_ENABLED)  
			if(dbg_retx){
				printf(" failed (error:%u)\n",result);
				printfflush();
			}
			#endif
			// Clear the busy flag
			busyReTx = TRUE;
			// Signal the send done to the upper layer with an error
			signal SendnReTx.sendDone(currentMsg,result); 
			return;
		}

		#if defined(PRINTF_ENABLED)  
		if(dbg_retx){
			printf(" ok\n");
			printfflush();
		}
		#endif
		// The command didn't fail, then wait for the RealSend.sendDone event
		return;
	}



	/* Subsend command to the link layer. It receives the number of retransmissions
     that apply to the current packet. Initially all attempts are addressed to the
     same parent */
	command error_t SendnReTx.send(am_addr_t addr, message_t *msg, uint8_t len, uint8_t numretx){
		error_t result;

		if(busyReTx){
			// Component is busy ReTx-ing another packet
			#if defined(PRINTF_ENABLED)  
			if(dbg_retx){
				printf("    ReTxE: BUSY\n");
				printfflush();
			}
			#endif
			return EBUSY;
		}

		// Initialize reTx
		reTx_MAX = numretx;
		reTx_current = 0;
		oneHopReTxs = 0; // TODO: added

		// Attempt to send the packet
		busyReTx = TRUE;
		currentMsg = msg;
	 	currentAddr = addr;
		currentLen = len;

		// Request ACK
		if (call PacketAcknowledgements.requestAck(currentMsg) == SUCCESS) {
			ackPending = TRUE;
		}
		else{
			ackPending = FALSE;
		}

		// TODO: MN: Only for testing...  remove!
		/*
		if (TESTING_SEND_DONE){
			#if defined(PRINTF_ENABLED)  
			if(TRUE){
				printf("\nTESTING SEND DONE! 1st attempt *** \n");
				//printfflush();
			}
			#endif
			TESTING_SEND_DONE = FALSE;			
			result = FAIL;
		}
		else {
			#if defined(PRINTF_ENABLED)  
			if(TRUE){
				printf("\nTESTING SEND DONE! NEW attempt *** \n");
				//printfflush();
			}
			#endif
			// Do the original transmission
			result = call RealSend.send(currentAddr,currentMsg, currentLen);
		}
		*/

		// Do the original transmission
		result = call RealSend.send(currentAddr,currentMsg, currentLen);


		if( result != SUCCESS){
			#if defined(PRINTF_ENABLED)  
			if(dbg_retx){
				printf("    ReTxE: originalTx (dest:%u) (F) (%u)\n",currentAddr,result);
				printfflush();
			}
			#endif
			
			// The radio failed, then return a command failure and clear the busy flag
			busyReTx = FALSE;
			return result;
		}

		// Original tx was successful
		#if defined(PRINTF_ENABLED)  
		if(dbg_retx){
			printf("    ReTxE: originalTx (dest:%u) (S)\n",currentAddr);
			printfflush();
		}
		#endif
		return result;	
	}


	/* Subsend sendDone event. This event decides if a task is posted 
	   to try retransmitting the packet one more time. The task is not
		 posted directly; instead, the retransmission timer is set */
	event void RealSend.sendDone(message_t* msg, error_t error) {	

		error_t linkEstResult;

		if(error != SUCCESS){
			// There was a problem sending the packet
			#if defined(PRINTF_ENABLED)  
			if(dbg_retx){
				printf("  ReTxE: realsend done: error (%u) ***\n",error);
				printfflush();
			}
			#endif

			// Clear busy flag
			//busyReTx = FALSE;

			// TODO: Verify if this applies for all errors...
			//signal SendnReTx.sendDone(msg,error);
			//return;

	    startTimerReTx(SENDDONE_FAIL_WINDOW, SENDDONE_FAIL_OFFSET);
		}
    else if (ackPending && !call PacketAcknowledgements.wasAcked(msg)) {
			// The packet was not acknowledged

			#if defined(PRINTF_ENABLED)  
			if(dbg_retx){
				printf("    ReTxE: realsend done: no ack (retx:%u)\n",reTx_current);
				printfflush();
			}
			#endif
			
			// TODO: verify final version...
			//if(reTx_current <= 1){
			#if defined(PRINTF_ENABLED)  
			if(FALSE){
				printf("    UPDATING LinkEstimator for %u ",currentAddr);
				printfflush();
			}
			#endif
			// Update link estimator
			linkEstResult = call LinkEstimator.txNoAck(currentAddr);
			#if defined(PRINTF_ENABLED)  
			if(FALSE){
				printf(" result:%u \n",linkEstResult);
				printfflush();
			}
			#endif
			//}

			call CtpInstrumentation.data_txpkt();
      call CtpInfo.recomputeRoutes();   // Recompute routes

			// TODO: added
			if(reTx_current == reTx_MAX/2 && (call CtpParentSelectionConfig.getParentSetSize() > 1)){
				oneHopReTxs = 0;
				currentAddr = call CtpParentSelectionConfig.drawRandomParent();
			}

			if(reTx_current < reTx_MAX){	
				// Do the ReTx

				// ADD: ctp instru
				call CtpHealth.hlth_retx();

			  reTx_current++;
				oneHopReTxs++; // TODO: added
	      startTimerReTx(SENDDONE_NOACK_WINDOW, SENDDONE_NOACK_OFFSET);
			}
			else{		
				// Max reTx reached	

				/*
				#if defined(PRINTF_ENABLED)  
				if(FALSE){
					printf("    UPDATING LinkEstimator for %u ",currentAddr);
					printfflush();
				}
				#endif
				// Update link estimator
				linkEstResult = call LinkEstimator.txNoAck(currentAddr);
				#if defined(PRINTF_ENABLED)  
				if(FALSE){
					printf(" result:%u \n",linkEstResult);
					printfflush();
				}
				#endif
				*/

				#if defined(PRINTF_ENABLED)  
				if(dbg_retx){
					printf("    ReTxE: MAX reTx reached (retx:%u) (dest:%u)\n",reTx_current,currentAddr);
					printfflush();
				}
				#endif
				call CtpHealth.hlth_dropped();
				// Clear busy flag
				busyReTx = FALSE;
				signal SendnReTx.sendDone(msg,FAIL);	 	// signal that it failed
				return;
			}
		}	
		else{
			// The packet was acknowledged!

			#if defined(PRINTF_ENABLED)  
			if(dbg_retx){
				printf("    ReTxE: realsend done: acked! (retx:%u)\n",reTx_current);
				printfflush();
			}
			#endif

			// Update link estimator			
			call LinkEstimator.txAck(currentAddr);
						
			// ADD: ctp instru
			call CtpInstrumentation.data_txpkt();
      call CtpInstrumentation.data_rxack();
	  
		  #if defined(PLATFORM_IRIS)
		    if(call PacketRSSI.isSet(msg)){
					call LinkEstimator.setLinkRssi(	call AMPacket.destination(msg), 
																					call PacketRSSI.get(msg));
		    } else {
					call LinkEstimator.setLinkRssi(	call AMPacket.destination(msg), 
																					0xFF);
		    }
		  #else
		    //call LinkEstimator.setLinkRssi(	call AMPacket.destination(msg), 
				//																call CC2420Packet.getRssi(msg));
				/*
		    if(call PacketRSSI.isSet(msg)){
					call LinkEstimator.setLinkRssi(currentAddr, call PacketRSSI.get(msg));
		    } else {
					call LinkEstimator.setLinkRssi(currentAddr, 0xFF);
		    }
				*/
		  #endif

			// Clear busy flag
			busyReTx = FALSE;
			signal SendnReTx.sendDone(msg,SUCCESS);	 	// signal that it was successful
			return;
		}
	}

  event void TimerReTx.fired() {
		#if defined(PRINTF_ENABLED)  
		if(dbg_retx){
			printf("\n    ReTxE: retx timer fired (ReTX a packet!)\n");
			printfflush();
		}
		#endif
    post reTxTask();
  }

  /* signalled when this neighbor is evicted from the neighbor table */
  event void LinkEstimator.evicted(am_addr_t neighbor) {}
  
}





