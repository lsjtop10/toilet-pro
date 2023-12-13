#include "src/infrastructure/cover-sensor-mgr.h"
#include "src/infrastructure/level-sensor-mgr.h"
#include "src/infrastructure/led-mgr.h"
#include "src/infrastructure/motor-controller.h"
#include "src/debug.h"

#define LED_R_PIN 3
#define LED_Y_PIN 4
#define LED_G_PIN 5
#define MOTOR_PWM_PIN 10
#define MOTOR_BREAK_PIN 9 
#define LEVEL_IN_PIN 6
#define TRIG_PIN 7
#define ECHO_PIN 8

LEDMgr led = LEDMgr(LED_R_PIN, LED_Y_PIN, LED_G_PIN);
LevelSensorMgr levelSensor = LevelSensorMgr(LEVEL_IN_PIN);
CoverSensorMgr coverSensor = CoverSensorMgr(TRIG_PIN, ECHO_PIN);
MotorController motor = MotorController(MOTOR_PWM_PIN, MOTOR_BREAK_PIN);

const int MotorEnableTime = (int)2.5*1000;

void testLevelSensor();
void testCoverSensor();
void testLEDs();

void setup()
{
    debug(Serial.begin(9600));
    pinMode(13,OUTPUT);

    digitalWrite(13, LOW);
}

// test logics
void testMotor()
{
    //motor.Off();

    digitalWrite(13, HIGH);
    motor.On(100);
    delay(5000);

    digitalWrite(13, LOW);
    motor.Off();
    delay(2000);
}

void testLevelSensor()
{
    digitalWrite(13,LOW);

    if(levelSensor.IsFull())
    {
        digitalWrite(13,HIGH);
        delay(500);
    }
}

void testCoverSensor()
{
    digitalWrite(13,LOW);

    if(coverSensor.IsOpen())
    {
        digitalWrite(13,HIGH);
    }
    delay(1000);
}

void testLEDs()
{
    led.Off();
    led.Write(true,false,false);
    delay(1000);
    led.Write(false,true,false);
    delay(1000);
    led.Write(false,false,true);
    delay(1000);
}


//domain logic
void loop()
{   

#ifndef DEBUG
    if(!coverSensor.IsOpen() && levelSensor.IsFull())
    {
        delay(2500);

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
    else if(coverSensor.IsOpen() && !levelSensor.IsFull())
    {
        led.Write(false,false,true);
    }
#else
//테스트 로직 기술하는 부분
testMotor();
#endif
}
