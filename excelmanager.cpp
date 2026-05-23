#include "excelmanager.h"

ExcelManager::ExcelManager() {

}

ExcelManager*ExcelManager::m_instance=nullptr;
ExcelManager*ExcelManager::CreateInstance(){
    if(!m_instance){
        m_instance=new ExcelManager();
    }
    return m_instance;
}

bool ExcelManager::openCOM(){
    //手动初始化COM
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if(FAILED(hr))
        return false;
    // 确保 Excel 应用和 Workbooks 集合已初始化
    if (!m_excel) {
        m_excel = new QAxObject("Excel.Application");
        if (!m_excel || m_excel->isNull())
            return false;
        m_excel->setProperty("Visible", false);
        m_excel->setProperty("DisplayAlerts", false);
        m_work_books = m_excel->querySubObject("Workbooks");
        if (!m_work_books || m_work_books->isNull()) {
            delete m_excel;
            m_excel = nullptr;
            return false;
        }
    }
    return true;
}

bool ExcelManager::openExcel(const QString& fileName){
    //释放旧的sheets
    if (m_work_sheets) {
        delete m_work_sheets;
        m_work_sheets = nullptr;
    }

    // 清理旧对象（如果有）
    if (m_work_book && !m_work_book->isNull()) {
        m_work_book->dynamicCall("Close(bool)", false); // 关闭旧工作簿
        delete m_work_book;
        m_work_book = nullptr;
    }
    // 先尝试打开新文件，获取工作簿对象
    if(!m_work_books||m_work_books->isNull())
        return false;
    QAxObject *newWorkBook = m_work_books->querySubObject("Open(const QString&)", fileName);
    if (!newWorkBook || newWorkBook->isNull()) {
        return false;
    }

    // 设置新对象
    m_work_book = newWorkBook;
    m_work_sheets = m_work_book->querySubObject("Sheets");
    if (!m_work_sheets || m_work_sheets->isNull()) {
        m_work_book->dynamicCall("Close(bool)", false);
        delete m_work_book;
        m_work_book = nullptr;
        return false;
    }

    return true;
}
void ExcelManager::closeExcel(){
    //excel->work_books->work_book->work_sheets->work_sheet(已释放)
    if(this->m_work_sheets){
        delete m_work_sheets;
        m_work_sheets = nullptr;
    }
    // 先关闭工作簿
    if (m_work_book && !m_work_book->isNull()) {
        m_work_book->dynamicCall("Close(bool)", false);
    }
    if(this->m_work_book&&!this->m_work_book->isNull()){
        delete m_work_book;
        m_work_book = nullptr;
    }
    if(this->m_work_book&&this->m_work_book->isNull()){
        delete m_work_books;
        m_work_books = nullptr;
    }
    // 最后退出 Excel 并删除主对象
    if (m_excel && !m_excel->isNull()) {
        m_excel->dynamicCall("Quit()");
        delete m_excel;     m_excel = nullptr;
    }
    //关闭COM
    CoUninitialize();
}


