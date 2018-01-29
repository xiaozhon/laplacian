/**
 * Test ORW application, record the routing path for further analysis
 *
 * Each node randomly send packets to the sink based on constant packet rate. Upon
 * the reception of a packet in the intermidiate node, the node piggybacks its address 
 * (node id) to the packets. 
 * 
 * @author Xiaoyang Zhong
 * @version $Revision: 0.1 $ $Date: 2017-02-06 16:16:47 $
 */
 
 #if defined(PRINTF_COOJA_ENABLED)  
#include "printf.h"
#endif

configuration OrwTestAppC {}
implementation {
	components OrwTestC as App; 
	components MainC, LedsC, ActiveMessageC;
	components new TimerMilliC();
	components OppC;
	components RandomC;
//	components ActiveMessageAddressC;

	App.Boot -> MainC;
	App.RadioControl -> OppC;
	App.Leds -> LedsC;
	App.Timer -> TimerMilliC;
	App.Send -> OppC.Send;
	App.Receive -> OppC.Receive;
	App.Packet -> OppC;	
	App.Random -> RandomC;	
//	App.ActiveMessageAddress -> ActiveMessageAddressC;
	
	App.SeedInit -> RandomC.SeedInit;
	components OppPacketP;
	App.OppPacket -> OppPacketP;
	App.AMPacket -> ActiveMessageC;
	
	App.Intercept -> OppC;
	
	#if defined(PRINTF_ENABLED)
	components PrintfC;							// For printf client
	components SerialStartC;
	#endif
	
}
