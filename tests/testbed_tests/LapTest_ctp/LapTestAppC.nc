#include "LapTest.h"


configuration LapTestAppC {
}
implementation {
	components LapTestC as App, MainC, LedsC;
	App.Boot		-> MainC;
	App.Leds		-> LedsC;
	
	components new TimerMilliC() as DataTimerC;
	App.DataTimer 	-> DataTimerC;
	
	components ActiveMessageC as RadioAM;
	App.RadioControl 	-> RadioAM;
	
	components CollectionC as Collector;
	App.CtpControl		-> Collector;
	App.RootControl		-> Collector;
	
	// ctp send data
	components new CollectionSenderC(CTP_DATA_MSG) as CtpDataSenderC;
	App.DataSend		-> CtpDataSenderC;
	App.DataReceive		-> Collector.Receive[CTP_DATA_MSG];
	App.DataIntercept	-> Collector.Intercept[CTP_DATA_MSG];
	App.CtpInfo 		-> Collector;
	App.CtpPacket 		-> Collector;
	
	
	// get ctp routing information
//	App.CtpRoutingInfo -> Collector;
	App.AMPacket -> RadioAM;
	
	#if defined(PRINTF_INDRIYA_ENABLED)
	components PrintfC;							// For printf client
//	components SerialPrintfC;	
	components SerialStartC;
	#endif
	
	components RandomC;
	App.Random -> RandomC;
	App.SeedInit -> RandomC.SeedInit;
	
}
