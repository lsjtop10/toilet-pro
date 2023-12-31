#include <Arduino.h.>
#include "level-sensor-mgr.h"


bool LevelSensorMgr::IsFull()
{
    return digitalRead(this->outPin) == HIGH;
}

LevelSensorMgr::LevelSensorMgr(int outPin)
{
    this->outPin = outPin;
}

LevelSensorMgr::~LevelSensorMgr()
{
}
