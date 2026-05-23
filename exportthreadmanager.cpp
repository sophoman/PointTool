#include "exportthreadmanager.h"

ExportThreadManager::ExportThreadManager(QObject *parent)
    : QObject{parent}
{
    this->m_dataManager=DataManager::createInstance();
    this->m_excelManager=ExcelManager::CreateInstance();
}
void ExportThreadManager::doExport(const QString& excelFilePath,const QString& exportPath){
    emit workState("正在加载COM",QColorConstants::Svg::orange);
    bool COMStatus= this->m_excelManager->openCOM();
    if(!COMStatus){
        emit workFinished(COMStatus,COMStatus?"COM初始化成功":"COM初始化失败");
        return;
    }

    emit workState("正在打开Excel",QColorConstants::Svg::orange);
    bool readStatus= this->m_excelManager->openExcel(excelFilePath);
    if(!readStatus){
        emit workFinished(readStatus,readStatus?"Excel读取成功":"Excel读取失败");
        return;
    }

    emit workState("正在处理文件内容",QColorConstants::Svg::orange);
    bool exportStatus=m_dataManager->readExcel();
    if(!exportStatus){
        emit workFinished(exportStatus,exportStatus?"内容处理成功":"内容处理失败");
        return;
    }

    emit workState("正在保存CSV文件",QColorConstants::Svg::orange);
    bool saveCsvStatus=m_dataManager->toCsv(exportPath);
    if(!saveCsvStatus){
        emit workFinished(saveCsvStatus,saveCsvStatus?"CSV文件保存成功":"CSV文件保存失败");
        return;
    }


    emit workState("正在保存NA文件",QColorConstants::Svg::orange);
    bool saveNAStatus=m_dataManager->toNA(exportPath);

    if(!saveNAStatus){
        emit workFinished(saveNAStatus,saveNAStatus?"NA文件保存成功":"NA文件保存失败");
        return;
    }
    emit workState("正在保存ND文件",QColorConstants::Svg::orange);
    bool saveNDStatus=m_dataManager->toND(exportPath);
    if(!saveNDStatus){
        emit workFinished(saveNDStatus,saveNDStatus?"ND文件保存成功":"ND文件保存失败");
        return;
    }

    emit workState("执行完毕",QColorConstants::Svg::seagreen);
    emit workFinished(true,"文件生成成功");
}

//由于excel是在该线程中创建的，需要在该线程中正确释放故在该线程中释放
ExportThreadManager::~ExportThreadManager(){
    this->m_excelManager->closeExcel();
}
