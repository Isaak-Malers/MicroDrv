#include <MicroDrv.h>

MicroDrv drivers = drivers(4);

void setup(){
  
}

void loop(){
  drivers.SetM1(100);
  drivers.SetM2(100);
  drivers.SetM3(-100);
  drivers.SetM4(-100);

  delay(1000);

  drivers.SetM1(0);
  drivers.SetM2(0);
  drivers.SetM3(0);
  drivers.SetM4(0);

  delay(1000);
  
}
