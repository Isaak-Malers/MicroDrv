/*
	PPH.h - class for reading PPM signals as a "Background" task using interrupts.
	Author - Isaak Malers, 2020
*/

#ifndef PPM_h
#define PPM_h

class PPM
{
	public:
		PPM(int boardRevision);

		static void Start1();
		static void Stop1();
		static int Value1();



	private:
		int _boardRevision;
		bool _configuredForRunning;

		//Note: must be delcared in the .CCP file not here for some reason.
		//TODO, figure out why.
		// static int _R1;
		// static int _R2;
		// static int _R3;
		// static int _R4;

		//Note, Variables for keeping track of timing are ALSO defined in the class.

		static void onChanging1();

};

#endif