#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Zumo32U4.h>

class LineSensor {
public:
    Zumo32U4LineSensors lineSensors;
    unsigned lineSensorValues[5];

    void init();
    void detectLine();
<<<<<<< HEAD
=======
    const unsigned* getSensorValues() const;
>>>>>>> d1c696791e23c6e169d3d7f244dd208daa0b7221
};
#endif