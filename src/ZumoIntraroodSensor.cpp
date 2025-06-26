#include "InfraRoodSensor.h"
void setup()
{
  proxSensors.initThreeSensors();   // Activeer front-, links- en rechtsensor
}

void loop()
{
  proxSensors.read();  // Lees IR-sensorwaarden

  uint16_t front = proxSensors.countsFrontWithRightLeds();

  if (front > proximityThreshold)
  {
    // Obstakel gezien → draai
    if (draaiLinks)
      motors.setSpeeds(-turnSpeed, turnSpeed); // draai linksom
    else
      motors.setSpeeds(turnSpeed, -turnSpeed); // draai rechtsom

    delay(turnDuration); // draai even

    motors.setSpeeds(0, 0); // korte pauze na draaien
    delay(100);

    draaiLinks = !draaiLinks; // wissel draaikant
  }
  else
  {
    motors.setSpeeds(motorSpeed, motorSpeed); // vooruit
  }

  delay(20); // korte pauze voor stabiliteit
}
