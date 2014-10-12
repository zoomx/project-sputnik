#include <Sputnik.h>
#include <Controller.h>



int onTime = 1000;  //the number of milliseconds for the motor to turn on for
int offTime = 1000; //the snumber of milliseconds for the motor to turn off for


Sputnik sputnik  (9,10,21,20,true);
DummyStrategy strategy (sputnik);
//XBeeStrategy strategy (sputnik);

void setup(){
  
  Serial.begin (9600);

}


void loop() {
  strategy.run(); 
}

