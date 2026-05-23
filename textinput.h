#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <QWidget>
#include<QShowEvent>
#include<QKeyEvent>
namespace Ui {
class TextInput;
}

class TextInput : public QWidget
{
    Q_OBJECT

public:
    explicit TextInput(QWidget *parent = nullptr);
    void setPos(const QPoint& pos);
    void setText(const QString& deviceText,const QString& flagText );
    void setDeviceTextEnable(bool enable);
    void clearTextEdit();
    ~TextInput();
private:
    void init();
    void showEvent(QShowEvent*event)override;
signals:
    void emitConfirmText(const QString& text,const QString &flagName);
    void emitModifyText(const QString& text,const QString &flagName);
private slots:
    void on_btnConfirm_clicked();
private:
    Ui::TextInput *ui;
};

#endif // TEXTINPUT_H
