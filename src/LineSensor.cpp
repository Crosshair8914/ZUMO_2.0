#include "LineSensor.h"

LineSensor::LineSensor() {
    lineSensors.initFiveSensors();
}

void LineSensor::detectLine() {
    lineSensors.read(lineSensorValues);
}

const uint16_t* LineSensor::getSensorValues() const {
    return lineSensorValues;
}
