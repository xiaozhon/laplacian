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

#include <Timer.h>
#include "health_ctp.h"


#if defined(FLASH_ACCESS)
	#include "FlashConfig.h"
#else
	#if defined(PLATFORM_IRIS) || defined(PLATFORM_MICAZ)
	#include <avr/wdt.h>
	#endif
#endif


#if defined(PRINTF_ENABLED)  
#include "printf.h"
#endif

module MotesC {
	uses interface Boot;
	uses interface SplitControl as RadioControl;
	uses interface StdControl as RoutingControl;
	uses interface Send;
	uses interface Timer<TMilli> as BeginningTimer;
	uses interface Timer<TMilli> as StableTimer;
	uses interface Timer<TMilli> as DataPeriodicTimer;
	uses interface CtpInfo;
	uses interface StdControl as PowerControl;
	uses interface SensorReader as Sensors;

	uses interface Random;

	#if defined(LED_ENABLED)
	uses interface Leds;
	#endif
	
	#if defined(SUMMARY_PACKET)
	uses interface Send as SummarySend;
	uses interface Timer<TMilli> as SummaryTimer;
	uses interface EerInstrumentation;		// for RCTP
//	uses interface CtpInstrumentation;
	#endif

	#if defined(TRAFFIC_MONITOR)
	uses interface TrafficMonitor;
	#endif
	
	#if defined(FLASH_ACCESS)
	uses interface FlashConfig<config_t>;
	#endif

	#if defined(IN_NET_PROCESSING)
	uses interface Send as InNetProcSend;
	uses interface Timer<TMilli> as InNetProcTimer;

	uses interface Intercept;//Compressed sensing
	uses interface CtpPacket;
	uses interface AMPacket;
	#endif
}

