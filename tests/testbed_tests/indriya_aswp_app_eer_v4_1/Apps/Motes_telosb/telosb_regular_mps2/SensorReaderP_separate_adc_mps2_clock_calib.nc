/**
* This file provides an implementation for reading the sensors
* to remove the reading of values away from the main application
* Author: Newlyn Erratt, Yimei Li, Xiaoyang Zhong
*
* 1. Make the MPS2 readings of resolution 0.1.
* 2. The first two fields in ADC[] array: adc[0] and adc[1] is used to store the 
*    MPS2 readings.
*	 - uint32_t mps2_readings = mps2_wp << 21 + mps2_temp;
*	 -          adc[0] = mps2_readings >> 16;
*	 -			adc[1] = mps2_readings;		// it automatically get the lower bytes.
*
* 3. Conversion foluma for MPS2 readings
* 		MPS2 Water potential = -mps2_wp * 0.1 kPa
* 		MPS2 Temprature = (mps2_temp - 400) * 0.1 Celsius
*
* Reading ADC and reading MPS2 go parallel.
*/
//#include "printf.h"
#include <Timer.h>

module SensorReaderP{
  	provides interface SensorReader;
  	provides interface StdControl;

  	uses interface Read<uint16_t> as Voltage;
	
	uses interface Read<uint16_t> as Temperature;
  	uses interface Read<uint16_t> as Humidity;
  	uses interface HplMsp430GeneralIO as Power2_5;
  	uses interface HplMsp430GeneralIO as Power5_0;

  	uses interface Read<uint16_t> as ADC0;
  	uses interface Read<uint16_t> as ADC1;
  	uses interface Read<uint16_t> as ADC2;
  	uses interface Read<uint16_t> as ADC3;
  	//uses interface Read<uint16_t> as ADC4;
  	//uses interface Read<uint16_t> as ADC5;
  	uses interface Read<uint16_t> as ADC6;
  	uses interface Read<uint16_t> as ADC7;

  	uses interface Timer<TMilli>;

  	//  UART
  	uses interface UartStream;
 	uses interface Resource as UartResource;
 	
 	uses interface Init as MoteClockInit;
 	uses interface Timer<TMilli> as delayTimer;
}

