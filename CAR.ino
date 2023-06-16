//including the library that wil allow us to control the servos
#include <Servo.h>

//defining the pins that will be used to controll the servos
#define ServoPinLeft 3
#define ServoPinRight 8


//variables for controlling the servos
Servo Servo1;
Servo Servo2;
int pos = 0;
int pos2 = 0;
int SensorValLeft = 0;
int SensorValRight = 0;
float PulseLength = 0.0;
const float Period = 0.02;
float DutyCycle = 0.0;

//the boolean that controls whether the robo is on or off
bool on = false;

//this timer will control whether the robot is going backwards or not and for how long
float backwardsTimer = 0;

//the buzzer is activated with pin A1
int buzzer = A1;

//the lights are activated with pins 4 and 5
int leftLight = 4;
int rightLight = 5; 

//the button is detected with pin 7
int button = 7;

//the trigger pin that will be used to send a signal to the ultrasonic sensor
int trigPin = 12;    // TRIG pin
int echoPin = 13;    // ECHO pin


//setting the inputs/outputs out
void setup() {
  
  //attaching the servos to their pins on the arduino
  Servo1.attach(ServoPinLeft);
  Servo2.attach(ServoPinRight);

  //configure the buzzer pin to output mode
  pinMode(buzzer, OUTPUT);
  
  //configure the right headlight pin to output mode
  pinMode(rightLight, OUTPUT);
  //configure the left headlight pin to output mode
  pinMode(leftLight, OUTPUT);

  //configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  //configure the echo pin to input mode
  pinMode(echoPin, INPUT);

  //configure the button pin to input mode
  pinMode(button, INPUT);

}

//main loop
void loop() {
  
  //only move the robot if it is powered on
  if(on){



  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  float duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  float distance_cm = 0.017 * duration_us;

  delay(500);

  //checking if the robot is set to go backwards  
  if(backwardsTimer > 0){
    
    //turning both lights on to signal that the robot is going backwards
    digitalWrite(leftLight, HIGH);
    digitalWrite(rightLight, HIGH);
    
    //creating a tone with the buzzer 
    tone(buzzer, 10000, 500);

    //turning left wheel backwards
    SensorValLeft = 0;

    //turning right wheel backwards
    SensorValRight = 1000;

    //decrementing the backwards timer so the robot stops going backwards after a while
    backwardsTimer -= 1;
    delay(100);
  
  }

 //checking if there is an obstacle some distance ahead of the robot
 else if(distance_cm < 20 && distance_cm >= 10){
  
  //making the left wheel turn backwards
  SensorValLeft = 0;

  //making the right wheel turn forwards
  SensorValRight = 0;

  //this causes the robot to turn left to avoid the obstacle



  //creating a tone with the buzzer
  tone(buzzer, 10000, 500);

  //turning the left light on and the right light off to signal that the robot is turning left
  digitalWrite(leftLight, HIGH);
  digitalWrite(rightLight, LOW);
  

  }

  //checking if there is an obstacle directly in front of the arduino
  else if(distance_cm < 10){
    
    //setting the backwards timer to 3 will cause the robot to go backwards for 3 seconds
    backwardsTimer = 3;

  }

  //if there are no obstacles in front of the arduino it will go forward
  else{
  
  //turning both lights on to signal that the robot is going forwards
  digitalWrite(leftLight, HIGH);
  digitalWrite(rightLight, HIGH);

  //turning the left wheel forwards
  SensorValLeft = 1000;

  //turning the right wheel forwards
  SensorValRight = 0;

  //stopping the buzzer from producing a tone
  noTone(buzzer);
    
  }



  }
  //if the robot is not turned on
  else{

  //keeping the left wheel still
  SensorValLeft = 545;

  //keeping the right wheel still
  SensorValRight = 545;

  }  
 
  //sending a signal to both servos 
  pos = map(SensorValLeft, 0, 1023, 0, 180);
  Servo1.write(pos);
  pos2 = map(SensorValRight, 0, 1023, 0, 180);
  Servo2.write(pos2);
  DutyCycle = -((PulseLength / pow(10,6)) / Period) * 100;
  
  //if the on button is pressed the robot will turn on
  if(digitalRead(button) == HIGH){

    on = !on;  

  }


}
