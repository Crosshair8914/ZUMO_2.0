#include "ZumoGyroHandler.h"

ZumoGyroHandler::ZumoGyroHandler(Zumo32U4IMU* imu, float offset) {
    imuHandler = imu;
    gyroYOffset = offset;
    vorigeMillis = millis();
    hoekY = 0.0f;
}

void ZumoGyroHandler::setup() {
    imuHandler->init();
    imuHandler->enableDefault();
}

float ZumoGyroHandler::printGyroYGrade() {
    imuHandler->readGyro();  // Only read gyro, not accel/mag (faster)

    int16_t gyroYraw = imuHandler->g.y;

    float gy = gyroYraw * 0.0175f - gyroYOffset;

    unsigned long huidigeMillis = millis();
    float dt = (huidigeMillis - vorigeMillis) / 1000.0f;
    vorigeMillis = huidigeMillis;

    gy = constrain(gy, -360.0f, 360.0f);

    if (abs(gy) > 1) {
        hoekY += gy * dt;
    }

    return hoekY;
}


