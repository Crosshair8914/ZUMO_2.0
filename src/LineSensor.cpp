void setup()
{
  lineSensors.initFiveSensors();

  for (int i = 0; i < 100; i++)
  {
    lineSensors.calibrate();
    delay(20);
  }
}

void loop()
{
  // Read raw reflectance values
  lineSensors.read(lineSensorValues);

  // Check if any sensor sees the line
  bool lineDetected = false;
  for (int i = 0; i < 5; i++)
  {
    if (lineSensorValues[i] < 500)
    {
      lineDetected = true;
      break;
    }
  }

  if (!lineDetected)
  {
    // No line detected → go straight
    motors.setSpeeds(baseSpeed, baseSpeed);
  }
  else
  {
    // Line detected → proportional steering
    uint16_t position = lineSensors.readLine(lineSensorValues);  // 0 to 4000
    int error = position - 2000;

    int turnCorrection = customKp * error;

    int leftSpeed = baseSpeed + turnCorrection;
    int rightSpeed = baseSpeed - turnCorrection;

    leftSpeed = constrain(leftSpeed, -maxSpeed, maxSpeed);
    rightSpeed = constrain(rightSpeed, -maxSpeed, maxSpeed);

    motors.setSpeeds(leftSpeed, rightSpeed);
  }

  delay(5);
}

