#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Zumo32U4.h>

class LineSensor {
private:
    Zumo32U4LineSensors lineSensors;
    uint16_t lineSensorValues[5];

public:
    LineSensor();
    void detectLine();
    const uint16_t* getSensorValues() const;
};

#endif // LINESENSOR_H
