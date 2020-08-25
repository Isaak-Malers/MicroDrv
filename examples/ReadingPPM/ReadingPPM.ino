#include <PPM.h>

PPM rx = PPM(3);

void setup(){
	Serial.begin(115200);
	rx.Start1();
}

void loop(){
	Serial.println(rx.Value1());
	delay(250);
}