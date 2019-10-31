#include "SabertoothMotor.h"

SabertoothMotor::SabertoothMotor() {}  // Sabertooth motor object init

void SabertoothMotor::init (int addr [5]) { //addresses of the 2x60 Sabertooth boards connected to Serial
	for (int i = 0; i < 5; i++) {
    ADDR [i] = addr [i];
	}
}

void SabertoothMotor::run (int addr, int cmd, int data) {
	data = data;
	Serial1.write(addr); 
	Serial1.write(cmd); 
	Serial1.write(data); 
	Serial1.write((addr + cmd + data) & 127);
}

void SabertoothMotor::fwd(int addr, int data, int n) {  // n = 0 by default
	switch (n) {
		case 0:  // Both motors -> technically never used
		run (addr, MOTOR1_FWD, data);
		run (addr, MOTOR2_FWD, data);
		break;
	case 1:  // First motor
		run (addr, MOTOR1_FWD, data);
		break;
	case 2:  // Second motor
		run (addr, MOTOR2_FWD, data);
   		break;
	default: break;
  }
}
void SabertoothMotor::bwd(int addr, int data, int n) {
	switch (n) {
		case 0: // Both motors
		run (addr, MOTOR1_BWD, data);
		run (addr, MOTOR2_BWD, data);
		break;
  	  case 1: // First motor
		run (addr, MOTOR1_BWD, data);
		break;
	case 2:  // Second motor
		run (addr, MOTOR2_BWD, data);
		break;
	default: break;
  }
}

void SabertoothMotor::halt (int addr) {
  run (addr, 0, 0);  // Stops motor one
  run (addr, 4, 0);  // Stops motor two
}

void SabertoothMotor::read (String msg) { //input a string msg, presumably from the odroid, execute it
  //format: #[motor]$[power]
  int a = msg.indexOf('#') + 1,
    b = msg.indexOf('$'),
    c = msg.length ();
  String p1 = msg.substring (a, b),
    p2 = msg.substring (b + 1, c);
  int tmp = p1.toInt(),
    mot = ((tmp+2) % 2) + 1,
    addr = ADDR [(tmp - 1)/2],
    pow = p2.toInt() - 128;
  Serial.println ("p1: " + p1 + "  addr: " + String(addr) + "  pow: " + String(pow) + "  mot: " + String(mot));
  
  if (pow == 0) {
      Serial.println ("Halt");
    halt (addr);
  } else if (pow > 0) {
      Serial.println ("F");
    fwd (addr, pow, mot);
  } else {
      Serial.println ("B");
    bwd (addr, 0 - pow, mot);
  }
}
