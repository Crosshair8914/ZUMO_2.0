#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H

#include "ZumoGyroHandler.h"
#include "LineSensor.h"
#include "ZumoInfraRoodSensor.h"

class SensorController {
private:
    ZumoGyroHandler* gyro;
    LineSensor* lineSensor;
    InfraRoodSensor* irSensor;

    // Cached sensor values
    float hoekY;
    uint16_t lineValues[3];
    uint16_t irValues[2];

public:
    SensorController(ZumoGyroHandler* g, LineSensor* l, InfraRoodSensor* ir);

    void updateSensorData();

    float getHoekY() const;
    const uint16_t* getLineValues() const;
    const uint16_t* getIrValues() const;
};

#endif // SENSORCONTROLLER_H
