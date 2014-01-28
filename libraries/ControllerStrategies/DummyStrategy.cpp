#include "DummyStrategy.h"
DummyStrategy::DummyStrategy(Sputnik _sputnik) : ControllerStrategy( _sputnik){
	Serial.println( "DummyStrategy Initialized");
}

void DummyStrategy::run(){
	Serial.println(  "run DummyStrategy");
	delay(1000);
	Serial.println("Begin dummyrun");
	sputnik.forward();
	delay(1000);
	sputnik.stopMoving();
	delay(1000);
	sputnik.backward();
	delay(1000);
	sputnik.stopMoving();
	sputnik.forward();
	sputnik.turn(1000, 0);
	sputnik.stopMoving();
	sputnik.backward();
	delay(1000);
	sputnik.stopMoving();
	sputnik.forward();
	sputnik.turn(1000, 1);
	sputnik.stopMoving();

	Serial.println("End dummyrun");

	Serial.println("*************************************");
}
