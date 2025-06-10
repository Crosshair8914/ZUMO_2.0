#include "../Include/BatteryVoltageSensor.h"

Zumo32U4Buzzer buzzer;
#define LED_RED_PIN LED_RED
#define LOW_VOLTAGE_THRESHOLD 6000


void BatteryMonitor::readVoltage() {
    currentVoltage = readBatteryMillivolts();
}

bool BatteryMonitor::isVoltageLow() {
    return currentVoltage < LOW_VOLTAGE_THRESHOLD;
}

void BatteryMonitor::alertLowVoltage() {
    ledRed(1);  // Turn red LED on
    Serial.println("⚠️ Warning: Battery voltage is LOW!");
    Serial.print("Current Voltage: ");
    Serial.print(currentVoltage);
    Serial.println(" mV");

    buzzer.play("!L16 cdegr");
    delay(1000);
    ledRed(0);  // Turn red LED off

}
