//Include external libaries
#include <Arduino.h>

//Defining vars

//Define ultrasound 
int tripPin = 12;
int echoPin = 13;

//Defining own functions
float getDistance()
{
    float echoTime; //var to store the time it takes for a ping to bounce back off an object
    float calculatedDistance; //var to store the distance calculated from the echo time

    //Sound out an ultrasonic pulse that's 10 m long
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);

    echoTime = pulseIN(echoPin, HIGH); //Use the pulsein command to see how long it takes for the pulse to bounce back to the sensor

    calculatedDistance = echoTime / 148.0 ; //Calculate the distance of the object that reflected the pulse 

    return calculatedDistance; //Send back the calculated Distance
}

//Setup function
void setup(){
    //Setup ultrasound
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
}





