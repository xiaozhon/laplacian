 
 #include "FlashConfig.h" 
 generic configuration FlashConfigC(typedef t) {
 	provides interface FlashConfig<t>;
 }
 implementation {
 	components new FlashConfigP(t) as App;
 	components MainC;
 	components new FlashEditorC(config_t);
 	
 	App.Boot -> MainC;
 	App.FlashEditor -> FlashEditorC;

	FlashConfig = App;
 	
 }
