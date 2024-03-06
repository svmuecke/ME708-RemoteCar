//Remote-Car
//Marma, Kyamra; Vaitkune, Simona; Siemens, Seth Henry; Mücke, Sven
//Date: 02/07/2024
//Version: V1

//Inlude external libaries
#include <Arduino.h>
#include <Servo.h>
#define IR_SMALLD_NEC
#include <IRsmallDecoder.h>

using namespace std;


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
int servorearPin = A2;
Servo servosound;
Servo servorear;

//Vars for ultrasound sensors
int echorotPin = 12;//grün
int trigrotPin = 13;//blau
int echostatPin = A0;
int trigstatPin = 11;
float distancestat;
float distancerot;

//Vars for linesensors
int lineleftPin = A3; //in driving direction
int linemidPin = A4;
int linerightPin = A5; //black cable
float lineleftState;
float linemidState;
float linerightState;

//Vars for ir-receiver
int IRpin = 2;
IRsmallDecoder irDecoder(IRpin);
irSmallD_t irData;
int IRstate =40;

//Vars for LEDs
int redPin = 9;
//int green1Pin = A2;
int green2Pin = 0;
int yellowPin = A1;

//Delete later
int LEDtest = 10;

//Refresh rates
int refresh_remote = 3000;


void setup()
{
  //Start Serial Monitor
  Serial.begin(9600);
  Serial.println("Waiting for a NEC remote control IR signal...");
  Serial.println("cmd");

  //Motor controller pins as output
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(PWMB,OUTPUT);

  //Servo motor pins as output
  servosound.attach(servosoundPin);
  servorear.attach(servorearPin);

  //Ultrasound
  pinMode(echorotPin,INPUT);
  pinMode(trigrotPin,OUTPUT);
  pinMode(echostatPin,INPUT);
  pinMode(trigstatPin,OUTPUT);

  //IR pin as input
  //pinMode(irPin,INPUT);

  //LED pins as output
  pinMode(redPin,OUTPUT);
  //pinMode(green1Pin,OUTPUT);
  pinMode(green2Pin,OUTPUT);
  pinMode(yellowPin,OUTPUT);

  //Just for Testing
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDtest,OUTPUT);
}

//Include selfwritten functions/components
#include "Functions/RemoteControl.h"
#include "Functions/LineFollowing.h"
#include "Functions/ObstacleAvoidance.h"
#include "Components/IR.h"
#include "Components/LED.h"
#include "Components/Test.h"

void loop()
{
  all_blinking(500,3);
  all_on();
  IRstate = 40;
  while (IRstate == 40) 
  {
    getData();
    Serial.println("waiting for data");
  }
  all_off();
  switch(IRstate) {

    case 1: //Remote
      Serial.println("remote was choosen");
      remote(100);
      break;

    case 2: //Obstacle
      obstacle(10,15);
      Serial.println("obstacle was choosen");
      break;

    case 3: //Line following
      line(100);
      Serial.println("line was choosen");
      break;
  }
  IRstate = 40;
}













