//Inlude external libaries
#include <Arduino.h>
#include 'MotorController.h'


class motorcontroller {
public:
float x, y;
void print() {Serial.println(x); Serial.println(y);}
void set(float u, float v) {x = u; y = v;}
};

class MotorController{
  public:
  	int motorspeed;
  	void forward(int speed);
  	void right(int speed);
  	void left(int speed);
    void right45();
    void left45();
  	void setspeed(int speed);
};

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




