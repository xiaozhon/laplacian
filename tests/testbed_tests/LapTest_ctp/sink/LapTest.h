#ifndef LAP_TEST_H
#define LAP_TEST_H

// message types
enum {
	CTP_DATA_MSG = 0xDD,
};

// others
enum{
	MAX_PATH_LEN = 30,
	

//	DEF_INTERVAL = 1024*60,		//default timer interval
};

// general data message of CTP
typedef nx_struct DataMsg {
  	nx_uint16_t parent;
  	nx_uint16_t data;	// data
  	nx_uint16_t path[MAX_PATH_LEN];	// MAX_PATH_LEN = 30
} data_msg_t;


#endif


