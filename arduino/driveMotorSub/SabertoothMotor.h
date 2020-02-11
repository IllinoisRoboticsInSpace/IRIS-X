#ifndef SABERTOOTHMOTOR_H
#define SABERTOOTHMOTOR_H

#include "Arduino.h"
#include "Stream.h"
	
static const int MOTOR1_BWD = 0, //check documentation
	MOTOR1_FWD = 1,
	MOTOR2_BWD = 4,
	MOTOR2_FWD = 5,
	RAMP = 16,
	DBND = 17;
		
class SabertoothMotor { //i'm lazy so all these functions have 3-4 letter names
	public:
	SabertoothMotor ();
	void init (int addr []);
	void run (int addr, int cmd, int data);
	void fwd (int addr, int data, int n = 0); //n -> 0=both motors, 1=first motor, 2=second motor
	void bwd (int addr, int data, int n = 0);
 
	void halt (int addr);
	void read (String msg);
	
	int ADDR [5];
};
#endif
