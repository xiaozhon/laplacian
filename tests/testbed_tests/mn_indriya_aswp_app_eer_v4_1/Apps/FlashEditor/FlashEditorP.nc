
/**
 * Implementation of the FlashEditor. Initialize the flash memory, read and write data
 * 
 * @author Xiaoyang Zhong <xiaozhon@iupui.edu>
 **/

//#include "printf.h"

generic module FlashEditorP(typedef t) {
	provides interface FlashEditor<t>;

	uses {
  		interface Mount;
  		interface ConfigStorage as Config;
	}
}
implementation {
	t flashData;
	bool flashReady = FALSE;
	
	enum{
		NOT_READY = 8,
		READY = 9,
		MOUNTING = 10,
		COMMITING = 10,
		WRITING = 11,
		WRITE_COMMITING = 12,
		READING = 13,
	};
	
	uint8_t flashState = NOT_READY;
	bool isValid = FALSE;

	
	/**
	 * Step 1. Mount
	 */
	command void FlashEditor.init() {
		
		if (call Mount.mount() != SUCCESS) {
			// handle failure
		
			flashState = NOT_READY;
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - Mount failed, flashState is: NOT_READY\n");
			printfflush();		
		#endif
			signal FlashEditor.initDone(FAIL);
			
		} else {
			// goto MountDone event
			flashState = MOUNTING;
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - Mount SUCCESS, flashState is: MOUNTING\n");
			printfflush();		
		#endif
		}
		
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - end of initialization\n");
			printfflush();		
		#endif
	}
	
	event void Mount.mountDone(error_t error) {
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - MountDone triggered\n");
			printfflush();		
			#endif
		if (error == SUCCESS) {
			// check whether the volume is valid, if not, make it valid
			#if defined(PRINTF_FLASH)
			printf("	FlashEditor - MountDone success\n");
			printfflush();		
			#endif
			if (call Config.valid() == TRUE) {
			
				flashReady = TRUE;
				isValid = TRUE;
				flashState = READY;
				
			#if defined(PRINTF_FLASH)
				printf("	FlashEditor - The volume is valid, flashState is: READY\n");
				printfflush();		
			#endif
				signal FlashEditor.initDone(SUCCESS);			
				
				
			} else {
				// the volume is invalid, make it valid
			#if defined(PRINTF_FLASH)
				printf("	FlashEditor - The volume is invalid, make it valid\n");
				printfflush();		
			#endif
				if(call Config.commit() == SUCCESS) {
					// commit success
				
//					flashReady = TRUE;
					isValid = FALSE;
					flashState = COMMITING;
					
				#if defined(PRINTF_FLASH)
					printf("	FlashEditor - make the volume valid, commit success, flashState is: COMMITING\n");
					printfflush();		
				#endif
					
				} else {
				
				
					flashState = NOT_READY;
				#if defined(PRINTF_FLASH)
					printf("	FlashEditor - make the volume valid, commit failed, flashState is: NOT_READY\n");
					printfflush();		
				#endif
					signal FlashEditor.initDone(FAIL);
				}
			}
			
		} else {
			// handle failure
			#if defined(PRINTF_FLASH)
				printf("	FlashEditor - MountDone failed, flashState is: NOT_READY\n");
				printfflush();		
			#endif
			flashState = NOT_READY;
			signal FlashEditor.initDone(FAIL);

		}
	}
	
	command void FlashEditor.read() {
		if(!flashReady) {
			call FlashEditor.init();
		} else {
			// read data
			if(call Config.read(0, &flashData, sizeof(t)) != SUCCESS) {
				// read data failed
			#if defined(PRINTF_FLASH)
				printf("	FlashEditor - read: read data failed\n");
				printfflush();		
			#endif
				signal FlashEditor.readDone(FAIL, &flashData, sizeof(t));
			} else {
				flashState = READING;
			#if defined(PRINTF_FLASH)
				printf("	FlashEditor - read: read data SUCCESS, flashState is: READING\n");
				printfflush();		
			#endif
				// goto Config.readDone();
			}
		}
	}
	
	event void Config.readDone(storage_addr_t addr, void* buf, 
    		storage_len_t len, error_t err) __attribute__((noinline)) {
		if(err == SUCCESS){
			memcpy(&flashData, buf, len);
			#if defined(PRINTF_FLASH)
				printf("	FlashEditor - readDone: read data success\n");
				printfflush();		
			#endif
			signal FlashEditor.readDone(SUCCESS, &flashData, len);
		} else {
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - readDone: read data failed\n");
			printfflush();		
		#endif
			signal FlashEditor.readDone(FAIL, &flashData, len);
		}
		flashState = READY;		// after readDone, the flash returns to READY state
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - readDone: after readDone, flashState is READY\n");
			printfflush();		
		#endif
		
    }
	
	
	command void FlashEditor.write(const t* val) {
		memcpy(&flashData, val, sizeof(t));
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - write: write data to flash, flashState is WRITTING\n");
			printfflush();		
		#endif
		flashState = WRITING;
		call Config.write(0, &flashData, sizeof(t));
	}
	
	
	event void Config.writeDone(storage_addr_t addr, void *buf, 
    	storage_len_t len, error_t err)  {
		if(err == SUCCESS) {
			// write success, commit the change
			#if defined(PRINTF_FLASH)
				printf("	FlashEditor - writeDone: success, commit the change\n");
				printfflush();		
			#endif
			if(call Config.commit() != SUCCESS) {
				// handle failure
			} else {
				flashState = WRITE_COMMITING;
			#if defined(PRINTF_FLASH)
				printf("				writeDone: success, flashState is: WRITE_COMMITING\n");
				printfflush();		
			#endif
			}
			
		} else {
			// handle failure
			flashState = READY;
			#if defined(PRINTF_FLASH)
				printf("	FlashEditor - writeDone: failed, flashState is: READY\n");
				printfflush();		
			#endif
			signal FlashEditor.writeDone(FAIL, &flashData, sizeof(t));
		}
		
	}
	
	event void Config.commitDone(error_t err) {
    	if (err == SUCCESS) {
    		if(isValid == FALSE && flashState == COMMITING) {
    			// if it is invalid, this commit makes the volume valid.	
    			isValid = TRUE;
    			flashReady = TRUE;
    			flashState = READY;
    			signal FlashEditor.initDone(SUCCESS);
    		}
    		if (flashState == WRITE_COMMITING) {
    			signal FlashEditor.writeDone(SUCCESS, &flashData, sizeof(t));
    		}
    		flashState = READY;
    		
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - commitDone: success, flashState is: READY\n");
			printfflush();		
		#endif
    	} else {
    		if(isValid == FALSE) {
    			if(flashState == COMMITING) {
					// if it is invalid, this commit makes the volume valid, but failed.	
				//	isValid = TRUE;
					flashState = NOT_READY;
					signal FlashEditor.initDone(FAIL);
    			}
    		} else {
    			if (flashState == WRITE_COMMITING) {
    				signal FlashEditor.writeDone(FAIL, &flashData, sizeof(t));
    			}
    			flashState = READY;
    		}
    		
		#if defined(PRINTF_FLASH)
			printf("	FlashEditor - commitDone: failed\n");
			printfflush();		
		#endif
    	}
  	}
 /* 	
  	command t* FlashEditor.readConfig() {
		return &flashData;
	}
*/	
}

