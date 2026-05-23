#ifndef PROGRESSMANAGER_H
#define PROGRESSMANAGER_H
#include<QString>
#include<QProgressBar>
#include<QObject>
class ProgressManager: public QObject
{
     Q_OBJECT
public:
    static ProgressManager* createInstance();
signals:
    void broadcast(int value);
private:
    explicit ProgressManager(QObject *parent = nullptr);
    ProgressManager(const ProgressManager& other);
    static ProgressManager*m_progressManage;
};

#endif // PROGRESSMANAGER_H
