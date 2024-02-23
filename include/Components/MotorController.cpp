//Include external libaries
#include <Arduino.h>

class MotorController{
  public:
  	void forward(int speed);
	void backwards(int speed);
  	void right(int speedturn);
  	void left(int speedturn);
	void right45(int speedturn);
	void left45(int speedturn);
};

//Forwards
void MotorController::forward(int speed)
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speed);
  	analogWrite(PWMB, speed);
}

//Backwards
void MotorController::backwards(int speed)
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speed);
  	analogWrite(PWMB, speed);
}

//Turn left on spot
void MotorController::right(int speedturn)
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2,LOW);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn);
}

//Turn left while continuing forward driving
void MotorController::right45(int speedturn)
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2,LOW);
  	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, HIGH);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn);
}
//Turn right on spot
void MotorController::left(int speedturn)
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn);
}

//Turn right while continuing forward driving
void MotorController::left45(int speedturn)
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, HIGH);
  	digitalWrite(BIN1, HIGH);
	digitalWrite(BIN2, LOW);
	analogWrite(PWMA, speedturn);
  	analogWrite(PWMB, speedturn);
}
