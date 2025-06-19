#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Zumo32U4.h>

class LineSensor {
private:
    Zumo32U4LineSensors lineSensors;
    unsigned lineSensorValues[5];

public:
    LineSensor();
    void detectLine();
    const unsigned* getSensorValues() const;
};

#endif // LINESENSOR_H
