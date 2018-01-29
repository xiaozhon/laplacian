configuration MDA300C{
  provides interface Read<uint16_t> as ADC0;
  provides interface Read<uint16_t> as ADC1;
  provides interface Read<uint16_t> as ADC2;
  provides interface Read<uint16_t> as ADC3;
  provides interface Read<uint16_t> as ADC4;
  provides interface Read<uint16_t> as ADC5;
  provides interface Read<uint16_t> as ADC6;

  provides interface Read<uint16_t> as Voltage;

  provides interface Power as volt25;
  provides interface Power as volt33;
  provides interface Power as volt50;

  provides interface Read<uint16_t> as Temperature;
  provides interface Read<uint16_t> as Humidity;
  
}implementation{
  components ExcitationC, ADCC, TempHum;
  components new VoltageC();

  Voltage = VoltageC;

  ADC0 = ADCC.ADC0;
  ADC1 = ADCC.ADC1;
  ADC2 = ADCC.ADC2;
  ADC3 = ADCC.ADC3;
  ADC4 = ADCC.ADC4;
  ADC5 = ADCC.ADC5;
  ADC6 = ADCC.ADC6;

  volt25 = ExcitationC.volt25;
  volt33 = ExcitationC.volt33;
  volt50 = ExcitationC.volt50;

  Temperature = TempHum.Temperature;
  Humidity = TempHum.Humidity;
}
