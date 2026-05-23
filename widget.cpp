#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->init();
}

Widget::~Widget()
{
    //退出线程循环
    m_exportThread.quit();
    //等待线程执行结束
    m_exportThread.wait();

    if(this->m_configManager){
        delete this->m_configManager;
        this->m_configManager=nullptr;
    }
    this->m_attachWindow.close();
    delete ui;
}

//选择excel文件地址按钮
void Widget::on_btnSelect_clicked()
{
    //判断地址栏是否有文件路径，如果有的话就直接打开该路径，否则就打开软件所在路径
    QString path=this->ui->textEdit->toPlainText();
    if(path.isEmpty()||!QFile::exists(path)){
        path="./";
    }
        //接收选中的文件保存类型
        QString selectedFilter;
        //打开选择文件对话框
        QString fileName=QFileDialog::getOpenFileName(this,QString("保存文件"),path,"xlsx文件 (*.xlsx);",&selectedFilter);//分割类型使用俩个分号
        //空字符串表示用户取消操作(关闭保存对话框或者点了取消按钮)
        if(fileName.isEmpty())
            return;
        this->ui->textEdit->setText(fileName);
}
//生成CSV文件按钮 使用线程
void Widget::on_btnExport_clicked()
{
    bool isPathCorrect=(ui->textEdit->toPlainText().isEmpty())||(this->ui->savePath->text().isEmpty());
    if(isPathCorrect)
        return;
    if(this->canExport){
        this->canExport=false;
        // 通过信号触发工作线程中的导出操作
        QMetaObject::invokeMethod(m_worker, "doExport", Qt::QueuedConnection,
                                  Q_ARG(QString, this->m_configManager->cleanText(ui->textEdit->toPlainText())),
                                  Q_ARG(QString, this->m_configManager->cleanText(ui->savePath->text())));
    }
}

//生成地址选择按钮
void Widget::on_btnExportPath_clicked()
{
    QString path=ui->savePath->text();
    QFileInfo fileInfo(path);
    QString dirPath="./";
    //判断地址栏是否有文件路径
    //如果有的话就直接打开该路径所在的目录位置，否则就打开软件所在目录位置
    if(QFileInfo::exists(fileInfo.path())){
        dirPath=fileInfo.path();
    }
    //接收选中的文件保存类型
    QString selectedFilter;
    //打开保存文件对话框
    QString fileName=QFileDialog::getSaveFileName(this,QString("保存文件"),dirPath,"CSV文件 (*.csv);;xlsx文件 (*.xlsx)",&selectedFilter);//分割类型使用俩个分号
    //空字符串表示用户取消操作(关闭保存对话框或者点了取消按钮)
    if(fileName.isEmpty())
        return;

    //判断类型同时添加后缀，用户没有添加.csv/.xlsx后缀时，添加.csv/.xlsx后缀保证格式正确
    if(selectedFilter=="CSV文件 (*.csv)"){//保存为.csv文件
        if(!fileName.contains(".csv")){
            fileName=fileName%".csv";
        }
    }
    else{
        if(!fileName.contains(".xlsx")){//保存为.xlsx文件
            fileName=fileName%".xlsx";
        }
    }
    this->ui->savePath->setText(fileName);
}

//设置为默认生成路径选择
void Widget::on_defaultPathCheck_checkStateChanged(const Qt::CheckState &arg1)
{
    if(arg1==Qt::Checked){
        this->m_configManager->SaveConfig(ui->textEdit->toPlainText(),ui->savePath->text());
    }
}

