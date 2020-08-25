#include "Arduino.h"
#include "Drivers.h"

Drivers::Drivers(int boardRevision)
{
	_boardRevision = boardRevision;

	//Allows for pinout changes with future board revisions.
	switch(_boardRevision){
		case 4:
			_IN1 = 4;
			_IN2 = 14;
			_PWM1 = 5;

			_IN3 = A1;
			_IN4 = A0;
			_PWM2 = 6;

			_IN5 = 8;
			_IN6 = 7;
			_PWM3 = 9;

			_IN7 = 15;
			_IN8 = 16;
			_PWM4 = 10;

			_configuredForRunning = true;
		default:
			_configuredForRunning = false;
	}


	pinMode(_IN1, OUTPUT);
	pinMode(_IN2, OUTPUT);
	pinMode(_IN3, OUTPUT);
	pinMode(_IN4, OUTPUT);
	pinMode(_IN5, OUTPUT);
	pinMode(_IN6, OUTPUT);
	pinMode(_IN7, OUTPUT);
	pinMode(_IN8, OUTPUT);

	pinMode(_PWM1, OUTPUT);
	pinMode(_PWM2, OUTPUT);
	pinMode(_PWM3, OUTPUT);
	pinMode(_PWM4, OUTPUT);

}

//Utility methods:
bool direction(int speed){
	if(speed < 0){
		return false;
	}
	return true;
}

int dutyCycle(int speed){
	int constrained = constrain(speed, -100, 100);
	int mapped = map(constrained, -100, 100, -255, 255);
	int directionRemoved = abs(mapped);
	return directionRemoved;
}

void SetMotor(int IN1, int IN2, int PWM, int speed){
	analogWrite(PWM, 0);
	bool dir = direction(speed);
	digitalWrite(IN1, dir);
	digitalWrite(IN2, !dir);
	analogWrite(PWM, dutyCycle(speed));
}

void Drivers::SetM1(int speed){
	SetMotor(_IN1, _IN2, _PWM1, speed);
}

void Drivers::SetM2(int speed){
	SetMotor(_IN3, _IN4, _PWM2, speed);
}

void Drivers::SetM3(int speed){
	SetMotor(_IN5, _IN6, _PWM3, speed);
}

void Drivers::SetM4(int speed){
	SetMotor(_IN7, _IN8, _PWM4, speed);
}