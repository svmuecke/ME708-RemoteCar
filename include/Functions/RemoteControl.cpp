#pragma once
#include <Arduino.h>
#include "../Components/MotorController.cpp"
#include "../Components/LED.h"
//Vars to control components
int speed = 100;
int speedturn = 50;


void test()
{
    MotorController mc;
    mc.forward(speedturn);
    delay(1000);
    mc.backwards(speedturn);
    delay(1000);
}


void licht()
{
    LED testleuchte;
    testleuchte.blinkenextern();
}