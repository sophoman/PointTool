#include "fourvalvedevice.h"

FourValveDevice::FourValveDevice(){

}

void FourValveDevice::addDefaultAssemble()
{
    this->m_dataAssemble.emplaceBack(DataAssemble{"_A","VAVALUE","Spare_AI","读","","NA"});
    this->m_dataAssemble.emplaceBack(DataAssemble{"_B","VBVALUE","PFOV","读","","NA"});
    this->m_dataAssemble.emplaceBack(DataAssemble{"_I","VI1VALUE","CV","读","","ND"});
    this->m_dataAssemble.emplaceBack(DataAssemble{"_O","VI2VALUE","CV","读","","ND"});
    DeviceBase::addDefaultAssemble();
}
