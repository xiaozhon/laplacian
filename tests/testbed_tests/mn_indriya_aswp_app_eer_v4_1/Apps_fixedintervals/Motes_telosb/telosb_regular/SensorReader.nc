/**
* A simple interface we provide to allow an application to
* read sensors.
* Author: Newlyn Erratt
*/

interface SensorReader{
  command error_t getReadings();
  event void readingsDone(error_t,uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
}
