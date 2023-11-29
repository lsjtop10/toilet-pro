class LevelSensorMgr
{
private:
    int outPin;
public:
    bool IsFull();
    LevelSensorMgr(int outPin);
    ~LevelSensorMgr();
};

