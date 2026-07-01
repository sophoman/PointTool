#ifndef ATTACH_H
#define ATTACH_H

#include <QWidget>
#include<QHideEvent>
#include<QTableView>
#include<QStandardItemModel>
#include<QString>
#include<QTextEdit>
#include"pumpdevice.h" // IWYU pragma: keep
#include"fourvalvedevice.h" // IWYU pragma: keep
#include"blockdevice.h" // IWYU pragma: keep
#include"vivalvedevice.h" // IWYU pragma: keep
#include"vxvalvedevice.h" // IWYU pragma: keep
#include"singlevalvedevice.h" // IWYU pragma: keep
#include"textinput.h"
#include"datamanager.h"
#include"jsonmanager.h" // IWYU pragma: keep
#include"JlCompress.h"  // IWYU pragma: keep
#include"QMessageBox"
#include"QFileDialog"
namespace Ui {
class Attach;
}

class Attach : public QWidget
{
    Q_OBJECT

public:
    explicit Attach(QWidget *parent = nullptr);
    ~Attach();
    void setPos(const QPoint& pos);
    //获得装置数据
    DeviceBase*getDeviceData(const QString& name);
protected:
    void hideEvent(QHideEvent*event)override;
    void closeEvent(QCloseEvent*event)override;
signals:
    void charChange();
private slots:
    //保存按钮点击
    void on_btnSave_clicked();
    //添加行按钮点击
    void on_btnAddRow_clicked();
    //移除行按钮点击
    void on_btnRemoveRow_clicked();
    //ComboBox索引改变
    void on_comboBox_currentIndexChanged(int index);
    //删除表按钮点击
    void on_btnDelTable_clicked();
    //收到输入窗口确认文本信号
    void onReceiveConfirmText(const QString& deviceName,const QString &flagName);
    //收到输入窗口修改标记信号
    void onReceiveModifyText(const QString& deviceName,const QString &flagName);
    //添加新表按钮
    void on_btnAddTable_clicked();
    //修改标记按钮点击
    void on_btnModifyFlag_clicked();
    // 重置按钮
    void on_btnReset_clicked();
    //另存Json文件按钮
    void on_btnSaveTo_clicked();
    //载入Json文件按钮
    void on_btnLoad_clicked();

private:
    Ui::Attach *ui;
    QStandardItemModel* model;
    DataManager*m_dataManager;
    TextInput m_addWindow;
    TextInput m_modifyWindow;
    //往表格写内容
    void writeContent(const QList<DataAssemble>& content,int defaultRows);
    //初始化相关
    void init();
    //添加默认装置
    void addDefaultDevice();
    //往ComboBox添加标签
    void addNewComboBox();
    //修改标志
    void modifyFlag();
    //连接信号
    void connectSignals();
    //添加装置
    void addDevice(const QString &deviceName,const QString &flagName,DeviceBase* const device);
    //添加装置
    void addDevice(const std::unordered_map<QString,DeviceBase*>& deviceMap);
    //载入Json数据
    void loadJson();
    //设置ComboxBox显示
    void setComboBox(int currentIndex);
    //清空ComboxBox显示
    void clearComboBox();
    //载入Json文件时清空数据操作
    void clearDataWhenLoadJson();
    //将数据保存到Json文件夹中
    void jsonSave();
};

#endif // ATTACH_H
