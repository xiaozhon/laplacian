#include <Timer.h>
#include "LapTest.h"


module LapTestC {
	uses interface Boot;
	uses interface Leds;
	uses interface SplitControl as RadioControl;
	
	uses interface Timer<TMilli> as DataTimer;
	uses interface AMPacket;
	
	// ctp controls
	uses interface StdControl as CtpControl;
	uses interface RootControl;
	
	// ctp data collection
	uses interface Send as DataSend;
	uses interface Receive as DataReceive;
	uses interface Intercept as DataIntercept;	// record the routing path
	uses interface CtpPacket;
	uses interface CtpInfo;
	
}
implementation {
	
	message_t data_pkt;
	
	bool radioBusy = FALSE;	// a radio busy controls all the radio activity
	uint16_t rounds = 0;
	uint8_t i = 0;
	
	// data payload
	uint16_t counter = 0;	// data payload
	am_addr_t parent = 0xFFFF;
	
	
	event void Boot.booted() {
		call RadioControl.start();
		dbg("Boot", "Mote Booted!\n");
		
	}
	
	event void RadioControl.startDone(error_t err) {
		if (err != SUCCESS)
			call RadioControl.start();
		else {
		
			call CtpControl.start();
			
	  		if (TOS_NODE_ID == SINK_ADDR) {
				call RootControl.setRoot();
				dbg("Root", "Root: set root\n");
	  		}
	  		// root start this to count for cycles
	  		call DataTimer.startPeriodic((uint32_t) DEF_INTERVAL);
	  		
	  		
		}
	}
	
	/************************* Data collection logic **************************/
	
	/*
	 * Send data packet
	 */
	task void sendDataMessage() {
		data_msg_t* d_msg = (data_msg_t*) call DataSend.getPayload(&data_pkt, sizeof(data_msg_t));
	
		d_msg->data = counter++;
		// TODO
		
		if ((call CtpInfo.getParent(&parent)) != SUCCESS) {
			dbg("CtpParent", "CtpParent: get parent fail\n");
		}
		d_msg->parent = parent;
		for(i = 0; i < MAX_PATH_LEN; i++){
			d_msg->path[i] = 0;
		}
		
		if (call DataSend.send(&data_pkt, sizeof(data_msg_t)) != SUCCESS) {
	  		dbg("DataSend", "DataSend: send data packet FAIL(len: %hu)\n", sizeof(data_msg_t));
	    } else {
	  		radioBusy = TRUE;
		  	dbg("DataSend", "DataSend: send data packet (counter: %hu)\n", d_msg->data);
	    }
	}
	/*
	 * Data timer fired, collect data 
	 */
	event void DataTimer.fired() {
		rounds++;
		if(TOS_NODE_ID != SINK_ADDR && !radioBusy) {
			post sendDataMessage();
		
		}
	}
	
	/*
	 * Intermediate nodes intercept the data packet, and fill the path 
	 */
	event bool DataIntercept.forward(message_t* msg, void* payload, uint8_t len){
		uint8_t hopCounter = call CtpPacket.getThl(msg);
		uint16_t child = call AMPacket.source(msg);
		data_msg_t* i_msg = (data_msg_t*) payload;
		
		// for the path, record the link layer sender of the packet 
		if(hopCounter > 1 && hopCounter <= MAX_PATH_LEN) {
			// the first hop sender is the source of CTP packet, no need to record it
			i_msg->path[hopCounter-2] = child;	
		}else if (hopCounter == 1){
			i_msg->path[hopCounter-1] = 0;	
		}
			
		return TRUE;
	}
	
	/*
	 * Sink receive data packet, do nothing, or record the path
	 */
	event message_t* DataReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len != sizeof(data_msg_t)) {
			dbg("Root", "Root: the data msg payload length does not match\n");
		} else {
			uint16_t source;
			uint8_t hopCounter;
			uint8_t seqno;
			uint16_t child = call AMPacket.source(msg);
			data_msg_t* rcm = (data_msg_t*)payload;

			source = call CtpPacket.getOrigin(msg);
 	 		seqno = call CtpPacket.getSequenceNumber(msg);
 	 		hopCounter = call CtpPacket.getThl(msg);

			if(hopCounter > 1 && hopCounter <= MAX_PATH_LEN) {
				rcm->path[hopCounter-2] = child;	
				rcm->path[hopCounter-1] = TOS_NODE_ID;	
			}else if (hopCounter == 1){
				rcm->path[hopCounter-1] = TOS_NODE_ID;	
			}
			
			
			
			dbg("DATA", "data: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
					rounds, source, seqno, hopCounter, rcm->parent, rcm->path[1], 
					rcm->path[2], rcm->path[3], rcm->path[4], rcm->path[5], rcm->path[6],
					rcm->path[7], rcm->path[8], rcm->path[9],rcm->path[10],rcm->path[11],
					rcm->path[12], rcm->path[13], rcm->path[14], rcm->path[15], rcm->path[16],
					rcm->path[17], rcm->path[18], rcm->path[19], rcm->path[20], rcm->path[21], 
					rcm->path[22], rcm->path[23], rcm->path[24], rcm->path[25], rcm->path[26],
					rcm->path[27], rcm->path[28], rcm->path[29], rcm -> data);
			
		}    
		return msg;
	}
	
	
	event void DataSend.sendDone(message_t* msg, error_t err) {
		if (err != SUCCESS) {
	  		dbg("Mote", "Mote: sendDone FAIL\n");
	    }
		else {
			dbg("Mote", "Mote: sendDone SUCCESS\n");
		}
		radioBusy = FALSE;
	}
	
	
	event void RadioControl.stopDone(error_t err) {}
	
}			
