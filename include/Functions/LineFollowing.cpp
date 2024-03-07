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

void check_lines(int period){
    while (IRstate != 10 && IRstate != 11){

        line_read(0);
        calculate_proportion(0);
        
        //define all white

        if (rm < 0.9 && lm < 0.9 && 0.9 < rl < 1.1){ //Line is on mid 
            Serial.println("Forward");
        }

         else if(0.9 < rm < 1.1  && lm < 0.9 && rl > 1.1 && linerightState > 800 && linemidState > 800){ //90° crossing with left turn
            Serial.println("Right_Crossing");
        }

        else if(rm < 0.9 &&  0.9<lm<1.1 && rl < 0.9 && lineleftState > 800 && linemidState > 800){//90° crossing with left turn
            Serial.println("Left_Crossing");
        }

        else if(0.9 <rm < 1.1  && lm < 0.9 && rl > 1.1){ //Line is between mid and right
            Serial.println("RightSoft");
        }

        else if(rm < 0.9 &&  0.9<lm<1.1 && rl < 0.9){//Line is between mid and left
            Serial.println("LeftSoft");
        }
        
        else if( rm > 1.25 && 0.9<lm<1.1 && rl > 1.25){ //Line is on right
            Serial.println("RightHard");
        }

        else if(0.9<rm<1.1 && lm> 1.1 && rl < 0.9){ //Line is on left
            Serial.println("LeftHard");
        }
        
    
        else //no localisation
        {         
            Serial.println("No localisation possible");
        }
        getData();
        delay(period);
        getData();

    }
}

void line(int period){
    int position;

    LED yellow;
    yellow.set(yellowPin);      //Turn on status LED
    yellow.on();


    MotorController mc1;
    mc1.set_speed(50);


    while (IRstate != 10 && IRstate != 11){

        line_read(0);
        calculate_proportion(0);

        if (rm < 0.9 && lm < 0.9 && 0.9 < rl < 1.1){ //Line is on mid 
            mc1.forward(); 
            Serial.println("Forward");
        }

       
        else if(0.9 < rm < 1.1  && lm < 0.9 && rl > 1.1 && linerightState > 830 && linemidState > 830){ //90° crossing with left turn
            mc1.righthard();
            delay(1000);
            mc1.backwards();
            delay(200);
            mc1.right();
            Serial.println("RightCrossing");
        }
        

        else if(rm < 0.9 &&  0.9<lm<1.1 && rl < 0.9 && lineleftState > 830 && linemidState > 830){//90° crossing with left turn
            mc1.lefthard();
            delay(1000);
            mc1.backwards();
            delay(200);
            mc1.left();
            Serial.println("LeftCrossing");
        }

        else if(0.9 < rm < 1.1  && lm < 0.9 && rl > 1.1){ //Line is between mid and right
            mc1.right45();
            Serial.println("RightSoft");

        }

        else if(rm < 0.9 &&  0.9<lm<1.1 && rl < 0.9){//Line is between mid and left
            mc1.left45();
            Serial.println("LeftSoft");
        }
        
        
        else if( rm > 1.25 && 0.9<lm<1.1 && rl > 1.25){ //Line is on right
            mc1.right();
            Serial.println("RightHard");
        }

        else if(0.9<rm<1.1 && lm> 1.1 && rl < 0.9){ //Line is on left
            mc1.left();
            Serial.println("LeftHard");
        }
        

        else //no localisation
        {   
            mc1.forward();
            //delay(50);
            Serial.println("No localisation possible");
        }
    
        delay(period);
        getData();
    }

    mc1.stop();
    yellow.off();
   
}

