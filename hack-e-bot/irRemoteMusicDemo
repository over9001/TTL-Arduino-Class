#include <IRremote.h>  // Library from https://github.com/z3t0/Arduino-IRremote
#include <toneAC.h>    // Library from https://bitbucket.org/teckel12/arduino-toneac/wiki/Home

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


int RECV_PIN = 11;
int LED_PIN = 13;
//Speaker pins are 9 and 10 for UNO, check toneAC for other pinouts

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irHandler(results.value);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

void irHandler(unsigned long irCODE){
  
  switch (irCODE) {
    
  case irONE:
    toneAC(440, VOLUME, 100, true);
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
  break;
  
  case irDOWN:
  break;
  
  case irOK:
    toneAC(FREQUENCY, VOLUME, 100, true);
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
