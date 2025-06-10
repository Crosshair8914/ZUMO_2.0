#ifndef ZUMOGYROHANDLER_H
#define ZUMOGYROHANDLER_H

#include <Zumo32U4.h>

class ZumoGyroHandler {
private:
    Zumo32U4IMU* imuHandler;
    float hoekY;
    unsigned long vorigeMillis;
    float gyroYOffset;

public:
    ZumoGyroHandler(Zumo32U4IMU* imu, float offset = 0.0f);

    void setup();  // Call this once in your main setup()
    float printGyroYGrade();  // Call this repeatedly in loop()
};

#endif // ZUMOGYROHANDLER_H
