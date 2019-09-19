#define vel 120
#define addr 130

void setup() {
  Serial.begin (9600);
  Serial1.begin (9600);
}

void propel (int cmd, int data) {
  Serial1.write (addr);
  Serial1.write (cmd);
  Serial1.write (data);

  //check, or something
  Serial1.write ((addr + cmd + data) & 0b01111111);
}

void forwards (float r) {
  propel (0, vel);
  propel (1, vel);
}

void backwards (float r) {
  propel (4, vel);
  propel (5, vel);
}

void turn (float L, float R) {
  propel (0, L);
  propel (1, R);
}

void loop() {
  while (Serial.available () < 1) {
    //nothing until character input
  }
  char val = Serial.read(); //yay character inputted
  switch (val) {
    case 'w': case 'W': forwards (1.0); Serial.println ("Forwards");
    break;
    case 's': case 'S': backwards (1.0); Serial.println ("Backwards");
    break;
    case 'a': case 'A': turn (-1.0, 1.0); Serial.println ("Left turn");
    break;
    case 'd': case 'D': turn (1.0, -1.0); Serial.println ("Right turn");
    break;
    default:
    //
    break;
  }
}
