#ifndef ZUMOGYROHANDLER_H
#define ZUMOGYROHANDLER_H

#include <Zumo32U4.h>

class ZumoGyroHandler {
private:
    Zumo32U4IMU imu;
    int16_t xOffset = 0;
    int16_t yOffset = 0;
    int16_t zOffset = 0;

public:
    // Initialiseer IMU en kalibreer
    void begin();

    // Meet en print gyro-waardes 
    void update();

    // Ophalen van de offsetwaarden 
    int16_t getXOffset() const;
    int16_t getYOffset() const;
    int16_t getZOffset() const;
};

#endif // ZUMOGYROHANDLER_H
