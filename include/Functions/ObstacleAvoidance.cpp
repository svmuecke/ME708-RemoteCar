#pragma once
#include <Arduino.h>
#include "../Components/MotorController.h"
#include "../Components/Ultrasound.h"
#include "../Components/Servo.h"
#include "../Components/IR.h"


float distance_static;
float distance_rot;
float mean_left = 0;
float mean_right = 0;


void stat_read(int period)
{
    Ultrasound staticUltra;
    staticUltra.set(echostatPin,trigstatPin);

    distance_static = staticUltra.getDistance();
    Serial.println("Static");
    Serial.println(distance_static);
    delay(period);
}


void rot_read(int period, int start, int end, int turnrate) //turnrate = ° per measurement
{

    mean_left = 0;
    mean_right = 0;

    int leng = (abs(end - start))/turnrate +1;
    //Serial.print("Länge");
    //Serial.println(leng);
    float dist[leng];

    Ultrasound rotUltra;
    rotUltra.set(echorotPin,trigrotPin);

    servosound.write(start);

    if (start < end){
        for (int i=0; i< leng; i++){
            //Serial.println(i);
            servosound.write(start+i*turnrate);

            distance_rot = rotUltra.getDistance();
            dist[i] = distance_rot;

            if (i<(0.5*leng)){
                mean_left = mean_left + dist[i];  //Calc accumulated distance on left side#
                //Serial.println(dist[i]);
            }
            else{
                mean_right = mean_right + dist[i];
                //Serial.println(dist[i]);
            }
            delay(period);
        }
    }
    else{
        for (int i=0; i< leng; i++){
            //Serial.println(i);
            servosound.write(start-i*turnrate);
            distance_rot = rotUltra.getDistance();
            dist[i] = distance_rot;

            if (i<(0.5*leng)){
                mean_right = mean_right + dist[i];  //Calc accumulated distance on left side#
                //Serial.println(dist[i]);
            }
            else{
                mean_left = mean_left + dist[i];
                //Serial.println(dist[i]);
            }
            delay(period);
        }
    }

    mean_right = mean_right /leng*2; //calculate average
    mean_left = mean_left / leng*2;

    //Serial.print("Right:");
    //Serial.println(mean_right);
    //Serial.print("Left:");
    //Serial.println(mean_left);

}

void calibrate(int pos){
    servosound.write(pos);
}





void obstacle_single(int period, int safety,int turning){

    //while (IR){}
    LED red;
    red.set(redPin);      //Turn on status LED
    red.on();

    MotorController mc;
    //mc1.set_speed(150);

    stat_read(0);
    if (turning == 0){
        rot_read(100,50,130,10);
    }
    else{
        rot_read(100,130,50,10);
    }
    Serial.print("Static:");
    Serial.println(distance_static);
    Serial.print("Left:");
    Serial.println(mean_left);
    Serial.print("Right:");
    Serial.println(mean_right);

    if (distance_static > safety && mean_left > safety && mean_right > safety) //No obstacle
    {  
        mc.forward();
        Serial.println("No obstacle");
    }

    else if (distance_static < safety && mean_left > safety && mean_right < safety) //Obtstacle on right-middle
    {
        mc.left();
        Serial.println("Obstacle right middle");
    }

    else if (distance_static < safety && mean_left < safety && mean_right > safety) //Obtstacle on left-middle
    {
        mc.right();
        Serial.println("Obstacle left middle");
    }

    else if (distance_static < safety && mean_left  < safety && mean_right < safety) //Obstacle direct in front
    {                               
        mc.left();
        Serial.println("Obstacle direct in front");
    }

    else if (distance_static < safety && mean_left  > safety && mean_right > safety) //No recogniziton from rotating
    {                               
        mc.left();
        Serial.println("No recogniziton from rotating");
    }
    else{
        mc.backwards();
        Serial.println("Error");
    }
    mc.stop();
    red.off();
    delay(period);
}


void obstacle(int period, int safety){
    while (IRstate != 10 && IRstate != 11){
        obstacle_single(period,safety,0);
        obstacle_single(period,safety,1);
        getData();
        Serial.println(IRstate);
    }

}