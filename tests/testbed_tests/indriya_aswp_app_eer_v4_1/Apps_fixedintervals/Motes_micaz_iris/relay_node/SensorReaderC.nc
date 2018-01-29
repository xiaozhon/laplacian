/**
* Simply wires our implementation of SensorReader to
* the sensors and provides the result
* Author: Newlyn Erratt
*/

configuration SensorReaderC{
  provides interface SensorReader;
  provides interface StdControl;
}
implementation{
  components SensorReaderP;
  components new TimerMilliC();
  components MDA300C;  

  StdControl = SensorReaderP.StdControl;
  SensorReaderP.Timer -> TimerMilliC;

  //SensorReaderP.Excitation2_5 -> MDA300C.volt25;
  //SensorReaderP.Excitation3_3 -> MDA300C.volt33;
  //SensorReaderP.Excitation5_0 -> MDA300C.volt50;

  SensorReaderP.Voltage -> MDA300C.Voltage;

  SensorReaderP.Temperature -> MDA300C.Temperature;
  SensorReaderP.Humidity -> MDA300C.Humidity;
  
  SensorReaderP.ADC0 -> MDA300C.ADC0;
  SensorReaderP.ADC1 -> MDA300C.ADC1;
  SensorReaderP.ADC2 -> MDA300C.ADC2;
  SensorReaderP.ADC3 -> MDA300C.ADC3;
  SensorReaderP.ADC4 -> MDA300C.ADC4;
  SensorReaderP.ADC5 -> MDA300C.ADC5;
  SensorReaderP.ADC6 -> MDA300C.ADC6;

  SensorReader = SensorReaderP;
}
  
