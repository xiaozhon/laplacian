/**
* This file provides an implementation for reading the sensors
* to remove the reading of values away from the main application
* Author: Newlyn Erratt
*/
//#include "printf.h"
#include <Timer.h>

#ifndef ADC0_MIN
#define ADC0_MIN 40
#endif
#ifndef ADC0_MAX
#define ADC0_MAX 1000
#endif
#ifndef ADC1_MIN
#define ADC1_MIN 40
#endif
#ifndef ADC1_MAX
#define ADC1_MAX 1000
#endif

module SensorReaderP{
  provides interface SensorReader;
  provides interface StdControl;

  uses interface Read<uint16_t> as Voltage;

  uses interface Read<uint16_t> as Temperature;
  uses interface Read<uint16_t> as Humidity;

  uses interface Power as Excitation2_5;
  uses interface Power as Excitation3_3;
  uses interface Power as Excitation5_0; 

  uses interface Read<uint16_t> as ADC0;
  uses interface Read<uint16_t> as ADC1;
  uses interface Read<uint16_t> as ADC2;
  uses interface Read<uint16_t> as ADC3;
  uses interface Read<uint16_t> as ADC4;
  uses interface Read<uint16_t> as ADC5;
  uses interface Read<uint16_t> as ADC6;

  uses interface Timer<TMilli>;
}

implementation{
  bool busy = FALSE;
  error_t error;
  uint16_t volt;
  uint16_t hum;
  uint16_t temp;
  uint16_t adc0, adc1, adc2, adc3, adc4, adc5, adc6,adc7;
  unsigned char check;
  
  uint8_t re_sampled = 0;
  uint16_t re_sample_count = 0;

  task void readingTask(){
    //call Excitation2_5.on();
    //call Excitation3_3.on();
    //call Timer.startOneShot(50);
    call Voltage.read();
  }

  command error_t StdControl.start(){
    return SUCCESS;
  }
  
  command error_t StdControl.stop(){
    return SUCCESS;
  }

  event void Timer.fired(){
  	call ADC0.read();
    //call Voltage.read();
    //call Humidity.read();
  }

  /*task void dummyReadings(){
    call Excitation2_5.off();
    call Excitation3_3.off();
   	signal SensorReader.readingsDone(SUCCESS, volt, hum, temp, adc0, adc1, adc2, adc3, adc4, adc5, adc6, 0);
//   signal SensorReader.readingsDone(SUCCESS, volt, hum, temp, 0, 0, 0, 0, 0, 0, 0, 0);
//   signal SensorReader.readingsDone(SUCCESS, volt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
//   signal SensorReader.readingsDone(SUCCESS, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
   busy = FALSE;
  }
  */
  
  task void dummyReadings(){

		if (re_sampled < 1 && (adc0 < ADC0_MIN || adc0 > ADC0_MAX || adc1 < ADC1_MIN || adc1 > ADC1_MAX)) {
			// Measurement error, and has not been re sampled, sample again
			
			re_sampled++;
			re_sample_count++;
		
			call ADC0.read();
			
		} else {
			call Excitation2_5.off();
  		 	call Excitation3_3.off();
  // 			signal SensorReader.readingsDone(SUCCESS, volt, hum, temp, adc0, adc1, adc2, adc3, adc4, adc5, adc6, 0);
  			signal SensorReader.readingsDone(SUCCESS, volt, hum, temp, adc0, adc1, adc2, adc3, adc4, re_sample_count*10, adc6, 0);
   			busy = FALSE;
		}
  	}

  command error_t SensorReader.getReadings(){
    if(busy){
      return FAIL;
    }else{
      busy = TRUE;
      re_sampled = 0;
      post readingTask();
    	//post dummyReadings();
      return SUCCESS;
    }
  }


  event void Voltage.readDone(error_t err, uint16_t reading){
//    if(err != SUCCESS){
      error = err;
 //   }
    volt = reading;
//    post dummyReadings();
    call Humidity.read();
  }

  event void Humidity.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    hum = reading;
    call Temperature.read();
  }

  event void Temperature.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    temp = reading;
//    post dummyReadings();
	call Excitation2_5.on();
  call Excitation3_3.on();
	call Timer.startOneShot(50);
    //call ADC0.read();
  }

// currently we do not use ADC channels
// if we want to use these channels, we need to add 10k resistors on the board
  
  event void ADC0.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    adc0= reading;
    call ADC1.read();
  }
  
  event void ADC1.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    adc1= reading;
    call ADC2.read();
  }

  event void ADC2.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    adc2 = reading;
    call ADC3.read();
  }

  event void ADC3.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }

    adc3 = reading;
    call ADC4.read();
  }

  event void ADC4.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    adc4 = reading;
    call ADC5.read();
  }

  event void ADC5.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    adc5 = reading;
    call ADC6.read();
  }

  event void ADC6.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    adc6 = reading;
    post dummyReadings();
  }

}
