#pragma once
//Include external libaries
#include <Arduino.h>


class LineSensor{
  public:
  int pin;
  void set(int senspin);
};

void LineSensor::set(int senspin){
  pin = senspin;
}