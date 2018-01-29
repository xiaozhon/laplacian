#ifndef PACKET_H
#define PACKET_H

#ifndef ADC_NUMBER
#define ADC_NUMBER 6
#endif


//This is our packet
typedef nx_struct r_msg{

  nx_uint8_t indicator;   // first four bits: number of adcs, 
                          // last four bits: correlation_sampling_ratio

  nx_uint8_t appversion;  // Include application version and mote type


  //nx_uint32_t total_time;  // Moved to the summary packet
  nx_uint16_t dutycyle;

	// values from the flash    
	nx_uint16_t flash_node_id;
	nx_uint8_t  flash_wdt_resets;

// sensor readings  
  nx_uint16_t voltage;
  nx_uint16_t temp;
  nx_uint16_t hum;
  nx_uint16_t adc[ADC_NUMBER];

	nx_uint16_t not_used[2];
 
} ReadingMsg;



#endif
