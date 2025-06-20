#include <Wire.h>
#include <Zumo32U4.h>
 
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
 
const int baseSpeed = 200;           // Basissnelheid vooruit
const int maxSpeed = 400;            // Maximale motorsnelheid
const float kp = 0.2;                // Hogere P-gain voor scherpere bijsturing
 
uint16_t lineSensorValues[5];
 
// Detection thresholds - adjust based on your surfaces
const int blackThreshold = 300;      // Threshold for black line detection
const int greenMinThreshold = 400;   // Minimum reflectance for green (bright green tape)
const int greenMaxThreshold = 900;   // Maximum reflectance for green (very reflective)
const int whiteThreshold = 700;      // Threshold above which surface is considered white/background

bool greenDetected = false;
bool blackDetected = false;
 
void setup()
{
  lineSensors.initFiveSensors();
 
  // Kalibreer: beweeg handmatig heen-en-weer over de lijn
  for (int i = 0; i < 100; i++)
  {
    lineSensors.calibrate();
    delay(20);
  }
 
  // Enable serial for debugging reflectance values - ENABLE THIS TO TUNE
  Serial.begin(9600);
}
 
void loop()
{
  // Lees lijnpositie (0 = links, 4000 = rechts)
  uint16_t position = lineSensors.readLine(lineSensorValues);
 
  // Reset detection flags
  greenDetected = false;
  blackDetected = false;
  bool anyLineDetected = false;
 
  // Analyze each sensor for line detection
  for (int i = 0; i < 5; i++)
  {
    // Detect black line (very low reflectance)
    if (lineSensorValues[i] < blackThreshold)
    {
      blackDetected = true;
      anyLineDetected = true;
    }
 
    // Detect green line (medium-high reflectance range for bright green tape)
    if (lineSensorValues[i] >= greenMinThreshold && lineSensorValues[i] <= greenMaxThreshold)
    {
      greenDetected = true;
      anyLineDetected = true;
    }
  }
 
  // Debug output - shows sensor values to help tune thresholds
  Serial.print("Sensors: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(lineSensorValues[i]);
    Serial.print(" ");
  }
  Serial.print("| Green: "); Serial.print(greenDetected);
  Serial.print(" Black: "); Serial.print(blackDetected);
  Serial.print(" Position: "); Serial.println(position);
 
  int currentBaseSpeed = baseSpeed;
 
  // Adjust speed based on line type
  if (greenDetected && !blackDetected)
  {
    // Pure green line - reduce speed for better tracking
    currentBaseSpeed = baseSpeed * 0.7;  // Reduce speed by 30%
  }
  else if (greenDetected && blackDetected)
  {
    // Mixed green and black - moderate speed reduction
    currentBaseSpeed = baseSpeed * 0.8;  // Reduce speed by 20%
  }
 
  if (!anyLineDetected)
  {
    // Geen lijn gevonden → rijd rechtdoor met lage snelheid
    motors.setSpeeds(currentBaseSpeed * 0.5, currentBaseSpeed * 0.5);
  }
  else
  {
    // Volg de gedetecteerde lijn (zwart of groen)
    // Bereken fout vanaf midden (2000)
    int error = position - 2000;
 
    // Bereken correctie
    int correction = kp * error;
 
    // Voor groene lijnen, gebruik zachte correctie
    if (greenDetected && !blackDetected)
    {
      correction *= 0.8;  // Gentler correction for green lines
    }
 
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
