#include <Drivers.h>

Drivers motors = Drivers(4);


void setup(){
  
}


void loop(){
  motors.SetM1(100);
  delay(1000);
  motors.SetM1(0);
  delay(1000);

  motors.SetM2(100);
  delay(1000);
  motors.SetM2(0);
  delay(1000);

  motors.SetM3(100);
  delay(1000);
  motors.SetM3(0);
  delay(1000);

  motors.SetM4(100);
  delay(1000);
  motors.SetM4(0);
  delay(1000);  
}