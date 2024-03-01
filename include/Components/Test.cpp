#pragma once

//Include external libaries
#include <Arduino.h>


class ControllerTest{
  public:
	void start();
	void stop();
};


void ControllerTest::start()
{
	digitalWrite(AIN1, HIGH);
	digitalWrite(AIN2, LOW);
	analogWrite(PWMA, 255);
}

void ControllerTest::stop()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, LOW);
	analogWrite(PWMA,255);
}

void test()
{
    MotorController mc;
    mc.forward();
    delay(1000);
    mc.backwards();
    delay(1000);
}

void Ledbuiltin()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}

