#include <Arduino.h>
#include "led-mgr.h"
#include "pins.h"

LEDMgr::LEDMgr()
{
    redPin = LED_R_PIN;
    yellowPin = LED_R_PIN;
    greenPin = LED_G_PIN;

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

