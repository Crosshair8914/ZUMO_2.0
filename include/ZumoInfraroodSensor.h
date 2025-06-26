#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ProximitySensors proxSensors;

const int motorSpeed = 400;         // Vooruitrijsnelheid
const int turnSpeed = 400;          // Draaisnelheid
const int turnDuration = 500;       // Duur van draai (~90°)
const int proximityThreshold = 2;   // Hoe gevoelig de detectie is
bool draaiLinks = true;             // Afwisselend links/rechts draaien
