#include "Arduino.h"
#include "PPM.h"

static int _R1;
static int _R2;
static int _R3;
static int _R4;

static long _LastRising1;
static long _lastFalling1;
static int _lastPPM1;



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

void PPM::Stop1()
{
	detachInterrupt(digitalPinToInterrupt(_R1));
}

int PPM::Value1()
{
	return _lastPPM1;
}

void PPM::onChanging1()
{
	long now = micros();//Get time before anything else, in case this interrupt gets interrupted
	bool isRising = digitalRead(_R1);
	if(isRising){
		_LastRising1 = now;
	}else{
		_lastFalling1 = now;
		_lastPPM1 = _lastFalling1 - _LastRising1;	
	}
}