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

		static void Start2();
		static void Stop2();
		static int Value2();

		static void Start3();
		static void Stop3();
		static int Value3();

		static void Start4();
		static void Stop4();
		static int Value4();



	private:
		int _boardRevision;
		bool _configuredForRunning;

		static void onChanging1();
		static void onChanging2();
		static void onChanging3();
		static void onChanging4();
};

#endif