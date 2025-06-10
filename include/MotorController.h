#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Zumo32U4.h>

class MotorController {
private:
    Zumo32U4Motors* motors;
    int baseSpeed;

public:
    MotorController(Zumo32U4Motors* m, int speed = 150);

    void driveForward();
    void stop();
    void turnLeft();
    void turnRight();
    void setSpeed(int speed); // optional runtime speed change
};

#endif // MOTORCONTROLLER_H
