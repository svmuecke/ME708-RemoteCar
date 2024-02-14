#include <Arduino.h>
#include 'Servo.h'
#include <Servo.h> 

//Defining vars
//Define servo motor 
Servo myservo;
int servopin = 9; //White cable to control
int servodegree = 100;

//Defining own functions
float servo(servodegree)
{
    myservo.write(servo_degree); //move servo to x degrees
}

//Setup function
void setup(){
    //Setup servo motor
    myservo.attach(servopin); //tell teh servo object that its servo is plugged to servopin
}