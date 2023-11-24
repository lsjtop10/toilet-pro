#include <Arduino.h>

class MotorController
{
private:
    int pwmPin;
    int brakePin;

    int minVal;
    int maxVal;

public:
   
    /// @brief 
    /// @param power 퍼센트 단위의 모터의 회전 속도
    void On(int power);
    void Off();
    MotorController::MotorController(int min, int max);
    MotorController::~MotorController();
};

