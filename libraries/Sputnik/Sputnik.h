#ifndef Sputnik_h
#define Sputnik_h
#include "Arduino.h"
//#include "Wire.h"
#include "Adafruit_MotorShield.h"
#include "utility/Adafruit_PWMServoDriver.h"


class Sputnik{
	public:
		Sputnik();
		Sputnik(int directionPin, int motorPin, int turnPin, int turnPowerPin);
		Sputnik(int directionPin, int motorPin, int turnPin, int turnPowerPin,boolean verbose);
		void forward();
		void forward(int Speed);
		void backward();
		void backward(int Speed);
		void turn(int direction);
		void neutral();
		void stopMoving();
		void stopMoving(int stopTime);
		void setup();
		
	private:
		boolean verbose = false;

		int directionPin = 9; // HIGH is forward, LOW is backward
		int motorPin = 10;   // HIGH is on, LOW is off

		int ledPin = 14;     // Led for sonar treshold. 

		int speedPin = 15;

		int turnPin = 21;
		int turnPowerPin = 20;

		int onTime = 1000;  //the number of milliseconds for the motor to turn on for
		int offTime = 1000; //the number of milliseconds for the motor to turn off for
		  
		int threshold = 100;  //In centimeters, the distance from objects where the car stops

		// Create the motor shield object with the default I2C address
		Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
		// Or, create it with a different I2C address (say for stacking)
		// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

		// Select which 'port' M1, M2, M3 or M4. In this case, M1
		Adafruit_DCMotor *mainMotor = AFMS.getMotor(1);
		// You can also make another motor on port M2
		Adafruit_DCMotor *turnMotor = AFMS.getMotor(2);
};

#endif
