#include "SensorController.h"

SensorController::SensorController(ZumoGyroHandler* g, LineSensor* l, InfraRoodSensor* ir) {
    gyro = g;
    lineSensor = l;
    irSensor = ir;
    hoekY = 0.0f;
    for (int i = 0; i < 3; ++i) lineValues[i] = 0;
    for (int i = 0; i < 2; ++i) irValues[i] = 0;
}

void SensorController::updateSensorData() {
    // Update gyro
    hoekY = gyro->printGyroYGrade();

    // Update line sensor
    lineSensor->detectLine();
const uint16_t* lv = lineSensor->getSensorValues();
    for (int i = 0; i < 3; ++i) lineValues[i] = lv[i];

    // Update IR sensor
    irSensor->detectObstacle();
    const uint16_t* ir = irSensor->getProximityValues();
    irValues[0] = ir[0];
    irValues[1] = ir[1];
}

float SensorController::getHoekY() const {
    return hoekY;
}

const uint16_t* SensorController::getLineValues() const {
    return lineValues;
}

const uint16_t* SensorController::getIrValues() const {
    return irValues;
}
