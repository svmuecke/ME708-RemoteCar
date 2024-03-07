#pragma once
#include <Arduino.h>
#include "../Components/MotorController.cpp"
#include "../Components/LED.h"
#include "../Components/IR.h"



void remote(int refresh_remote)
{
  MotorController mc;
  mc.set_speed(120);
  LED red;
  red.set(redPin);
  red.on();

  getData();

  while(IRstate != 10 && IRstate != 11)  //IRstate != 11)
  {
    if (IRstate == 20){
      mc.forward();
      Serial.println("Forward");
    }

    else if (IRstate ==21){
        mc.backwards();
        Serial.println("Backwards");
    }
    else if (IRstate == 22){
      mc.right();
      Serial.println("Right");
    }
    else if(IRstate ==23){
      mc.left45();
      Serial.println("Left");
    }
    else if(IRstate ==12){
      mc.stop();
      Serial.println("Stop");
    }
  
    delay(refresh_remote);
    getData();
  }
  mc.stop();
  red.off();
}

void testdrive(){
  MotorController mc1;
  mc1.set_speed(50);
  mc1.right();
  delay(5000);
}

