//Include external libaries
#include <Arduino.h>

void blinkenintern(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void blinkenextern(){
  digitalWrite(LEDtest,HIGH);
  delay(500);
  digitalWrite(LEDtest,LOW);
  delay(500);
}