#pragma once
//Include external libaries
#include <Arduino.h>



void getData(){
  
  if(irDecoder.dataAvailable(irData)) 
  {
    int IRstate = irData.cmd;
  }
}





