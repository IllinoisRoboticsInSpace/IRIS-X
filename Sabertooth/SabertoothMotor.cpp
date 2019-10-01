#include "SabertoothMotor.h"

SabertoothMotor::SabertoothMotor() {}  // Sabertooth motor object init

void SabertoothMotor::init (int serial_idx, int addr, int max_vel) {  
  SERIAL_IDX = serial_idx;
  ADDR = addr;
  MAX_VEL = max_vel;
}

/* *************************************************************************** */

/*
run commands that send the commands to the sabertooth? One for the int fn's and one for double fn's? Maybe? I guess..?
*/

void SabertoothMotor::run (int cmd, int data) {  // Int fn's
  data = min(MAX_VEL, data);
  switch (SERIAL_IDX) {
    case 1: 
	Serial1.write(ADDR); 
	Serial1.write(cmd); 
	Serial1.write(data); 
	Serial1.write((ADDR + cmd + data) & 127); 
	break;
    case 2: 
	Serial2.write(ADDR); 
	Serial2.write(cmd); 
	Serial2.write(data); 
	Serial2.write((ADDR + cmd + data) & 127); 
	break;
    case 3: 
	Serial3.write(ADDR); 
	Serial3.write(cmd); 
	Serial3.write(data); 
	Serial3.write((ADDR + cmd + data) & 127); 
	break;
    default: break; 
  }
}

void SabertoothMotor::run (int cmd, double r) {  // Double fn's
  run (cmd, (int)(MAX_VEL * r));
}

/* *************************************************************************** */

/*
Runs the robot using speed variables as ints
EX: fwd(200, 0)
    -Runs both motors at 200 whatever's
    -Only runs when r sent is an int
*/

void SabertoothMotor::fwd(int data, int n) {  // n = 0 by default
  switch (n) {
    case 0:  // Both motors
      run (MOTOR1_FWD, data);
      run (MOTOR2_FWD, data);
      break;
    case 1:  // First motor
      run (MOTOR1_FWD, data);
      break;
    case 2:  // Second motor
      run (MOTOR2_FWD, data);
      break;
    default: break;
  }
}
void SabertoothMotor::bwd(int data, int n) {
  switch (n) {
    case 0: // Both motors
      run (MOTOR1_BWD, data);
      run (MOTOR2_BWD, data);
      break;
    case 1: // First motor
      run (MOTOR1_BWD, data);
      break;
    case 2:  // Second motor
      run (MOTOR2_BWD, data);
      break;
    default: break;
  }
}
void SabertoothMotor::lht(int data) {  // Turns from still position
  run (MOTOR1_FWD, data);
  run (MOTOR2_BWD, data);
}
void SabertoothMotor::rht(int data) {  // Turns from still position
  run (MOTOR2_FWD, data);
  run (MOTOR1_BWD, data);
}

void SabertoothMotor::fmt(int m1, int m2) {  // Forward moving turn
  run (MOTOR1_FWD, m1);
  run (MOTOR2_FWD, m2);
}

void SabertoothMotor::bmt(int m1, int m2) {  //  Backward moving turn
  run (MOTOR1_BWD, m1);
  run (MOTOR2_BWD, m2);
}

/* *************************************************************************** */

/* 

Same as the functions above, but take percentage values (in decimal form) instead of ints
EX: fwd(0.2, 0)
   -Runs both motors at 20% power (maybe)
   -Only run when sent 'r' is a double

*/

void SabertoothMotor::fwd(double r, int n) {  // n = 0 by default
  switch (n) {
    case 0:  // Both motors
      run (MOTOR1_FWD, r);
      run (MOTOR2_FWD, r);
      break;
    case 1:  // First motor
      run (MOTOR1_FWD, r);
      break;
    case 2:  // Second motor
      run (MOTOR2_FWD, r);
      break;
    default: break;
  }
}
void SabertoothMotor::bwd(double r, int n) {switch (n) {  // n = 0 by default
    case 0:  // Both motors
      run (MOTOR1_BWD, r);
      run (MOTOR2_BWD, r);
      break;
    case 1:  // First motor
      run (MOTOR1_BWD, r);
      break;
    case 2:  // Second motor
      run (MOTOR2_BWD, r);
      break;
    default: break;
  }
}
void SabertoothMotor::lht(double r) {
  run (MOTOR1_FWD, r);
  run (MOTOR2_BWD, r);
}
void SabertoothMotor::rht(double r) {
  run (MOTOR1_BWD, r);
  run (MOTOR2_FWD, r);
}

void SabertoothMotor::fmt(double m1, double m2) {  // Forwards moving turn
  run (MOTOR1_FWD, m1);
  run (MOTOR2_FWD, m2);
}

void SabertoothMotor::bmt(double m1, double m2) {  // Backwards moving turn
  run (MOTOR1_BWD, m1);
  run (MOTOR2_BWD, m2);
}

/* *************************************************************************** */

void SabertoothMotor::stop () {
  run (0, 0);  // Stops motor one
  run (4, 0);  // Stops motor two
}
