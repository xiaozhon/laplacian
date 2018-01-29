
#include "FlashConfig.h"

#if defined(PRINTF_FLASH)
#include "printf.h"
#endif

#if defined(PLATFORM_IRIS) || defined(PLATFORM_MICAZ)
#include <avr/wdt.h>
#endif

generic module FlashConfigP(typedef t) {
	provides interface FlashConfig<t>;
  	uses {
    	interface Boot;
    	interface FlashEditor<config_t>;
	}
}

implementation {

	config_t config_data;
	
	event void Boot.booted() {
	#if defined(PRINTF_FLASH)
		printf("Start to initialize the flash!\n");
		printfflush();		
	#endif
		config_data.orig_id = TOS_NODE_ID;
		config_data.wdt_flag = 0;
		config_data.wdt_resets = 0;
		config_data.flash_flag = 123;
		
		call FlashEditor.init();
	}
	
	event void FlashEditor.initDone(error_t err){
		#if defined(PRINTF_FLASH)
			printf("initDone event triggered!\n");
			printfflush();		
		#endif
		if(err != SUCCESS) {	
		#if defined(PRINTF_FLASH)
			printf("Initialization failed! Try again\n");
			printfflush();		
		#endif
			call FlashEditor.init();
		} else {
		#if defined(PRINTF_FLASH)
			printf("Initialization SUCCESS! Start to read Flash\n");
			printfflush();		
		#endif
			call FlashEditor.read();
		}
	}
	
	event void FlashEditor.readDone(error_t err, void* data, uint8_t len) {
		if(err != SUCCESS || len != sizeof(config_t)) {
			// handle failure
		#if defined(PRINTF_FLASH)
			printf("read flash falied! Read again\n");
			printfflush();		
		#endif
			call FlashEditor.read();
		} else {
			config_t* conf = (config_t*) data;
		
		#if defined(PRINTF_FLASH)
			printf("Read flash success, get the data in flash: \n");
			printfflush();		
		#endif
		#if defined(PRINTF_FLASH)
			printf("		conf -> orig_id: %d\n", conf -> orig_id);
			printfflush();		
		#endif
		#if defined(PRINTF_FLASH)
			printf("		conf -> wdt_flag: %d\n", conf -> wdt_flag);
			printfflush();		
		#endif
		#if defined(PRINTF_FLASH)
			printf("		conf -> wdt_resets: %d\n", conf -> wdt_resets);
			printfflush();		
		#endif
		#if defined(PRINTF_FLASH)
			printf("		conf -> flash_flag: %d\n", conf -> flash_flag);
			printfflush();		
		#endif
		
			if(conf -> flash_flag != RESET_CODE) {
				// reset the content in the flash, for the first access
				// 
				conf -> orig_id = TOS_NODE_ID;
				conf -> wdt_flag = 0;
				conf -> wdt_resets = 0;
				conf -> flash_flag = RESET_CODE;
				call FlashEditor.write(conf);
				
			} else if(conf -> wdt_flag == 1) {	// the reset of wdt_resets only happens in reprogramming
				// the reboot is triggered by wdt
			//	conf -> wdt_resets++;
				conf -> wdt_flag = 0;
				call FlashEditor.write(conf);
				
			} /*else {
				// the reboot is not triggered by wdt
				conf -> wdt_resets = 0;
				conf -> wdt_flag = 0;
				call FlashEditor.write(conf);
			}
			*/
			config_data.orig_id = conf -> orig_id;
			config_data.wdt_flag = conf -> wdt_flag;
			config_data.wdt_resets = conf -> wdt_resets;
			config_data.flash_flag = conf -> flash_flag;
		
		#if defined(PRINTF_FLASH)
			printf("Data Written  to flash: \n");
			printfflush();		
		#endif
		#if defined(PRINTF_FLASH)
			printf("		conf -> orig_id: %d\n", conf -> orig_id);
			printfflush();		
		#endif
		#if defined(PRINTF_FLASH)
			printf("		conf -> wdt_flag: %d\n", conf -> wdt_flag);
			printfflush();		
		#endif
		#if defined(PRINTF_FLASH)
			printf("		conf -> wdt_resets: %d\n", conf -> wdt_resets);
			printfflush();		
		#endif
		#if defined(PRINTF_FLASH)
			printf("		conf -> flash_flag: %d\n", conf -> flash_flag);
			printfflush();		
		#endif
		
		}
	}
	
	event void FlashEditor.writeDone(error_t err, void* buf, uint8_t len){
		if(err != SUCCESS) {
			call FlashEditor.write(buf);
		} else {
			if(config_data.wdt_flag == 1) {	// enable wdt, the flag indicates a wdt should be triggered
		#if defined(PRINTF_FLASH)
			printf("Rebooting the mote....\n\n\n***********************************************\n\n");
			printfflush();		
		#endif
			#if defined(PLATFORM_IRIS) || defined(PLATFORM_MICAZ)
				wdt_enable(WDTO_30MS);
			#elif defined(PLATFORM_TELOSB)
				WDTCTL = 0;
			#endif
			}
		}
	}
	
	command const t* FlashConfig.read() {
		return (t*)&config_data;
	}
	
	command void FlashConfig.write(const t* newVal) {
		// this command can be more functional, but now it only write the 
		// wdt_flag and reboot the mote after writeDone.
		config_data.wdt_flag = 1;
			
		#if defined(PRINTF_FLASH)
			printf("Write new wdt_flag: %d, to flash\n", config_data.wdt_flag);
			printfflush();		
		#endif
		
		// increase the wdt_resets
		config_data.wdt_resets++;
		call FlashEditor.write(&config_data);
	}
	

}


