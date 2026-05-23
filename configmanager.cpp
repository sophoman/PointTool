#include "configmanager.h"

ConfigManager*ConfigManager::m_instance=nullptr;
ConfigManager::ConfigManager() {
    this->m_configPath="./config.ini";
    //读取配置文件
    this->LoadConfig();
}

ConfigManager*ConfigManager::createInstance(){
    if(!m_instance){
        m_instance=new ConfigManager();
    }
    return m_instance;
}

QString ConfigManager::GetOpenPath()const{
    return m_defalutOpenPath;
}

QString ConfigManager::GetSavePath()const{
    return  m_defaultGeneratePath;
}

bool ConfigManager::SaveConfig(const QString& openPath,const QString& savePath){
    this->m_defalutOpenPath=openPath;
    this->m_defaultGeneratePath=savePath;
    QFile file(this->m_configPath);
    //以只写的方式打开文件 会清空文件内容 用于重新打开文件写入
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return false;
    }
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);  // 设置utf-8编码保存生成路径
    //组合配置文件的输出内容
    QString content="DefaultOpenPath="%this->m_defalutOpenPath%"\n"
                      %"DefaultSavePath="%this->m_defaultGeneratePath;
    out<<content;
    file.close();
    file.flush();
    return true;
}
bool ConfigManager::LoadConfig(){
    //判断配置文件路径是否存在
    if(this->m_configPath.isNull()||this->m_configPath.isEmpty()){
        return false;
    }
    QFile file(this->m_configPath);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return false;
    }
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString readLine;
    //逐行读取配置文件，并根据前面的文字判断路径内容
    while(in.readLineInto(&readLine)){
        QStringList textList=readLine.split("=");

        if(textList.at(0).compare("DefaultOpenPath")==0){
            this->m_defalutOpenPath=textList.at(1);
        }
        else if(textList.at(0).compare("DefaultSavePath")==0){
            this->m_defaultGeneratePath=textList.at(1);
        }
    }
    file.close();
    file.flush();
    return true;
}

QString ConfigManager:: cleanText(const QString& str ){
    QString cleanStr = str.simplified();        // 去掉首尾空白和内部多余空白
    cleanStr.remove(QChar::Null);
    cleanStr.remove(QChar(0x200B)); // ZWSP
    cleanStr.remove(QChar(0x00A0)); // NBSP
    cleanStr = cleanStr.trimmed();
    return cleanStr;
}








