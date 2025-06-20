#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Zumo32U4.h>

class MotorController {
public:
    int baseSpeed = 150;
    int turnSpeed = 100;

    void setSpeeds(int leftSpeed, int rightSpeed);
    void stop();
};
#endif