#ifndef SINGLEVALVEDEVICE_H
#define SINGLEVALVEDEVICE_H

#include "devicebase.h"

class SingleValveDevice : public DeviceBase
{
public:
    SingleValveDevice();
    ~SingleValveDevice()=default;
    //添加默认数据集
    void addDefaultAssemble()override;
};

#endif // SINGLEVALVEDEVICE_H
