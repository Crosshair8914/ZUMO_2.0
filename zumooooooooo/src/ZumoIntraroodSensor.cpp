#include "InfraRoodSensor.h"

InfraRoodSensor::InfraRoodSensor() {
    proximitySensors.initFrontSensor();
    proxValues[0] = 0;
    proxValues[1] = 0;
}

void InfraRoodSensor::detectObstacle() {
    proximitySensors.read(); // reads all proximity values

    // Store left and right front sensor readings
    proxValues[0] = proximitySensors.countsLeftWithLeftLeds();
    proxValues[1] = proximitySensors.countsRightWithRightLeds();
}

const uint16_t* InfraRoodSensor::getProximityValues() const {
    return proxValues;
}
