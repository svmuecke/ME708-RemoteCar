#pragma once
//Include external libaries
#include <Arduino.h>



void getData(){
  if(irDecoder.dataAvailable(irData)) 
  {
    int pressedbutton = irData.cmd;

    if (pressedbutton == 69){
      IRstate = 1;
    }
    else if(pressedbutton ==70){
      IRstate = 2;
    }
    else if(pressedbutton ==71){
      IRstate = 3;
    }
    else if(pressedbutton ==68){
      IRstate = 4;
    }
    else if(pressedbutton ==64){
      IRstate = 5;
    }
    else if(pressedbutton ==67){
      IRstate =62;
    }
    else if(pressedbutton ==7){
      IRstate = 7;
    }
    else if(pressedbutton ==21){
      IRstate = 8;
    }
    else if(pressedbutton ==9){
      IRstate = 9;
    }
    else if(pressedbutton ==22){
      IRstate = 10;
    }
    else if(pressedbutton ==25){
      IRstate = 0;
    }
    else if(pressedbutton ==13){
      IRstate = 11;
    }
    else if(pressedbutton ==24){
      IRstate = 20;
    }
    else if(pressedbutton ==82){
      IRstate = 21;
    }
    else if(pressedbutton ==90){
      IRstate = 22;
    }
    else if(pressedbutton ==8){
      IRstate = 23;
    }
    else if(pressedbutton ==28){
      IRstate = 12;
    }
    else {  //Error State
      IRstate = 99;
    }
  }
}





