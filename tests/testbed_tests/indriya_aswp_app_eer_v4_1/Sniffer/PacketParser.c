/**
typedef nx_struct {
  nx_ctp_options_t    options;
  nx_uint8_t          thl;
  nx_uint16_t         etx;
  nx_am_addr_t        origin;
  nx_uint8_t          originSeqNo;
  nx_collection_id_t  type;
  
  // ctp instrumentation
  nx_uint16_t  stats_nexthop;  // Forwarder
  nx_uint16_t  stats_petx;
  nx_uint16_t  stats_letx;
  nx_uint8_t   stats_frssi;
  nx_uint8_t   stats_brssi;
  
  // health information
  nx_uint16_t generated;
  nx_uint16_t forwarded;
  nx_uint16_t retx;
  nx_uint16_t dropped;

	// R-CTP
  nx_uint8_t  psetSize; 				// Size of the parent set
  nx_uint16_t rctp_parent;			// rctp parent node
  nx_uint8_t  reTxs; 						// Number of reTxs for current packet

  
  nx_uint8_t (COUNT(0) data)[0]; // Deputy place-holder, field will probably be removed when we Deputize Ctp
} ctp_data_header_t;


typedef nx_struct r_msg{

  nx_uint8_t indicator;   	// first four bits: number of adcs, 
                          	// last four bits: correlation_sampling_ratio

  nx_uint8_t appversion;  	// Include application version and mote type

  //nx_uint32_t total_time;  // Moved to the summary packet
  nx_uint16_t dutycycle;

  // values from the flash    
  nx_uint16_t flash_node_id;
  nx_uint8_t  flash_wdt_resets;

  // sensor readings  
  nx_uint16_t voltage;
  nx_uint16_t temp;
  nx_uint16_t hum;
  nx_uint16_t adc[ADC_NUMBER];
								// if MSP2_ENABLED == 1
								// adc[0]: msp_2
  								// adc[1]: msp_2 temperature
  								// adc[3~ADC_NUMBER-1]: normal adc channels
  
} ReadingMsg;



DE Packets:

02 37 61 88 14 22 00 BB 0B DD 00 3F 71 00 00 00 0A 00 DD 09 DE 0B BB 00 0A 00 0A
0           4        7     9                                20 
00 F3 00 0A 00 00 00 00 00 00 01 0B BB 00 00 00 00 00 1A 93 1A 93 07 8B 07 8B 05

50 05 50 6A D3 01 09 16 4E EC 02 00 

EE Packets:

02 40 61 88 17 22 00 BB 0B DD 00 3F 71 00 00 00 0A 00 DD 0C EE 0B BB 00 0A 00 0A
0                                                           20                26                                       
00 F0 00 0D 00 00 00 00 00 00 01 0B BB 00 69 23 03 DB 07 D2 01 09 E1 1A 93 07 92
                                       40 41 42                48
05 3C 05 A3 05 90 05 AC 03 9A 03 22 6C D3 01 09 16 DE 3E 2C 00 


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "serialsource.h"

static char *msgs[] = {
	"unknown_packet_type",
	"ack_timeout"	,
	"sync"	,
	"too_long"	,
	"too_short"	,
	"bad_sync"	,
	"bad_packet"	,
	"closed"	,
	"no_memory"	,
	"unix_error"
};

void stderr_msg(serial_source_msg problem)
{
	fprintf(stderr, "Note: %s\n", msgs[problem]);
}

enum {
	TOS_SERIAL_802_15_4_ID = 2,
	
	MAC_SEQ = 4,
	MAC_DEST = 7, 		// MAC_DEST = msg[8] << 8 | msg[7]
	MAC_SRC = 9,		// MAC_SRC = msg[10] << 8 | msg[9]
	AM_ID = 12,
		
	
	CTP_HEADER_OFFSET = 20, // change this value if anything inside the header is changed
							// this is the position of the ctp_type field
	// EE packets
	INDICATOR = 41, 
	APP_VERSION = 42,
	VOLT = 48,
	TEMP = 50,
	HUM = 52,	
	ADC = 54,
	PAYLOAD_OFFSET = 41, 	// the start of the payload
	
	
};

// packet parsers
/***************************** Ctp routing packet ***********************************/
void CtpRoutingParser(const unsigned char* msg) {
	// ctp packet
	// 02 15 41 88 AE 22 00 FF FF 9A 02 3F 70 01 0A 00 AA AA 00 0A AA AA FA 6C DC 01 09 1A D4 0F F1 00 
	//                                     12|13|     |16 17|18 19|20 21   |23 24 25|26 27 28|
	
	// typedef nx_struct linkest_header {
 	//	  nx_uint8_t flags;
  	//	  nx_uint8_t seq;
	// } linkest_header_t;
	
	//	typedef nx_struct {
  	//		nx_ctp_options_t    options;
  	//		nx_am_addr_t        parent;
  	//		nx_uint16_t         etx;
  	//		nx_uint8_t (COUNT(0) data)[0]; // Deputy place-holder, field will probably be removed when we Deputize Ctp
	//	} ctp_routing_header_t;
	
	//	typedef nx_struct neighbor_stat_entry {
	//  	nx_am_addr_t ll_addr;
	//  	nx_uint8_t inquality;
	//	} neighbor_stat_entry_t;

	//	typedef nx_struct linkest_footer {
	//  	neighbor_stat_entry_t neighborList[1];
	//	} linkest_footer_t;

	unsigned short source, parent;
	int ne_count = msg[13];
	int etx = msg[18] << 8 | msg[19];
	int i = 0;

	source = msg[10] << 8 | msg[9];
	parent = msg[16] << 8 | msg[17];
		
	printf("Routing - src: %d, parent: %d, etx: %d\n", source, parent, etx);
	printf("\t<Neighbor, Link_Quality>: ");
	for(i = 0; i < ne_count; i++) {
		unsigned short ne = msg[20 + i*3] << 8 | msg[20 + i*3 + 1];
		unsigned short linkEtx = msg[20 + i*3 + 2];
		if(i % 3 == 0){
			printf("\n\t\t"); 
		}
		printf("%d %d \t", ne, linkEtx);
		
	}
	printf("\n");
}

