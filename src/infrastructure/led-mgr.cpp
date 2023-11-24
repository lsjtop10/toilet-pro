#include <Arduino.h>
#include "led-mgr.h"

LEDMgr::LEDMgr()
{
    redPin = 3;
    yellowPin = 4;
    greenPin = 5;

    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void LEDMgr::Write(bool red, bool yellow, bool green)
{
    digitalWrite(redPin, red);
    digitalWrite(yellowPin, yellow);
    digitalWrite(greenPin, green);
}

LEDMgr::~LEDMgr()
{
    
}

