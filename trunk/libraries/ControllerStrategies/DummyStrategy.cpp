#include "DummyStrategy.h"
DummyStrategy::DummyStrategy(Sputnik _sputnik) : ControllerStrategy( _sputnik){
	Serial.println( "DummyStrategy Initialized");
	pinMode(15,OUTPUT);
}

void DummyStrategy::run(){
	Serial.println(  "run DummyStrategy");	
	Serial.println("Begin dummyrun");
	analogWrite(15,255);
	forward()
	for(int i=255;i>1;i-=10){
	analogWrite(15,i);
	Serial.println( i);
	delay(1000);
	}
/*
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
*/

	Serial.println("End dummyrun");

	Serial.println("*************************************");
}
