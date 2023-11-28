#include <Arduino.h>
#include "cover-sensor-mgr.h"
#include "pins.h"

void CoverSensorMgr::emitTrigger()
{
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
}

bool CoverSensorMgr::IsOpen()
{
    long duration, distance;

    emitTrigger();

    duration = pulseIn (echoPin, HIGH);
    distance = duration * 17 / 1000; 

    if(distance > 20)
    {
        return true;
    }
    else
    {
        return false;
    }
}

CoverSensorMgr::CoverSensorMgr()
{
    this->trigPin = TRIG_PIN;
    this->echoPin = ECHO_PIN;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

CoverSensorMgr::~CoverSensorMgr()
{
}
