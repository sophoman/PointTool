#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include<QString>
#include<QCheckBox>
#include<QAxObject>
#include<QFile>
#include<QFileDevice>
#include<QVector>
#include<QThread>
#include<QStringBuilder>
#include<QFileInfo>
#include<QProcess>
#include<QDir>
#include<windows.h>
#include"progressmanager.h"
#include"excelmanager.h"
#include"devicebase.h"

class DataManager
{
private:
    DataManager();
    DataManager(const DataManager&other)=delete;
    static DataManager*m_dataManager;
    ProgressManager*m_progressManager=nullptr;
    ExcelManager*m_excelManager=nullptr;
    QString m_defaluePathSave;
    QString m_CsvContent;
    QString m_NAContent;
    QString m_NDContent;
    QString readOrWrite(const QString& group )const;
    //生成NA、ND文本
    void assembleNAND(const QString& sourceName,const QString& suffix);
    //通用组装
    void outputUniversal(const QString& sheetName,const QString& col1,const QString& col2,const QString&col3,
                         const QString& col4,const QString& col5,const QString&col6);
    //含有四个位号的组装
    void outputDetail(const QString& suffix,const QString& sheetName,const QString& col2,const QString&col3,
                         const QString& col4,const QString& col5,const QString&col6,const QString&dataDirection,const QString& NAND);
    //生成csv文件
    bool assembleCsv(const QString& sheetName,const QString& col1,const QString& col2,const QString& col3,
                     const QString& col4,const QString& col5,const QString& col6);

public:
    ~DataManager();
    std::unordered_map<QString,QString> m_flags;//flag:device  泵:$  切换表的时候使用
    std::unordered_map<QString,QString> m_reFlags;//device:flag $:泵 生成的时候使用，使用$找到装置映射后在m_device查找
    std::unordered_map<QString,DeviceBase*> m_devices;
    static DataManager* createInstance();
    //导出相关操作
    bool exportOperation();
    bool readExcel();
    bool toCsv(const QString& fileName);
    bool toNA(const QString& fileName);
    bool toND(const QString& fileName);
    //清空装备表数据
    void clearDeviceTable();
};

#endif // DATAMANAGER_H
