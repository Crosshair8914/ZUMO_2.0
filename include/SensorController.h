#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H

#include "LineSensor.h"

class SensorController {
public:
    float Kp = 0.2;
    float Kd = 5.0;
    float Ki = 0.0;

    int16_t lastError = 0;
    int32_t integral = 0;

    SensorController();
    int computeCorrection(LineSensor& sensor);
};

#endif // SENSORCONTROLLER_H