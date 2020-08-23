#include <PPM.h>

PPM rx = PPM(3);

void setup(){
	Serial.begin(9600);
	rx.Begin();
}

void loop(){
	int value = rx.GetLastPulse();
	Serial.println(value);
	delay(250);
}