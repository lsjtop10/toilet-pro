#include "src/infrastructure/cover-sensor-mgr.h"
#include "src/infrastructure/level-sensor-mgr.h"
#include "src/infrastructure/led-mgr.h"
#include "src/infrastructure/motor-controller.h"

#define LED_R_PIN 3
#define LED_Y_PIN 4
#define LED_G_PIN 5
#define MOTOR_PWM_PIN 9
#define MOTOR_BREAK_PIN 10 
#define LEVEL_IN_PIN 6
#define TRIG_PIN 7
#define ECHO_PIN 8

LEDMgr led = LEDMgr(LED_R_PIN, LED_Y_PIN,LED_G_PIN);
LevelSensorMgr levelSensor = LevelSensorMgr(LEVEL_IN_PIN);
CoverSensorMgr coverSensor = CoverSensorMgr(TRIG_PIN, ECHO_PIN);
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
