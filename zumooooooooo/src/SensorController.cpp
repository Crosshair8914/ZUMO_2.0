#include "SensorController.h"

SensorController::SensorController() {}

int SensorController::computeCorrection(LineSensor& sensor) {
    unsigned int position = sensor.lineSensors.readLine(reinterpret_cast<unsigned int*>(sensor.lineSensorValues));
    int16_t error = position - 2000; // 2000 is the center for 5 sensors
    integral += error;
    int16_t derivative = error - lastError;
    lastError = error;

    int correction = (Kp * error) + (Ki * integral) + (Kd * derivative);
    return correction;
}