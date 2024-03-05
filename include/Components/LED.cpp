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



void all_blinking(int duration, int repeats)
{
   LED yellow;
  yellow.set(yellowPin);
  LED red;
  red.set(redPin);
  LED green2;
  green2.set(green2Pin);
  red.on();
  for (int i = 1; i<= repeats; i++)
  {
    red.on();
    yellow.on();
    green2.on();
    delay(duration);
    red.off();
    yellow.off();
    green2.off();
    delay(duration);
  }
}

void all_on()
{
   LED yellow;
  yellow.set(yellowPin);
  LED red;
  red.set(redPin);
  red.on();
  yellow.on();
}

void all_off()
{
   LED yellow;
  yellow.set(yellowPin);
  LED red;
  red.set(redPin);
  red.off();
  yellow.off();
}