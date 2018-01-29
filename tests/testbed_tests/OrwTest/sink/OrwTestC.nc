/**
 * Test ORW application, record the routing path for further analysis
 *
 * Each node randomly send packets to the sink based on constant packet rate. Upon
 * the reception of a packet in the intermidiate node, the node piggybacks its address 
 * (node id) to the packets. 
 * 
 * @author Xiaoyang Zhong
 * @version $Revision: 0.1 $ $Date: 2017-02-06 16:16:47 $
 */

#include <Timer.h>
#include "opp.h"
#include "OrwTest.h"


#if defined(PRINTF_ENABLED)
#include "printf.h"
#endif

module OrwTestC {
	uses interface Boot;
	uses interface SplitControl as RadioControl;
	uses interface Leds;
	uses interface Timer<TMilli>;
	uses interface Random;
	uses interface ParameterInit<uint16_t> as SeedInit;
	uses interface Packet;
	uses interface Receive;
//	uses interface ActiveMessageAddress;

	uses interface AMPacket;	
	uses interface OppPacket;	
	uses interface Intercept;
	
	uses interface Send;
}
implementation {

	message_t packet;
	bool sendBusy = FALSE;
	uint16_t counter;
	uint16_t rounds;
	
	uint16_t randInt;	// random time interval

	uint16_t DEF_INTERVAL = 1024*60;	// 30 seconds in Indriya test
	
	event void Boot.booted() {
	
		counter = 0;
		sendBusy = FALSE;
		rounds = 0;
		randInt = 0;
		call SeedInit.init(TOS_NODE_ID);
		call RadioControl.start();
		#if defined(PRINTF_ENABLED)  
			printf("Mote %d started.. \n", TOS_NODE_ID);
			printfflush();
		#endif
	}
	
	event void RadioControl.startDone(error_t err) {
		if (err != SUCCESS) {
			call RadioControl.start();
		}
		else {
//		call ActiveMessageAddress.setAddress(call ActiveMessageAddress.amGroup(), TOS_NODE_ID);

				// sink start a regular timer
			call Timer.startOneShot(DEF_INTERVAL);
			
			#if defined(PRINTF_ENABLED)  
				printf("Sink started timer, sink id: %d \n", TOS_NODE_ID);
				printfflush();
			#endif
		}
	}

//	async event void ActiveMessageAddress.changed(){}

	event void RadioControl.stopDone(error_t err) {}
	event void Send.sendDone(message_t* msg, error_t err) {}
	
 
	event void Timer.fired() {
		rounds++;
		
			
		#if defined(PRINTF_ENABLED)  
			printf("Timer fired on SINK, round: %d \n", rounds);
			printfflush();
		#endif
//			if(rounds <= 150) {
		call Timer.startOneShot(DEF_INTERVAL);
//			}
			
	}

	
	event bool Intercept.forward(message_t* msg, void* payload, uint8_t len) {
		// record the path
		uint8_t hopCounter = call OppPacket.getTtl(msg) + 1;
		data_msg_t* imsg = (data_msg_t*) payload;
		
		if(hopCounter > 1 && (hopCounter < MAX_PATH_LEN)) {
			// hop 0: src, hop 1: prnt, hop 2.......
			// USE 'hopCounter-2' to save two bytes, since parent is stored independly
			imsg->path[hopCounter-2] = call AMPacket.source(msg);		
			
			#if defined(PRINTF_ENABLED)  
				printf("\t\t--- Mote: Intercept packet: hop: %d, pre_hop: %d, cur_id: %d\n", 
						hopCounter, 
						call AMPacket.source(msg),
						TOS_NODE_ID);
				printfflush();
			#endif
			
		} else if (hopCounter == 1){
			imsg->path[hopCounter-1] = TOS_NODE_ID;	
			imsg->parent = TOS_NODE_ID;
			#if defined(PRINTF_ENABLED)  
				printf("\t\t--- Mote: Intercept packet: hop: %d, pre_hop: %d, cur_id: %d\n", 
						hopCounter, 
						call AMPacket.source(msg),
						TOS_NODE_ID);
				printfflush();
			#endif
		}
		#if defined(PRINTF_ENABLED)  
			printf("\nDATA packet intercept at node: %d, org: %d, hop: %d\n", TOS_NODE_ID, call OppPacket.getSource(msg), hopCounter);
			printfflush();
		#endif
		return TRUE;
	}
	
	event message_t* Receive.receive(message_t* msg, 
					 void* payload, uint8_t len){
		// sink receive the packet 
//		#if defined(PRINTF_ENABLED)  
//			printf("Receive packet on SINK\n");
//			printfflush();
//		#endif
		if(len != sizeof(data_msg_t)) {
			return msg;
		} else{
			uint16_t source;
			uint8_t hopCounter;
			uint8_t seqno;
			uint16_t child = call AMPacket.source(msg);
			data_msg_t* rcm = (data_msg_t*)payload;

			source = call OppPacket.getSource(msg);
 	 		seqno = call OppPacket.getSeqNum(msg);
 	 		hopCounter = call OppPacket.getTtl(msg) + 1;

			if(hopCounter > 1 && (hopCounter < MAX_PATH_LEN)) {
				rcm->path[hopCounter-2] = child;	
				rcm->path[hopCounter-1] = TOS_NODE_ID;	
			}else if (hopCounter == 1){
				rcm->path[hopCounter-1] = TOS_NODE_ID;	
				rcm->parent = TOS_NODE_ID;
			}
			
			
			#if defined(PRINTF_ENABLED)  
				printf("Sink Received: data: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
							rounds, source, seqno, hopCounter, rcm->parent, rcm->path[1], 
							rcm->path[2], rcm->path[3], rcm->path[4], rcm->path[5], rcm->path[6],
							rcm->path[7], rcm->path[8], rcm->path[9],rcm->path[10],rcm->path[11],
							rcm->path[12], rcm->path[13], rcm->path[14], rcm->path[15], rcm->path[16],
							rcm->path[17], rcm->path[18], rcm->path[19], rcm->path[20], rcm->path[21], 
							rcm->path[22], rcm->path[23], rcm->path[24], rcm->path[25], rcm->path[26],
							rcm->path[27], rcm->path[28], rcm->path[29], rcm -> data);
				printfflush();
			#endif
			
			return msg;
		}
	}


}
