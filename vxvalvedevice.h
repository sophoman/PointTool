#ifndef VXVALVEDEVICE_H
#define VXVALVEDEVICE_H

#include "devicebase.h"

class VXValveDevice : public DeviceBase
{
public:
    VXValveDevice();
    ~VXValveDevice()=default;
    //添加默认数据集
    void addDefaultAssemble()override;
};

#endif // VXVALVEDEVICE_H
