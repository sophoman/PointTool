#include "datamanager.h"

DataManager::DataManager() {
    this->m_defaluePathSave="./config.ini";
    this->m_progressManager=ProgressManager::createInstance();
    this->m_excelManager=ExcelManager::CreateInstance();
}
DataManager*DataManager::m_dataManager=nullptr;
DataManager* DataManager::createInstance(){
    if(m_dataManager==nullptr){
        m_dataManager=new DataManager();
    }
    return m_dataManager;
}
DataManager::~DataManager(){
    //释放进度条管理
    if(this->m_progressManager){
        delete this->m_progressManager;
        this->m_progressManager=nullptr;
    }

    this->clearDeviceTable();
}
//生成NA ND文本
void DataManager::assembleNAND(const QString& sourceName,const QString& dotSuffix){
    if(dotSuffix.compare("NA")==0||dotSuffix.compare("OP")==0||sourceName.contains("_A")||sourceName.contains("_B")){
        this->m_NAContent=this->m_NAContent%sourceName%'\n';
    }
    else if(dotSuffix.compare("ND")==0||dotSuffix.compare("STATUS")==0||sourceName.contains("_I")||sourceName.contains("_O")||sourceName.contains("_LC")||
               sourceName.contains("_LO")||sourceName.contains("_LR")||sourceName.contains("ST")){
        this->m_NDContent=this->m_NDContent%sourceName%'\n';
    }
}
//通用内容组装
void  DataManager::outputUniversal(const QString& sheetName,const QString& col1,const QString& col2,const QString&col3,
                                  const QString& col4,const QString& col5,const QString&col6){
    // 组装 CSV 行（使用双引号包裹）
    QString csvRowContent= '\"' % sheetName % "\","
                            % "\"VF\","
                            % '\"' % col1 % "\","
                            % "\"OTS\","
                            % "\"VxOTS\","
                            % '\"' % col2 % '.' % col3 % "\","
                            % '\"' % col4 % "\","
                            % '\"' % readOrWrite(col4) % "\","
                            % '\"' % col5 % "\","
                            % '\"' % col6 % "\"\n";

    this->m_CsvContent=this->m_CsvContent%csvRowContent;
    if(col4.compare("AI")==0||col4.compare("AO")==0||col4.compare("DI")==0||col4.compare("DO")==0)
        return;
    this->assembleNAND(col1,col3);

}
//四组阀内容组装  通过#辨识该内容是现场四组阀，写入_A,_I,_O,_B内容 也可以用来组装泵的内容
void DataManager::outputDetail(const QString& sheetName,const QString& suffix,const QString& col2,const QString&col3,
                             const QString& group,const QString& col5,const QString&col6,const QString&dataDirection,const QString& NAND){
    // 组装 CSV 行（使用双引号包裹）
    QString csvRowContent= '\"' % sheetName % "\","
                                % "\"VF\","
                                % '\"' + col2%suffix % "\","
                                % "\"OTS\","
                                % "\"VxOTS\","
                                % '\"' % col2 % '.' % col3 % "\","
                                % '\"' % group% "\","
                                % '\"' % dataDirection % "\","
                                % '\"' % col5 % "\","
                                % '\"' % col6 % "\"\n";

    this->m_CsvContent=this->m_CsvContent%csvRowContent;

    this->assembleNAND(col2%suffix,NAND);

}
//按照组别确定数据流向
QString DataManager::readOrWrite(const QString& group )const{
    QString direction;
    if(group.compare("AO")==0||group.compare("DO")==0||group.compare("FOV")==0||group.compare("PFOV")==0||group.compare("CV")==0||group.compare("RD")==0){
        direction="读";
    }
    else if(group.compare("AI")==0||group.compare("DI")==0||group.compare("PSV")==0||group.compare("Spare_AI")==0||group.compare("WR")==0){
        direction="写";
    }
    return direction;
}

