#include <Arduino.h>
#include "../Components/MotorControllertest.cpp"

void test()
{
    MotorController mc;
    mc.start();
    delay(1000);
    mc.stop();
    delay(1000);
}