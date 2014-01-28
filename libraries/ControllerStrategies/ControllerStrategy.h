#ifndef ControllerStrategy_h
#define ControllerStrategy_h
#include "Arduino.h"

#include <Sputnik.h>

class ControllerStrategy{
	public:
		ControllerStrategy(Sputnik _sputnik);
		virtual void run() =0;
	protected:
	 	Sputnik sputnik;
	private:

};

#endif
