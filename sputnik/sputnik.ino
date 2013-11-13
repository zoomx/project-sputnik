/*     -----------------------------------------------------------
 *     |  Project Sputnik                                        |
 *     |  Main controller                                        |
 *     -----------------------------------------------------------
 * 
 * This is the master controller which supervises the driving
 * All functions created here should be put in a library
 *
 */
 
int echoPin =7; // Echo Pin
int trigPin =8; // Trigger Pin
int directionPort = 9; // HIGH is forward, LOW is backward
int motorPort = 10;   // HIGH is on, LOW is off
int ledPort = 14;     // Led for sonar treshold. 


int onTime = 1000;  //the number of milliseconds for the motor to turn on for
int offTime = 1000; //the number of milliseconds for the motor to turn off for
  
int threshold = 100;  //In centimeters, the distance from objects where the car stops
 
int dir = 1; // At the start we move forward 

void setup()
{
   Serial.begin (9600);
  pinMode(directionPort, OUTPUT); 
  pinMode(motorPort, OUTPUT); 
  pinMode(ledPort, OUTPUT); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
}


/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called motorOnThenOff()
 */

void loop() {
switch dir {
case 1:
    forward();
    break;
case 2:
    backward();
    break;
default:
    StopMoving();
    break;
  }
  int dist = readSonar();
  if(dist < threshold && dist != -1 ){
    digitalWrite(ledPort, HIGH);
    if(dir != 2){
      stopMoving();
    }
    dir = 2;
  }else{
    digitalWrite(ledPort, LOW);
    if(dir != 1){
      stopMoving();
    }
    dir = 1;
  }
  /*forward();
    backward();*/
   
   
}

int readSonar(){
  
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
  
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10); 
   
   digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH,10000);
   duration -= 5;
   
  int distance = duration/76;
  Serial.println(distance);
  delay(50);
  if(distance ==0){
  distance = -1;
  }
   return distance;
}

void forward(){
  digitalWrite(motorPort, HIGH); // turns the motor On
  digitalWrite(directionPort, HIGH); // turns the motor On
  /*
  delay(onTime);                // waits for onTime milliseconds
  digitalWrite(motorPort, LOW); // turns the motor On
  delay(offTime);*/
}


void backward(){
  digitalWrite(motorPort, HIGH); // turns the motor On
  digitalWrite(directionPort, LOW); // turns the motor On
  /*
  delay(onTime);                // waits for onTime milliseconds
  digitalWrite(motorPort, LOW); // turns the motor On
  delay(offTime);*/
}

void stopMoving(){
  digitalWrite(motorPort, LOW); // turns the motor On
  delay(1000);
}
