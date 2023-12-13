#include <Arduino.h>

class MotorController
{
private:

    const int limit = 85;
    /// @brief 모터 제한 출력의 퍼센테이지 단위
    
    int pwmPin;
    int brakePin;
    
    int slope;
    int duty;

    void flash();
public:
   
    /// @brief turn on the motor
    /// @param speed 퍼센트 단위의 모터의 회전 속도
    void On(int speed);

    /// @brief turn off the motor
    void Off();
    
    MotorController::MotorController(int pwmPin, int breakPin);
    MotorController::~MotorController();
};

