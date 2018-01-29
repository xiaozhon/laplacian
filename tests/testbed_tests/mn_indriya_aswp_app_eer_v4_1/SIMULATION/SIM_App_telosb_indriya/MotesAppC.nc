/**
 * @Author Miguel Navarro, Xiaoyang Zhong, Newlyn Erratt
 */

#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA)
#include "printf.h"
#endif

#if defined(FLASH_ACCESS)
#include "FlashConfig.h"
#endif

configuration MotesAppC {
}

implementation {

  components MotesC, MainC;
  components new TimerMilliC() as BeginningTimerC;
  components new TimerMilliC() as StableTimerC;

  components new TimerMilliC() as DataPeriodicTimer;
	components RandomC;
	MotesC.Random -> RandomC;

  components ActiveMessageC;
  components CollectionC as Collector;
  components new CollectionSenderC(0xee);
  components SensorReaderC;

	#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA)
		#if defined(PRINTF_ENABLED_REAL_EXPERIMENT)
		components PrintfC;
		#else
		components SerialPrintfC; // For cooja
		#endif 	
	components SerialStartC;
	#endif



	#if defined(LED_ENABLED)  
	components LedsC;
	MotesC.Leds -> LedsC;
	#endif

  //General wiring
  MotesC.Boot -> MainC;
  MotesC.BeginningTimer -> BeginningTimerC;
  MotesC.StableTimer -> StableTimerC;
  MotesC.DataPeriodicTimer -> DataPeriodicTimer;
  
	//Sensors
  MotesC.PowerControl -> SensorReaderC.StdControl; 
  MotesC.Sensors -> SensorReaderC;
 
  //Wire radio related
  MotesC.RadioControl -> ActiveMessageC;
  MotesC.RoutingControl -> Collector;
  MotesC.Send -> CollectionSenderC;
  MotesC.CtpInfo -> Collector;

  
  //Wireless reprogrammer
  #if defined (REPROGRAMMER)
  components ReprogrammerNodeC;
  #endif


	#if defined(SUMMARY_PACKET)
		//Summary packet rate (seconds)
		#ifndef SUMMARY_RATE
		#define SUMMARY_RATE 1024*60*30
		#endif

		components EerInstrumentationP;
		components new TimerMilliC() as SummaryTimerC;
		components new CollectionSenderC(0xCD) as SummarySenderC;
		MotesC.SummarySend -> SummarySenderC;
		MotesC.SummaryTimer -> SummaryTimerC;
		MotesC.EerInstrumentation -> EerInstrumentationP;
	#endif  


	#if defined(TRAFFIC_MONITOR)
  	#if defined(PLATFORM_IRIS)
  	  components RF230RadioC as MyTrafficMonitor;
			MotesC.TrafficMonitor -> MyTrafficMonitor;

  	#elif defined(PLATFORM_MICAZ) || defined(PLATFORM_TELOSB)
	  	components PowerCycleC as MyTrafficMonitor;
			MotesC.TrafficMonitor -> MyTrafficMonitor;
			//#warning " * TRAFFIC MONITOR NOT IMPLEMENTED FOR THE CC2420 *"

		#else
    	#error " * NO PLATFORM SUPPORT FOR PACKET TRAFFIC MONITOR *"
    
  	#endif
	#endif
	
	#if defined(FLASH_ACCESS)
	components new FlashConfigC(config_t);
	MotesC.FlashConfig -> FlashConfigC;
	#endif

	MotesC.RootControl -> Collector;


}
