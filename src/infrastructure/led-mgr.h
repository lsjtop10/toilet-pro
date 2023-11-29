#include <Arduino.h>

class LEDMgr
{
private:
    int redPin;
    int yellowPin;
    int greenPin;
public:
    void Off();
    void Write(bool red, bool yellow, bool green);
    LEDMgr(int redPin, int yellowPin, int greenPin);
    ~LEDMgr();
};

