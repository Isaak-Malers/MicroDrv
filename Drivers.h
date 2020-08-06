/*
	Drivers.h - Class for driving motors using the MicroDrv Quad Channel motor controller.
	Author - Isaak Malers, 2020
*/

#ifndef Drivers_h
#define Drivers_h

class Drivers
{
	public:
		Drivers(int boardRevision);
		void SetM1(int speed);//-100 to 100 constrain higher values
		void SetM2(int speed);//-100 to 100 constrain higher values
		void SetM3(int speed);//-100 to 100 constrain higher values
		void SetM4(int speed);//-100 to 100 constrain higher values
	private:
		int _boardRevision;
		bool _configuredForRunning;

		int _IN1;
		int _IN2;
		int _PWM1;

		int _IN3;
		int _IN4;
		int _PWM2;

		int _IN5;
		int _IN6;
		int _PWM3;

		int _IN7;
		int _IN8;
		int _PWM4;
}

#endif