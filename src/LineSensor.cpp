#include "LineSensor.h"

void LineSensor::init() {
    lineSensors.initFiveSensors();
    delay(1000);
    // Calibrate for a bit by sweeping
    for (uint16_t i = 0; i < 400; i++) {
        lineSensors.calibrate();
        delay(5);
    }
}

void LineSensor::detectLine() {
    lineSensors.readCalibrated(reinterpret_cast<unsigned int*>(lineSensorValues));

}
