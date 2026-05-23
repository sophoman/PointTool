#ifndef EXPORTTHREADMANAGER_H
#define EXPORTTHREADMANAGER_H

#include <QObject>
#include"datamanager.h"
#include"excelmanager.h"
class ExportThreadManager : public QObject
{
    Q_OBJECT
public:
    explicit ExportThreadManager(QObject *parent = nullptr);
    ~ExportThreadManager();
public slots:
    void doExport(const QString& excelFilePath,const QString& exportPath);
signals:
    void workFinished(bool success, const QString &msg);
    void workState(const QString& state,QColor color);
private:
    DataManager*m_dataManager=nullptr;
    ExcelManager*m_excelManager=nullptr;
};

#endif // EXPORTTHREADMANAGER_H
