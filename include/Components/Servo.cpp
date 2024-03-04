#pragma once

//wird nicht benutzt


//Include external libaries
#include <Arduino.h>
#include <Servo.h>


class UltraServo{
  public:
    
    void positioning(int angle, Servo servo);
};

void UltraServo::positioning(int angle, Servo servo){
  servo.write(angle);
}