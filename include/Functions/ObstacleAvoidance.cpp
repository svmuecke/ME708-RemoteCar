#pragma once
#include <Arduino.h>
#include "../Components/MotorController.h"
#include "../Components/Ultrasound.h"
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
    //Serial.println("Static");
    //Serial.println(distance_static);
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
                Serial.println(dist[i]);
            }
            else{
                mean_left = mean_left + dist[i];
                Serial.println(dist[i]);
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


void obstacle(int period, int safety){
    LED red;
    red.set(redPin);      //Turn on status LED
    red.on();

    MotorController mc;


    mc.set_speed(50);

    while (IRstate != 10 && IRstate != 11){

    stat_read(0);

    rot_read(140,70,110,10);
    
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


    stat_read(0);
    rot_read(140,110,70,10);

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

    getData();

    }

    mc.stop();
    red.off();
}


void obstacle2(int period, int safety){
    LED red;
    red.set(redPin);      //Turn on status LED
    red.on();

    MotorController mc;


    mc.set_speed(70);

    while (IRstate != 10 && IRstate != 11){

    stat_read(0);

    rot_read(60,55,125,10);

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

    else if (distance_static < safety && mean_left  < safety && mean_right < safety) //Obstacle direct in front
    {                               
        mc.left();
        Serial.println("Obstacle direct in front");
    }

    else if (distance_static < safety && mean_left  > safety && mean_right < safety) //Obstacle direct in front
    {                               
        mc.left();
        Serial.println("Obstacle direct in front");
    }

    else if (distance_static > safety && mean_left  > safety && mean_right < safety) //Obstacle on far right
    {                               
        mc.left45();
        Serial.println("Obstacle on far right");
    }

    else if (distance_static > safety && mean_left  <  safety && mean_right > safety) //Obstacle on far left
    {                               
        mc.right45();
        Serial.println("Obstacle on far left");
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

    else if (distance_static > safety && mean_left < safety && mean_right < safety) //Obtstacle in front, but no recognition by static
    {
        if (mean_left > mean_right){
            mc.left();
            Serial.println("Obtstacle in front, but no recognition by static, go left");
        }
        else {
            mc.right();
            Serial.println("Obtstacle in front, but no recognition by static, go right");
        }
        }

    else if (distance_static < safety && mean_left > safety && mean_right > safety) //Obtstacle in front, but no recognition by rotr
    {
        if (mean_left > mean_right){
            mc.left();
            Serial.println("Obtstacle in front, but no recognition by rot, go left");
        }
        else {
            mc.right();
            Serial.println("Obtstacle in front, but no recognition by rot, go right");
        }
        }

    else if (distance_static == 0 || mean_left  == 0 || mean_right == 0) //Sensor Error
    {                               
        mc.stop();
        Serial.println("Sensor Error");
    }

    else{
        mc.backwards();
        Serial.println("No use case defined, backwards");
    }

    getData();

    }

    mc.stop();
    red.off();
}
