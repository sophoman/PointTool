#ifndef PUMPDEVICE_H
#define PUMPDEVICE_H
#include"devicebase.h"
class PumpDevice:public DeviceBase
{
public:
    PumpDevice();
    ~PumpDevice()=default;
    //添加默认数据集
    virtual void addDefaultAssemble()override;
};

#endif // PUMPDEVICE_H
