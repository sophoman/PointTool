#include "textinput.h"
#include "ui_textinput.h"

TextInput::TextInput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextInput)
{
    ui->setupUi(this);
    this->init();
}

void TextInput::setPos(const QPoint &pos)
{
    this->move(pos);
}

void TextInput::setText(const QString &deviceText, const QString &flagText)
{
    ui->textDevice->setText(deviceText);
    ui->textFlag->setText(flagText);
}

void TextInput::setDeviceTextEnable(bool enable)
{
    ui->textDevice->setEnabled(enable);
}

void TextInput::clearTextEdit()
{
    ui->textDevice->clear();
    ui->textFlag->clear();
}

TextInput::~TextInput()
{
    delete ui;
}

void TextInput::init()
{
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    this->setWindowTitle("添加");
}

void TextInput::showEvent(QShowEvent *event)
{
    event->accept();
}

void TextInput::on_btnConfirm_clicked()
{
    emit this->emitConfirmText(ui->textDevice->toPlainText(),ui->textFlag->toPlainText());
    emit this->emitModifyText(ui->textDevice->toPlainText(),ui->textFlag->toPlainText());
    this->close();
}

