/*
 * Configurations for our gateway BaseStation app
 * Author: Newlyn Erratt, Xiaoyang Zhong, Miguel Navarro

	ONLY FOR IRIS MOTES

 */


configuration BaseStationAppC {}

implementation {
  components BaseStationC, MainC, LedsC, ActiveMessageC;
  //For CTP
  components CollectionC as Collector;
  //For UART
  components SerialActiveMessageC as Serial;
  // components new SerialAMSenderC(0xee);   

  //Buffer for received radio messages
  components new QueueC(message_t*, 35);			// MN: Initially was size 12
  components new PoolC(message_t, 35);

  //General wirings
  BaseStationC.Boot -> MainC;
  BaseStationC.Leds -> LedsC;


  //Radio wirings
  //for starting and stopping the radio
  BaseStationC.RadioControl -> ActiveMessageC;
  //CTP Wirings
  BaseStationC.CollectionControl -> Collector;
  BaseStationC.RootControl -> Collector;
  BaseStationC.CollectReceive -> Collector.Receive[0xee];				// Data packet
  BaseStationC.SummaryReceive -> Collector.Receive[0xCD];				// Summary packet
  BaseStationC.RoutInstrumReceive -> Collector.Receive[0xDD];		// Neighbor packet
  BaseStationC.InNetProcReceive -> Collector.Receive[0xDE];			// CS packet

  BaseStationC.CollectAMPacket -> ActiveMessageC;

  BaseStationC.CollectPacket -> ActiveMessageC;
  //for debugging
  BaseStationC.CollectionPacket -> Collector;  

  //Added for UART
  BaseStationC.UartSend -> Serial;
  BaseStationC.SerialControl -> Serial;
  BaseStationC.UartPacket -> Serial;
  BaseStationC.UartAMPacket -> Serial;

  //buffer
  BaseStationC.Pool -> PoolC;
  BaseStationC.Queue -> QueueC;

  //Added for LPL
  BaseStationC.LowPowerListening -> ActiveMessageC;
  
  #if defined(IN_NET_PROCESSING)
  #warning " ********************* USING IN_NET_PROCESSING ********************** "
  BaseStationC.CtpPacket -> Collector;
  #endif
}
