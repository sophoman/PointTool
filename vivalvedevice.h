#ifndef VIVALVEDEVICE_H
#define VIVALVEDEVICE_H

#include "devicebase.h"

class VIValveDevice : public DeviceBase
{
public:
    VIValveDevice();
    ~VIValveDevice()=default;
    //添加默认数据集
    void addDefaultAssemble()override;
};

#endif // VIVALVEDEVICE_H
