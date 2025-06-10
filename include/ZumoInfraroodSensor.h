#ifndef INFRAROODSENSOR_H
#define INFRAROODSENSOR_H

#include <Zumo32U4.h>

class InfraRoodSensor {
private:
    Zumo32U4ProximitySensors proximitySensors;
    uint16_t proxValues[2]; // 0 = left, 1 = right

public:
    InfraRoodSensor();
    void detectObstacle();
    const uint16_t* getProximityValues() const;
};

#endif // INFRAROODSENSOR_H
