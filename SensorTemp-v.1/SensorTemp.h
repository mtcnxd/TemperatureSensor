#include <Wire.h>
#include <Adafruit_BMP085.h>

class SensorTemp {
  Adafruit_BMP085 sensor;

public:
  void begin() {
    sensor.begin();
  }

private:
  float getTemperature() {
    delay(100);
    return sensor.readTemperature();
  }

public:
  void RunMain() {
    this->getTemperature();
  }
};