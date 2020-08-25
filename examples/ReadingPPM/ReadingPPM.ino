#include <PPM.h>

PPM rx = PPM(4);

void setup(){
	Serial.begin(115200);
	rx.Start1();
	rx.Start2();
	rx.Start3();
	rx.Start4();
}

void loop(){
	Serial.print("1: ");
	Serial.println(rx.Value1());
	Serial.print("2: ");
	Serial.println(rx.Value2());
	Serial.print("3: ");
	Serial.println(rx.Value3());
	Serial.print("4: ");
	Serial.println(rx.Value4());
	Serial.println();
	delay(250);
}