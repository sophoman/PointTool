#include "progressmanager.h"

ProgressManager::ProgressManager(QObject *parent)
    : QObject{parent}
{

}
ProgressManager* ProgressManager::m_progressManage=nullptr;
ProgressManager*ProgressManager::createInstance(){
    if(m_progressManage==nullptr){
        m_progressManage=new ProgressManager();
    }
    return m_progressManage;
}