//组装csv文件内容
bool DataManager::assembleCsv(const QString& sheetName,const QString& col1,const QString& col2,const QString& col3,
                              const QString& col4,const QString& col5,const QString& col6){

    std::unordered_map<QString,QString>::iterator flagIt = m_flags.find(col1);
    if(flagIt ==this->m_flags.end()||flagIt->second.isEmpty()){
        this->outputUniversal(sheetName,col1,col2,col3,col4,col5,col6);
    }
    else{
        DeviceBase* device=this->m_devices[this->m_flags[col1]];
        const QList<DataAssemble>& dataAssmble=device->m_dataAssemble;
        for(int i=0;i<dataAssmble.size();i++){
            this->outputDetail(sheetName,dataAssmble[i].dcsEnd,col2,dataAssmble[i].otsSuffix,dataAssmble[i].group,col5,dataAssmble[i].equal,dataAssmble[i].direction,dataAssmble[i].NAorND);
        }
    }

    return true;
}
//保存CSV文件
bool DataManager::toCsv(const QString& fileName){
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out.setEncoding(QStringConverter::System);//ANSI
    // 写入 UTF-8 BOM，告诉Excel这是UTF-8文件
    //out << QChar(0xFEFF);
    //写入表头
    out << "\"目标节点\",\"目标节点系统类型\",\"目标节点位号名\","
        << "\"源节点\",\"源节点类型\",\"源节点位号名\","
        << "\"组\",\"数据流向\",\"描述\",\"公式\"\n";
    out<<this->m_CsvContent;
    file.close();
    this->m_CsvContent.clear();
    return true;
}
//保存NA文本文件
bool DataManager::toNA(const QString& fileName){
    QFileInfo fileInfo(fileName);
    QString NAFileName=fileInfo.path()%"/NA.txt";
    QFile file(NAFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out.setEncoding(QStringConverter::System);//ANSI
    if(this->m_NAContent.isEmpty())
        out<<"No Content";
    else
        out<<this->m_NAContent;
    file.close();
    file.flush();
    this->m_NAContent.clear();
    return true;
}
//保存ND文本文件
bool DataManager::toND(const QString& fileName){
    QFileInfo fileInfo(fileName);
    QString NDFileName=fileInfo.path()%"/ND.txt";

    QFile file(NDFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out.setEncoding(QStringConverter::System);//ANSI
    if(this->m_NDContent.isEmpty())
        out<<"No Content";
    else
        out<<this->m_NDContent;
    file.close();
    file.flush();
    this->m_NDContent.clear();
    return true;
}

bool DataManager::readExcel(){
    int totalRows=0;
    int nowRows=0;
    if(!this->m_excelManager->m_work_sheets||this->m_excelManager->m_work_sheets->isNull())
        return false;
    int sheetCount = this->m_excelManager->m_work_sheets->property("Count").toInt();  // 缓存sheet数量
    for (int i = 1; i <= sheetCount; ++i) {
        QAxObject *work_sheet = this->m_excelManager->m_work_book->querySubObject("Sheets(int)", i);
        if (!work_sheet || work_sheet->isNull()) return false;

        QString sheetName = work_sheet->property("Name").toString();

        // 获取 UsedRange 的 Value 属性（二维数组）
        QAxObject *usedRange = work_sheet->querySubObject("UsedRange");
        if (!usedRange || usedRange->isNull()) {
            delete usedRange;
            delete work_sheet;
            return false;
        }

        QVariant rangeValue = usedRange->property("Value");  // 获取整个区域的值
        delete usedRange;  // 释放临时对象

        // 解析二维数组（假设返回 QVariantList，每行是 QVariantList）
        if (rangeValue.metaType().id() == QMetaType::QVariantList) {
            QVariantList rows = rangeValue.toList();
            //当前sheet有用行数
            int rowCount=0;
            //过滤空行  UsedRange获取的是曾经使用过的行数，故需要进行过滤
            for(int i=0;i<rows.size();i++){
                if(rows[i].toList()[0].isNull()||rows[i].toList()[0]==" "){
                    break;
                }
                ++rowCount;
            }
            totalRows+=(rowCount-1);

            for (int r = 0; r < rowCount; ++r) {
                if (r == 0) continue; // 跳过标题行（假设第一行是表头）
                QVariantList cols = rows[r].toList();
                int colCount = cols.size();
                if (colCount < 6) return false; // 确保至少有6列
                // 提取需要的列值
                QString col1 = cols[0].toString();//目标节点位号名
                QString col2 = cols[1].toString();//源节点位号名
                QString col3 = cols[2].toString();//suffix
                QString col4 = cols[3].toString();//组
                QString col5 = cols[4].toString();//描述
                QString col6 = cols[5].toString();//公式

                //组装CSV文件内容
                DataManager::createInstance()->assembleCsv(sheetName,col1,col2,col3,col4,col5,col6);

                nowRows+=1;
                //计算进度
                int progress=(nowRows*100)/totalRows;
                //广播进度
                emit this->m_progressManager->broadcast(progress);
            }
        }
        delete work_sheet;  // 释放工作表对象
    }
    return true;
}

void DataManager::clearDeviceTable()
{
    for(auto iter=m_dataManager->m_devices.begin();iter!=this->m_dataManager->m_devices.end();++iter){
        if(iter->second!=nullptr){
            delete iter->second;
            iter->second=nullptr;
        }
    }
    this->m_dataManager->m_devices.clear();
}
