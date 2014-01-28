#ifndef AutonomousStrategy_h
#define AutonomousStrategy_h
#include <ControllerStrategy.h>
class AutonomousStrategy: public ControllerStrategy{

	public:
		AutonomousStrategy(Sputnik _sputnik);
		AutonomousStrategy(Sputnik _sputnik, int _ledPin, int _echoPin, int _trigPin);
		void run();
	protected:
	
	private:
		int readSonar();
		int dir = 1;

		int threshold = 100;  //In centimeters, the distance from objects where the car stops
		
		int ledPin = 14;     // Led for sonar treshold. 

		int echoPin =7; // Echo Pin
		int trigPin =8; // Trigger Pin
};

#endif
