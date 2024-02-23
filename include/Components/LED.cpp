#pragma once

//Include external libaries
#include <Arduino.h>


class LED{
  public:
    void blinkenintern();
    void blinkenextern();
};

void LED::blinkenintern()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void LED::blinkenextern()
{
  digitalWrite(LEDtest,HIGH);
  delay(500);
  digitalWrite(LEDtest,LOW);
  delay(500);
}