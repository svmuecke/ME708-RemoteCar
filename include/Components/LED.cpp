#pragma once

//Include external libaries
#include <Arduino.h>


class LED{
  public:
    int pin;
    void set(int senspin);
    void on();
    void off();
    void onoff(int duration);
};

void LED::set(int senspin){
  pin = senspin;
}

void LED::on(){
  digitalWrite(pin,HIGH);
}

void LED::off(){
  digitalWrite(pin,LOW);
}
void LED::onoff(int duration = 1000)
{
  digitalWrite(pin,HIGH);
  delay(duration);
  digitalWrite(pin,LOW);
}

void startup(){
  LED yellow;
  yellow.set(yellowPin);
  LED red;
  red.set(redPin);
  LED green1;
  green1.set(green1Pin);
  LED green2;
  green2.set(green2Pin);
  for (int i = 1; i<4; i++)
    red.on();
    yellow.on();
    green1.on();
    green2.on();
    delay(500);
    red.off();
    yellow.off();
    green1.off();
    green2.off();
    delay(500);
}