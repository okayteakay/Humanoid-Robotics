//#include "Config.h"
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(12, 13);
//                        1     2     3     4     5    6     7     8     9
const int c_v[10] = {0, 1300, 1500, 1400, 1400, 1500, 1300, 1500, 1500, 1500};

#define mot_1_pin 3   // Head           // On increasing pulse, motor rotates towards right
#define mot_2_pin 4   // Left shoulder  // On increasing pulse, motor rotates towards front
#define mot_3_pin 5   // Left arm       // On increasing pulse, motor rotates towards outside
#define mot_4_pin 6   // Right shoulder // On increasing pulse, motor rotates towards back
#define mot_5_pin 7   // Right arm      // On increasing pulse, motor rotates towards inside

#define mot_6_pin 8   // Left thigh     // On increasing pulse, motor rotates towards outside
#define mot_7_pin 9   // Left foot      // On increasing pulse, motor rotates clockwise
#define mot_8_pin 10  // Right thigh    // On increasing pulse, motor rotates towards inside
#define mot_9_pin 11  // Right foot     // On increasing pulse, motor rotates clockwise

String data = "";
bool serial_updated = false;

void setup() {
  Serial.begin(115200);
  bluetooth.begin(9600);

  pinMode(mot_1_pin, OUTPUT);
  pinMode(mot_2_pin, OUTPUT);
  pinMode(mot_3_pin, OUTPUT);
  pinMode(mot_4_pin, OUTPUT);
  pinMode(mot_5_pin, OUTPUT);
  pinMode(mot_6_pin, OUTPUT);
  pinMode(mot_7_pin, OUTPUT);
  pinMode(mot_8_pin, OUTPUT);
  pinMode(mot_9_pin, OUTPUT);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  bluetooth.println("-> Hello human.. Humanoid this side..!\n");
}

void loop() {
  read_serial();

  if(data == "lock\r")
    lock_bot(10);
  else if(data == "forward\r")
    go_forward();
  else if(data == "back\r")
    go_back();
  else if(data == "left\r")
    go_left();
  else if(data == "right\r")
    go_right();
  else if(data == "namaste\r")
    do_namaste(10);
  else if(data == "gym\r")
    do_gym();
  else if(data == "no\r")
    do_no();
}