/****************** Ctp Data packets ***********************/
/*
 * Data packet
 */

void DataParser(const unsigned char* msg){
	// ctp packet
	// -- 02 42 61 88 AC 22 00 AA AA 9A 02 3F 71 00 00 00 00 00 00 00 00 00 00 00 0A 02 9A 01 EE
	//                         7  8 | 9 10|   12                                  24|25 26|27|28
	// -- AA AA 00 0A 00 0A 00 0F 00 02 00 00 00 00 00 00 01 AA AA 00 35 12 03 95 2A 9F 00 01 89 
	//    29 30|                                                     |49                  |56 57
	// -- 19 28 07 47 08 7C 07 F5 08 20 6C DD 01 09 1A 36 81 88 00
	
	unsigned short source, dest, orig, parent, mac_no;
	int i = 0;
	unsigned short volt_raw;	// raw voltage of the node.
	unsigned short mote_type;	// indicator field in the data packet
	unsigned short volt;
	unsigned short ctp_no;
	int indicator;
	
	source = msg[MAC_SRC+1] << 8 | msg[MAC_SRC];
	dest = msg[MAC_DEST+1] << 8 | msg[MAC_DEST];
	mac_no = msg[MAC_SEQ];
	orig = msg[CTP_HEADER_OFFSET - 3] << 8 | msg[CTP_HEADER_OFFSET - 2];
	parent = msg[CTP_HEADER_OFFSET + 1] << 8 | msg[CTP_HEADER_OFFSET + 2];
	ctp_no = msg[CTP_HEADER_OFFSET - 1];


	volt_raw = msg[VOLT] << 8 | msg[VOLT+1];
	
//	printf("----------------msg[VOLT] is: %d\tmsg[VOLT+1] is: %d\tvolt_raw is: %d\n",msg[VOLT], msg[VOLT+1], volt_raw);
//	mote_type = msg[INDICATOR] >> 2 & 0x3;		// the middle bits of the indicator is the mote type
												// change this if anything changes
												// 0b 0000 1100
	indicator = msg[INDICATOR];							
	mote_type = (indicator & 0x0C) >> 2;
	
	
	if(mote_type == 0 || mote_type == 1) {
		// for MICAz and IRIS motes
		volt = 1223*1024 / volt_raw;
		if(mote_type == 0) {
			printf("Data - MicaZ, ");
		}else {
			printf("Data - IRIS, ");
		}
	} else { // mote_type == 2, TelosB motes
		volt = volt_raw * 5 *1000/ 4096;
		printf("Data - TelosB, ");
	}

//	printf("Data - src: %d, dest: %d, mac_no: %d, orig: %d, prnt: %d, Ctp_no: %d, volt: %d\n", 
//				source, dest, mac_no, orig, parent, ctp_no, volt);
//	printf("Data - SRC %d, DEST %d, MAC_NO %d, ORG %d, PRNT %d, CTP_NO %d, Volt %d\n", 
//				source, dest, mac_no, orig, parent, ctp_no, volt);
	printf("Src: %d, Dest: %d, Mac_no: %d, Org: %d, Prnt: %d, Ctp_no: %d, Volt: %d\n", 
				source, dest, mac_no, orig, parent, ctp_no, volt);

}

