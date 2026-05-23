#ifndef EXCELMANAGER_H
#define EXCELMANAGER_H
#include<QAxObject>
#include<windows.h>
class ExcelManager
{
private:
    ExcelManager();
    static ExcelManager*m_instance;
public:
    QAxObject* m_excel=nullptr;
    QAxObject* m_work_books=nullptr;
    QAxObject*m_work_book=nullptr;
    QAxObject*m_work_sheets=nullptr;
    static ExcelManager*CreateInstance();
    //初始化COM和Excel集合相关
    bool openCOM();
    //打开对应的Excel文件
    bool openExcel(const QString& filePath);
    //关闭Excel
    void closeExcel();

};

#endif // EXCELMANAGER_H
