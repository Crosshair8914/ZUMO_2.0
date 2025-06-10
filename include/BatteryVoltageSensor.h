#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <Arduino.h>
#include <Zumo32U4.h>

class BatteryMonitor {
public:
    uint16_t currentVoltage;

    void readVoltage();
    bool isVoltageLow();
    void alertLowVoltage();
};

class Test {
    public:
    int test1;
    bool test4;
    void testFunction();
};

#endif