/*
 * Summary packet
 */

void SummaryParser(const unsigned char* msg){
	unsigned short source, dest, orig, parent, mac_no;
	int i = 0;
	unsigned short ctp_no;
	
	source = msg[10] << 8 | msg[9];
	dest = msg[8] << 8 | msg[7];
	mac_no = msg[4];
	orig = msg[CTP_HEADER_OFFSET - 3] << 8 | msg[CTP_HEADER_OFFSET - 2];
	parent = msg[CTP_HEADER_OFFSET + 1] << 8 | msg[CTP_HEADER_OFFSET + 2];
	ctp_no = msg[CTP_HEADER_OFFSET - 1];

	printf("Summary - Src: %d, Dest: %d, Mac_no: %d, Org: %d, Prnt: %d, Ctp_no: %d\n", 
				source, dest, mac_no, orig, parent, ctp_no);
}

/*
 * Routing Instrumentation
 */

void RoutInstruParser(const unsigned char* msg){
	unsigned short source, dest, orig, parent, mac_no;
	int i = 0;
	unsigned short ctp_no;
	
	source = msg[10] << 8 | msg[9];
	dest = msg[8] << 8 | msg[7];
	mac_no = msg[4];
	orig = msg[CTP_HEADER_OFFSET - 3] << 8 | msg[CTP_HEADER_OFFSET - 2];
	parent = msg[CTP_HEADER_OFFSET + 1] << 8 | msg[CTP_HEADER_OFFSET + 2];
	ctp_no = msg[CTP_HEADER_OFFSET - 1];

	printf("RoutInstru - Src: %d, Dest: %d, Mac_no: %d, Org: %d, Prnt: %d, Ctp_no: %d\n", 
				source, dest, mac_no, orig, parent, ctp_no);

} 

void CSParser(const unsigned char* msg){
	unsigned short source, dest, orig, parent, mac_no;
	int i = 0;
	unsigned short ctp_no;
	
	source = msg[10] << 8 | msg[9];
	dest = msg[8] << 8 | msg[7];
	mac_no = msg[4];
	orig = msg[CTP_HEADER_OFFSET - 3] << 8 | msg[CTP_HEADER_OFFSET - 2];
	parent = msg[CTP_HEADER_OFFSET + 1] << 8 | msg[CTP_HEADER_OFFSET + 2];
	ctp_no = msg[CTP_HEADER_OFFSET - 1];

	printf("CS - Src: %d, Dest: %d, Mac_no: %d, Org: %d, Prnt: %d, Ctp_no: %d\n", 
				source, dest, mac_no, orig, parent, ctp_no);
}

void CtpDataParser(const unsigned char* msg) {
	
	int data_type = msg[CTP_HEADER_OFFSET];	// with In-Network processing layer, the offer is 28
								// with out innetwork processing, the offer is 20
	switch(data_type) {
		case 0xEE:
			//TODO:
			DataParser(msg);
			break;
		case 0xCD:
			//TODO:
			SummaryParser(msg);
			break;
		case 0xDD:
			//TODO:
			RoutInstruParser(msg);
			break;
		case 0xDE:
			CSParser(msg);
		default:
			break;
	}
	
}

