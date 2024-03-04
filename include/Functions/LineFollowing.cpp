#pragma once
#include <Arduino.h>
#include "../Components/MotorController.h"
#include "../Components/LineSensor.h"
#include "../Components/LED.h"

float rm;
float lm;
float rl;





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

void calculate_proportion(int duration){

    rm = linerightState / linemidState;
    lm = lineleftState / linemidState;
    rl = linerightState / lineleftState;
    Serial.print("RM: ");
    Serial.println(rm);
    Serial.print("LM: ");
    Serial.println(lm);
    Serial.print("RL: ");
    Serial.println(rl);
    delay(duration);
}

void line(){
    int position;
    LED green1;
    green1.set(green1Pin);      //Turn on status LED
    green1.on();
    MotorController mc1;
    mc1.set_speed(150);

    line_read(0);
    calculate_proportion(0);

    if (rm < 0.7 && lm < 0.7){ //Line is on mid 
        mc1.forward();     
        Serial.println("Forward");
    }
    else if( rm > 1.2 && rl > 1.2 ){ //Line is on right
        mc1.right();
        Serial.println("RightHard");
    }
    //else if(lm > 1.2 && rl < 0.8){ //Line is on left
    //    mc1.left();
    //    Serial.println("LeftHard");
    //}
    //else if(rm > 0.9 && rl > 1.0){ //Line is between mid and right
    //    mc1.right45();
    //    Serial.println("RightSoft");
    //}
    //else if(lm > 1.2 && rl < 0.8) //Line is between mid and left
    //    mc1.left45();
    //    Serial.println("LeftSoft");
    //}
    else //no localisation
    {         
        mc1.set_speed(150);
        mc1.forward();
        Serial.println("No localisation possible");
    }
    delay(5000);
    mc1.stop();
}