//处理线程的信号的槽函数
void Widget::onExportFinished(bool success, const QString &msg)
{
    //生成完毕后将能继续生成置位
    //避免连续点击生成
    this->canExport=true;

    if (success) {
        QMessageBox::information(this, "成功", msg);
        this->resetProgress();
    }
    else {
        QMessageBox::warning(this, "失败", msg);
        this->resetProgress();
    }

    this->onWorkThreadState("等待",Qt::black);
}
void Widget::resetProgress(){
    this->ui->progressBar->setValue(0);
}
//进度条值更新
void Widget::changeProgress(int value){
    if(value>this->ui->progressBar->value())
        this->ui->progressBar->setValue(value);
}
//工作线程工作状态
void Widget::onWorkThreadState(const QString& msg,const QColor& color){
    this->ui->workThreadState->setText(msg);
    QPalette palette;
    palette.setColor(QPalette::WindowText,color);
    this->ui->workThreadState->setPalette(palette);
}

//在资源管理器中打开excel文件所在位置 并选中
void Widget::on_showExce_clicked()
{
    QString filePath=this->ui->textEdit->toPlainText();
    if(filePath.isEmpty()||(!QFile::exists(filePath)))
        return;
    QString path = QDir::toNativeSeparators(filePath); // 将路径分隔符转换为反斜杠 "\"
    QStringList args;
    args << "/select," << path;
    QProcess::startDetached("explorer.exe", args);
}

//在资源管理器中打开csv文件所在位置 并选中
void Widget::on_showCSV_clicked()
{
    QString filePath=this->ui->savePath->text();
    if(filePath.isEmpty()||(!QFile::exists(filePath)))
        return;
    QString path = QDir::toNativeSeparators(filePath); // 将路径分隔符转换为反斜杠 "\"
    QStringList args;
    args << "/select," << path;
    QProcess::startDetached("explorer.exe", args);
}
//使用说明文本被点击
void Widget::on_IntroLabel_clicked(){
    // 构建绝对路径：可执行文件所在目录下的 Manual/Introduce.docx
    QString filePath = QCoreApplication::applicationDirPath() + "/Manual/Introduce.docx";
    if (QFileInfo::exists(filePath)) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}

//初始化相关
void Widget::init(){
    //创建配置文件管理器
    this->m_configManager=ConfigManager::createInstance();
    //创建线程管理器
    this->m_worker=new ExportThreadManager();
    //加载文件保存路径
    ui->savePath->setText(this->m_configManager->GetSavePath());
    //加载文件生成路径
    ui->textEdit->setText(this->m_configManager->GetOpenPath());
    //移动到子线程
    m_worker->moveToThread(&m_exportThread);
    // 连接线程结束后的清理
    connect(&m_exportThread, &QThread::finished, m_worker, &QObject::deleteLater);
    // 连接工作完成信号到主线程的处理函数
    connect(m_worker, &ExportThreadManager::workFinished, this, &Widget::onExportFinished);
    // 启动线程（线程一直运行，等待任务）
    m_exportThread.start();
    //绑定进度条信号
    connect(ProgressManager::createInstance(),&ProgressManager::broadcast,this,&Widget::changeProgress);
    //绑定工作线程状态信号
    connect(m_worker,&ExportThreadManager::workState,this,&Widget::onWorkThreadState);
    //绑定使用说明文字点击
    connect(ui->IntroLabel,&ClickableLabel::clicked,this,&Widget::on_IntroLabel_clicked);
    //绑定依附窗口隐藏的字符变化
    connect(&this->m_attachWindow,&Attach::charChange,this,&Widget::onBtnAttachCharChanged);
}

void Widget::on_btnAttach_clicked()
{
    if(this->m_attachWindow.isVisible()){
        ui->btnAttach->setText(">>");
        this->m_attachWindow.hide();
    }
    else{
        ui->btnAttach->setText("<<");
        this->m_attachWindow.setPos(QPoint(this->pos().x()+this->width(),this->pos().y()));
        this->m_attachWindow.show();
    }
}
//依附窗口隐藏的字符变化
void Widget::onBtnAttachCharChanged(){
    ui->btnAttach->setText(">>");
}
//重写关闭窗口事件，实现依附窗口随主窗口的关闭而关闭
void Widget::closeEvent(QCloseEvent *event){
    if(this->m_attachWindow.isVisible()){
        this->m_attachWindow.close();
    }
    event->accept();
}

