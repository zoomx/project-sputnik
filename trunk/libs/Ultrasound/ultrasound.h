#ifndef Ultrasound_h
#define Ultrasound_h
#include "Arduino.h"

class Ultrasound{
	public:
		Ultrasound(int triggerpin, int echopin);
		int measure();
	private:
		int _trigpin;
		int _echopin;
};

#endif
