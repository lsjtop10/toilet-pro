#include "src/infrastructure/cover-sensor-mgr.h"
#include "src/infrastructure/level-sensor-mgr.h"
#include "src/infrastructure/led-mgr.h"
#include "src/infrastructure/motor-controller.h"

LEDMgr led = LEDMgr();
LevelSensorMgr levelSensor = LevelSensorMgr();
CoverSensorMgr coverSensor = CoverSensorMgr();
MotorController motor = MotorController(0,255);

const int MotorEnableTime = 10*1000;

void setup()
{
    Serial.begin(9600);
}

//domain logic
void loop()
{
    if(!coverSensor.IsOpen() && levelSensor.IsFull())
    {
        delay(5*1000);

        if(!levelSensor.IsFull())
        {
            motor.On(100);
            delay(MotorEnableTime);
            motor.Off();
            led.Write(false,false,true);
        }
        else if(levelSensor.IsFull())
        {
            led.Write(true,false,false);
        }
    }
    else if(!coverSensor.IsOpen() && !levelSensor.IsFull())
    {
        led.Write(false,true,false);
    }
}
