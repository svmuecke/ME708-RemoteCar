#pragma once
//Include external libaries
#pragma once
#include <Arduino.h>
#include <Servo.h>


class MotorController{
  public:
	int speed = 50;
	int speedturn = 70;
	void set_speed(int motorspeed);
  	void forward();
	void stop();
	void backwards();
  	void right();
	void righthard();
  	void left();
	void lefthard();
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
	servorear.write(90);
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
	servorear.write(92);
}

//Turn left on spot
void MotorController::right()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2,LOW);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, 1.5*speedturn);
  	analogWrite(PWMB, speedturn);
	servorear.write(150);
}

//Turn left on spot
void MotorController::righthard()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2,LOW);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn);
	servorear.write(160);
}

//Turn left while continuing forward driving
void MotorController::right45()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2,LOW);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn *0.5);
	servorear.write(130);
}
//Turn right on spot
void MotorController::left()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn*1.5);
	servorear.write(30);
}

//Turn right on spot
void MotorController::lefthard()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn);
	servorear.write(30);
}
//Turn right while continuing forward driving
void MotorController::left45()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speedturn*0.5);
  	analogWrite(PWMB, speedturn);
	servorear.write(50);
}

void test_servo(){
	MotorController mc;
	mc.forward();
	delay(2000);

}