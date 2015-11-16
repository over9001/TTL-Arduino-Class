#include <TimerFreeTone.h>  // Library from https://bitbucket.org/teckel12/arduino-timer-free-tone/wiki/Home
#include <IRremote.h>  // Library from https://github.com/z3t0/Arduino-IRremote
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

const unsigned long irONE = 0x20DF8877;
const unsigned long irTWO = 0x20DF48B7;
const unsigned long irTHREE = 0x20DFC837;
const unsigned long irFOUR = 0x20DF28D7;
const unsigned long irFIVE = 0x20DFA857;
const unsigned long irSIX = 0x20DF6897;
const unsigned long irSEVEN = 0x20DFE817;
const unsigned long irEIGHT = 0x20DF18E7;
const unsigned long irNINE = 0x20DF9867;
const unsigned long irZERO = 0x20DF08F7;
const unsigned long irUP = 0x20DF02FD;
const unsigned long irDOWN = 0x20DF827D;
const unsigned long irLEFT = 0x20DFE01F;
const unsigned long irRIGHT = 0x20DF609F;
const unsigned long irOK = 0x20DF22DD;
const unsigned long irPOWER = 0x20DF10EF;
const unsigned long irVOL_UP = 0x20DF40BF;
const unsigned long irVOL_DOWN = 0x20DFC03F;
const unsigned long irCH_UP = 0x20DF00FF;
const unsigned long irCH_DOWN = 0x20DF807F;

int VOLUME = 5;
int FREQUENCY = 440;


int RECV_PIN = 7;
int LED_PIN = 13;
int SPEAKER_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  leftMotor.attach(servoL);  // attaches the servo on pin 13 to a servo object
  rightMotor.attach(servoR); // attaches the servo on pin 12 to a servo object
  pinMode(sonarTrig, OUTPUT);
  pinMode(sonarEcho, INPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irHandler(results.value);
    irrecv.resume(); // Receive the next value
  }
  //SonarPing();
  //if (cm > obstacleDistance) {
  //MoveF(moveSpeed, 300);
  //} else {
  //MoveB(moveSpeed, 300);
  //}
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

void irHandler(unsigned long irCODE){
  
  switch (irCODE) {
    
  case irONE:
  break;
  
  case irTWO:
  break;
  
  case irTHREE:
  break;
  
  case irFOUR:
  break;
  
  case irFIVE:
  break;
  
  case irSIX:
  break;
  
  case irSEVEN:
  break;
  
  case irEIGHT:
  break;
  
  case irNINE:
  break;
  
  case irZERO:
  break;
  
  case irUP:
    MoveF(moveSpeed, 300);
  break;
  
  case irDOWN:
    MoveB(moveSpeed, 300);
  break;

  case irLEFT:
    TurnL(moveSpeed, 100);
  break;
  
  case irRIGHT:
    TurnR(moveSpeed, 100);
  break;
  
  case irOK:
    TimerFreeTone(SPEAKER_PIN, FREQUENCY, VOLUME*40);
  break;
  
  case irPOWER:
  break;
  
  case irVOL_UP:
    VOLUME = VOLUME + 1;
    if (VOLUME > 10) { VOLUME = 10; }
  break;
  
  case irVOL_DOWN:
    VOLUME = VOLUME - 1;
    if (VOLUME < 0) { VOLUME = 0; }
  break;
  
  case irCH_UP:
    FREQUENCY = FREQUENCY + 10;
  break;
  
  case irCH_DOWN:
    FREQUENCY = FREQUENCY - 10;
  break;
  }
}
