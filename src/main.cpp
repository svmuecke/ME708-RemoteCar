//Remote-Car
//Marma, Kyamra; Vaitkune, Simona; Siemens, Seth Henry; Mücke, Sven
//Date: 02/07/2024
//Version: V1

//Inlude external libaries
#include <Arduino.h>
#include <Servo.h>


//Defining vars
//Vars for motor controller
int AIN1 = 4;
int AIN2 = 5;
int PWMA = 3;
int BIN1 = 7;
int BIN2 = 8;
int PWMB = 6;

//Vars vor servo motors
int servosoundPin = 10;
int servopickPin = 9;
Servo servosound;
Servo servopick;

//Vars for ultrasound sensors
int echorotPin = 12;
int trigrotPin = 13;
int echostatPin = 1;
int trigstatPin = 2;

//Vars for linesensors
int lineleftPin = A3;
int linemidPin = A4;
int linerightPin = A5;
int lineleftState;
int linemidState;
int linerightState;

//Vars for ir-receiver
int irPin = 13;
int irState;

//Vars for LEDs
int redPin = A0;
int greenPin = A1;
int bluePin = A2;
int yellowPin = 0;
int LEDtest = 13;

//Include selfwritten functions/components

#include "Functions/RemoteControl.cpp"
//#include "Functions/LineFollowing.cpp"
//#include "Functions/ObstacleAvoidance.cpp"
#include "Components/IR.cpp"
#include "Components/LED.cpp"

void setup()
{
  //Motor controller pins as output
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(PWMB,OUTPUT);

  //Servo motor pins as output
  servosound.attach(servosoundPin);
  servopick.attach(servopickPin);

  //Ultrasound
  pinMode(echorotPin,INPUT);
  pinMode(trigrotPin,OUTPUT);
  pinMode(echostatPin,INPUT);
  pinMode(trigstatPin,OUTPUT);

  //IR pin as input
  pinMode(irPin,INPUT);

  //LED pins as output
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(yellowPin,OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDtest,OUTPUT);
}


//Loop function   
void loop()
{
  test();
}


