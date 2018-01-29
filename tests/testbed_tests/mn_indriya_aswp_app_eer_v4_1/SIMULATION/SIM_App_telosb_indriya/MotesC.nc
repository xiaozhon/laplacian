/**
 * @Author Miguel Navarro, Xiaoyang Zhong, Newlyn Erratt
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


#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA)
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
	uses interface Random;
	
	uses interface CtpInfo;
	uses interface StdControl as PowerControl;
	uses interface SensorReader as Sensors;

	#if defined(LED_ENABLED)
	uses interface Leds;
	#endif
	
	#if defined(SUMMARY_PACKET)
	uses interface Send as SummarySend;
	uses interface Timer<TMilli> as SummaryTimer;
	uses interface EerInstrumentation;
	#endif


	#if defined(TRAFFIC_MONITOR)
	uses interface TrafficMonitor;
	#endif
	
	#if defined(FLASH_ACCESS)
	uses interface FlashConfig<config_t>;
	#endif

  uses interface RootControl;

}

implementation {
	message_t packet;

	bool ignoreBusyFlags	= FALSE;	// Set to TRUE to ignore BUSY flags for all packet
	bool dataSendBusy 		= FALSE;
	
	#if defined(FLASH_ACCESS)
	config_t* config_data;
	#endif

	#if defined(SUMMARY_PACKET)
	message_t summary_packet;
	bool summarySendBusy;
	#endif

	#if defined(ROUTINSTRUM_PACKET)
	message_t routInstrum_packet;
	bool routInstrumSendBusy;
	#endif

	// for watchdog
  uint8_t wdtCounter = 0;

	uint16_t voltage;
	uint16_t temperature;
	uint16_t humidity;
	uint16_t adc[7];   // use an array to store adc readings

	// temp variable for loop
	uint16_t i;

	// counts the number of sampling rounds (with initial sampling rate)
	uint16_t sample_counter;

	enum {
		MICAZ_MOTE 	= 0,
		IRIS_MOTE 	= 1,
		TELOSB_MOTE = 2,
		BEGINNING_INTERVAL 		= (uint32_t)BEGINNING_RATE,
		STABLE_INTERVAL 			= (uint32_t)STABLE_RATE,
		SUMMARY_INTERVAL 			= (uint32_t)SUMMARY_RATE,
	};


	event void Boot.booted() {
		// reset sample counter		
		sample_counter = 0;

		#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA)
		printf("** Mote booted! **\n");
		printfflush();
		#endif
		
		call RadioControl.start();

	}
	
  // Start the sampling timer once the radio is started
	event void RadioControl.startDone(error_t err) {
		if (err != SUCCESS)
			call RadioControl.start();
		else {

			#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) && FALSE
				#if defined(TRAFFIC_MONITOR) && FALSE//&& defined(PLATFORM_IRIS)
				//printf("\nAPP: getStartCount: %lu \n", call TrafficMonitor.getStartCount());
				//printfflush();
				{
				uint32_t time_current, time_active;	
				call TrafficMonitor.getCurrentTime_ActiveTime(&time_current, &time_active);
				printf("APP: getCurrentTime: %lu    getActiveTime: %lu \n", time_current, time_active);
				printfflush();
				}
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

      if (TOS_NODE_ID == SINK_NODEID) {						// FOR COOJA:
				call RootControl.setRoot();			// USE NODE 1 AS ROOT. THIS NODE PRINTS THE PACKETS FROM THE FORWARDING ENGINE
      }

			// Start routing protocol
			call RoutingControl.start();

			if (TOS_NODE_ID != SINK_NODEID){
				// Data packet timer
				//call BeginningTimer.startOneShot( (BEGINNING_INTERVAL >> 2) + (call Random.rand32() % BEGINNING_INTERVAL) );
				call BeginningTimer.startPeriodic( ((uint32_t)BEGINNING_INTERVAL >> 1) + 
																					(call Random.rand32() % (uint32_t)BEGINNING_INTERVAL) );
				
				// Summary packet timer
				#if defined(SUMMARY_PACKET)
				//call SummaryTimer.startOneShot( (SUMMARY_INTERVAL >> 2) + (call Random.rand32() % SUMMARY_INTERVAL) );
				call SummaryTimer.startPeriodic( ((uint32_t)SUMMARY_INTERVAL >> 1) + 
																					(call Random.rand32() % (uint32_t)SUMMARY_INTERVAL) );
				#endif	


				#if defined(PRINTF_ENABLED)  
				printf("\nAPP: timers started\n");
				printfflush();
				#endif
			}
		}
	}

	event void RadioControl.stopDone(error_t err) {}


	//task to send our data
	task void sendMessage() {
		ReadingMsg* msg = (ReadingMsg*)call Send.getPayload(&packet, sizeof(ReadingMsg));
		uint32_t currentTime_temp, activeTime_temp;
		uint64_t dutycycle_temp;
		
		//#if defined(PRINTF_ENABLED)  || defined (PRINTF_ENABLED_COOJA)
		//printf("\nAPP: sendMessage\n");
		//printf("APP: sendMessage\n");
		//printfflush();
		//#endif

		// INDICATOR:
		// first four bits: number of adcs
		// 4-5 bits: IRIS/MICAZ/TELOSB mote indicator
		// last 2 bits: collection_sampling ratio				(not used)

		#if defined(PLATFORM_IRIS)
	 		msg->indicator = (ADC_NUMBER << 4) + (IRIS_MOTE << 2) + 1;
	 	#elif defined(PLATFORM_MICAZ)
	 		msg->indicator = (ADC_NUMBER << 4) + (MICAZ_MOTE << 2) + 1;
		#elif defined(PLATFORM_TELOSB)
			msg->indicator = (ADC_NUMBER << 4) + (TELOSB_MOTE << 2) + 1;
		#endif

		// Include the application version	
		msg->appversion = APP_VERSION;  

		#if defined(TRAFFIC_MONITOR)
		//msg->total_time = call TrafficMonitor.getCurrentTime();
		//msg->dutycyle = call TrafficMonitor.getActiveTime() * 10000 / call TrafficMonitor.getCurrentTime();
		call TrafficMonitor.getCurrentTime_ActiveTime(&currentTime_temp, &activeTime_temp);
		dutycycle_temp = ((uint64_t)activeTime_temp)*10000;
		msg->dutycyle  = dutycycle_temp / currentTime_temp;
		#else
		//msg->total_time = 0xFFFFFFFF;
		msg->dutycyle = 0xFFFF;
		#endif
		
		
		#if defined(FLASH_ACCESS)
		config_data = (config_t*)call FlashConfig.read();
		msg -> flash_node_id = config_data -> orig_id;
		msg -> flash_wdt_resets = config_data -> wdt_resets;
		#else
		// put default values into the fields
		msg -> flash_node_id = 0xFFFF;
		msg -> flash_wdt_resets = 0xFF;
		#endif


		// Sensor Readings
		msg->voltage = voltage;
		msg->temp = temperature;
		msg->hum = humidity;
      
		for (i = 0; i < ADC_NUMBER; i++){
			msg->adc[i] = adc[i];
		}

		msg->not_used[0] = 0xAAAA;
		msg->not_used[1] = 0xBBBB;

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

		#if defined(PRINTF_ENABLED)  || defined(PRINTF_ENABLED_COOJA) && FALSE
	  printf("\nAPP: BeginPktTimer: fired\n");
  	printfflush();
			#if defined(TRAFFIC_MONITOR) && FALSE//&& defined(PLATFORM_IRIS)
			//printf("\nAPP: getStartCount: %lu \n", call TrafficMonitor.getStartCount());
			//printfflush();
			{
			uint32_t time_current, time_active;	
			call TrafficMonitor.getCurrentTime_ActiveTime(&time_current, &time_active);
			printf("APP: getCurrentTime: %lu    getActiveTime: %lu \n", time_current, time_active);
			printfflush();
			}
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
			//call StableTimer.startOneShot( (STABLE_INTERVAL >> 2) + (call Random.rand32() % STABLE_INTERVAL) );
			call DataPeriodicTimer.startPeriodic((uint32_t)STABLE_INTERVAL);
			call BeginningTimer.stop();
		}
		//else{
		//	call BeginningTimer.startOneShot( (BEGINNING_INTERVAL >> 2) + (call Random.rand32() % BEGINNING_INTERVAL) );
		//}
	}

	event void DataPeriodicTimer.fired() {
		// Add the random delay to the sampling rate of the data packets. Not used for other packets 
		// to avoid additional timers
		call StableTimer.startOneShot( call Random.rand32() % ( ((uint32_t)STABLE_INTERVAL) - ((uint32_t)STABLE_INTERVAL >> 2) ) );
		/* #if defined(PRINTF_ENABLED)  
		printf("APP: DataPeriodicTimer: fired and set the StableTimer\n");
		printfflush();
		#endif */
	}


	event void StableTimer.fired() {
		wdtCounter++;

		#if defined(PRINTF_ENABLED)  
  	printf("\nAPP: StablePktTimer: fired\n");
  	printfflush();
			#if defined(TRAFFIC_MONITOR) && FALSE //&& defined(PLATFORM_IRIS)			
			//printf("\nAPP: getStartCount: %lu \n", call TrafficMonitor.getStartCount());
			//printfflush();
			{
			uint32_t time_current, time_active;	
			call TrafficMonitor.getCurrentTime_ActiveTime(&time_current, &time_active);
			printf("APP: getCurrentTime: %lu    getActiveTime: %lu \n", time_current, time_active);
			printfflush();
			}
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
			#if defined(PRINTF_ENABLED)   || defined(PRINTF_ENABLED_COOJA)
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
				WDTCTL = 0; //TODO: ENABLE!!!!!!
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
		
		//call StableTimer.startOneShot( (STABLE_INTERVAL >> 2) + (call Random.rand32() % STABLE_INTERVAL) );
	}

	//event void JitterTimer.fired() {
	//	post sendMessage();
	//}

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
			#if defined(PRINTF_ENABLED)  
				printf("   AppTask posted\n");
				printfflush();
			#endif
			post sendMessage();
			//call JitterTimer.startOneShot((uint32_t)( (call Random.rand32() % (STABLE_INTERVAL>>1)) ));
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
			#if defined(PRINTF_ENABLED)  
 	   	printf("   AppTask posted\n");
			printfflush();
			#endif
			post sendMessage();
			//call JitterTimer.startOneShot((uint32_t)( (call Random.rand32()+TOS_NODE_ID) % 1024));
			//call JitterTimer.startOneShot((uint32_t)( (call Random.rand32() % (STABLE_INTERVAL>>1)) ));
		}
	}

	event void Send.sendDone(message_t* m, error_t err) {
		dataSendBusy = FALSE;
		
		// Reset watchdog counter
		wdtCounter = 0;

		#if defined(PRINTF_ENABLED)  
  	printf("APP: send done: ");
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

		#if defined(PRINTF_ENABLED)  
		printf("APP: Summary timer fired\n");
		printfflush();
		#endif

		if(!summarySendBusy || ignoreBusyFlags){

			// Define the node total time
			//call CtpInstrumentation.set_total_time( call TrafficMonitor.getCurrentTime() );

			msgsize = call EerInstrumentation.summary_size();
			call EerInstrumentation.summary(call SummarySend.getPayload(&summary_packet, msgsize));

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
	  //call SummaryTimer.startOneShot( (SUMMARY_INTERVAL >> 2) + (call Random.rand32() % SUMMARY_INTERVAL) );
	}
	
	event void SummarySend.sendDone(message_t* m, error_t err) {
		summarySendBusy = FALSE;
		#if defined(PRINTF_ENABLED)  
		printf("APP: Summary pktSend done\n");
		printfflush();
		#endif
	}

#endif




}
