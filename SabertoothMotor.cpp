#include "SabertoothMotor.h"

SabertoothMotor::SabertoothMotor(){}

void SabertoothMotor::init (HardwareSerial stream, int addr, int max_vel) {
	STREAM = &stream;
	ADDR = addr;
	MAX_VEL = max_vel;
}

void SabertoothMotor::run (int cmd, int data) {
	HardwareSerial temp = *STREAM;
	temp.write (ADDR);
	temp.write (cmd);
	temp.write (data);
	temp.write ((ADDR + cmd + data) & 127);
}

void SabertoothMotor::run (int cmd, double r) {
  run (cmd, MAX_VEL * r);
}

void SabertoothMotor::fwd(int data, int n) { run (n == 0 ? FWD_MIX : n == 1 ? MOTOR1_FWD : MOTOR2_FWD, data); }
void SabertoothMotor::bwd(int data, int n) { run (n == 0 ? BWD_MIX : n == 1 ? MOTOR1_BWD : MOTOR2_BWD, data); }
void SabertoothMotor::lht(int data, bool mix) {
  if (mix) { //mixed motor control
    run (LHT_MIX, data);
  } else { //separate motor control
    run (MOTOR1_FWD, data);
    run (MOTOR2_BWD, data);
  }
}
void SabertoothMotor::rht(int data, bool mix) {
  if (mix) { //mixed motor control
    run (LHT_MIX, data);
  } else { //separate motor control
    run (MOTOR1_BWD, data);
    run (MOTOR2_FWD, data);
  }  
}

void SabertoothMotor::fwd(double r, int n) { run (n == 0 ? FWD_MIX : n == 1 ? MOTOR1_FWD : MOTOR2_FWD, r); }
void SabertoothMotor::bwd(double r, int n) { run (n == 0 ? BWD_MIX : n == 1 ? MOTOR1_FWD : MOTOR2_FWD, r); }
void SabertoothMotor::lht(double r, bool mix) {
  if (mix) { //mixed motor control
    run (LHT_MIX, r);
  } else { //separate motor control
    run (MOTOR1_FWD, r);
    run (MOTOR2_BWD, r);
  }
}
void SabertoothMotor::rht(double r, bool mix) {
  if (mix) { //mixed motor control
    run (LHT_MIX, r);
  } else { //separate motor control
    run (MOTOR1_BWD, r);
    run (MOTOR2_FWD, r);
  }
}

void SabertoothMotor::stop () {
  run (0, 0); //pretty sure that this is how you stop the motors
}
