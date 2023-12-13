#include <Arduino.h>
#include "cover-sensor-mgr.h"
#include "../debug.h"

CoverSensorMgr::CoverSensorMgr(int trigPin, int echoPin)
{
    this->trigPin = trigPin;
    this->echoPin = echoPin;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

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
    distance = ((340 * duration) / 10000) / 2; 

    debug(Serial.println(distance));

    if(distance < threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}


CoverSensorMgr::~CoverSensorMgr()
{
}
