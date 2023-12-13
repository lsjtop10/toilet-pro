#include <Arduino.h>
#include <TimerOne.h>
#include <MsTimer2.h>
#include <string.h>
#include "motor-controller.h"
#include "../debug.h"

MotorController::MotorController(int pwmPin, int breakPin)
{

    this->pwmPin = pwmPin;
    this->brakePin = breakPin;
    this->slope = 1;
    this->duty = 0;

    pinMode(pwmPin, OUTPUT);
     //Brake, Output
    digitalWrite(brakePin, HIGH); //Brake, '0'

    //Brake
    pinMode(brakePin, OUTPUT);
}

MotorController::~MotorController()
{

}

void MotorController::flash()
{

    Timer1.setPwmDuty(pwmPin, duty); //PWM, Duty
}

void MotorController::On(int speed)
{
    //PWM
    Timer1.initialize(); //Timer1
    Timer1.pwm(pwmPin, 0); //PWM, Duty 0%
    Timer1.setPeriod(50); //PWM period 20kHz
    Timer1.setPwmDuty(pwmPin, 0); //PWM, Duty 0%

    if ( 0 < speed && speed > 100)
    {
        return;
    }

    if(speed > limit)
    {
        speed = limit;
    }

    duty = map(speed, 0, 100, 0, 1024); 

    digitalWrite(brakePin, LOW);

    for(int i = 0; i < duty; i += slope)
    {
        Timer1.setPwmDuty(pwmPin, duty);
        delay(10);
    }

}

void MotorController::Off()
{

    digitalWrite(brakePin, HIGH);
    Timer1.setPwmDuty(pwmPin,0);
    Timer1.stop();
}
