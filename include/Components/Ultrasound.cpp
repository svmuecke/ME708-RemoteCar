#pragma once

//Include external libaries
#include <Arduino.h>

//Static ultrasound
class staticUltra{
    public:
        float getDistance();
};

float staticUltra::getDistance()
{
    float echoTime; //var to store the time it takes for a ping to bounce back off an object
    float calculatedDistance; //var to store the distance calculated from the echo time

    //Sound out an ultrasonic pulse that's 10 m long
    digitalWrite(trigstatPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigstatPin,LOW);

    echoTime = pulseIn(echostatPin, HIGH); //Use the pulsein command to see how long it takes for the pulse to bounce back to the sensor

    calculatedDistance = echoTime / 148.0 ; //Calculate the distance of the object that reflected the pulse 

    return calculatedDistance; //Send back the calculated Distance
}







