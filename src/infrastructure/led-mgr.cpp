#include <Arduino.h>
#include "led-mgr.h"
#include "pins.h"

LEDMgr::LEDMgr(int redPin, int yellowPin, int greenPin)
{
    this->redPin = redPin;
    this->yellowPin = yellowPin;
    this->greenPin = greenPin;

    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void LEDMgr::Off()
{
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
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

