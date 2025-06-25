#include <Wire.h>
#include <Zumo32U4.h>
 
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
 
const int baseSpeed = 200;           // Basissnelheid vooruit
const int maxSpeed = 400;            // Maximale motorsnelheid
const float kp = 0.2;                // Hogere P-gain voor scherpere bijsturing
 
uint16_t lineSensorValues[5];
 
const int greenThreshold = 200;      // Adjust this based on testing
bool greenDetected = false;
 
void setup()
{
  lineSensors.initFiveSensors();
 
  // Kalibreer: beweeg handmatig heen-en-weer over de lijn
  for (int i = 0; i < 100; i++)
  {
    lineSensors.calibrate();
    delay(20);
  }
 
  // (Optional) Serial to monitor reflectance values
  // Serial.begin(9600);
}
 
void loop()
{
  // Lees lijnpositie (0 = links, 4000 = rechts)
  uint16_t position = lineSensors.readLine(lineSensorValues);
 
  // Check of lijn volledig kwijt is
  bool lineMissing = true;
  greenDetected = false;
 
  for (int i = 0; i < 5; i++)
  {
    // Detect any dark surface (black or green)
    if (lineSensorValues[i] < 800)
    {
      lineMissing = false;
    }
 
    // Detect green based on reflectance (tune threshold if needed)
    if (lineSensorValues[i] > greenThreshold && lineSensorValues[i] < 800)
    {
      greenDetected = true;
    }
  }
 
  int currentBaseSpeed = baseSpeed;
 
  // If green detected, reduce speed slightly
  if (greenDetected)
  {
    currentBaseSpeed = baseSpeed * 0.75;  // Reduce speed by 25%
  }
 
  if (lineMissing)
  {
    // Geen lijn → rijd rechtdoor
    motors.setSpeeds(currentBaseSpeed, currentBaseSpeed);
  }
  else
  {
    // Bereken fout vanaf midden (2000)
    int error = position - 2000;
 
    // Bereken correctie (sterker door hogere kp)
    int correction = kp * error;
 
    // Bereken nieuwe snelheden per motor
    int leftSpeed = currentBaseSpeed + correction;
    int rightSpeed = currentBaseSpeed - correction;
 
    // Beperk snelheden binnen bereik
    leftSpeed = constrain(leftSpeed, -maxSpeed, maxSpeed);
    rightSpeed = constrain(rightSpeed, -maxSpeed, maxSpeed);
 
    // Motoren aansturen
    motors.setSpeeds(leftSpeed, rightSpeed);
  }
 
  delay(5); // korte delay voor vloeiende respons
}

