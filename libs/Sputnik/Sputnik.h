#ifndef Sputnik_h
#define Sputnik_h
#include "Arduino.h"

class Sputnik{
	public:
		Sputnik(int directionPin, int motorPin, int turnPin, int turnPowerPin);
		Sputnik(int directionPin, int motorPin, int turnPin, int turnPowerPin,boolean verbose);
		void forward();
		void backward();
		void turn(int turnTime, int direction);
		void stopMoving();
		void stopMoving(int stopTime);
		
	private:
		boolean verbose = false;

		int directionPin = 9; // HIGH is forward, LOW is backward
		int motorPin = 10;   // HIGH is on, LOW is off

		int ledPin = 14;     // Led for sonar treshold. 

		int turnPin = 21;
		int turnPowerPin = 20;

		int onTime = 1000;  //the number of milliseconds for the motor to turn on for
		int offTime = 1000; //the number of milliseconds for the motor to turn off for
		  
		int threshold = 100;  //In centimeters, the distance from objects where the car stops

};

#endif
