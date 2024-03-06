#pragma once
#include <Arduino.h>
#include "../Components/MotorController.h"
#include "../Components/LineSensor.h"
#include "../Components/LED.h"
#include "../Components/IR.h"

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

void line(int period){
    while (IRstate != 10 && IRstate != 11){

        int position;

        LED yellow;
        yellow.set(yellowPin);      //Turn on status LED
        yellow.on();


        MotorController mc1;
        mc1.set_speed(50);

        line_read(0);
        calculate_proportion(0);

        if (rm < 0.8 && lm < 0.8 && 0.9<rl < 1.1){ //Line is on mid 
            mc1.forward();     
            Serial.println("Forward");
        }
        else if( rm > 1.4 && rl > 1.4 && 0.9<lm<1.1 ){ //Line is on right
            mc1.right();
            Serial.println("LightHard");
        }
        else if(lm > 1.3 && rl < 0.8 && 0.9<rm<1.1){ //Line is on left
            mc1.left();
            Serial.println("RightHard");
        }
        else if(0.9 <rm < 1.1  && lm < 0.85 && rl > 1.4){ //Line is between mid and right
            mc1.right45();
            Serial.println("LeftSoft");
        }
        else if(rm < 0.85 &&  0.9<lm<1.1 && rl < 0.85){//Line is between mid and left
            mc1.left45();
            Serial.println("LeftSoft");
        }

        else //no localisation
        {         
            //mc1.set_speed(30);
            mc1.forward();
            Serial.println("No localisation possible");
        }
        delay(period);
        mc1.stop();
        yellow.off();
        getData();
    }
    
   
}

