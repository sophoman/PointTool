#ifndef JSONMANAGER_H
#define JSONMANAGER_H
#include<QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include"datamanager.h"
#include"blockdevice.h"
class JsonManager
{
public:
    static JsonManager*m_instance;
    static JsonManager* createInstance();
    //打开Json配置文件
    QString OpenJsonFile(const QString& filePath);
    //解析Json配置文件
    bool ParseFromJson(const QByteArray& jsonData);
    //保存Json配置文件
    bool SaveToJson(const QString& savePath);
    //保存标志映射文件
    bool SaveFlagsToJson(const QString& savePath);
    //保存逆向标志映射文件
    bool SaveReFlagsToJson(const QString& savePath);
    //读取标志映射文件
    bool LoadFlag(const QByteArray& jsonData);
    //读取逆向标志映射文件
    bool LoadReFlag(const QByteArray& jsonData);
private:
    JsonManager();
};

#endif // JSONMANAGER_H