/********************** Mobile Command Parser *****************/
void MobileCommandParser(const unsigned char* msg) {
	// 02 2F 41 88 E9 22 00 FF FF AA 00 3F 99 03 00 01 03 27 75 27 D9 2A 31 00 
	//                                     12|   14 15|16|17 18|     | 
	// 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
	// 0D 6B CC 01 09 0D 46 86 0E 00 
	
	/*
	typedef nx_struct cmd_msg {
	nx_uint8_t randCode;
	nx_uint8_t cmd;
  	nx_uint8_t  nodeCount;	// number of target ids
	nx_uint16_t nodeList[MAX_NUM_IDS];	// target id list
	nx_uint8_t newChannel;
} cmd_msg_t;
	*/
	// change this if the packet structure is changed
	unsigned short cmd = msg[14];
	unsigned short node_count = msg[15];
	int i = 0;
	printf("MB_CMD - Cmd: ");
	switch(cmd) {
		case 0:	// ABORT
			printf("ABORT, Targets: ");
			for(i = 0; i < node_count; i++) {
				unsigned short addr = msg[16 + i*2] << 8 | msg[16 + i * 2+ 1];
				printf("%d ", addr);
			}
			break;
		case 1:	// DISS
			printf("DISS, Targets: ");
			for(i = 0; i < node_count; i++) {
				unsigned short addr = msg[16 + i*2] << 8 | msg[16 + i * 2+ 1];
				printf("%d ", addr);
			}
			break;
		case 2:	// REPORT
			printf("REPORT, ALL");
			break;
		case 3:	// REPORT SUBSET
			printf("REPORT, SUBSET: ");
			for(i = 0; i < node_count; i++) {
				unsigned short addr = msg[16 + i*2] << 8 | msg[16 + i * 2+ 1];
				printf("%d ", addr);
			}
			break;
		case 4:	// REBOOT
			printf("REBOOT, Target: ");		// for REBOOT, there should be only one target
			for(i = 0; i < node_count; i++) {
				unsigned short addr = msg[16 + i*2] << 8 | msg[16 + i * 2+ 1];
				printf("%d ", addr);
			}
			break;
	}

	printf("\n");	

}

void MobileReplyParser(const unsigned char* msg) {

//
	// typedef nx_struct node_reply_msg {
	//		nx_uint16_t cmd;			// 13
	//		nx_uint16_t nodeid;
	//		nx_uint8_t  nodeType;
	//		nx_uint8_t appVersion;
	//		nx_uint16_t voltage;
	// } node_reply_msg_t;
	
	/*
		typedef nx_struct node_reply_msg {
			nx_uint8_t cmd;
			nx_uint16_t nodeid;
			nx_uint8_t  nodeType;
			nx_uint8_t appVersion;
			nx_uint16_t voltage;
		} node_reply_msg_t;
	*/
	// IRIS_MOTE = 0xA1,
	// MICAZ_MOTE = 0xA2,
	// TELOSB_MOTE = 0xA3,
	unsigned short cmd = msg[13];
	unsigned short nodeid = msg[14] << 8 | msg[15];
	unsigned short type = msg[16];
	unsigned short app_version = msg[17];
	unsigned short volt_raw = msg[18] << 8 | msg[19];
	int volt = 0;
	
	printf("Mobile_Reply - node: %d, ", nodeid);
	switch(type) {
		case 0xA1:
			// IRIS motes
			printf("Type: IRIS, ");
			volt = 1023*1024 / volt_raw;
			break;
		case 0xA2:
			// MICAz motes
			printf("Type: MICAz, ");
			volt = 1023*1024 / volt_raw;
			break;
		case 0xA3:
			// Telosb motes
			printf("Type: TelosB, ");
			volt = volt_raw * 5 *1000 / 4096;
			break;
		default:
			break;
	}
	printf("Volt: %d, Verison: %d\n", volt, app_version);
}

/********************** Drip Parser *****************/
void DripParser(const unsigned char* msg) {
	// 02 1B 41 88 26 22 00 FF FF 75 27 3F 60 DE 00 00 00 00 03  
	//                                     12|key  | seqno     |
	// 04 79 A9 0E 3C 03 00 00 BA F0 66 B2 01 09 0D 6E E3 15 00 
	//   |uidhash    |  |           |
	/*
		typedef nx_struct dissemination_message {
			nx_uint16_t key;
			nx_uint32_t seqno;
			nx_uint8_t (COUNT(0) data)[0]; // Deputy place-holder, field will probably be removed when we Deputize Drip
		} dissemination_message_t;
		
		typedef nx_struct DelugeCmd {
		  nx_uint8_t type;
		  nx_uint32_t uidhash;  // unique id of image
		  nx_uint8_t  imgNum;   // image number
		  nx_uint32_t size;     // size of the image
		} DelugeCmd;
		
	*/
	
	unsigned short source = msg[10] << 8 | msg[9];
	unsigned int seqno = msg[15] << 24 | msg[16] << 16 | msg[17] << 8 | msg[18];
	unsigned short type = msg[19];
	char* cmd;
	unsigned int uidhash = msg[20] << 24 | msg[21] << 16 | msg[22] << 8 | msg[23];
	unsigned short imgNum = msg[24];
	//0x%04hx
	
	if(type == 4) {
		// -dr
		cmd = "DISS_and_REPROG";
	} else if(type == 1) {
		cmd = "STOP";
	} else {
		cmd = "unknown";
	}
	
	
	printf("Deluge_CMD - Src: %d, Msg_no: %d, Cmd: %s, Img_ID: 0x%08lx, Vol_no: %d\n",
		 source, seqno, cmd, uidhash, imgNum);
	
}


