#include <Servo.h>


Servo pin2;
Servo pin3;
Servo pin4;
Servo pin5;

void setup() {
  pin2.attach(2);
  pin3.attach(3);
  pin4.attach(4);
  pin5.attach(5);
  Serial.begin(115200);
  Serial.println("Starting PPM");
}

void loop() {
  pin2.writeMicroseconds(1000);
  pin3.writeMicroseconds(1500);
  pin4.writeMicroseconds(2000);
  pin5.writeMicroseconds(2200);
  delay(50000);
}