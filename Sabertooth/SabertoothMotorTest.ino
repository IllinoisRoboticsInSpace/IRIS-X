#include "SabertoothMotor.h"

SabertoothMotor s = SabertoothMotor ();
void setup() {
  Serial.begin (9600);
  Serial1.begin (9600);
  s.init (1, 130);
  testrun1();
}

void testrun1 () {
  Serial.println ("Unecessary Delay");
  delay (5000);

  s.stop();
  Serial.println ("Break");
  delay (2000);

  Serial.println ("Testing fwd func");
  s.fwd (0.8);
  delay (5000);

  s.stop();
  Serial.println ("Break");
  delay (2000);
  
  Serial.println ("Testing bwd func");
  s.bwd (0.8);
  delay (5000);
  
  s.stop();
  Serial.println ("Break");
  delay (2000);
  
  Serial.println ("Testing lht(split) func");
  s.lht (0.8);
  delay (5000);


  s.stop();
  Serial.println ("Break");
  delay (2000);
  
  Serial.println ("Testing rht(split) func");
  s.rht (0.8);
  delay (5000);
  
  
  s.stop();
  Serial.println ("End");
}

void loop () {}
