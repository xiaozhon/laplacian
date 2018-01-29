/**
 * BlinkFlash is a flash test application based on BlinkConfig, TestSerial, 
 * and Blink. It reads data from the flash and send the data to serial port.
 * 
 * When the mote run the application for the first, it stores the first data 
 * to the flash. 
 * 
 * @author Xiaoyang Zhong <xiaozhon@iupui.edu>
 **/

// since Deluge already included this header file, we don't need it here 
#include "StorageVolumes.h"

generic configuration FlashEditorC(typedef t) {
	provides interface FlashEditor<t>;
}

implementation
{
	components new FlashEditorP(t);
	FlashEditor = FlashEditorP;
	
	// change the "VOLUME_NAME".
	components new ConfigStorageC(VOLUME_CONFIGDATA);
	FlashEditorP.Config -> ConfigStorageC.ConfigStorage;
  	FlashEditorP.Mount  -> ConfigStorageC.Mount;
	
}

