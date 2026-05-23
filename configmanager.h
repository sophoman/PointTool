#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QStringBuilder>
#include<QDir>
//配置管理
//单例模式
class ConfigManager
{
private:
    ConfigManager();
    ConfigManager(const ConfigManager&other)=delete;
    static ConfigManager*m_instance;
    //配置文件路径
    QString m_configPath=nullptr;
    //默认打开路径
    QString m_defalutOpenPath=nullptr;
    //默认生成路径
    QString m_defaultGeneratePath=nullptr;
public:
    //获取单例
    static ConfigManager*createInstance();
    //获取打开路径
    QString GetOpenPath()const;
    //获取生成路径
    QString GetSavePath()const;
    //保存配置文件
    bool SaveConfig(const QString& openPath,const QString& savePath);
    //加载配置文件
    bool LoadConfig();
    //格式化字符串 清理没必要的空格等
    QString cleanText(const QString& str);
};

#endif // CONFIGMANAGER_H
