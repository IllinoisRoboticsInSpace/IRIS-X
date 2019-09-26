#include "SabertoothMotor.h"

SabertoothMotor::SabertoothMotor() {}

void SabertoothMotor::init (int serial_idx, int addr, int max_vel) {
  SERIAL_IDX = serial_idx;
  ADDR = addr;
  MAX_VEL = max_vel;
}

void SabertoothMotor::run (int cmd, int data) {
  data = min (MAX_VEL, data);
  switch (SERIAL_IDX) {
    case 1: Serial1.write (ADDR); Serial1.write(cmd); Serial1.write (data); Serial1.write ((ADDR + cmd + data) & 127); break;
    case 2: Serial2.write (ADDR); Serial2.write(cmd); Serial2.write (data); Serial2.write ((ADDR + cmd + data) & 127); break;
    case 3: Serial3.write (ADDR); Serial3.write(cmd); Serial3.write (data); Serial3.write ((ADDR + cmd + data) & 127); break;
    default: break; 
  }
}

void SabertoothMotor::run (int cmd, double r) {
  run (cmd, (int)(MAX_VEL * r));
}

void SabertoothMotor::fwd(int data, int n) {
  switch (n) {
    case 0:
      run (MOTOR1_FWD, data);
      run (MOTOR2_FWD, data);
      break;
    case 1: 
      run (MOTOR1_FWD, data);
      break;
    case 2:
      run (MOTOR2_FWD, data);
      break;
    default: break;
  }
}
void SabertoothMotor::bwd(int data, int n) {
  switch (n) {
    case 0:
      run (MOTOR1_BWD, data);
      run (MOTOR2_BWD, data);
      break;
    case 1: 
      run (MOTOR1_BWD, data);
      break;
    case 2:
      run (MOTOR2_BWD, data);
      break;
    default: break;
  }
}
void SabertoothMotor::lht(int data) {
  run (MOTOR1_FWD, data);
  run (MOTOR2_BWD, data);
}
void SabertoothMotor::rht(int data) {
  run (MOTOR2_FWD, data);
  run (MOTOR1_BWD, data);
}

void SabertoothMotor::fmt(int m1, int m2) {
  run (MOTOR1_FWD, m1);
  run (MOTOR2_FWD, m2);
}

void SabertoothMotor::bmt(int m1, int m2) {
  run (MOTOR1_BWD, m1);
  run (MOTOR2_BWD, m2);
}

void SabertoothMotor::fwd(double r, int n) {
  switch (n) {
    case 0:
      run (MOTOR1_FWD, r);
      run (MOTOR2_FWD, r);
      break;
    case 1: 
      run (MOTOR1_FWD, r);
      break;
    case 2:
      run (MOTOR2_FWD, r);
      break;
    default: break;
  }
}
void SabertoothMotor::bwd(double r, int n) {switch (n) {
    case 0:
      run (MOTOR1_BWD, r);
      run (MOTOR2_BWD, r);
      break;
    case 1: 
      run (MOTOR1_BWD, r);
      break;
    case 2:
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

void SabertoothMotor::fmt(double m1, double m2) {
  run (MOTOR1_FWD, m1);
  run (MOTOR2_FWD, m2);
}

void SabertoothMotor::bmt(double m1, double m2) {
  run (MOTOR1_BWD, m1);
  run (MOTOR2_BWD, m2);
}
void SabertoothMotor::stop () {
  run (0, 0);
  run (4, 0);
}
