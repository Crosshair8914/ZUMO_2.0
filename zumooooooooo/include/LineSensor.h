#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Zumo32U4.h>

class LineSensor {
public:
    Zumo32U4LineSensors lineSensors;
    uint16_t lineSensorValues[5];

    void init();
    void detectLine();
};
#endif