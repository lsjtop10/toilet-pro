class CoverSensorMgr
{
private:
    
    /// @brief 변기 뚜껑이 열려 있다고 판단하는 길이 단위:cm 
    const int threshold = 13;

    int trigPin;
    int echoPin;
    
    void emitTrigger();

public:
    /// @brief 센서 값을 참고해 뚜껑이 열렸는지 여부를 반환하는 함수
    /// @return  true = 뚜껑 열림 true = 뚜껑 닫힘
    bool IsOpen();

    CoverSensorMgr(int trigPin, int echoPin);
    ~CoverSensorMgr();
};

