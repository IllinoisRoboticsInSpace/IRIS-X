#include "SabertoothMotor.h"

SabertoothMotor s = SabertoothMotor ();
void setup() {
  Serial.begin (9600);
  Serial1.begin (9600);
  s.init (1, 130);
  //testrun1();
  byte c = 0;
  int rVel = 0;
  int lVel = 0;

  while (1) {
  	if (Serial.available() > 0) {
  		//New command from odroid
  		c = Serial.read();
  		if (c & 00000001 == 0) {
  			#Right motor
  			rVel = (int) (c >> 2);
  			if (c & 00000010 == 1) {
  				#Negative
  				rVel = rVel * -1;
  			}
  		}
  		else {
  			#Left motor
  			lVel = (int) (c >> 2);
  			if (c & 00000010 == 1) {
  				#Negative
  				lVel = lVel * -1;
  			}

  			#Since both should have been received, send controls to motors
  			s.miw(rVel, lVel);
  		}
  	}
  }
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
