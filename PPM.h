/*
	


*/

#ifndef PPM_h
#define PPM_h

class PPM
{
	public:
		PPM(int digitalPin);
		int LastHighPulse();
		int LastLowPulse();
		void Begin();
		void Stop();
	private:
		int _digitalPin;
		volatile long _lastRising;
		volatile long _lastFalling;
		volatile int _lastHigh;
		volatile int _lastLow;
		void onRising();
		void onFalling();
}