/**
* This file provides an implementation for reading the sensors
* to remove the reading of values away from the main application
* Author: Newlyn Erratt
*/

#include <Timer.h>

module SensorReaderP{
  provides interface SensorReader;
  provides interface StdControl;

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

  task void readingTask(){

  }

  command error_t StdControl.start(){
    return SUCCESS;
  }
  
  command error_t StdControl.stop(){
    return SUCCESS;
  }

  event void Timer.fired(){

  }

  task void dummyReadings(){
   signal SensorReader.readingsDone(SUCCESS, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
   busy = FALSE;
  }

  command error_t SensorReader.getReadings(){
    if(busy){
      return FAIL;
    }else{
      busy = TRUE;
      //post readingTask();
			post dummyReadings();
      return SUCCESS;
    }
  }

}
