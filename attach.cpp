#include "attach.h"
#include "ui_attach.h"



Attach::Attach(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Attach)
{
    ui->setupUi(this);
    this->init();
    this->connectSignals();
    this->loadJson();

}

Attach::~Attach()
{
    delete ui;
}
void Attach::setPos(const QPoint& pos){
    this->move(pos);
}

DeviceBase *Attach::getDeviceData(const QString &name)
{
    if(this->m_dataManager->m_devices.find(name)==this->m_dataManager->m_devices.end())
        return nullptr;
    return this->m_dataManager->m_devices[name];
}
void Attach::hideEvent(QHideEvent*event){
    emit charChange();
    event->accept();
}

void Attach::closeEvent(QCloseEvent *event)
{
    this->m_addWindow.close();
    event->accept();
}

void Attach::jsonSave()
{
    DeviceBase* device=this->m_dataManager->m_devices[ui->comboBox->currentText()];
    QString index0,index1,index2,index3,index4,index5;
    QList<DataAssemble> rowsData;
    //item不进行任何操作时返回空
    for(int i=0;i<this->model->rowCount();i++){
        if(this->model->item(i,0))
            index0=this->model->item(i,0)->text();
        else
            index0="";
        if(this->model->item(i,1))
            index1=this->model->item(i,1)->text();
        else
            index1="";
        if(this->model->item(i,2))
            index2=this->model->item(i,2)->text();
        else
            index2="";
        if(this->model->item(i,3))
            index3=this->model->item(i,3)->text();
        else
            index3="";
        if(this->model->item(i,4))
            index4=this->model->item(i,4)->text();
        else
            index4="";
        if(this->model->item(i,5))
            index5=this->model->item(i,5)->text();
        else
            index5="";

        DataAssemble assemble= DataAssemble{index0,index1,index2,index3,index4,index5};
        rowsData.emplaceBack(assemble);
    }
    device->RestoreAssemble(rowsData);

    JsonManager::createInstance()->SaveToJson(".\\Json");
    JsonManager::createInstance()->SaveFlagsToJson(".\\Json");
    JsonManager::createInstance()->SaveReFlagsToJson(".\\Json");
}

void Attach::on_btnSave_clicked()
{
    this->jsonSave();
}

void Attach::writeContent(const QList<DataAssemble>& content,int defaultRows){

    this->model->removeRows(0,this->model->rowCount());
    this->model->setRowCount(content.size());
    ui->labelFlag->setText(this->m_dataManager->m_reFlags[ui->comboBox->currentText()]);
    for(int i=0;i<content.size();i++){
        if(i<defaultRows){
            //默认装置添加的第一列(DCS结尾)不允许编辑
            QStandardItem *item = new QStandardItem(content[i].dcsEnd);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);  // 去掉编辑标志
            item->setBackground(QBrush(Qt::gray));//表格为灰色

            this->model->setItem(i,0,item);
            this->model->setData(this->model->index(i,1),content[i].otsSuffix);
            this->model->setData(this->model->index(i,2),content[i].group);
            this->model->setData(this->model->index(i,3),content[i].direction);
            this->model->setData(this->model->index(i,4),content[i].equal);
            this->model->setData(this->model->index(i,5),content[i].NAorND);
        }
        else{
            this->model->setData(this->model->index(i,0),content[i].dcsEnd);
            this->model->setData(this->model->index(i,1),content[i].otsSuffix);
            this->model->setData(this->model->index(i,2),content[i].group);
            this->model->setData(this->model->index(i,3),content[i].direction);
            this->model->setData(this->model->index(i,4),content[i].equal);
            this->model->setData(this->model->index(i,5),content[i].NAorND);
        }

    }
}


void Attach::on_btnAddRow_clicked()
{
    this->model->setRowCount(this->model->rowCount()+1);
}


void Attach::on_btnRemoveRow_clicked()
{
    //选中行小于默认添加的条数,则不删除该行
    int selectedRow=ui->configTable->currentIndex().row();
    if(this->m_dataManager->m_devices[ui->comboBox->currentText()]->minSize>selectedRow)
        return;
    this->model->removeRow(ui->configTable->currentIndex().row());

}


