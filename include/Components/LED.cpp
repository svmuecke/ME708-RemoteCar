//Include external libaries

#include <Arduino.h>
#include "Components/LED.h"


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
  delay(2000);
  digitalWrite(LEDtest,LOW);
  delay(2000);
}