configuration ADCC{
  provides {
    //interface StdControl;
    //interface ADConvert[uint8_t port];
    //interface Read<uint16_t>[uint8_t id];
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
}implementation{
  components MainC, ADCP;
  components new Atm128I2CMasterC() as I2C;

  MainC.SoftwareInit -> ADCP.Init;

  ADCP.I2CPacket -> I2C.I2CPacket;
  ADCP.I2CControl -> I2C.Resource;

  //read interfaces
  ADC0 = ADCP.ADC0;
  ADC1 = ADCP.ADC1;
  ADC2 = ADCP.ADC2;
  ADC3 = ADCP.ADC3;
  ADC4 = ADCP.ADC4;
  ADC5 = ADCP.ADC5;
  ADC6 = ADCP.ADC6;
}
