/*
 *
 * Copyright (c) 2003 The Regents of the University of California.  All 
 * rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Neither the name of the University nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * Authors:   Mohammad Rahimi mhr@cens.ucla.edu
 * History:   created @ 01/14/2003 
 * Last Modified:     @ 11/14/2003
 * 
 * driver for sensirion temperature and humidity sensor 
 *
 * $Id: TempHumM.nc,v 1.3 2004/04/08 15:22:57 jdprabhu Exp $
 */

module TempHumM {
  provides {
    //update for init or start (splitcontrol for now
    //interface SplitControl as TempHumControl;
    //update to Read interface
    interface Init;
    interface Read<uint16_t> as Temperature;
    interface Read<uint16_t> as Humidity;
  }
  uses {
    //PW0 for clock and INT3 for data
    interface GeneralIO as Clock;
    interface GeneralIO as Data;
    interface HplAtm128Interrupt as Int7;
    //enable() and disable() and event void fired()
  }
}
implementation {

  //states
  enum { IDLE, TEMP_MEASUREMENT, HUM_MEASUREMENT };

  // Feature flags: set whether to perform conversions on mote.
#define CONVERT_TEMP 0
#define CONVERT_HUM 0

  //Temprature Conversion semantics
#define FAHRENHEIT 1
#define KELVIN 0

  //flags
#define TEMP_PENDING 0x01
#define HUM_PENDING 0x02

//Interrupt definition.It is INT3 in sch which is INT7 of MCU! 
//TODO: update to use HPL128InterruptC (need Miguel's help)
//e7 is our interrupt do we want rising or falling?
//#define INT_ENABLE()  sbi(EIMSK , 7)
//#define INT_DISABLE() cbi(EIMSK , 7)

//#define delay() asm volatile  ("nop" ::)
/*
#define SET_CLOCK() sbi(PORTC, 3)
#define CLEAR_CLOCK() cbi(PORTC, 3)
#define SET_DATA() sbi(PORTD, 3)
#define CLEAR_DATA() cbi(PORTD, 3)
#define MAKE_DATA_OUTPUT() sbi(DDRD, 3)
#define MAKE_DATA_INPUT() cbi(DDRD, 3)
#define GET_DATA() (inp(PIND) >> 3) & 0x1
*/

/*
//usese PW0 (PORTC,0) for Clock and INT3 (PORTE,7) for data.
#define SET_CLOCK() sbi(PORTC, 0)
#define CLEAR_CLOCK() cbi(PORTC, 0)
#define MAKE_CLOCK_OUTPUT() sbi(DDRC, 0)    
#define SET_DATA() sbi(PORTE, 7)
#define CLEAR_DATA() cbi(PORTE, 7)
#define MAKE_DATA_OUTPUT() sbi(DDRE, 7)
#define MAKE_DATA_INPUT() cbi(DDRE, 7)
#define GET_DATA() (inp(PINE) >> 7) & 0x1
*/

void delay() {
    asm volatile  ("nop" ::);
    asm volatile  ("nop" ::);
    asm volatile  ("nop" ::);
}


//#define TEMP_COMMAND 0x1e
#define TEMP_COMMAND 0x03
#define HUM_COMMAND  0x05
#define SOFT_RESET   0x1e 
 
//#define TOS_FRAME_TYPE Sensor_frame
 char state;  //all states are changed inside tasks.
 float t=25;   //temprature value.we set temprature to 25.if sombody not reads temprature and 
               //reads humidity then by t=25 it means no temperature compensation  
 char pending_states;

static inline void clk(){
    delay();
    call Clock.clr();
    delay();
    call Clock.set();
}

static inline void  ack()
{
  call Data.makeOutput();
  call Data.clr();
  delay();
  call Clock.set();
  delay();
  call Clock.clr();
  call Data.makeInput();
}

static inline void initseq()
{ 
  call Data.makeOutput();
  call Data.set();
  call Clock.clr();
  delay();         
  call Clock.set();
  delay();
  call Data.clr();
  delay();
  call Clock.clr();
  delay();
  call Clock.set();
  delay(); 
  call Data.set();
  delay(); 
  call Clock.clr();
}

static inline void reset()
{
  int i;
  call Data.makeOutput();
  call Data.set();
  call Clock.clr();
  for (i=0;i<9;i++) {
    call Clock.set();
    delay();
    call Clock.clr();
  }
}

  //TODO: update to use GeneralIO
static inline char processCommand(int cmd)
{
  int i;
  int CMD=cmd;
  cmd &= 0x1f;
  call Int7.disable();
  reset();           
  initseq();        //sending the init sequence
  for(i=0;i<8;i++){
    if(cmd & 0x80) call Data.set();
    else call Data.clr();
    cmd = cmd << 1 ;
    call Clock.set();
    delay();              
    delay();              
    call Clock.clr();        
    
  }
  call Data.makeInput();
  delay();
  call Clock.set();
  delay();
  //TODO:how to I use this properly?
  if(call Data.get()) 
    { 
      reset(); 
      return 0; 
    }
  delay();
  call Clock.clr();
  if( CMD==TEMP_COMMAND || CMD==HUM_COMMAND){
    call Int7.enable();
  }
 return 1;
}

  task void startSensor(){
    atomic { state=IDLE;  pending_states=0x0;}
    call Int7.disable();
    call Clock.makeOutput();
    reset();
    processCommand(SOFT_RESET);
    //signal TempHumControl.startDone(SUCCESS);
  }

  //TODO: update to be done in hardware init
command error_t Init.init() {
  post startSensor();
  return SUCCESS;
}

  /*
//doesn't currently stop
command error_t TempHumControl.stop() {
  return FAIL;
  }*/

/*
default event result_t TempSensor.dataReady(uint16_t tempData) 
{
    return SUCCESS;
}

default event result_t HumSensor.dataReady(uint16_t humData) 
{
    return SUCCESS;
}
*/

// Start gathering temperature reading.
task void initiateTemperature() {
  if(state != IDLE) {
    pending_states |= TEMP_PENDING; 
    return;
  };
  state=TEMP_MEASUREMENT;
  processCommand(TEMP_COMMAND);
  return;
}

// Start gathering a humidity reading.
task void initiateHumidity() {
  if (state!= IDLE) {
    pending_states |= HUM_PENDING;
    return;
  };
  state = HUM_MEASUREMENT;
  processCommand(HUM_COMMAND);
  return;
}

  //TODO: update to use GeneralIO
task void readSensor()
{
  char i;
  char CRC=0;
  uint16_t data;
  uint16_t temp,hum;
#if CONVERT_HUM
  float h;   //humidity value.
#endif
  data=0; 
  for(i=0;i<8;i++){
    call Clock.set();   
    delay();
    data |= call Data.get();
    data = data << 1;
    //    if(i!=7) data = data << 1;
    call Clock.clr();
 }
  ack();
  for(i=0;i<8;i++){
    call Clock.set(); 
    delay();
    data |= call Data.get();
    //    data = data << 1;
    if(i!=7) data = data << 1;  //the last byte of data should not be shifted
    call Clock.clr();
    
 }
  ack();
  for(i=0;i<8;i++){           //I am not cheching the checksum
    call Clock.set();   
    delay(); 
    CRC |= call Data.get();
    if(i!=7)CRC = CRC << 1;
    call Clock.clr();
 }
  //ack with high as it should be for the CRC ack
  call Data.makeOutput();
  call Data.set();          
  delay();
  call Clock.set();
  delay();
  call Clock.clr();

  if(state==TEMP_MEASUREMENT){
      temp=data;
#if CONVERT_TEMP
      t= (((float)(temp) )*0.98-3840)/100;
      if(t > 100 ) temp=100;      //for centigrade    
      if(t < -15 ) temp=-15;      //for centigrade    

      //we convert to Fahrenheit or Kelvin to avoid negative values in transmition
#if !FAHRENHEIT
      // Convert to Kelvin * 100 by adding the offset plus a small
      // increment that will give rounded results instead of truncated
      // results.
      temp = (uint16_t)( ( ((float)(data))*0.98-3840) + 27315 + 0.5);
#else
      // Fahrenheit
      temp = (uint16_t) (t * 180 + 3200);
#endif
#endif
      signal Temperature.readDone(SUCCESS, temp);      
      if(pending_states & HUM_PENDING) { pending_states=0; post initiateHumidity();}
  }
  else if(state==HUM_MEASUREMENT) {
    hum=data;
#if CONVERT_HUM
    h= 0.0405 * (float) (hum) - 4 - (float)(hum) * (float)(hum)*0.0000028;
    h= (t-25) * (0.01 + 0.00128 * hum) + h;
    hum= (uint16_t) h;
    if(hum > 100 ) hum=100;
    if(hum < 0 ) hum=0;
#endif
    signal Humidity.readDone(SUCCESS, hum);
    if(pending_states & TEMP_PENDING) {pending_states=0;  post initiateTemperature();}
  }
  state=IDLE;
}

  //TODO: UPDATE to event fired
async event void Int7.fired(){
    call Int7.disable();
    post readSensor();
    return;
 }

  //TODO: Update to Read interface
command error_t Temperature.read(){
  if(!post initiateTemperature()) return FAIL;
  return SUCCESS;
}

command error_t Humidity.read(){
  if(!post initiateHumidity()) return FAIL;
  return SUCCESS;
}
}