void Attach::on_comboBox_currentIndexChanged(int index)
{
    if(index>this->m_dataManager->m_devices.size())
        return;
    DeviceBase* device=this->m_dataManager->m_devices[ui->comboBox->currentText()];

    this->writeContent(device->m_dataAssemble,device->minSize);
}


void Attach::on_btnDelTable_clicked()
{

    int index=ui->comboBox->currentIndex();
    if(ui->comboBox->currentText().compare("单阀")==0||ui->comboBox->currentText().compare("四组阀")==0||
        ui->comboBox->currentText().compare("泵")==0||ui->comboBox->currentText().compare("现场开关手阀")==0||
        ui->comboBox->currentText().compare("现场可调手阀")==0)
        return;

    ui->comboBox->blockSignals(true);

    //先释放，再置空，最后从Map中将键移除
    delete this->m_dataManager->m_devices[ui->comboBox->currentText()];
    this->m_dataManager->m_devices[ui->comboBox->currentText()]=nullptr;
    this->m_dataManager->m_devices.erase(ui->comboBox->currentText());

    QString flag=this->m_dataManager->m_reFlags[ui->comboBox->currentText()];
    this->m_dataManager->m_reFlags[ui->comboBox->currentText()]="";
    this->m_dataManager->m_reFlags.erase(ui->comboBox->currentText());
    this->m_dataManager->m_flags[flag]="";
    this->m_dataManager->m_flags.erase(flag);

    ui->comboBox->removeItem(index);
    //删除后设置显示表
    ui->comboBox->setCurrentIndex(index-1);
    this->writeContent(this->m_dataManager->m_devices[ui->comboBox->currentText()]->m_dataAssemble,this->m_dataManager->m_devices[ui->comboBox->currentText()]->minSize);
    ui->labelFlag->setText(this->m_dataManager->m_reFlags[ui->comboBox->currentText()]);
    ui->comboBox->blockSignals(false);
}

void Attach::onReceiveConfirmText(const QString &deviceName,const QString &flagName)
{
    if(deviceName.isEmpty()){
        return;
    }
    this->addDevice(deviceName,flagName,new BlockDevice);
}

void Attach::onReceiveModifyText(const QString &deviceName,const QString &flagName)
{
    //如果标记已经被使用则不能修改
    if(!this->m_dataManager->m_flags[flagName].isEmpty())
        return;
    //根据装置去除最开始的
    QString preFlag=this->m_dataManager->m_reFlags[deviceName];
    //将之前的标志对应的设备置为空字符串
    this->m_dataManager->m_flags[preFlag]="";
    //修改当前
    this->m_dataManager->m_reFlags[deviceName]=flagName;
    this->m_dataManager->m_flags[flagName]=deviceName;
    ui->labelFlag->setText(this->m_dataManager->m_reFlags[deviceName]);
}


