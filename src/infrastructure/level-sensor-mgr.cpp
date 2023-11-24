#include <Arduino.h.>
#include "level-sensor-mgr.h"

bool LevelSensorMgr::IsFull()
{
    return digitalRead(this->outPin) == HIGH;
}

LevelSensorMgr::LevelSensorMgr(/* args */)
{
    outPin = 6;
}

LevelSensorMgr::~LevelSensorMgr()
{
}