/********************** Deluge Parser *****************/
void DelugeADVParser(const unsigned char* msg) {
//	printf("Deluge_ADV - ");
	//02 19 41 88 F0 22 00 FF FF AA 00 3F 50 
	//									  12
	// 00 AA 02   00  79 A9 0E 3C 2F     22 8F 2F         00 00 6B CC 01 09 0D 2A AD 15 00 
	// src  | V| type| objectID  |numpgs|     |complete  |     |
	/*
		typedef nx_struct DelugeAdvMsg {
		  nx_uint16_t    sourceAddr;
		  nx_uint8_t     version;    // Deluge Version
		  nx_uint8_t     type;
		  DelugeObjDesc  objDesc;
		  nx_uint8_t     reserved;
		} DelugeAdvMsg;
		
		typedef nx_struct DelugeObjDesc {
		  nx_object_id_t objid;
		  nx_page_num_t  numPgs;         // num pages of complete image
		  nx_uint16_t    crc;            // crc for vNum and numPgs
		  nx_page_num_t  numPgsComplete; // numPgsComplete in image
		  nx_uint8_t     reserved;
		} DelugeObjDesc;
	*/
	unsigned short source = msg[10] << 8 | msg[9];
//	unsigned type		// adv type, not important
	unsigned int objid = msg[17] << 24 | msg[18] << 16 | msg[19] << 8 | msg[20];
	unsigned short numPgs = msg[21];
	unsigned short completed_pages = msg[24];
	
	printf("Deluge_ADV - Src: %d, Img_ID: 0x%08lx, Total_Pgs: %d, Completed: %d\n", 
		source, objid, numPgs, completed_pages);
}

void DelugeDATAParser(const unsigned char* msg) {
	// 02 47 41 88 F2 22 00 FF FF AA 00 3F 52 
	// 79 A9 0E 3C 00 00 79 A9 0E 3C 00 
	
	// 00 BA F0 2B 00 15 DE 2E 2E 2F 2E 2E 2F 4D 6F 74 65 73 41 70 70 43 00 78 
	// 69 61 6F 79 61 6E 67 00 00 00 00 00 00 00 00 78 69 61 6F 79 61 6E 67 2D 
	// 56 6C CB 01 09 0D C2 6B 16 00 
	
	//	typedef nx_struct DelugeDataMsg {
	//	  nx_object_id_t objid;		// 4		13
	//	  nx_page_num_t  pgNum;		// 1
	//	  nx_uint8_t     pktNum;	// 1
	//	  nx_uint8_t     data[DELUGET2_PKT_PAYLOAD_SIZE];
	//	} DelugeDataMsg;
	

	
	unsigned short source = msg[10] << 8 | msg[9];
	unsigned int objid = msg[13] << 24 | msg[14] << 16 | msg[15] << 8 | msg[16];

	unsigned short cur_page = msg[17];
	unsigned short pkt_num = msg[18];
	printf("Deluge_DATA - Src: %d, Img_ID: 0x%08lx, Cur_Pg: %d, Cur_Pkt: %d, \n", 
			source, objid, cur_page, pkt_num);
}

void DelugeREQParser(const unsigned char* msg) {
	// 02 17 61 88 28 22 00 AA 00 75 27 3F 51 
	// 00 AA 27 75 79 A9 0E 3C 00 FF FF FF 6B B1 01 09 0D C2 67 16 00 
	// dest |     |           |  |        |
	//	typedef nx_struct DelugeReqMsg {
	//	  nx_uint16_t    dest;		// 2
	//	  nx_uint16_t    sourceAddr;	//2
	//	  nx_object_id_t objid;		
	//	  nx_page_num_t  pgNum;
	//	  nx_uint8_t     requestedPkts[DELUGET2_PKT_BITVEC_SIZE];
	//	} DelugeReqMsg;

	unsigned short source = msg[10] << 8 | msg[9];
	unsigned short dest = msg[13] << 8 | msg[14];
	unsigned int objid = msg[17] << 24 | msg[18] << 16 | msg[19] << 8 | msg[20];
	unsigned short cur_page = msg[21];
	printf("Deluge_REQ - Src: %d, Dest: %d, Img_ID: 0x%08lx, Cur_pg: %d\n", 
			source, dest, objid, cur_page);
}


