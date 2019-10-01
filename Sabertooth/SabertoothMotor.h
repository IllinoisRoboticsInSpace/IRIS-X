#ifndef SABERTOOTHMOTOR_H
#define SABERTOOTHMOTOR_H

#include "Arduino.h"
#include "Stream.h"

static const int MOTOR1_FWD = 0, //check documentation
  MOTOR1_BWD = 1,
  //MIN_V = 2,
  //MAX_V = 3,
  MOTOR2_FWD = 4,
  MOTOR2_BWD = 5,
  //MOTOR1_7BIT= 6,
  //MOTOR2_7BIT= 7,
  //FWD_MIX = 8,
  //BWD_MIX = 9,
  //RHT_MIX = 10,
  //LHT_MIX = 11,
  //FWD_7BIT = 12,
  //TURN_7BIT = 13,
  //STIM = 14,
  //BAUD = 15,
  RAMP = 16,
  DBND = 17;
      
class SabertoothMotor { //i'm lazy so all these functions have 3-4 letter names
  public:
    SabertoothMotor ();
    void init (int serial_idx, int addr, int max_vel = 127);

    void run (int cmd, int data);
    void fwd (int data, int n = 0); //n -> 0=both motors, 1=first motor, 2=second motor
    void bwd (int data, int n = 0);
    void lht (int data); //turn on the spot
    void rht (int data);
    void fmt (int m1, int m2); //forwards moving turn
    void bmt (int m1, int m2); //backwards moving turn

    void run (int cmd, double r);
    void fwd (double r, int n = 0);
    void bwd (double r, int n = 0);
    void lht (double r);
    void rht (double r);
    void fmt (double m1, double m2); //forwards moving turn
    void bmt (double m1, double m2); //backwards moving turn

    void stop ();
    
  private:
    int SERIAL_IDX;
    int ADDR;
    int MAX_VEL;
};
#endif
