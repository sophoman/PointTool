#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<qstring.h>
#include<QFileDialog>
#include<QDebug>
#include<QMessageBox>
#include<QThread>
#include <QDesktopServices>
#include"exportthreadmanager.h"
#include"configmanager.h"
#include"attach.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    ConfigManager*m_configManager=nullptr;
    ExportThreadManager*m_worker=nullptr;
    QThread m_exportThread;
    //右侧设置窗口
    Attach m_attachWindow;
    //初始化
    void init();
    //防止多次点击生成
    bool canExport=true;
    //改变进度条进度显示
    void changeProgress(int value);
    //重置进度条
    void resetProgress();
private slots:
    void on_btnSelect_clicked();

    void on_btnExport_clicked();

    void on_btnExportPath_clicked();

    void on_defaultPathCheck_checkStateChanged(const Qt::CheckState &arg1);

    void onExportFinished(bool success, const QString &msg);

    void onWorkThreadState(const QString& msg,const QColor& color);

    void on_showExce_clicked();

    void on_showCSV_clicked();

    void on_IntroLabel_clicked();

    void on_btnAttach_clicked();

    void onBtnAttachCharChanged();
protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
