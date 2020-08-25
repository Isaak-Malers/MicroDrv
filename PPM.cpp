#include "Arduino.h"
#include "PPM.h"

static int _R1;
static int _R2;
static int _R3;
static int _R4;

static int timingOffset = -6;

static volatile long _LastRising1;
static volatile long _lastFalling1;
static volatile int _lastPPM1 = 1500;

static volatile long _LastRising2;
static volatile long _lastFalling2;
static volatile int _lastPPM2 = 1500;

static volatile long _LastRising3;
static volatile long _lastFalling3;
static volatile int _lastPPM3 = 1500;

static volatile long _LastRising4;
static volatile long _lastFalling4;
static volatile int _lastPPM4 = 1500;


PPM::PPM(int boardRevision)
{
	_boardRevision = boardRevision;

	//Allows for pinout changes with future board revisions
	switch(_boardRevision){
		case 4:
			_R1 = 0;
			_R2 = 1;
			_R3 = 2;
			_R4 = 3;

			_configuredForRunning = true;
		default:
			_configuredForRunning = false;
	}

}



void PPM::Start1()
{
	pinMode(_R1, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(_R1), PPM::onChanging1, CHANGE);
}
void PPM::Start2()
{
	pinMode(_R2, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(_R2), PPM::onChanging2, CHANGE);
}
void PPM::Start3()
{
	pinMode(_R3, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(_R3), PPM::onChanging3, CHANGE);
}
void PPM::Start4()
{
	pinMode(_R4, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(_R4), PPM::onChanging4, CHANGE);
}




void PPM::Stop1()
{
	detachInterrupt(digitalPinToInterrupt(_R1));
}
void PPM::Stop2()
{
	detachInterrupt(digitalPinToInterrupt(_R2));
}
void PPM::Stop3()
{
	detachInterrupt(digitalPinToInterrupt(_R3));
}
void PPM::Stop4()
{
	detachInterrupt(digitalPinToInterrupt(_R4));
}




int PPM::Value1()
{
	return _lastPPM1;
}
int PPM::Value2()
{
	return _lastPPM2;
}
int PPM::Value3()
{
	return _lastPPM3;
}
int PPM::Value4()
{
	return _lastPPM4;
}




void PPM::onChanging1()
{
	long now = micros();//Get time before anything else, in case this interrupt gets interrupted
	bool isRising = digitalRead(_R1);
	if(isRising){
		_LastRising1 = now;
	}else{
		_lastFalling1 = now;
		_lastPPM1 = (_lastFalling1 - _LastRising1) + timingOffset;	
	}
}
void PPM::onChanging2()
{
	long now = micros();//Get time before anything else, in case this interrupt gets interrupted
	bool isRising = digitalRead(_R2);
	if(isRising){
		_LastRising2 = now;
	}else{
		_lastFalling2 = now;
		_lastPPM2 = (_lastFalling2 - _LastRising2) + timingOffset;	
	}
}
void PPM::onChanging3()
{
	long now = micros();//Get time before anything else, in case this interrupt gets interrupted
	bool isRising = digitalRead(_R3);
	if(isRising){
		_LastRising3 = now;
	}else{
		_lastFalling3 = now;
		_lastPPM3 = (_lastFalling3 - _LastRising3) + timingOffset;	
	}
}
void PPM::onChanging4()
{
	long now = micros();//Get time before anything else, in case this interrupt gets interrupted
	bool isRising = digitalRead(_R4);
	if(isRising){
		_LastRising4 = now;
	}else{
		_lastFalling4 = now;
		_lastPPM4 = (_lastFalling4 - _LastRising4) + timingOffset;	
	}
}