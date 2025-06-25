#include "MotorController.h"

Zumo32U4Motors motors;

void MotorController::setSpeeds(int leftSpeed, int rightSpeed) {
    motors.setSpeeds(leftSpeed, rightSpeed);
}

void MotorController::stop() {
    motors.setSpeeds(0, 0);
}