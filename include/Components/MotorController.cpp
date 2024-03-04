#pragma once
//Include external libaries
#pragma once
#include <Arduino.h>


class MotorController{
  public:
	int speed = 100;
	int speedturn = 50;
	void set_speed(int motorspeed);
  	void forward();
	void stop();
	void backwards();
  	void right();
  	void left();
	void right45();
	void left45();
};

void MotorController::set_speed(int motorspeed)
{
	speed = motorspeed;
	speedturn = motorspeed; //original *0.5
}

//Forwards
void MotorController::forward()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speed);
  	analogWrite(PWMB, speed);
}

void MotorController::stop()
{ 
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, 0);
  	analogWrite(PWMB, 0);
}
//Backwards
void MotorController::backwards()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speed);
  	analogWrite(PWMB, speed);
}

//Turn left on spot
void MotorController::right()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2,LOW);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn);
}

//Turn left while continuing forward driving
void MotorController::right45()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2,LOW);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, 0.5*speedturn);
}
//Turn right on spot
void MotorController::left()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn);
}

//Turn right while continuing forward driving
void MotorController::left45()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, 0.5*speedturn);
  	analogWrite(PWMB, speedturn);
}
