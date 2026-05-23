#include "devicebase.h"

void DeviceBase::addDefaultAssemble()
{
    this->minSize=this->m_dataAssemble.size();
}

void DeviceBase::RestoreAssemble(const QList<DataAssemble>& data){
    this->m_dataAssemble.clear();
    for(auto item:data){
        this->m_dataAssemble.emplaceBack(item);
    }
}

void DeviceBase::addDestinationPoint(const QString&  name){

}
void DeviceBase::addSourcePoint(const QString& name){

}
