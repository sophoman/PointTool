#include "vivalvedevice.h"

VIValveDevice::VIValveDevice() {}

void VIValveDevice::addDefaultAssemble()
{
    this->m_dataAssemble.emplaceBack(DataAssemble{"","STATUS","FOV","读","","ND"});
     DeviceBase::addDefaultAssemble();
}
