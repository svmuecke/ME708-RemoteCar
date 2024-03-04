#pragma once
//Include external libaries
#include <Arduino.h>


class LineSensor
{
  public:
  int pin;
  int state;
  void set(int senspin);
  int read();
};

void LineSensor::set(int senspin)
{
  pin = senspin;
}

int LineSensor::read()
{
  state = analogRead(pin);
  return state;
}