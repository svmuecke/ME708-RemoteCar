//Include external libaries
#include <Arduino.h>


class MotorController{
  public:
	void start();
	void stop();
};


void MotorController::start()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
	analogWrite(PWMA, 100);
}

void MotorController::stop()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, LOW);
	analogWrite(PWMA,0);
}