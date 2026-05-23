/********************************************************************************
** Form generated from reading UI file 'textinput.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTINPUT_H
#define UI_TEXTINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "editabletextedit.h"

QT_BEGIN_NAMESPACE

class Ui_TextInput
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    EditableTextEdit *textDevice;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    EditableTextEdit *textFlag;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConfirm;

    void setupUi(QWidget *TextInput)
    {
        if (TextInput->objectName().isEmpty())
            TextInput->setObjectName("TextInput");
        TextInput->resize(200, 163);
        verticalLayout = new QVBoxLayout(TextInput);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget_2 = new QWidget(TextInput);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        textDevice = new EditableTextEdit(widget_2);
        textDevice->setObjectName("textDevice");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textDevice->sizePolicy().hasHeightForWidth());
        textDevice->setSizePolicy(sizePolicy);
        textDevice->setMinimumSize(QSize(110, 22));
        textDevice->setMaximumSize(QSize(110, 22));
        QFont font;
        font.setPointSize(7);
        textDevice->setFont(font);
        textDevice->setAcceptRichText(false);

        horizontalLayout_2->addWidget(textDevice);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(TextInput);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        textFlag = new EditableTextEdit(widget_3);
        textFlag->setObjectName("textFlag");
        sizePolicy.setHeightForWidth(textFlag->sizePolicy().hasHeightForWidth());
        textFlag->setSizePolicy(sizePolicy);
        textFlag->setMinimumSize(QSize(110, 22));
        textFlag->setMaximumSize(QSize(110, 22));
        textFlag->setFont(font);
        textFlag->setAcceptRichText(false);

        horizontalLayout_3->addWidget(textFlag);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(TextInput);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        btnConfirm = new QPushButton(widget);
        btnConfirm->setObjectName("btnConfirm");
        sizePolicy.setHeightForWidth(btnConfirm->sizePolicy().hasHeightForWidth());
        btnConfirm->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnConfirm);


        verticalLayout->addWidget(widget);


        retranslateUi(TextInput);

        QMetaObject::connectSlotsByName(TextInput);
    } // setupUi

    void retranslateUi(QWidget *TextInput)
    {
        TextInput->setWindowTitle(QCoreApplication::translate("TextInput", "Form", nullptr));
        label->setText(QCoreApplication::translate("TextInput", "\350\256\276\345\244\207\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("TextInput", "\346\240\207\350\256\260\357\274\232", nullptr));
        btnConfirm->setText(QCoreApplication::translate("TextInput", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextInput: public Ui_TextInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTINPUT_H
