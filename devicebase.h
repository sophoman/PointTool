#ifndef DEVICEBASE_H
#define DEVICEBASE_H
#include<QStringList>

struct DataAssemble
{
    QString dcsEnd;
    QString otsSuffix;
    QString group;
    QString direction;
    QString equal;
    QString NAorND;
};

class DeviceBase
{
public:
    DeviceBase()=default;
    virtual ~DeviceBase()=default;
    //用于保存后缀
    QList<DataAssemble> m_dataAssemble;
    //添加默认数据集
    virtual void addDefaultAssemble();
    //添加新后缀
    virtual void RestoreAssemble(const QList<DataAssemble>& data);
    //添加目标点名(DCS)
    virtual void addDestinationPoint(const QString&  name);
    //添加源位号(OTS)
    virtual void addSourcePoint(const QString& name);
    //默认的数量
    int minSize=0;
};

#endif // DEVICEBASE_H
