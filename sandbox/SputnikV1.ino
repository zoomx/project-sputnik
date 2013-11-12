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
int directionPort = 9;
int motorPort = 10; // HIGH is forward, LOW is backward


int onTime = 2500;  //the number of milliseconds for the motor to turn on for
int offTime = 1000; //the number of milliseconds for the motor to turn off for
  
 
  
/*
 * setup() - this function runs once when you turn your Arduino on
 * We set the motors pin to be an output (turning the pin high (+5v) or low (ground) (-))
 * rather than an input (checking whether a pin is high or low)
 */
void setup()
{
  pinMode(directionPort, OUTPUT); 
  pinMode(motorPort, OUTPUT); 
}


/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called motorOnThenOff()
 */

void loop() {
      forward();
  //  stopMoving();
    backward();
   // stopMoving(); 
   
   
}

void forward(){
  digitalWrite(motorPort, HIGH); // turns the motor On
  digitalWrite(directionPort, HIGH); // turns the motor On
  
  delay(onTime);                // waits for onTime milliseconds
  digitalWrite(motorPort, LOW); // turns the motor On
  delay(offTime);
}


void backward(){
  digitalWrite(motorPort, HIGH); // turns the motor On
  digitalWrite(directionPort, LOW); // turns the motor On
  
  delay(onTime);                // waits for onTime milliseconds
  digitalWrite(motorPort, LOW); // turns the motor On
  delay(offTime);
}

void stopMoving(){
  digitalWrite(motorPort, LOW); // turns the motor On
  delay(offTime);
}
