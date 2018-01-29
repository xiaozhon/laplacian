//when all off call voltageBooster.set()

module ExcitationP{
  provides{
    interface Init;
    interface Power as volt25;
    interface Power as volt33;
    interface Power as volt50;
  }
  uses{
    interface GeneralIO as FiveVolt;
    interface GeneralIO as ThreeVolt;
    interface GeneralIO as VoltageBuffer;
    interface GeneralIO as VoltageBooster;
    interface GeneralIO as Amplifiers;
    interface GeneralIO as PW4;
  }
}implementation{
  uint8_t on[3];
  
  command error_t Init.init(){
    uint8_t i;
    call VoltageBuffer.makeOutput();
    //We don't use PW4 but it was in xbow code
    call PW4.makeOutput();
    call FiveVolt.makeOutput();
    call Amplifiers.makeOutput();
    call VoltageBooster.makeOutput();
    call ThreeVolt.makeOutput();
  
    call Amplifiers.clr();
    //if we keep track of state voltagebooster.set
    call VoltageBooster.set();
    call FiveVolt.clr();
    call ThreeVolt.clr();
    call VoltageBuffer.clr();
    for(i=0; i<3;i++){
      on[i]=0;
    }
    return SUCCESS;
  }

  void resetBooster(){
    uint8_t i;
    bool off=TRUE;

    for(i=0;i<3;i++){
      if(on[i]==1){
        off=FALSE;
      }
    }
    if(off==TRUE){
      call VoltageBooster.set();
    }   
  }

  command void volt25.on(){
    atomic on[0]=1;
    call VoltageBooster.clr();
    call VoltageBuffer.set();
  }
  command void volt25.off(){
    call VoltageBuffer.clr();
    atomic on[0]=0;
    resetBooster();
  }

  command void volt33.on(){
    atomic on[1]=1;
    call VoltageBooster.clr();
    call ThreeVolt.set();
  }
  command void volt33.off(){
    call ThreeVolt.clr();
    atomic on[1]=0;
    resetBooster();
  }
  
  command void volt50.on(){
    atomic on[2]=1;
    call VoltageBooster.clr();
    call FiveVolt.set();
  }
  command void volt50.off(){
    call FiveVolt.clr();
    atomic on[2]=0;
    resetBooster();
  }
}
