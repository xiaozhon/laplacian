/*
 * Modified version of the BaseStation provided by 
 * TinyOS distribution. Has been modified to receive
 * CTP data.
 * Author: Newlyn Erratt, Xiaoyang Zhong, Miguel Navarro
 */

#include <Timer.h>
//#include "AvroraPrint.h"
#include "health_ctp.h"

module BaseStationC @safe() {
  uses interface Boot;
  uses interface Leds;

  //UART interfaces
  uses interface SplitControl as SerialControl;
  uses interface AMSend as UartSend[am_id_t id];
  uses interface Packet as UartPacket;
  uses interface AMPacket as UartAMPacket;

  //CTP interfaces
  uses interface SplitControl as RadioControl;
  uses interface StdControl as CollectionControl;
  uses interface RootControl;
  uses interface Receive as CollectReceive;
  uses interface Packet as CollectPacket;
  uses interface AMPacket as CollectAMPacket;

	// Summary packet  
	uses interface Receive as SummaryReceive;  
	// Neighbor instrumentation packet  
	uses interface Receive as RoutInstrumReceive;  
	// CS packet  
	uses interface Receive as InNetProcReceive;  

	//for debugging
  uses interface CollectionPacket;

  //Buffers
  uses interface Queue<message_t*>;
  uses interface Pool<message_t>;

  //interface for lowpowerlistening
  uses interface LowPowerListening;
  
  #if defined(IN_NET_PROCESSING)
	uses interface CtpPacket;
	#endif


}

implementation {

  bool uartBusy;

  //Other
  uint8_t tmpLen;
  uint8_t count = 0;

  //tasks
  task void uartSendTask();
  //  task void radioSendTask();
  message_t* ONE receive(message_t* ONE msg, void* payload, uint8_t len);

  //Led toggle for when we must drop a packet
  void dropBlink() {
    call Leds.led2Toggle();
  }

  //Led toggle for when we fail to send data
  void failBlink() {
    call Leds.led2Toggle();
  }


  //Set up our data Structures and start radio and serial communication
  event void Boot.booted() {
    //printChar('\n');
    uartBusy = FALSE;

    //call LowPowerListening.setLocalWakeupInterval(0);
    call RadioControl.start();
    call SerialControl.start();
  }
  
  //After the radio starts we need to start CTP routing
  //and set this node as root
  event void RadioControl.startDone(error_t error) {
    if (error == SUCCESS) {
      call CollectionControl.start();
      call RootControl.setRoot();
    }
  }

  event void RadioControl.stopDone(error_t err) {}
  

  
  //Receiving a CTP message
  event message_t* 
  CollectReceive.receive(message_t* msg, void* payload, uint8_t len) {
    // the print statement is used in Avrora
    //printStr("Received Packet ");
    //printInt32(call CollectionPacket.getOrigin(msg));
    call Leds.led0Toggle();	
    return receive(msg, payload, len);
  }

  // Receiving a summary packet
  event message_t* SummaryReceive.receive(message_t* msg, void* payload, uint8_t len) {
    // the print statement is used in Avrora
    //printStr("Received Packet ");
    //printInt32(call CollectionPacket.getOrigin(msg));
    call Leds.led0Toggle();
    return receive(msg, payload, len);
  }

  // Receiving a routeInstrum packet
  event message_t* RoutInstrumReceive.receive(message_t* msg, void* payload, uint8_t len) {
    // the print statement is used in Avrora
    //printStr("Received Packet ");
    //printInt32(call CollectionPacket.getOrigin(msg));
    call Leds.led0Toggle();
    return receive(msg, payload, len);
  }

  // Receiving a CS packet
  event message_t* InNetProcReceive.receive(message_t* msg, void* payload, uint8_t len) {
    // the print statement is used in Avrora
    //printStr("Received Packet ");
    //printInt32(call CollectionPacket.getOrigin(msg));
    call Leds.led0Toggle();
    #if defined(IN_NET_PROCESSING)
		{	
			uint32_t linkId;
			uint32_t childId;
			uint8_t hopCounter = call CtpPacket.getThl(msg);
			//ReadingMsg* imsg = (ReadingMsg*) payload;
			CsMsg* imsg = (CsMsg*) payload;
		
			// linkid = id_u * 2^16 +2 id_v- id_u
			// u is child, v is parent
		  	// parent id is TOS_NODE_ID

			childId = (uint32_t)call CollectAMPacket.source(msg);		// child id
	
			linkId = (childId << 16) + 2*TOS_NODE_ID - childId;
			imsg -> linkId_sum = imsg -> linkId_sum + linkId * hopCounter;
			
			if(hopCounter > 2 && hopCounter <= MAX_PATH_LEN) {
				imsg->path[hopCounter-3] = call CollectAMPacket.source(msg);
				imsg->path[hopCounter-2] = TOS_NODE_ID;	
			}else if (hopCounter == 2){
				imsg->path[hopCounter-2] = TOS_NODE_ID;	
			}
		
		}
		#endif
    return receive(msg, payload, len);
  }

  //When we actually receive we need to add it to our queue if we have room
  message_t* receive(message_t *msg, void *payload, uint8_t len) {
    message_t *ret;
    //Make sure we have space for a new message
    if((!call Pool.empty()) && (call Queue.size() < call Queue.maxSize())){
      atomic{
        //enqueue the new message
        ret = call Pool.get();
        call Queue.enqueue(msg);
      }
      if(!uartBusy){
        post uartSendTask();
      }
      return ret;
    }else{
      dropBlink();
    } 
    return msg;
  }

  

  //Once Serial is started we allow our queue to start filling
  event void SerialControl.startDone(error_t error){
    if (error == SUCCESS) {
      //call LowPowerListening.setLocalWakeupInterval(0);
    }
  }

  event void SerialControl.stopDone(error_t error){}

  //Triggers after we send a Uart message
  //TODO:This will be very similar to the Drip sendDone
  //TODO: Do not modify this
  //put msg on pool
  //if queue isn't empty post sendtask
  event void UartSend.sendDone[am_id_t id](message_t* msg, error_t error){
    if (error != SUCCESS){
      failBlink();
    }else{
      call Pool.put(msg);
      uartBusy = FALSE;
      if (!call Queue.empty()){
        post uartSendTask();
      }
    }
  }
   
  //Task that actually sends data over Uart TO the computer
  task void uartSendTask() {
    am_id_t id;
    am_addr_t addr, src;
    message_t* msg;
    uint8_t len;
    //new code
    if (call Queue.empty()){
      return;
    }else if(!uartBusy){
      msg = call Queue.head();
      len = call CollectPacket.payloadLength(msg);
      id = call CollectAMPacket.type(msg);
      src = call CollectAMPacket.source(msg);
      addr = call CollectAMPacket.destination(msg);
      call UartPacket.clear(msg);
      call UartAMPacket.setSource(msg, src);
      if (call UartSend.send[id](addr, call Queue.dequeue(), len) == SUCCESS){
        call Leds.led1Toggle();
        uartBusy = TRUE;
      }else{
        failBlink();
      }
    }
  }
}
