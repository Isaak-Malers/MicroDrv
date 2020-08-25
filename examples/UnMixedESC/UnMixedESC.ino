#include <Drivers.h>
#include <PPM.h>


Drivers motors = Drivers(4);  //Board Revision 4, printed on the silkscreen
PPM rx = PPM(4);              //Board Revision 4, printed on the silkscreen


void setup(){
	Serial.begin(115200);

	//Start tracking ppm signals on all 4 channels.
	rx.Start1();
	rx.Start2();
	rx.Start3();
	rx.Start4();
}

void loop(){
	int val1 = map(rx.Value1(), 1200, 1800, -100, 100);
	int val2 = map(rx.Value2(), 1200, 1800, -100, 100);
	int val3 = map(rx.Value3(), 1200, 1800, -100, 100);
	int val4 = map(rx.Value4(), 1200, 1800, -100, 100);

	Serial.print("1: ");
	Serial.println(val1);
	Serial.print("2: ");
	Serial.println(val2);
	Serial.print("3: ");
	Serial.println(val3);
	Serial.print("4: ");
	Serial.println(val4);
	Serial.println();


	motors.SetM1(val1);
	motors.SetM2(val2);
	motors.SetM3(val3);
	motors.SetM4(val4);

	delay(15);//Delay at least 4x the PWM period (8ms) to avoid stutter.
}