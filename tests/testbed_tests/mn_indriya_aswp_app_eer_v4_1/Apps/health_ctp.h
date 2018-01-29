/*
 * Copyright (c) 2016 Indiana University Purdue University Indianapolis
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither the name of the copyright holders nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 /*
  * Author: Miguel Navarro
  * Author: Xiaoyang Zhong
  * Author: Yimei Li
	* Author: Newlyn Erratt
  */

#ifndef PACKET_H
#define PACKET_H

#ifndef ADC_NUMBER
#define ADC_NUMBER 3
#warning " * USING DEFAULT ADC NUMBER (3 ADCs) * "
#endif

#ifndef MSP2_ENABLED
#define MSP2_ENABLED 0
#warning " * MSP2 DISABLED * "
#endif


//This is our packet
typedef nx_struct r_msg{

	nx_uint8_t indicator;   	// first four bits: number of adcs, 
                          		// last four bits: correlation_sampling_ratio

	nx_uint8_t appversion;  	// Include application version and mote type

//	nx_uint32_t total_time;  	// Move back to the data packet--- Moved to the summary packet
	nx_uint16_t dutycycle;

	// values from the flash    
	nx_uint16_t flash_node_id;
	nx_uint8_t  flash_wdt_resets;

	// sensor readings  
	nx_uint16_t voltage;
	nx_uint16_t temp;
	nx_uint16_t hum;
	nx_uint16_t adc[ADC_NUMBER];// if MSP2_ENABLED == 1
								// adc[0]: msp_2
  								// adc[1]: msp_2 temperature
  								// adc[3~ADC_NUMBER-1]: normal adc channels
} ReadingMsg;


#if defined(IN_NET_PROCESSING)  
enum {
	MAX_PATH_LEN = 12,
};

typedef nx_struct cs_msg{		// set TOSH_DATA_LENGTH = 61
	nx_uint8_t flag;		// if forwarded a packet in last cycle, flag is 1, else is 0

	// the path measurement							
	nx_uint32_t linkId_sum;

	nx_uint16_t temp_cs;
	nx_uint16_t temp;
	nx_uint16_t hum_cs;
	nx_uint16_t hum;  
	nx_uint16_t adc_cs;
	nx_uint16_t adc;			// 16 + 28 = 44
								// + 24 = 68

	nx_uint16_t path[MAX_PATH_LEN];		// the full path
} CsMsg;
#endif



#endif
