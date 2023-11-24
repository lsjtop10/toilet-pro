#include <Arduino.h>
#include "motor-controller.h"

MotorController::MotorController(int min, int max)
{

    pwmPin = 10;
    brakePin = 9;

    minVal = min;
    maxVal = max;

    pinMode(pwmPin, OUTPUT);
    pinMode(brakePin, OUTPUT);

    /*
    //PWM
    Timer1.initialize(); //Timer1
    Timer1.pwm(pwmPin, 0); //PWM, Duty 0%
    Timer1.setPeriod(50); //PWM period 20kHz
    Timer1.setPwmDuty(pwmPin, 0); //PWM, Duty 0%

    //Direction
    pinMode(Direction, OUTPUT); //Direction, Output
    digitalWrite(Direction, LOW); //Direction, '0'

    //Brake
    pinMode(Brake, OUTPUT); //Brake, Output
    digitalWrite(Brake, LOW); //Brake, '0'

    //Timer interrupt
    MsTimer2::set(10/Slope, flash); //Timer interrupt period
    MsTimer2::start(); //Timer interrupt start
    */
}

MotorController::~MotorController()
{
}

void MotorController::On(int power)
{
    if ( 0 <= power && power <= 100)
    {
        return;
    }
    
    digitalWrite(brakePin, HIGH);
    digitalWrite(pwmPin, map(power, 0, 100, minVal, maxVal));
}

void MotorController::Off()
{
    digitalWrite(brakePin, LOW);
    digitalWrite(pwmPin, LOW);
}
