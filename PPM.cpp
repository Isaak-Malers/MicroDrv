#include "Arduino.h"
#include "PPM.h"

PPM:PPM(int digitalPin)
{
	_digitalPin = digitalPin;
}

int PPM:LastHighPulse(){
	return _lastHigh;
}

int PPM:LastLowPulse(){
	return _lastLow;
}

void PPM:Begin(){
	pinMode(_digitalPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(_digitalPin), onRising, RISING);
}

void PPM:Stop(){
	detachInterrupt(digitalPinToInterrupt(_digitalPin))
}

int PPM:LastHighPulse(){
	return _lastHigh;
}

int PPM:LastHighPulse(){
	return _lastLow;
}

void PPM:onRising(){
	long now = micros();
	lastLow = now - _lastFalling;
	_lastRising = now;
	attachInterrupt(digitalPinToInterrupt(_digitalPin), onFalling, FALLING);
}

void PPM:onFalling(){
	long now = micros();
	lastHigh = now - _lastRising;
	_lastFalling = now;
	attachInterrupt(digitalPinToInterrupt(_digitalPin), onRising, RISING);
}