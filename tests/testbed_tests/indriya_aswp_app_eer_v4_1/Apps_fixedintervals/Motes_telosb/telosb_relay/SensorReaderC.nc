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
//  components new TimerMilliC();
  components new ADC0C(), new ADC1C(), new ADC2C(), new ADC3C(), new ADC6C(), new ADC7C();
  components new SensirionSht11C(); 
//  components HplMsp430GeneralIOC;

//  SensorReaderP.Power -> HplMsp430GeneralIOC.Port67;
//  SensorReaderP.Power -> HplMsp430GeneralIOC.Port23;

  StdControl = SensorReaderP.StdControl;
//  SensorReaderP.Timer -> TimerMilliC;

//  components new Msp430InternalVoltageC();  
//  SensorReaderP.Voltage -> Msp430InternalVoltageC;

  components new InternalVoltageC();  
  SensorReaderP.Voltage -> InternalVoltageC;

  SensorReaderP.Temperature -> SensirionSht11C.Temperature;
  SensorReaderP.Humidity -> SensirionSht11C.Humidity;;
  

  SensorReaderP.ADC0 -> ADC0C.Read;
  SensorReaderP.ADC1 -> ADC1C.Read;
  SensorReaderP.ADC2 -> ADC2C.Read;
  SensorReaderP.ADC3 -> ADC3C.Read;
  //SensorReaderP.ADC4 -> MDA300C.ADC4;
  //SensorReaderP.ADC5 -> MDA300C.ADC5;
  SensorReaderP.ADC6 -> ADC6C.Read;
  SensorReaderP.ADC7 -> ADC7C.Read;

  SensorReader = SensorReaderP;

}
  
