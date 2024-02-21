//Include external libaries
#include <Arduino.h>
#include "Components.h"


void MotorController::forward(int speed = 100)
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speed);
  	analogWrite(PWMB, speed);
}

//Turn left
void MotorController::right(int speed = 100)
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2,LOW);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speed);
  	analogWrite(PWMB, speed);
}

//Turn right
void MotorController::left(int speed = 100)
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speed);
  	analogWrite(PWMB, speed);
}




void loop(){
	MotorController mc;
}