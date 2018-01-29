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

#ifndef ORW_TEST_H
#define ORW_TEST_H


#define SINK_ID 31
enum{
	MAX_PATH_LEN = 30,
	
//	OL_SINK = 1,
//	DEF_INTERVAL = 1024*60,		//default timer interval
};

// general data message of ORW
typedef nx_struct DataMsg {
  	nx_uint16_t parent;
  	nx_uint16_t data;	// data
  	nx_uint16_t path[MAX_PATH_LEN];	// MAX_PATH_LEN = 30
} data_msg_t;

#endif
