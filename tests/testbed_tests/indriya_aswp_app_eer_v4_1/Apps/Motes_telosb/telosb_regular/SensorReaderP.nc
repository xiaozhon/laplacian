/**
* This file provides an implementation for reading the sensors
* to remove the reading of values away from the main application
* Author: Newlyn Erratt
*/
//#include "printf.h"
#include <Timer.h>

module SensorReaderP{
  provides interface SensorReader;
  provides interface StdControl;

  uses interface Read<uint16_t> as Voltage;

  uses interface Read<uint16_t> as Temperature;
  uses interface Read<uint16_t> as Humidity;
  uses interface HplMsp430GeneralIO as Power;

  uses interface Read<uint16_t> as ADC0;
  uses interface Read<uint16_t> as ADC1;
  uses interface Read<uint16_t> as ADC2;
  uses interface Read<uint16_t> as ADC3;
  //uses interface Read<uint16_t> as ADC4;
  //uses interface Read<uint16_t> as ADC5;
  uses interface Read<uint16_t> as ADC6;
  uses interface Read<uint16_t> as ADC7;

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
    call Voltage.read();
    //call Power.set();
    //call Timer.startOneShot(50);
  }

  command error_t StdControl.start(){
    return SUCCESS;
  }
  
  command error_t StdControl.stop(){
    return SUCCESS;
  }

  event void Timer.fired(){
    //call Voltage.read();
    //call Humidity.read();
    call ADC0.read();
  }

  task void dummyReadings(){
    //call Excitation2_5.off();
    //call Excitation3_3.off();
    call Power.clr();

    signal SensorReader.readingsDone(error, volt, hum, temp, adc0, adc1, adc2, adc3, adc6, adc7, 0, 0);
//   signal SensorReader.readingsDone(SUCCESS, volt, hum, temp, 0, 0, 0, 0, 0, 0, 0, 0);
//   signal SensorReader.readingsDone(SUCCESS, volt, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
   busy = FALSE;
  }

  command error_t SensorReader.getReadings(){
    if(busy){
      return FAIL;
    }else{
      busy = TRUE;
      post readingTask();
      return SUCCESS;
    }
  }


  event void Voltage.readDone(error_t err, uint16_t reading){
    error = err;
    volt = reading;
//    post dummyReadings();
    call Humidity.read();
  }

  event void Humidity.readDone(error_t err, uint16_t reading){

    error = err;
    hum = reading;
    call Temperature.read();
  }

  event void Temperature.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    temp = reading;
//    post dummyReadings();
    call Power.set();
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
    call ADC6.read();
  }

 // event void ADC4.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
  //    error = err;
 //   }
  //  adc4 = reading;
   // call ADC5.read();
 // }

 // event void ADC5.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
  //    error = err;
 //   }
  //  adc5 = reading;
 //   call ADC6.read();
 // }
  event void ADC6.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    adc6 = reading;
 //   post dummyReadings();
    call ADC7.read();
  }

  event void ADC7.readDone(error_t err, uint16_t reading){
 //   if(err != SUCCESS){
      error = err;
 //   }
    adc7 = reading;
    post dummyReadings();
  }

}