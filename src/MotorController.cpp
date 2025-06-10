#include "MotorController.h"

MotorController::MotorController(Zumo32U4Motors* m, int speed) {
    motors = m;
    baseSpeed = speed;
}

void MotorController::setSpeed(int speed) {
    baseSpeed = speed;
}

void MotorController::driveForward() {
    motors->setLeftSpeed(baseSpeed);
    motors->setRightSpeed(baseSpeed);
}

void MotorController::stop() {
    motors->setLeftSpeed(0);
    motors->setRightSpeed(0);
}

void MotorController::turnLeft() {
    motors->setLeftSpeed(baseSpeed / 2);
    motors->setRightSpeed(baseSpeed);
}

void MotorController::turnRight() {
    motors->setLeftSpeed(baseSpeed);
    motors->setRightSpeed(baseSpeed / 2);
}
