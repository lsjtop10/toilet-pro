#include <Arduino.h>
#include <TimerOne.h>
#include <MsTimer2.h>
#include "motor-controller.h"


MotorController::MotorController(int pwmPin, int breakPin)
{

    pwmPin = pwmPin;
    brakePin = breakPin;
    slope = 8;

    limit = 50;

    pinMode(pwmPin, OUTPUT);
    pinMode(brakePin, OUTPUT);

    //Brake
    pinMode(brakePin, OUTPUT); //Brake, Output
    digitalWrite(brakePin, LOW); //Brake, '0'

    //PWM
    Timer1.initialize(); //Timer1
    Timer1.pwm(pwmPin, 0); //PWM, Duty 0%
    Timer1.setPeriod(50); //PWM period 20kHz
    Timer1.setPwmDuty(pwmPin, 0); //PWM, Duty 0%

}

MotorController::~MotorController()
{

}

void MotorController::flash()
{
    if(duty < dutyRef) duty++;
    Timer1.setPwmDuty(pwmPin, duty); //PWM, Duty
}

void MotorController::On(int power)
{
    if ( 0 <= power && power <= 100)
    {
        return;
    }

    if(power > limit)
    {
        power = limit;
    }

    duty = map(power, 0, 100, 0, 1024);
    
    digitalWrite(brakePin, LOW);

    //Timer interrupt
    MsTimer2::set(10/slope, (void(*)())&flash); //Timer interrupt period
    MsTimer2::start(); //Timer interrupt start

}

void MotorController::Off()
{
    digitalWrite(brakePin, HIGH);

    MsTimer2::stop();
}
