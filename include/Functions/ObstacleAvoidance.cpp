#pragma once
#include <Arduino.h>
#include "../Components/MotorController.h"
#include "../Components/Ultrasound.h"
#include "../Components/Servo.h"


float distance_static;

void obstacle(){
    
}

void ultra_read(int period)
{
    Ultrasound staticUltra;
    staticUltra.set(echostatPin,trigstatPin);

    Ultrasound rotUltra;
    rotUltra.set(echorotPin,trigrotPin);

    distancestat = staticUltra.getDistance();
    Serial.println("Static");
    Serial.println(distancestat);

    distancerot = rotUltra.getDistance();
    Serial.println("Rotatory");
    Serial.println(distancerot);
    
    delay(period);
}