implementation {
	message_t packet;

	bool ignoreBusyFlags = FALSE;
	bool dataSendBusy = FALSE;
	
	#if defined(FLASH_ACCESS)
	config_t* config_data;
	#endif

	#if defined(SUMMARY_PACKET)
	message_t summary_packet;
	bool summarySendBusy = FALSE;
	#endif

	#if defined(IN_NET_PROCESSING)
	message_t inNetProc_packet;
	bool inNetProcSendBusy = FALSE;

	uint16_t temp_cs;
	uint16_t hum_cs;
	uint16_t adc2_cs;
	
	uint8_t cs_flag = 0;
	#endif

	// for watchdog
  uint8_t wdtCounter = 0;

	uint16_t voltage;
	uint16_t temperature;
	uint16_t humidity;
	uint16_t adc[8];   // use an array to store adc readings

	// temp variable for loop
	uint16_t i;

	// counts the number of sampling rounds (with initial sampling rate)
	uint16_t sample_counter;

	enum {
		MICAZ_MOTE 	= 0,
		IRIS_MOTE 	= 1,
		TELOSB_MOTE = 2,
	};

	event void Boot.booted() {
		// Initialize sample counter		
		sample_counter = 0;
		
		call RadioControl.start();
		
		#if defined(PRINTF_ENABLED)  
		printf("** Mote booted! **\n\n");
		printfflush();
		#endif
	}
	
  // Start the sampling timer once the radio is started
	event void RadioControl.startDone(error_t err) {
		if (err != SUCCESS)
			call RadioControl.start();
		else {

			// Start routing protocol
			call RoutingControl.start();
			
			// Data packet timer
			call BeginningTimer.startPeriodic((uint32_t)BEGINNING_INTERVAL);
				

			// Summary packet timer
			#if defined(SUMMARY_PACKET)
			call SummaryTimer.startPeriodic((uint32_t)SUMMARY_INTERVAL);
			#endif	


			// CS packet
			#if defined(IN_NET_PROCESSING)
			call InNetProcTimer.startPeriodic((uint32_t)IN_NET_PROCESSING_INTERVAL);
			#endif	

			#if defined(PRINTF_ENABLED)  
	  	printf("APP: timers started\n");
	  	printfflush();
			#endif
		}
	}

	event void RadioControl.stopDone(error_t err) {}


	//task to send our data
	task void sendMessage() {
		ReadingMsg* msg = (ReadingMsg*)call Send.getPayload(&packet, sizeof(ReadingMsg));
		uint32_t currentTime_temp, activeTime_temp;
		uint64_t dutycycle_temp;
		
		#if defined(PRINTF_ENABLED)  
		printf("\nAPP: sendMessage\n");
		printfflush();
		#endif

		// indicator
		// first four bits: number of adcs
		// 4-5 bits: IRIS/MICAZ/TELOSB mote indicator
		// last 2 bits: collection_sampling ratio				(not used)

		#if defined(PLATFORM_IRIS)
	 		msg->indicator = (ADC_NUMBER << 4) + (IRIS_MOTE << 2) + 1;
	 	#elif defined(PLATFORM_MICAZ)
	 		msg->indicator = (ADC_NUMBER << 4) + (MICAZ_MOTE << 2) + 1;
		#elif defined(PLATFORM_TELOSB)
			msg->indicator = (ADC_NUMBER << 4) + (TELOSB_MOTE << 2) + (MSP2_ENABLED << 1) + 1;
		#endif

		// Include the application version	
		msg->appversion = APP_VERSION;  

		
		#if defined(TRAFFIC_MONITOR)
			#if defined(PLATFORM_IRIS)
				currentTime_temp = call TrafficMonitor.getCurrentTime();
				activeTime_temp  = call TrafficMonitor.getActiveTime();
			#else
				//msg->total_time = call TrafficMonitor.getCurrentTime();
				//msg->dutycycle = call TrafficMonitor.getActiveTime() * 10000 / call TrafficMonitor.getCurrentTime();
				call TrafficMonitor.getCurrentTime_ActiveTime(&currentTime_temp, &activeTime_temp);
			#endif
			
			dutycycle_temp = ((uint64_t)activeTime_temp) * 10000;
			#if defined(PLATFORM_MICAZ)
			// Using 1.0 consumes less memory in MICAZ motes, but doesn't compile in TELOSB motes
			msg->dutycycle = (dutycycle_temp / currentTime_temp);	
			#else
			msg->dutycycle = (dutycycle_temp / currentTime_temp);
			#endif

		#else
		//msg->total_time = 0xFFFFFFFF;
		msg->dutycycle = 0xFFFF;
		#endif
		
		
		
		#if defined(FLASH_ACCESS)
		config_data = (config_t*)call FlashConfig.read();
		msg -> flash_node_id = config_data -> orig_id;
		msg -> flash_wdt_resets = config_data -> wdt_resets;
		#else
		// put default values into the fields
		msg -> flash_node_id 		= 0xFFFF;
		msg -> flash_wdt_resets = 0xFF;
		#endif
		

		// Sensor Readings
		msg->voltage = voltage;
		msg->temp = temperature;
		msg->hum = humidity;
      
		for (i = 0; i < ADC_NUMBER; i++){
			msg->adc[i] = adc[i];
		}

		/*
		#if defined(IN_NET_PROCESSING)
		msg->linkId_sum = 0;
		#endif		
		*/

		if (call Send.send(&packet, sizeof(ReadingMsg)) == SUCCESS){
			#if defined(PRINTF_ENABLED)  
			printf("APP: send (S)\n");
			printfflush();
			#endif

			#if defined(LED_ENABLED)
			call Leds.led0On();	// if send successful, red led ON (off after sendDone)
			#endif

		}
		else{
			dataSendBusy = FALSE;
			#if defined(PRINTF_ENABLED)  
			printf("APP: send (F)\n");
			printfflush();
			#endif			
			}
	}


	event void BeginningTimer.fired() {
		wdtCounter++;  

		#if defined(LED_ENABLED)
			call Leds.led1Toggle();	// timer fired, green led blink
		#endif

		#if defined(PRINTF_ENABLED)  
	  printf("\nAPP: BeginPktTimer: fired\n");
  	printfflush();
			#if defined(TRAFFIC_MONITOR) 
			//printf("\nAPP: getStartCount: %lu \n", call TrafficMonitor.getStartCount());
			//printfflush();
			//printf("APP: getCurrentTime: %lu \n", call TrafficMonitor.getCurrentTime());
			//printfflush();
			//printf("APP: getActiveTime: %lu \n", call TrafficMonitor.getActiveTime());
			//printfflush();
			//printf("APP: getTxMessages: %lu \n", call TrafficMonitor.getTxMessages());
			//printfflush();
			//printf("APP: getRxMessages: %lu \n", call TrafficMonitor.getRxMessages());
			//printfflush();
			//printf("APP: getTxBytes: %lu \n", call TrafficMonitor.getTxBytes());
			//printfflush();
			//printf("APP: getRxBytes: %lu \n", call TrafficMonitor.getRxBytes());
			//printfflush();
			//printf("APP: getTxErrors: %lu \n", call TrafficMonitor.getTxErrors());
			//printfflush();			
			#endif
		#endif

		if (!dataSendBusy || ignoreBusyFlags){
			dataSendBusy = TRUE;
			#if defined(LED_ENABLED)
			call Leds.led2Toggle();	// start reading, yellow led blink
			#endif
			#if defined(PRINTF_ENABLED)  
			printf("APP: BeginPktTimer: call getReadings\n");
			printfflush();
			#endif
			call Sensors.getReadings();
		}

		sample_counter++;
		if (sample_counter >= BEGIN_ROUNDS) {	// start stable timer, stop beginning timer
			call StableTimer.startPeriodic((uint32_t)STABLE_INTERVAL);
			call BeginningTimer.stop();
		}
	}


	event void DataPeriodicTimer.fired() {
		// Add the random delay to the sampling rate of the data packets. Not used for other packets to avoid additional timers
		call StableTimer.startOneShot( call Random.rand32() % ( ((uint32_t)STABLE_INTERVAL) - ((uint32_t)STABLE_INTERVAL >> 2) ) );
		#if defined(PRINTF_ENABLED)  
		printf("APP: DataPeriodicTimer: fired and set the StableTimer\n");
		printfflush();
		#endif
	}


	event void StableTimer.fired() {
		wdtCounter++;

		#if defined(PRINTF_ENABLED)  
  	printf("\nAPP: StablePktTimer: fired\n");
  	printfflush();
			#if defined(TRAFFIC_MONITOR) && defined(PLATFORM_IRIS)			
			//printf("\nAPP: getStartCount: %lu \n", call TrafficMonitor.getStartCount());
			//printfflush();
			//printf("APP: getCurrentTime: %lu \n", call TrafficMonitor.getCurrentTime());
			//printfflush();
			//printf("APP: getActiveTime: %lu \n", call TrafficMonitor.getActiveTime());
			//printfflush();
			//printf("APP: getTxMessages: %lu \n", call TrafficMonitor.getTxMessages());
			//printfflush();
			//printf("APP: getRxMessages: %lu \n", call TrafficMonitor.getRxMessages());
			//printfflush();
			//printf("APP: getTxBytes: %lu \n", call TrafficMonitor.getTxBytes());
			//printfflush();
			//printf("APP: getRxBytes: %lu \n", call TrafficMonitor.getRxBytes());
			//printfflush();
			//printf("APP: getTxErrors: %lu \n", call TrafficMonitor.getTxErrors());
			//printfflush();	
			#endif
		printf("APP: wdtCounter=%u \n",wdtCounter);
		printfflush();
		#endif

		// enable the watchdog if there are problems in the node		
		if( wdtCounter > WDT_THRESHOLD){
			#if defined(PRINTF_ENABLED)  
			printf("\nAPP: WATCHDOG TRIGGERED!!!\n");
			printfflush();
			#endif
			
			#if defined(FLASH_ACCESS)
			call FlashConfig.write(config_data);
			#else
			// trigger the wdt directly
				#if defined(PLATFORM_IRIS) || defined(PLATFORM_MICAZ)
				wdt_enable(WDTO_30MS);
				#elif defined(PLATFORM_TELOSB)
				WDTCTL = 0;
				#endif	
			#endif	
		}

		#if defined(LED_ENABLED)
		call Leds.led1Toggle();						// timer fired, green led blink
		#endif

		if (!dataSendBusy || ignoreBusyFlags){
			dataSendBusy = TRUE;
			#if defined(LED_ENABLED)
			call Leds.led2Toggle();					// start reading, yellow led blink
			#endif
			#if defined(PRINTF_ENABLED)  
	  	printf("APP: StablePktTimer: call gerReadings\n");
			printfflush();
			#endif
			call Sensors.getReadings();
		}
		else{																// else: skip this reading
			#if defined(PRINTF_ENABLED)  
	  	printf("APP: StablePktTimer: BUSY\n");
	  	printfflush();
			#endif
		}
	}

  //triggering a send after readings are received.  
	event void Sensors.readingsDone(error_t err, uint16_t volt, uint16_t hum, 
					uint16_t temp, uint16_t r_adc0, uint16_t r_adc1, uint16_t r_adc2, 
					uint16_t r_adc3, uint16_t r_adc4, uint16_t r_adc5, uint16_t r_adc6, 
					uint16_t r_adc7){
		#if defined(PRINTF_ENABLED)  
		printf("APP: readings done\n");
		printfflush();
		#endif

		if (err == SUCCESS){
			voltage = volt;
			humidity = hum;
			temperature = temp;
			adc[0] = r_adc0;
			adc[1] = r_adc1;
			adc[2] = r_adc2;
			adc[3] = r_adc3;
			adc[4] = r_adc4;
			adc[5] = r_adc5;
			adc[6] = r_adc6;
			adc[7] = r_adc7;    			
			#if defined(PRINTF_ENABLED)  
				printf("   AppTask posted\n");
				printfflush();
			#endif
			post sendMessage();
		} 
		else {
			voltage = 0xFFFF;
			humidity = 0xFFFF;
			temperature = 0xFFFF;
			adc[0] = 0xFFFF;
			adc[1] = 0xFFFF;
			adc[2] = 0xFFFF;
			adc[3] = 0xFFFF;
			adc[4] = 0xFFFF;
			adc[5] = 0xFFFF;
			adc[6] = 0xFFFF; 
			adc[7] = 0xFFFF; 
			#if defined(PRINTF_ENABLED)  
 	   	printf("   AppTask posted\n");
			printfflush();
			#endif
			post sendMessage();
		}
	}

	event void Send.sendDone(message_t* m, error_t err) {

		// Clear busy flag		
		dataSendBusy = FALSE;
		
		// Reset watchdog counter
		wdtCounter = 0;

		#if defined(PRINTF_ENABLED)  
  	printf("\nAPP: send done: ");
		#endif

		if(err == SUCCESS){
			#if defined(PRINTF_ENABLED)  
	  	printf(" (S)\n");
			#endif

			#if defined(LED_ENABLED)
			call Leds.led0Off();	// if send successful, red led OFF
			#endif
		}
		else{
			#if defined(PRINTF_ENABLED)  
	  	printf(" (F)\n");
			#endif
		}
		#if defined(PRINTF_ENABLED)  
  	printfflush();
		#endif
	}


//---------------------------------- SUMMARY PACKET  -----------------------------------//
#if defined(SUMMARY_PACKET)	

	event void SummaryTimer.fired() {
		uint8_t msgsize;
		//uint32_t currentTime_temp, activeTime_temp;
		//uint64_t dutycycle_temp;

		#if defined(PRINTF_ENABLED)  
		printf("\nAPP: Summary timer fired\n");
		printfflush();
		#endif

		if(!summarySendBusy || ignoreBusyFlags){

			// Define the node total time
			call EerInstrumentation.set_total_time( call TrafficMonitor.getCurrentTime() );

			/*
			// Define dutycycle
			#if defined(TRAFFIC_MONITOR)
				#if defined(PLATFORM_IRIS)
					currentTime_temp = call TrafficMonitor.getCurrentTime();
					activeTime_temp  = call TrafficMonitor.getActiveTime();
				#else
					call TrafficMonitor.getCurrentTime_ActiveTime(&currentTime_temp, &activeTime_temp);
				#endif
				dutycycle_temp = ((uint64_t)activeTime_temp) * 10000;
				call CtpInstrumentation.set_dutycycle( dutycycle_temp / currentTime_temp );
			#else
			//msg->total_time = 0xFFFFFFFF;
			//msg->dutycycle = 0xFFFF;
			call CtpInstrumentation.set_dutycycle( 0xFFFF );
			#endif

			// Define flash values
			#if defined(FLASH_ACCESS)
			config_data = (config_t*)call FlashConfig.read();
			call CtpInstrumentation.set_flash_node_id( config_data -> orig_id );
			call CtpInstrumentation.set_flash_wdt_resets( config_data -> wdt_resets );
			#else
			// put default values into the fields
			call CtpInstrumentation.set_flash_node_id( 0xFFFF );
			call CtpInstrumentation.set_flash_wdt_resets( 0xFF );
			#endif
			*/

			msgsize = call EerInstrumentation.summary_size();
			call EerInstrumentation.summary(call SummarySend.getPayload(&summary_packet, msgsize));
			
//			msgsize = call CtpInstrumentation.summary_size();
//			call CtpInstrumentation.summary(call SummarySend.getPayload(&summary_packet, msgsize));

			if (call SummarySend.send(&summary_packet, msgsize) != SUCCESS) {
				#if defined(PRINTF_ENABLED)  
				printf("APP: SummaryTimer: Send (F)\n");
				printfflush();
				#endif
			} 
			else {
				summarySendBusy = TRUE;
				#if defined(PRINTF_ENABLED)  
				printf("APP: SummaryTimer: Send (S)\n");
				printfflush();
				#endif
			}
		}
	}
	
	event void SummarySend.sendDone(message_t* m, error_t err) {
		summarySendBusy = FALSE;
		#if defined(PRINTF_ENABLED)  
		printf("\nAPP: Summary pktSend done\n");
		printfflush();
		#endif
	}

#endif


//---------------------- INNETWORK PROCESSING PACKET  ----------------------------//
#if defined(IN_NET_PROCESSING)

	event bool Intercept.forward(message_t* msg, void* payload, uint8_t len){
		uint32_t linkId;
		uint32_t childId;
		uint8_t hopCounter = call CtpPacket.getThl(msg);
		//ReadingMsg* imsg = (ReadingMsg*) payload;
		CsMsg* imsg = (CsMsg*) payload;
		
		// linkid = id_u * 2^16 +2 id_v- id_u
		// u is child, v is parent
    	// parent id is TOS_NODE_ID

		childId = (uint32_t)call AMPacket.source(msg);		// child id
	
		linkId = (childId << 16) + 2*TOS_NODE_ID - childId;
		imsg -> linkId_sum = imsg -> linkId_sum + linkId * hopCounter;

		//		imsg -> temp = imsg -> temp + temperature;
		//		imsg -> hum = imsg -> hum + humidity;


		imsg -> temp_cs = imsg -> temp_cs + temp_cs;
		imsg -> hum_cs = imsg -> hum_cs + hum_cs;


		if(adc2_cs != 0){
			imsg -> adc_cs = imsg -> adc_cs + adc2_cs;
		}
		
		// add path
		if(hopCounter > 2 && hopCounter <= MAX_PATH_LEN) {
			// hop 0: src, hop 1: prnt, hop 2.......
			// if use hopCounter > 1, parent is still recorded in the path. Use hopCounter > 2 instead
			imsg->path[hopCounter-3] = call AMPacket.source(msg);
		} else{
			imsg->path[hopCounter-1] = 0;	
		}
		
		// set flag
		cs_flag = 1;
				
		return TRUE;
	}

	event void InNetProcTimer.fired() {
		CsMsg* cs_msg;

		#if defined(PRINTF_ENABLED)  
		printf("\nAPP: InNetProc Timer fired\n");
		printfflush();
		#endif

		if(!inNetProcSendBusy || ignoreBusyFlags){

			cs_msg = (CsMsg*)call InNetProcSend.getPayload(&inNetProc_packet, sizeof(CsMsg));

			// this cycle send the readings of last cycle
			cs_msg->linkId_sum 	= 0;
			cs_msg->temp 			= temp_cs;
			cs_msg->temp_cs 		= temp_cs;
			cs_msg->hum 			= hum_cs;
			cs_msg->hum_cs 			= hum_cs;

			cs_msg->adc 			= adc2_cs;
			cs_msg->adc_cs 			= adc2_cs;
			
			cs_msg->flag			= cs_flag;
			// update readings of this cycle
			hum_cs = humidity;
			temp_cs = temperature;
			adc2_cs = adc[2];
			cs_flag = 0;
			
			if (call InNetProcSend.send(&inNetProc_packet, sizeof(CsMsg)) != SUCCESS) {
				#if defined(PRINTF_ENABLED)  
				printf("APP: InNetProc: Send (F)\n");
				printfflush();
				#endif
			} 
			else {
				inNetProcSendBusy = TRUE;
				#if defined(PRINTF_ENABLED)  
				printf("APP: InNetProc: Send (S)\n");
				printfflush();
				#endif
			}
		}
	}
	
	event void InNetProcSend.sendDone(message_t* m, error_t err) {
		inNetProcSendBusy = FALSE;
		#if defined(PRINTF_ENABLED)  
		printf("\nAPP: InNetProc pktSend done\n");
		printfflush();
		#endif
	}

#endif


}
