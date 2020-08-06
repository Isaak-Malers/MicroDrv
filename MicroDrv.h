/*
	MicroDrv.h - Class for driving motors using the MicroDrv Quad Channel motor controller.
	Author - Isaak Malers, 2020
*/

#ifndef MicroDrv_h
#define MicroDrv_h

class MicroDrv
{
	public:
		MicroDrv(int boardRevision);
		void SetM1(int speed);//-100 to 100 constrain higher values
		void SetM2(int speed);//-100 to 100 constrain higher values
		void SetM3(int speed);//-100 to 100 constrain higher values
		void SetM4(int speed);//-100 to 100 constrain higher values
}

#endif