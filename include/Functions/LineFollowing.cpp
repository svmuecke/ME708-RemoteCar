#pragma once
#include <Arduino.h>
#include "../Components/MotorController.h"
#include "../Components/LineSensor.h"

int val_right;
int val_mid;
int val_left;


void line(){
    
}

void line_read(int period)
{
    LineSensor left;
    left.set(lineleftPin);
    LineSensor mid;
    mid.set(linemidPin);
    LineSensor right;
    right.set(linerightPin);
    lineleftState = left.read();
    Serial.println("Left");
    Serial.println(lineleftState);
    linemidState = mid.read();
    Serial.println("Mid");
    Serial.println(linemidState);
    linerightState = right.read();
    Serial.println("Right");
    Serial.println(linerightState);
    delay(period);
}