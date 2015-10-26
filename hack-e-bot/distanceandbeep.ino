#include <Servo.h> // include the Servo library

// create the servo objects
Servo leftMotor;
Servo rightMotor;

const int servoR = 10;  // Right Servo control line (orange) on Pin #10
const int servoL = 9;   // Left Servo control line (orange) on Pin #9
const int centerR = 90; //This sets the center or Stopping point for the servo. If the robot drifts to one side, try changing this number by +/- 1.
const int centerL = 90; //This sets the center or Stopping point for the servo. If the robot drifts to one side, try changing this number by +/- 1.

int moveSpeed = 40;

const int sonarTrig = 3;   // Connect the sonar signal pin to this pin on the Trinket.
const int sonarEcho = 4;
long duration, cm;

int obstacleDistance = 8;

const int speakerPin = 11;

void setup()
{
  leftMotor.attach(servoL);  // attaches the servo on pin 13 to a servo object
  rightMotor.attach(servoR); // attaches the servo on pin 12 to a servo object
  pinMode(sonarTrig, OUTPUT);
  pinMode(sonarEcho, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop()
{
  SonarPing();
  if (cm > obstacleDistance) {
  MoveF(moveSpeed, 300);
  } else {
  MoveB(moveSpeed, 300);
  happyBEEP();
  }
}

/* The Hack-E-Bot can now be programmed to move by giving it instructions like:
MoveStop(stopTime); -- to stop moving
MoveF(moveSpeed, moveTime); -- to drive forward
MoveB(moveSpeed, moveTime); -- to drive backward
TurnR(moveSpeed, moveTime); -- to turn right
TurnL(moveSpeed, moveTime); -- to turn left
stopTime and moveTime are mesured in miliseconds.
moveSpeed is a number between 0 to 90 with 0 being no movment and 90 being full speed.
*/
 
void MoveStop(int T){ // Stop moving, T = stopTime.
  rightMotor.write(centerR);
  leftMotor.write(centerL);
  delay(T);
}
 
void MoveF(int S, int T){ // Move forward, S = moveSpeed, T = moveTime.
  rightMotor.write(centerR - S);
  leftMotor.write(S + centerL);
  delay(T);
}
 
void MoveB(int S, int T){ // Move backward, S = moveSpeed, T = moveTime.
  rightMotor.write(S + centerR);
  leftMotor.write(centerL - S);
  delay(T);
}
 
void TurnL(int S, int T){ // Turn Left, S = moveSpeed, T = moveTime.
  rightMotor.write(centerR - S);
  leftMotor.write(centerL - S);
  delay(T);
}
 
void TurnR(int S, int T){ // Turn Right, S = moveSpeed, T = moveTime.
  rightMotor.write(S + centerR);
  leftMotor.write(S + centerL);
  delay(T);
}

void SonarPing() {
  /* The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  Give a short LOW pulse beforehand to ensure a clean HIGH pulse:*/
  digitalWrite(sonarTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(sonarTrig, LOW);
  /* The sonarEcho pin is used to read the signal from the PING))): a HIGH
  pulse whose duration is the time (in microseconds) from the sending
  of the ping to the reception of its echo off of an object.*/
  duration = pulseIn(sonarEcho, HIGH);
  
  // convert the time into a distance.
  cm = microsecondsToCentimeters(duration);
}
 
long microsecondsToCentimeters(long microseconds)
{
  // The moveSpeed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void happyBEEP()
{
  tone(speakerPin, 440, 400);
}
