#include <Arduino.h>

class MotorController
{
private:

    int pwmPin;
    int brakePin;

    /// @brief 모터 제한 출력의 퍼센테이지 단위
    int limit;

    int slope;
    int duty;
    int dutyRef;

    void flash();
public:
   
    /// @brief turn on the motor
    /// @param power 퍼센트 단위의 모터의 회전 속도
    void On(int power);
    void Off();
    MotorController::MotorController(int pwmPin, int breakPin);
    MotorController::~MotorController();
};

