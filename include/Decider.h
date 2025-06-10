#ifndef DECIDER_H
#define DECIDER_H

#include <Zumo32U4.h>
#include "SensorController.h"

class Decider {
private:
    SensorController* sensorController;
    Zumo32U4Motors* motors;

public:
    Decider(SensorController* sc, Zumo32U4Motors* m);

    void decideAndAct(); // call this in loop()
};

#endif // DECIDER_H
