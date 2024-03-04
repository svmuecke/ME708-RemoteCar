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
int servopickPin = 9;
Servo servosound;
Servo servopick;

//Vars for ultrasound sensors
int echorotPin = 12;
int trigrotPin = 13;
int echostatPin = A0;
int trigstatPin = 11;
float distancestat;
float distancerot;

//Vars for linesensors
int lineleftPin = A3; //in driving direction
int linemidPin = A4;
int linerightPin = A5; //black cable
int lineleftState;
int linemidState;
int linerightState;

//Vars for ir-receiver
int IRpin = 2;
IRsmallDecoder irDecoder(IRpin);
irSmallD_t irData;
int IRstate;

//Vars for LEDs
int redPin = 1;
int green2Pin = 0;
int green1Pin = A2;
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
  servopick.attach(servopickPin);

  //Ultrasound
  pinMode(echorotPin,INPUT);
  pinMode(trigrotPin,OUTPUT);
  pinMode(echostatPin,INPUT);
  pinMode(trigstatPin,OUTPUT);

  //IR pin as input
  //pinMode(irPin,INPUT);

  //LED pins as output
  pinMode(redPin,OUTPUT);
  pinMode(green1Pin,OUTPUT);
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

//Loop function   

  //test();
  //Ledbuiltin();
  //Serial.println('1');
  //MotorController mc;
  //Serial.println('2');
  //mc.forward();
  //delay(1000);
  //Serial.println('3');
  //mc.backwards(100);
  //delay(1000);

  //if(irDecoder.dataAvailable(irData)){
  //  int x = irData.cmd;
  //  Serial.println(x);
  //  if (x==26)Serial.println('The key is 9');
  //}


void blinken(){
  all_blinking(300,5);
}

void loop(){
  if(irDecoder.dataAvailable(irData)){
    Serial.println('angekommen');
    int x = irData.cmd;
    Serial.println(x);
    if (x==26)Serial.println('The key is 9');
  }
}



void test2()
{
  startup();
  getData();
  IRstate = 13;
    switch (IRstate)
    {
    case 13:
      remote();
      break;
    
    case 14:
      //line();
      break;

    case 15:
    obstacle();
      break;

    default:
      break;
    }
}




  
  //staticUltra ultra;
  //int i = ultra.getDistance();
  //Serial.println(i);
  //delay(1000);

  ///Startupsequence: all LEDS blink for 3s
  ///...

  //Read IRButton
  //irState = ...;

    ///Choose Mode: 1-Line 2- Obstacle 3- Remote 
  //switch (irState){
    //case 1: //Remote
      //remote();
      //break;

    //case 2: //Obstacle
      //obstacle();
      //break;

    //case 3: //LineFollowing
      //linefollowing();
      //break;
  //}

  ///Stop Everything when pushing Stop/Mode or Off Switch -> How implementation?
  ///New Choice