implementation{
  	bool busy = FALSE;
  	bool adc_is_reading = FALSE;
  	bool mps2_is_reading = FALSE;
  	error_t error;
  	uint16_t volt;
  	uint16_t hum;
  	uint16_t temp;
  	uint16_t adc0, adc1, adc2, adc3, adc4, adc5, adc6, adc7, mps2_wp, mps2_temp;
	
	// to calculate the number of decimal numbers in WP readings
	uint32_t mps2_readings;
	uint8_t is_after_dot;
	uint8_t dec_num_count;

  	uint16_t uartlen;
  	uint32_t t = 0;
  	uint8_t t_sign = 1;
  	
  	// return the clock resets using adc2
  	uint8_t clock_resets = 0;
  	bool calibrated = FALSE;

  	task void readingTask(){
    	call Voltage.read();
    	//  UART
    	call UartResource.immediateRequest();
    #if defined(PRINTF_ENABLED)  
	  	printf("\n+++++++++++++ SensorReaderP: Uart request resource\n");
	  	printfflush();
	#endif
   
  	}
  	
  	task void dummyReadings(){
//    	call Power2_5.clr();
//		call Power5_0.clr();

		if (calibrated == FALSE && (mps2_wp == 0xAAAA || mps2_wp < 90)) {
			// wrong readings detected, and haven't been calibrated yet
			call MoteClockInit.init();
			
			calibrated = TRUE;
			clock_resets++;
		#if defined(PRINTF_ENABLED)  
	  		printf("\n+++++++++++++ SensorReaderP: calibration... clock_resets is: %d\n", clock_resets);
	  		printfflush();
		#endif
			atomic{
      			adc_is_reading = FALSE;
      			mps2_is_reading = FALSE;
      			mps2_wp = 0xAAAA;
				mps2_temp = 0xBBBB;
      			t = 0;
      			t_sign = 1;
      			
      			// initialization of the variables for decimal counting
      			mps2_readings = 0xAAAABBBB;
      			is_after_dot = 0;
      			dec_num_count = 0;
      		}
      		// a delay to let the calibrated clock stable
      		call delayTimer.startOneShot(500);
//			post readingTask();
			
			
		} else {
		
//   		 	signal SensorReader.readingsDone(error, volt, hum, temp, mps2_wp, mps2_temp, adc0, adc1, adc2, adc3, adc6, adc7);
   		 	signal SensorReader.readingsDone(error, volt, hum, temp, mps2_wp, mps2_temp, adc0, adc1, clock_resets*10, adc3, adc6, adc7);
   			busy = FALSE;
   		#if defined(PRINTF_ENABLED)  
	  		printf("\n+++++++++++++ SensorReaderP: signal readingsDone\n");
	  		printf("\n+++++++++++++ SensorReaderP: signalled..... clock_resets is: %d\n", clock_resets);
	  		printfflush();
		#endif
		}
  	}

  	command error_t StdControl.start(){
    	return SUCCESS;
  	}
  
  	command error_t StdControl.stop(){
    	return SUCCESS;
  	}
  	
  	event void delayTimer.fired() {
  		if(calibrated == TRUE) {
  			post readingTask();
  		}
  	}
  
  	event void Timer.fired(){
  		if (adc_is_reading == TRUE) {
  			call ADC0.read();
  		} else if (mps2_is_reading == TRUE) {
  		
			call UartResource.release();
		#if defined(PRINTF_ENABLED)  
	  		printf("\n+++++++++++++ SensorReaderP: Timer fired, read ADC0\n");
	  		printfflush();
		#endif
			call Power5_0.clr();
			mps2_is_reading = FALSE;
			post dummyReadings();
		}

	}


  	command error_t SensorReader.getReadings(){
    	if(busy){
      		return FAIL;
    	}else{
      		busy = TRUE;
      		calibrated = FALSE;
      		atomic{
      			adc_is_reading = FALSE;
      			mps2_is_reading = FALSE;
      			mps2_wp = 0xAAAA;
				mps2_temp = 0xBBBB;
      			t = 0;
      			t_sign = 1;
      			
      			// initialization of the variables for decimal counting
      			mps2_readings = 0xAAAABBBB;
      			is_after_dot = 0;
      			dec_num_count = 0;
      		}
      		post readingTask();
      		return SUCCESS;
    	}
  	}


  	event void Voltage.readDone(error_t err, uint16_t reading){
    	error = err;
    	volt = reading;
    	call Humidity.read();
  	}

  	event void Humidity.readDone(error_t err, uint16_t reading){

    	error = err;
    	hum = reading;
    	call Temperature.read();
  	}

  	event void Temperature.readDone(error_t err, uint16_t reading){
      	error = err;
    	temp = reading; 
    	
    	// power on ADCs first
    	call Power2_5.set();
    	call Timer.startOneShot(50);		// power for 250 ms
    	adc_is_reading = TRUE;
    	
//    	call Power5_0.set();
//    	call Power2_5.set();
//    	call Timer.startOneShot(250);		// power for 250 ms
    	
  	}
  
  	event void UartResource.granted() {
  		// in here, do nothing.	
  	#if defined(PRINTF_ENABLED)  
	  	printf("\n+++++++++++++ SensorReaderP: Uart.resource granted\n");
	  	printfflush();
	#endif
  	}
  
  	/*
	 * <09>-34.8 22.3<0D>yN<0D><0A>
	 * "<0A>" indicates the end of the transmission
	 */
  	async event void UartStream.receivedByte(uint8_t byte){
  	#if defined(PRINTF_ENABLED)  
  		printf("\n+++++++++++++ SensorReaderP: received uart byte: %d, t is: %d\n", byte, t);
  		printfflush();
	#endif
  		if(byte == 45) {
  			// the "-", minus sign
  			atomic{
				t_sign = 2;
			}
  		}else if(byte > 47 && byte < 58) {
  			// the numbers
  			
  			if (is_after_dot == 1) {
  				// now the numbers are decimal numbers
  				atomic{
  					dec_num_count++;
  				}
  			}
  			
  			if (dec_num_count < 2) {
  					// only store the first decimal number
  					atomic{
  						t = t*10 + byte - 48;
  					}
  			}
  			
  		} else if(byte == 32) {
  			// the space, the end of the first number, the start of the next number
  			// after the "space", the wp reading ends
  			atomic{
  				is_after_dot = 0;
  				dec_num_count = 0;
  				
  				// The water potential readings are stored in the higher part of the 
  				// readings. 
  				mps2_readings = t << 11;	
// 				mps2_wp = t;
  				t_sign = 1;
  				t = 0;
  			}		
  		} else if(byte == 46) {
  			// the point: "."
  			// ignore.
  			atomic{
  				is_after_dot = 1;
  			}
  		} else if(byte == 0x79) {
  			// the "0x0A", the data ends here.
  			if(t_sign == 2){
	  			mps2_temp = 400 - t;
	  		} else {
	  			mps2_temp = 400 + t;
  			}
  			
  			// at this point mps2_wp and mps2_temp are stored as:
  			//    mps2_readings = mps2_wp << 21 + mps2_temp;
  			mps2_readings = mps2_readings + mps2_temp;
  			
  			// Now store the values back to the variables: mps2_wp and mps2_temp
  			// to be sent in the packets.
  			mps2_temp = (uint16_t)mps2_readings;		// the lower two bytes
  			mps2_wp = mps2_readings >> 16;	// the higher two bytes
  			
  			// The data ends here, send it out.
  			call UartResource.release();
  			
/* 			if(!adc_is_reading) {
  				adc_is_reading = TRUE;
  				call ADC0.read();
  			}
*/  		
			atomic{ 
				mps2_is_reading = FALSE;
			}
			
  			if (call Timer.isRunning()) {
  				call Timer.stop();	
  			}
  			call Power5_0.clr();
  			post dummyReadings();
  			
  		#if defined(PRINTF_ENABLED)  
	  		printf("\n+++++++++++++ SensorReaderP: byte stream received, release resource\n");
	  		printfflush();
		#endif
  			
  		}
  	}
  
  	event void ADC0.readDone(error_t err, uint16_t reading){
      	error = err;
    	adc0= reading;
    	call ADC1.read();
  	}
  
  	event void ADC1.readDone(error_t err, uint16_t reading){
      	error = err;
    	adc1= reading;
    	call ADC2.read();
  	}

  	event void ADC2.readDone(error_t err, uint16_t reading){
      	error = err;
    	adc2 = reading;
    	call ADC3.read();
  	}

  	event void ADC3.readDone(error_t err, uint16_t reading){
      	error = err;

    	adc3 = reading;
    	call ADC6.read();
  	}

  	event void ADC6.readDone(error_t err, uint16_t reading){
      	error = err;
    	adc6 = reading;
    	call ADC7.read();
  	}

  	event void ADC7.readDone(error_t err, uint16_t reading){
      	error = err;
    	adc7 = reading;
    	call Power2_5.clr();
    	adc_is_reading = FALSE;
    	
    	// start reading MPS2
    	call Power5_0.set();
    	call Timer.startOneShot(225);
    	mps2_is_reading = TRUE;
//    	post dummyReadings();
  	}
  	async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){}
  	async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err) {}
}
