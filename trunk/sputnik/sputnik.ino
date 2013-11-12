/*     -----------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code               |
 *     |  CIRC-03 .: Spin Motor Spin :. (Transistor and Motor)   |
 *     -----------------------------------------------------------
 * 
 * The Arduinos pins are great for driving LEDs however if you hook 
 * up something that requires more power you will quickly break them.
 * To control bigger items we need the help of a transistor. 
 * Here we will use a transistor to control a small toy motor
 * 
 * http://tinyurl.com/d4wht7
 *
 */
 
int echoPin =7; // Echo Pin
int trigPin =8; // Trigger Pin
int directionPort = 9;
int motorPort = 10; // HIGH is forward, LOW is backward
int ledPort = 14;


int onTime = 1000;  //the number of milliseconds for the motor to turn on for
int offTime = 1000; //the number of milliseconds for the motor to turn off for
  
 int threshold = 100;
  
/*
 * setup() - this function runs once when you turn your Arduino on
 * We set the motors pin to be an output (turning the pin high (+5v) or low (ground) (-))
 * rather than an input (checking whether a pin is high or low)
 */
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
int dir = 1;
void loop() {
  if(dir == 1){
    forward();
  }else{
    backward();
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
