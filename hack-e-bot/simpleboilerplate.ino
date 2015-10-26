#include <Servo.h> // include the Servo library

// create the servo objects
Servo leftMotor;
Servo rightMotor;

const int servoR = 10;  // Right Servo control line (orange) on Pin #10
const int servoL = 9;   // Left Servo control line (orange) on Pin #9
const int centerR = 90; //This sets the center or Stopping point for the servo. If the robot drifts to one side, try changing this number by +/- 1.
const int centerL = 90; //This sets the center or Stopping point for the servo. If the robot drifts to one side, try changing this number by +/- 1.

int moveSpeed = 40;

void setup()
{
  leftMotor.attach(servoL);  // attaches the servo on pin 13 to a servo object
  rightMotor.attach(servoR); // attaches the servo on pin 12 to a servo object
}

void loop()
{
  MoveStop(1000);
  MoveF(moveSpeed, 1000);
  MoveStop(1000);
  MoveB(moveSpeed, 1000);
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
 
 
