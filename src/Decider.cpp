#include "Decider.h"

Decider::Decider(SensorController* sc, Zumo32U4Motors* m) {
    sensorController = sc;
    motors = m;
}

void Decider::decideAndAct() {
    // Update and get sensor data
    sensorController->updateSensorData();
    float hoekY = sensorController->getHoekY();
    const uint16_t* line = sensorController->getLineValues();
    const uint16_t* ir = sensorController->getIrValues();

    // --- IR Sensor Logic (Obstacle Avoidance) ---
    if (ir[0] > 2 || ir[1] > 2) {
        Serial.println("Obstacle detected, turning!");
        motors->setLeftSpeed(-100);
        motors->setRightSpeed(100);
        delay(400); // quick turn
        motors->setLeftSpeed(0);
        motors->setRightSpeed(0);
        return; // skip further actions this cycle
    }

    // --- Gyro Logic (Angle-based motor response) ---
    if (hoekY > 95 && hoekY < 105) {
        Serial.println("Tussen 95 en 105 kantelpunt begint hier");
        motors->setLeftSpeed(50);
        motors->setRightSpeed(50);
    } else if (hoekY > 110 && hoekY < 130) {
        Serial.println("Tussen 110 en 130 kantelpunt begint hier");
        motors->setLeftSpeed(50);
        motors->setRightSpeed(50);
    }

    // --- Line Sensor Logic (Follow line) ---
    if (line[0] > 200 && line[2] < 200) {
        // Line is more to the left
        motors->setLeftSpeed(100);
        motors->setRightSpeed(150);
    } else if (line[2] > 200 && line[0] < 200) {
        // Line is more to the right
        motors->setLeftSpeed(150);
        motors->setRightSpeed(100);
    } else {
        // Go straight
        motors->setLeftSpeed(150);
        motors->setRightSpeed(150);
    }
}
