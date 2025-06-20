
#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4IMU imu;

// Offset variabelen
int16_t xOffset = 0;
int16_t yOffset = 0;
int16_t zOffset = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  if (!imu.init()) {
    Serial.println("IMU niet gevonden!");
    while(1); // robot stopt als die niks binnen krijgt
  }

  imu.enableDefault();

  // code voor kalibreren
  long xSum = 0, ySum = 0, zSum = 0;
  const int samples = 500;

  for (int i = 0; i < samples; i++) {
    imu.readGyro();
    xSum += imu.g.x;
    ySum += imu.g.y;
    zSum += imu.g.z;
    delay(5); // sneller sampelen (elke 5ms)
  }

  xOffset = xSum / samples;
  yOffset = ySum / samples;
  zOffset = zSum / samples;
} 

void loop() {
  imu.readGyro();

  int16_t x = imu.g.x - xOffset;
  int16_t y = imu.g.y - yOffset;
  int16_t z = imu.g.z - zOffset;

  // voor kleine trillingen van sensor te negeren
  if (abs(x) < 20) x = 0;
  if (abs(y) < 20) y = 0;
  if (abs(z) < 20) z = 0;

  Serial.print("Gyro X: "); Serial.print(x);
  Serial.print(" | Gyro Y: "); Serial.print(y);
  Serial.print(" | Gyro Z: "); Serial.println(z);

  delay(500); // kortere delay voor snellere updates
}
