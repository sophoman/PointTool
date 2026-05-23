#ifndef FOURVALVEDEVICE_H
#define FOURVALVEDEVICE_H
#include"devicebase.h"
class FourValveDevice:public DeviceBase
{
public:
    FourValveDevice();
    ~FourValveDevice()=default;
    //添加默认数据集
    virtual void addDefaultAssemble()override;
};

#endif // FOURVALVEDEVICE_H
