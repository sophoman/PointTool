#include "vxvalvedevice.h"

VXValveDevice::VXValveDevice() {}

void VXValveDevice::addDefaultAssemble()
{
    this->m_dataAssemble.emplaceBack(DataAssemble{"","OP","FOV","读","","NA"});
    DeviceBase::addDefaultAssemble();
}
