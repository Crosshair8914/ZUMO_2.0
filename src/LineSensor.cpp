#include "LineSensor.h"

LineSensor::LineSensor() {
    lineSensors.initFiveSensors();
}

void LineSensor::detectLine() {
    lineSensors.read(lineSensorValues);
}

const unsigned* LineSensor::getSensorValues() const {
    return lineSensorValues;
}
