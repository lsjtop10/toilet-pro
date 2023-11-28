#include <Arduino.h.>
#include "level-sensor-mgr.h"
#include "pins.h"

bool LevelSensorMgr::IsFull()
{
    return digitalRead(this->outPin) == HIGH;
}

LevelSensorMgr::LevelSensorMgr(/* args */)
{
    outPin = LEVEL_IN_PIN;
}

LevelSensorMgr::~LevelSensorMgr()
{
}