void Attach::init()
{
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    this->setWindowTitle("规则配置");

    this->m_dataManager=DataManager::createInstance();


    this->model=new QStandardItemModel;
    //设置列数
    this->model->setColumnCount(6);
    //设置表头
    this->model->setHeaderData(0,Qt::Horizontal, "DCS结尾");
    this->model->setHeaderData(1,Qt::Horizontal, "模型后缀");
    this->model->setHeaderData(2,Qt::Horizontal, "组");
    this->model->setHeaderData(3,Qt::Horizontal, "数据流向");
    this->model->setHeaderData(4,Qt::Horizontal, "公式");
    this->model->setHeaderData(5,Qt::Horizontal, "NA/ND");
    //设置数据模型
    ui->configTable->setModel(model);
    //设置宽度
    ui->configTable->horizontalHeader()->setDefaultSectionSize(76);
    //固定宽度
    ui->configTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void Attach::setComboBox(int currentIndex)
{
    ui->comboBox->setCurrentIndex(currentIndex);
    this->writeContent(this->m_dataManager->m_devices[ui->comboBox->currentText()]->m_dataAssemble,this->m_dataManager->m_devices[ui->comboBox->currentText()]->minSize);
}

void Attach::clearComboBox()
{
    ui->comboBox->blockSignals(true);
    ui->comboBox->clear();
    ui->comboBox->blockSignals(false);
}

void Attach::clearDataWhenLoadJson()
{
    //清空保存的数据
    this->m_dataManager->clearDeviceTable();
    //清空box中的显示
    this->clearComboBox();
}

void Attach::addDefaultDevice()
{


    PumpDevice* pumpDevice=new PumpDevice;
    pumpDevice->addDefaultAssemble();
    this->addDevice("泵","$",pumpDevice);

    FourValveDevice* fourValveDevice=new FourValveDevice;
    fourValveDevice->addDefaultAssemble();
    this->addDevice("四组阀","#",fourValveDevice);

    SingleValveDevice*  signalValveDevice=new SingleValveDevice;
    signalValveDevice->addDefaultAssemble();
    this->addDevice("单阀","SINGLE",signalValveDevice);

    VIValveDevice* viValveDevice=new VIValveDevice;
    viValveDevice->addDefaultAssemble();
    this->addDevice("现场开关手阀","VI",viValveDevice);

    VXValveDevice* vxValveDevice=new VXValveDevice;
    vxValveDevice->addDefaultAssemble();
    this->addDevice("现场可调手阀","VX",vxValveDevice);

    //设置到0索引 ComboBox
    this->setComboBox(0);
}

void Attach::addDevice(const QString &deviceName,const QString &flagName,DeviceBase* const device)
{
    //有一个是重复的则不能添加
    if( !(this->m_dataManager->m_flags[flagName].isEmpty()&&this->m_dataManager->m_reFlags[deviceName].isEmpty()))
        return;
    this->m_dataManager->m_flags[flagName]=deviceName;
    this->m_dataManager->m_reFlags[deviceName]=flagName;

    //阻塞信号，防止添加在初始化默认项的时候触发ComboBox Index改变信号
    ui->comboBox->blockSignals(true);
    ui->comboBox->addItem(deviceName);
    ui->labelFlag->setText(flagName);
    ui->comboBox->setCurrentIndex(ui->comboBox->count()-1);
    this->m_dataManager->m_devices[ui->comboBox->currentText()]=device;
    this->writeContent(this->m_dataManager->m_devices[ui->comboBox->currentText()]->m_dataAssemble,this->m_dataManager->m_devices[ui->comboBox->currentText()]->minSize);
    //解除信号阻塞
    ui->comboBox->blockSignals(false);

}

void Attach::addDevice(const std::unordered_map<QString,DeviceBase*>& deviceMap)
{
    //阻塞信号，防止添加在初始化默认项的时候触发ComboBox Index改变信号
    ui->comboBox->blockSignals(true);
    for(auto it=deviceMap.begin();it!=deviceMap.end();++it){
        ui->comboBox->addItem(it->first);
    }
    //解除信号阻塞
    ui->comboBox->blockSignals(false);
    this->setComboBox(0);
}

//配置并弹出添加新的ComboBox Item
void Attach::addNewComboBox()
{
    this->m_addWindow.setPos(QPoint(this->pos().x()+this->m_addWindow.width(),this->pos().y()));
    this->m_addWindow.show();
    this->m_addWindow.clearTextEdit();
}

//配置并弹出修改标记窗口
void Attach::modifyFlag()
{
    this->m_modifyWindow.setPos(QPoint(this->pos().x()+this->m_addWindow.width(),this->pos().y()));
    this->m_modifyWindow.show();
    this->m_modifyWindow.setDeviceTextEnable(false);
    this->m_modifyWindow.setText(ui->comboBox->currentText(),ui->labelFlag->text());
}

void Attach::connectSignals()
{
    connect(&this->m_addWindow,&TextInput::emitConfirmText,this,&Attach::onReceiveConfirmText);
    connect(&this->m_modifyWindow,&TextInput::emitModifyText,this,&Attach::onReceiveModifyText);
}

void Attach::on_btnAddTable_clicked()
{
    this->addNewComboBox();
}


void Attach::on_btnModifyFlag_clicked()
{
    this->modifyFlag();
}

void Attach::loadJson()
{
    QString jsonData=JsonManager::createInstance()->OpenJsonFile(".\\Json\\devices.json");
    QString flagsData=JsonManager::createInstance()->OpenJsonFile(".\\Json\\flags.json");
    QString reFlagsData=JsonManager::createInstance()->OpenJsonFile(".\\Json\\reflags.json");
    if(jsonData.isNull()||jsonData.isEmpty()){
        this->addDefaultDevice();
    }
    else{
        JsonManager::createInstance()->ParseFromJson(jsonData.toUtf8());
        JsonManager::createInstance()->LoadFlag(flagsData.toUtf8());
        JsonManager::createInstance()->LoadReFlag(reFlagsData.toUtf8());
        this->addDevice(DataManager::createInstance()->m_devices);
    }
}
void Attach::on_btnReset_clicked()
{
    this->m_dataManager->clearDeviceTable();
    this->clearComboBox();
    this->addDefaultDevice();
}


void Attach::on_btnSaveTo_clicked()
{
    //执行一下保存Json文件确保Json文件夹存在
    this->jsonSave();
    // 1. 弹出保存对话框，让用户选择 .zip 文件路径
    QString savePath = QFileDialog::getSaveFileName(this,
        tr("另存为压缩包"),
        QDir::homePath(),                 // 默认起始目录（可自定义）
        tr("ZIP 压缩文件 (*.zip)")
        );
    if (savePath.isEmpty()) {
        return;  // 用户取消了
    }

    // 2. 准备要压缩的文件列表（使用绝对路径，避免工作目录变化）
    QString baseDir = QDir::currentPath();          // 或使用 QCoreApplication::applicationDirPath()
    QStringList files;
    files << baseDir + "/Json/devices.json"
          << baseDir + "/Json/flags.json"
          << baseDir + "/Json/reflags.json";

    // 3. 检查每个文件是否存在
    for (const QString &file :std::as_const(files)) {
        if (!QFile::exists(file)) {
            QMessageBox::warning(
                this,
                tr("文件缺失"),
                tr("找不到需要压缩的文件：\n%1").arg(file)
                );
            return;
        }
    }

    // 4. 执行压缩（使用 QuaZip 的 JlCompress 工具类）
    bool success = JlCompress::compressFiles(savePath, files);

    //5. 提示结果
    if (success) {
        QMessageBox::information(
            this,
            tr("压缩成功"),
            tr("压缩包已保存至：\n%1").arg(savePath)
            );
    } else {
        QMessageBox::critical(
            this,
            tr("压缩失败"),
            tr("压缩过程中出现错误，请检查文件权限或磁盘空间。")
            );
    }

}


void Attach::on_btnLoad_clicked()
{
    // 1. 弹出打开文件对话框，让用户选择要解压的 .zip 文件
    QString zipPath = QFileDialog::getOpenFileName(
        this,
        tr("选择压缩包"),
        QDir::homePath(),
        tr("ZIP 压缩文件 (*.zip)")
        );
    if (zipPath.isEmpty()) {
        return;  // 用户取消了
    }

    // 2. 检查压缩包是否存在
    if (!QFile::exists(zipPath)) {
        QMessageBox::warning(
            this,
            tr("文件不存在"),
            tr("找不到指定的压缩包：\n%1").arg(zipPath)
            );
        return;
    }

    // 3. 确定解压目标目录（Json 文件夹）
    QString baseDir = QCoreApplication::applicationDirPath(); // 或 QDir::currentPath()
    QString targetDir = baseDir + "/Json";

    // 4. 如果目标目录不存在，则创建它
    QDir dir;
    if (!dir.exists(targetDir)) {
        if (!dir.mkpath(targetDir)) {
            QMessageBox::critical(
                this,
                tr("创建目录失败"),
                tr("无法创建目标目录：\n%1").arg(targetDir)
                );
            return;
        }
    }

    // 5. 执行解压（使用 QuaZip 的 JlCompress 工具类）
    //    extractDir 会将压缩包内的所有文件解压到指定目录，并保持原有目录结构
    QStringList extractedFiles = JlCompress::extractDir(zipPath, targetDir);

    // 6. 判断解压是否成功
    if (extractedFiles.isEmpty()) {
        QMessageBox::critical(
            this,
            tr("解压失败"),
            tr("解压过程中出现错误，请检查压缩包是否损坏或格式不正确。")
            );
    } else {
        QMessageBox::information(
            this,
            tr("解压成功"),
            tr("已成功解压 %1 个文件到：\n%2").arg(extractedFiles.size()).arg(targetDir)
            );
    }

    //清空相关内容
    this->clearDataWhenLoadJson();
    //重新载入Json文件
    this->loadJson();

}

