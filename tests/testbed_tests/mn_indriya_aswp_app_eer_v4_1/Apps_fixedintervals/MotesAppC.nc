/*
 * Copyright (c) 2016 Indiana University Purdue University Indianapolis
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither the name of the copyright holders nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 /*
  * Author: Miguel Navarro
  * Author: Xiaoyang Zhong
  * Author: Yimei Li
	* Author: Newlyn Erratt
  */

#if defined(PRINTF_ENABLED)  
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
  components ActiveMessageC;
  components CollectionC as Collector;
  components new CollectionSenderC(0xee);
  components SensorReaderC;

	components RandomC;
	MotesC.Random -> RandomC;

	#if defined(PRINTF_ENABLED)  
	components PrintfC;							// For printf client
	components SerialStartC;
	#endif

	#if defined(LED_ENABLED)  
  #warning " ** LEDS ENABLED IN THE APPLICATION ** "
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
  #warning " ** WIRELESS REPROGRAMMER ENABLED ** "
  components ReprogrammerNodeC;
  #endif


	#if defined(SUMMARY_PACKET)
		//Summary packet rate (seconds)
		#ifndef SUMMARY_INTERVAL
		#define SUMMARY_INTERVAL 1024*60*30				// DEFAULT: 30 minutes
  	#warning " * USING DEFAULT INTERVAL FOR SUMMARY PACKETS * "
		#endif


		components new TimerMilliC() as SummaryTimerC;
		components new CollectionSenderC(0xCD) as SummarySenderC;
		MotesC.SummarySend -> SummarySenderC;
		MotesC.SummaryTimer -> SummaryTimerC;
//		components EerInstrumentationP;		// for RCTP
//		MotesC.EerInstrumentation -> EerInstrumentationP;
		components CtpInstrumentationP;		// for CTP
		MotesC.CtpInstrumentation -> CtpInstrumentationP;
	#endif  


	#if defined(TRAFFIC_MONITOR)
  	#if defined(PLATFORM_IRIS)
  	  components RF230RadioC as MyTrafficMonitor;
			MotesC.TrafficMonitor -> MyTrafficMonitor;

  	#elif defined(PLATFORM_MICAZ) || defined(PLATFORM_TELOSB)
	  	components PowerCycleC as MyTrafficMonitor;
			MotesC.TrafficMonitor -> MyTrafficMonitor;

		#else
    	#error " * NO PLATFORM SUPPORT FOR PACKET TRAFFIC MONITOR *"
    
  	#endif
	#endif
	
	#if defined(FLASH_ACCESS)
 	#warning " * FLASH ACCESS ENABLED * "
	components new FlashConfigC(config_t);
	MotesC.FlashConfig -> FlashConfigC;
	#endif

	// *********************************************************************************************
	#if defined(IN_NET_PROCESSING)
		//Route instrumentation packet rate (seconds)
		#if !defined(IN_NET_PROCESSING_INTERVAL)
			#define IN_NET_PROCESSING_INTERVAL 1024*60*60*2 		// DEFAULT: 2 hours
  		#warning " * USING DEFAULT INTERVAL FOR IN_NET_PROCESSING * "
		#endif

		components new TimerMilliC() as InNetProcTimerC;
		components new CollectionSenderC(0xDE) as InNetProcSenderC;
		MotesC.InNetProcSend -> InNetProcSenderC;
		MotesC.InNetProcTimer -> InNetProcTimerC;

		#warning " ********************* USING IN_NET_PROCESSING ********************** "
		MotesC.Intercept -> Collector.Intercept[0xDE]; //Compressed sensing
		MotesC.CtpPacket -> Collector;
		MotesC.AMPacket -> ActiveMessageC;

	#endif  
	// *********************************************************************************************
}
