#include "pumpdevice.h"

PumpDevice::PumpDevice() {

}

void PumpDevice::addDefaultAssemble(){
    this->m_dataAssemble.emplaceBack(DataAssemble{"_LO","STATUS","PFOV","读","","ND"});
    this->m_dataAssemble.emplaceBack(DataAssemble{"_LC","STATUS","PFOV","读","","ND"});
    this->m_dataAssemble.emplaceBack(DataAssemble{"_LR","remotepoint","PFOV","读","","ND"});
    this->m_dataAssemble.emplaceBack(DataAssemble{"_I","VISTA","PFOV","读","","ND"});
    this->m_dataAssemble.emplaceBack(DataAssemble{"_O","VOSTA","PFOV","读","","ND"});
    this->m_dataAssemble.emplaceBack(DataAssemble{"_ST","STATUS","PFOV","写","","ND"});
    DeviceBase::addDefaultAssemble();
}
