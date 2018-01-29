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

  StdControl = SensorReaderP.StdControl;
  SensorReaderP.Timer -> TimerMilliC;

  SensorReader = SensorReaderP;

}
  