/******************** Main function **********************/
int main(int argc, char **argv)
{
	serial_source src;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <device> <rate>\n", argv[0]);
		fprintf(stderr, "Telosb e.g.: %s /dev/ttyUSB0 115200\n", argv[0]);
    	exit(2);
	}

	// open serial port
	src = open_serial_source(argv[1], platform_baud_rate(argv[2]), 0, stderr_msg);
	printf("buid source\n");
	if (!src) {
		fprintf(stderr, "Couldn't open serial port at %s:%s\n",
		    argv[1], argv[2]);
		exit(1);
	}
	
	printf("synchronizing done...\n");
	
	// infinite loop for each sniffered packet	  
	// ACK: seqno
	// 0x70: Routing: sender id, neighbors
	// 0x71 - 0xEE: Data: sender id, dest, orig id, parent
	// 0x71 - 0xCD: Summary: sender id, dest, origin id, parent
	// 0x71 - 0xDD: RoutInstru: sender id, dest, origin, parent
	
	for (;;)
    {
    	int len, i, plen;
    	short fcf;
    	const unsigned char *packet = read_serial_packet(src, &len);	// get the packet
    	int intraPan = 0;
    	int seqno = 0;
      
    	if (!packet)
			exit(0);
    	else if (packet[0] != TOS_SERIAL_802_15_4_ID) {
			printf("bad packet (serial type is %02x, not %02x)\n", packet[0], TOS_SERIAL_802_15_4_ID);
      	}
		
		plen = packet[1];
		fcf = packet[3] << 8 | packet[2];
		seqno = packet[4];
		
		if ((fcf & 0x7) == 0x02) {
			// ack packet
			// Print "ACK" and the seqno number that been acked
			printf("ACK - Mac_seq: %d\n", seqno);
			
		} else if ((fcf & 0x7) == 0x01) {
			// other packet
			//
			// -- 02 42 61 88 AC 22 00 AA AA 9A 02 3F 71 00 00 00 00 00 00 00 00 00 00 00 0A 02 9A 01 EE
			//                         7  8 | 9 10|   12                                  24|25 26|27|28
			// -- AA AA 00 0A 00 0A 00 0F 00 02 00 00 00 00 00 00 01 AA AA 00 35 12 03 95 2A 9F 00 01 89 
			//    29 30|
			// -- 19 28 07 47 08 7C 07 F5 08 20 6C DD 01 09 1A 36 81 88 00 
			// TODO: parse mac layer data packet (ctp routing, ctp data)
	  		int am_id = packet[12];
	  		
	  		switch(am_id) {
	  			case 0x70:
	  				// TODO: parse routing
	  				CtpRoutingParser(packet);
	  				break;
	  			case 0x71: 
	  				// TODO: parse ctp data
	  				CtpDataParser(packet);
	  				break;
	  			case 0x99:
	  				// TODO: parse MobileBase command
	  				MobileCommandParser(packet);
	  				break;
	  			case 0x98:
	  				// TODO: parse MobileDeluge reply
	  				MobileReplyParser(packet);
	  				break;
	  			case 0x60:
	  				// TODO: parse Drip
	  				DripParser(packet);
	  				break;
	  			case 0x50:
	  				// TODO: parse Deluge ADV
	  				DelugeADVParser(packet);
	  				break;
	  			case 0x52: 
	  				// TODO: parse Deluge DATA
	  				DelugeDATAParser(packet);
	  				break;
	  			case 0x51:
	  				// TODO: parse Deluge REQ
	  				DelugeREQParser(packet);
	  				break;
	  			default:
	  				// TODO: other packets, simple print it to the terminal
	  				// PrintDefault(packet);
	  				break;
	  		}
	  		
		}
		else {
			// unknown packet
	  		printf("  Frame type - other: ");
			for (i = 0; i < plen; i++) {
	  			printf("%02hhx ", packet[i]);
			}
			printf("\n");
		}		
		printf("\n");
      	free((void *)packet);
	}
}
