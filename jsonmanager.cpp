#include "jsonmanager.h"

JsonManager*JsonManager::m_instance=nullptr;
JsonManager* JsonManager::createInstance()
{
    if(m_instance==nullptr){
        m_instance=new JsonManager;
    }
    return m_instance;
}

QString JsonManager::OpenJsonFile(const QString &filePath)
{
    //判断配置文件路径是否存在
    if(filePath.isNull()||filePath.isEmpty()){
        return nullptr;
    }
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return nullptr;
    }
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString jsonData=in.readAll();
    file.close();
    file.flush();
    return jsonData;
}

bool JsonManager::ParseFromJson(const QByteArray& jsonData)
{
    QJsonParseError error;
    //读取Json配置文件
    QJsonDocument doc=QJsonDocument::fromJson(jsonData,&error);
    if(error.error!=QJsonParseError::NoError){
        qWarning()<<"Json Parse Error";
        return false;
    }
    QJsonObject rootObject=doc.object();
    //获取根键值
    QStringList objectKeys=rootObject.keys();
    //根据键获取值
    for(const QString& key:std::as_const(objectKeys)){
        QJsonObject deviceObj = rootObject[key].toObject();
        BlockDevice*blockDevice=new BlockDevice;
        if(deviceObj.contains("minSize")){
            blockDevice->minSize=deviceObj["minSize"].toDouble();
        }
        //组装DataAssemble结构体
        if(deviceObj.contains("dataAssemble")){
            if(deviceObj["dataAssemble"].isArray()){
                QJsonArray dataAssemble=deviceObj["dataAssemble"].toArray();
                for(int i=0;i<dataAssemble.size();i++){
                    QString dcsEnd=dataAssemble[i][0].toString();
                    QString otsSuffix=dataAssemble[i][1].toString();
                    QString group=dataAssemble[i][2].toString();
                    QString direction=dataAssemble[i][3].toString();
                    QString equal=dataAssemble[i][4].toString();
                    QString NAorND=dataAssemble[i][5].toString();
                    blockDevice->m_dataAssemble.emplaceBack(DataAssemble{dcsEnd,otsSuffix,group,direction,equal,NAorND});
                }
            }
        }
        //反序列化好的文件写入装置Map中
        DataManager::createInstance()->m_devices[key]=blockDevice;
    }
    return true;
}

bool JsonManager::SaveToJson(const QString &savePath)
{
    DataManager*dataManager=DataManager::createInstance();
    // 构建根对象
    QJsonObject rootObj;
    for(auto it=dataManager->m_devices.begin();it!=dataManager->m_devices.end();++it){
        const QString& deviceName = it->first;
        DeviceBase* device = it->second;
        if (!device) continue;

        // 创建设备对象
        QJsonObject deviceObj;

        deviceObj["minSize"] = device->minSize;   // 如果 DeviceBase 有 minSize 成员

        // 构建 dataAssemble 数组
        QJsonArray dataAssembleArray;
        for (const DataAssemble& da : std::as_const(device->m_dataAssemble)) {
            QJsonArray innerArray;
            innerArray.append(da.dcsEnd);
            innerArray.append(da.otsSuffix);
            innerArray.append(da.group);
            innerArray.append(da.direction);
            innerArray.append(da.equal);
            innerArray.append(da.NAorND);
            dataAssembleArray.append(innerArray);
        }
        deviceObj["dataAssemble"] = dataAssembleArray;

        // 将设备对象添加到根对象，键为设备名
        rootObj[deviceName] = deviceObj;
    }

    // 转换为 JSON 文档
    QJsonDocument doc(rootObj);
    //检查文件路径是否存在
    if(!QDir(savePath).exists()){
        QDir().mkdir(savePath);
    }
    QString devicesPath=savePath+"\\"+"devices.json";
    // 写入文件
    QFile file(devicesPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    file.write(doc.toJson(QJsonDocument::Indented));  // 格式化输出
    file.close();



    return true;
}

bool JsonManager::SaveFlagsToJson(const QString &savePath)
{
     DataManager*dataManager=DataManager::createInstance();
    QFile file;
    QJsonDocument doc;
    //检查文件路径是否存在
    if(!QDir(savePath).exists()){
        QDir().mkdir(savePath);
    }
    QString devicesPath=savePath+"\\"+"devices.json";
    //保存flags
    QString flagPath=savePath+"\\"+"flags.json";
    QJsonObject flagObj;
    for(auto it= dataManager->m_flags.begin();it!=dataManager->m_flags.end();++it){
        flagObj[it->first]=it->second;
    }
    doc.setObject(flagObj);
    file.setFileName(flagPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    file.write(doc.toJson(QJsonDocument::Indented));  // 格式化输出
    file.close();
    return true;
}

bool JsonManager::SaveReFlagsToJson(const QString &savePath)
{
    DataManager*dataManager=DataManager::createInstance();
    QFile file;
    QJsonDocument doc;
    //检查文件路径是否存在
    if(!QDir(savePath).exists()){
        QDir().mkdir(savePath);
    }
    //保存reFlags
    QString reFlagPath=savePath+"\\"+"reflags.json";
    QJsonObject reFlagObj;
    for(auto it= dataManager->m_reFlags.begin();it!=dataManager->m_reFlags.end();++it){
        reFlagObj[it->first]=it->second;
    }
    doc.setObject(reFlagObj);
    file.setFileName(reFlagPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    file.write(doc.toJson(QJsonDocument::Indented));  // 格式化输出
    file.close();
    return true;
}

bool JsonManager::LoadFlag(const QByteArray& jsonData)
{
    QJsonParseError error;
    //读取Flag文件
    QJsonDocument doc=QJsonDocument::fromJson(jsonData,&error);
    if(error.error!=QJsonParseError::NoError){
        return false;
    }
    QJsonObject rootObject=doc.object();
    QStringList keys=rootObject.keys();
    for(const auto&key:std::as_const(keys)){
        DataManager::createInstance()->m_flags[key]=rootObject[key].toString();
    }
    return true;
}

bool JsonManager::LoadReFlag(const QByteArray &jsonData)
{
    QJsonParseError error;
    //读取reFlag文件
    QJsonDocument doc=QJsonDocument::fromJson(jsonData,&error);
    if(error.error!=QJsonParseError::NoError){
        return false;
    }
    QJsonObject rootObject=doc.object();
    QStringList keys=rootObject.keys();
    for(const auto&key:std::as_const(keys)){
        DataManager::createInstance()->m_reFlags[key]=rootObject[key].toString();
    }
    return true;
}

JsonManager::JsonManager() {}
