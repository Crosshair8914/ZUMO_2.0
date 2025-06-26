#include <Wire.h>
#include <Zumo32U4.h>

class LineSensor {
private:
    Zumo32U4LineSensors lineSensors;
    uint16_t lineSensorValues[5];

    void init();
    void detectLine();
    const int baseSpeed = 750;
const int maxSpeed = 1000;

// Increase this value to turn more aggressively
const float customKp = 0.55;  // Previously 0.05

uint16_t lineSensorValues[5];


};
