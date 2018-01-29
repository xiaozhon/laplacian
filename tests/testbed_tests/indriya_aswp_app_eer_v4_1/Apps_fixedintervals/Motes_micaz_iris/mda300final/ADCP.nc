//#include "printf.h"
module ADCP {
  provides {
    interface Init;
    //interface StdControl;
    //interface Read<uint16_t>[uint8_t port];
    interface Read<uint16_t> as ADC0;
    interface Read<uint16_t> as ADC1;
    interface Read<uint16_t> as ADC2;
    interface Read<uint16_t> as ADC3;
    interface Read<uint16_t> as ADC4;
    interface Read<uint16_t> as ADC5;
    interface Read<uint16_t> as ADC6;
    //interface SetParam[uint8_t port];
    //interface Power as EXCITATION25;
    //interface Power as EXCITATION33;
    //interface Power as EXCITATION50;
  }
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface Resource as I2CControl;
  uses interface Leds;
  //uses interface AsyncStdControl as I2CPacketControl;
  //uses interface Timer<TMilli> as PowerStabalizingTimer;
  //uses interface StdControl as SwitchControl;
  //uses interface Switch;

  //Updated Excitation code to use GIO
  //uses interface GeneralIO as FiveVolt;
  //uses interface GeneralIO as ThreeVolt;
  //uses interface GeneralIO as VoltageBuffer;
  //uses interface GeneralIO as VoltageBooster;
  //uses interface GeneralIO as Amplifiers;
  //uses interface GeneralIO as PW4;

}implementation{
  uint8_t channel, sendData;
  uint16_t reading;
  uint8_t readData[2];
  bool busy;

  void cleanup(){
    sendData = 0;
    atomic reading = 0;
    readData[0] = 0;
    readData[1] = 0;
    call I2CControl.release();
    busy = FALSE;
  }

  task void I2CSendTask(){
    switch(channel){
      case 0:
        sendData = 8;
        break;
      case 1:
        sendData = 12;
        break;
      case 2:
        sendData = 9;
        break;
      case 3:
        sendData = 13;
        break;
      case 4:
        sendData = 10;
        break;
      case 5:
        sendData = 14;
        break;
      case 6:
        sendData = 11;
        break;
      default:
        return;
        break;
    }
    sendData = (sendData << 4) & 0xf0;
    sendData = sendData | 0x0f;
    if (call I2CControl.request() != SUCCESS){
      post I2CSendTask();
    }
  }
  
  task void readingDoneTask(){
    uint16_t val;
    atomic  val = reading;
    cleanup();
    switch(channel){
      case 0:
	signal ADC0.readDone(SUCCESS, val);
	break;
      case 1:
	signal ADC1.readDone(SUCCESS, val);
	break;
      case 2:
	signal ADC2.readDone(SUCCESS, val);
	break;
      case 3:
	signal ADC3.readDone(SUCCESS, val);
	break;
      case 4:
	signal ADC4.readDone(SUCCESS, val);
	break;
      case 5:
	signal ADC5.readDone(SUCCESS, val);
	break;
      case 6:
	signal ADC6.readDone(SUCCESS, val);
	break;
      default:
	break;
    }
  }
  
  task void readFailedTask(){
    cleanup();
    switch(channel){
      case 0:
        signal ADC0.readDone(FAIL, 0xFFFF);
        break;
      case 1:
        signal ADC1.readDone(FAIL, 0xFFFF);
        break;
      case 2:
        signal ADC2.readDone(FAIL, 0xFFFF);
        break;
      case 3:
        signal ADC3.readDone(FAIL, 0xFFFF);
        break;
      case 4:
        signal ADC4.readDone(FAIL, 0xFFFF);
        break;
      case 5:
        signal ADC5.readDone(FAIL, 0xFFFF);
        break;
      case 6:
        signal ADC6.readDone(FAIL, 0xFFFF);
        break;
      default:
        break;
    }
  }

  command error_t Init.init(){
    cleanup();
    return SUCCESS;
  }
  

  command error_t ADC0.read(){
    //printf("Read ADC0 called\n");
    //printfflush();
    atomic{
      if(busy == FALSE){
        busy = TRUE;
      }else{
        return FAIL;
      }
    }
    channel = 0;
    post I2CSendTask();
    return SUCCESS;
  }

  command error_t ADC1.read(){
    //printf("Read ADC1 called\n");
    //printfflush();
    atomic{
      if(busy == FALSE){
        busy = TRUE;
      }else{
        return FAIL;
      }
    }
    //printf("ADC1 called and not busy\n");
    //printfflush();
    channel = 1;
    post I2CSendTask();
    return SUCCESS;
  }

  command error_t ADC2.read(){
    atomic{
      if(busy == FALSE){
        busy = TRUE;
      }else{
        return FAIL;
      }
    }
    channel = 2;
    post I2CSendTask();
    return SUCCESS;
  }

  command error_t ADC3.read(){
    atomic{
      if(busy == FALSE){
        busy = TRUE;
      }else{
        return FAIL;
      }
    }
    channel = 3;
    post I2CSendTask();
    return SUCCESS;
  }

  command error_t ADC4.read(){
    atomic{
      if(busy == FALSE){
        busy = TRUE;
      }else{
        return FAIL;
      }
    }
    channel = 4;
    post I2CSendTask();
    return SUCCESS;
  }

  command error_t ADC5.read(){
    atomic{
      if(busy == FALSE){
        busy = TRUE;
      }else{
        return FAIL;
      }
    }
    channel = 5;
    post I2CSendTask();
    return SUCCESS;
  }

  command error_t ADC6.read(){
    atomic{
      if(busy == FALSE){
        busy = TRUE;
      }else{
        return FAIL;
      }
    }
    channel = 6;
    post I2CSendTask();
    return SUCCESS;
  }

  event void I2CControl.granted(){
    //printf("Got the I2C Bus, attempting to write\n");
    //printfflush();
    if (call I2CPacket.write(0x03, 74, 1, (uint8_t*)(&sendData)) == FAIL){
      post I2CSendTask();
    }
  }

  async event void I2CPacket.writeDone(error_t err, uint16_t addr, uint8_t length, uint8_t* data){
    //printf("I2C Write done.  Checking errors and attempting read.\n");
    //printfflush();
    if((addr!= 74) || (err != SUCCESS)){
      //printf("had an error\n");
      //printfflush();
      //post readFailedTask();
    }else if (call I2CPacket.read(0x03, 74, 2, readData)!= SUCCESS){
      post readFailedTask();
    }
  }

  async event void I2CPacket.readDone(error_t err, uint16_t addr, uint8_t length, uint8_t *data){
    //printf("I2C Read done.  Checking errors and done.\n");
    //printfflush();
    if ((addr != 74) || (length != 2)){  
    }else{
      reading += (data[1] & 0xff) + ((data[0] << 8) & 0x0f00);
      post readingDoneTask();
    }
  }
}
