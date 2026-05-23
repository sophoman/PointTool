#include "singlevalvedevice.h"

SingleValveDevice::SingleValveDevice() {}

void SingleValveDevice::addDefaultAssemble()
{
    this->m_dataAssemble.emplaceBack(DataAssemble{"_A","OP","Spare_AI","读","","NA"});
    DeviceBase::addDefaultAssemble();
}
