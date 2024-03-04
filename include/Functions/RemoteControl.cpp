#pragma once
#include <Arduino.h>
#include "../Components/MotorController.cpp"
#include "../Components/LED.h"
#include "../Components/IR.h"



void remote()
{
  MotorController mc;
  while(IRstate != 6)
  {
    getData();
    IRstate = 5;
    switch (IRstate)
    {
    case 5:
      mc.forward();
      break;
    
    case 11:
      mc.backwards();
      break;

    case 7:
      mc.left();
      break;

    default:
      break;
    }
    delay(refresh_remote);
    getData();
    IRstate = 6;
  }
  mc.stop();
    
}

void testdrive(){
  MotorController mc1;
  mc1.set_speed(200);
  mc1.right45();
  delay(5000);
  mc1.left45();
  delay(5000);
}
