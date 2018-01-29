#ifndef FLASH_TEST_H
#define FLASH_TEST_H

// configuration data stored in Flash memory
typedef nx_struct config_t {	
	nx_uint16_t	orig_id;
	nx_uint8_t 	wdt_flag;		// if this flag is set, the reboot is trigger by wdt
	nx_uint16_t wdt_resets;		// record the number of resets triggered by wdt.
	nx_uint8_t 	flash_flag;		// if the value of this field is not "123", the flash is the first time accessed.
} config_t;

#ifndef RESET_CODE
#define RESET_CODE 213
#endif

#endif
