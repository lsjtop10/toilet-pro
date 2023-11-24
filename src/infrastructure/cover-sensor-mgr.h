class CoverSensorMgr
{
private:
    int trigPin;
    int echoPin;

    //변기 뚜껑이 열려 있다고 판단하는 길이 단위:cm
    int offDistance;
    void emitTrigger();

public:
    bool IsOpen();

    CoverSensorMgr();
    ~CoverSensorMgr();
};

