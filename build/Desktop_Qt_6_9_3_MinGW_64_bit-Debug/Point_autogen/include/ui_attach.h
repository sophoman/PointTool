/********************************************************************************
** Form generated from reading UI file 'attach.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTACH_H
#define UI_ATTACH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "editablecombobox.h"

QT_BEGIN_NAMESPACE

class Ui_Attach
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    EditableComboBox *comboBox;
    QPushButton *btnAddTable;
    QPushButton *btnDelTable;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *labelFlag;
    QPushButton *btnModifyFlag;
    QTableView *configTable;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddRow;
    QPushButton *btnRemoveRow;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSave;

    void setupUi(QWidget *Attach)
    {
        if (Attach->objectName().isEmpty())
            Attach->setObjectName("Attach");
        Attach->resize(520, 351);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Attach->sizePolicy().hasHeightForWidth());
        Attach->setSizePolicy(sizePolicy);
        Attach->setMinimumSize(QSize(520, 351));
        Attach->setMaximumSize(QSize(520, 351));
        verticalLayout = new QVBoxLayout(Attach);
        verticalLayout->setObjectName("verticalLayout");
        widget_2 = new QWidget(Attach);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(9, -1, -1, -1);
        comboBox = new EditableComboBox(widget_2);
        comboBox->setObjectName("comboBox");
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(comboBox);

        btnAddTable = new QPushButton(widget_2);
        btnAddTable->setObjectName("btnAddTable");
        sizePolicy.setHeightForWidth(btnAddTable->sizePolicy().hasHeightForWidth());
        btnAddTable->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(btnAddTable);

        btnDelTable = new QPushButton(widget_2);
        btnDelTable->setObjectName("btnDelTable");
        sizePolicy.setHeightForWidth(btnDelTable->sizePolicy().hasHeightForWidth());
        btnDelTable->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(btnDelTable);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        labelFlag = new QLabel(widget_2);
        labelFlag->setObjectName("labelFlag");

        horizontalLayout_2->addWidget(labelFlag);

        btnModifyFlag = new QPushButton(widget_2);
        btnModifyFlag->setObjectName("btnModifyFlag");

        horizontalLayout_2->addWidget(btnModifyFlag);


        verticalLayout->addWidget(widget_2);

        configTable = new QTableView(Attach);
        configTable->setObjectName("configTable");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(configTable->sizePolicy().hasHeightForWidth());
        configTable->setSizePolicy(sizePolicy1);
        configTable->setMinimumSize(QSize(0, 0));
        configTable->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(configTable);

        widget = new QWidget(Attach);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        btnAddRow = new QPushButton(widget);
        btnAddRow->setObjectName("btnAddRow");
        sizePolicy.setHeightForWidth(btnAddRow->sizePolicy().hasHeightForWidth());
        btnAddRow->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnAddRow);

        btnRemoveRow = new QPushButton(widget);
        btnRemoveRow->setObjectName("btnRemoveRow");
        sizePolicy.setHeightForWidth(btnRemoveRow->sizePolicy().hasHeightForWidth());
        btnRemoveRow->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnRemoveRow);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName("btnSave");
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addWidget(widget);


        retranslateUi(Attach);

        QMetaObject::connectSlotsByName(Attach);
    } // setupUi

    void retranslateUi(QWidget *Attach)
    {
        Attach->setWindowTitle(QCoreApplication::translate("Attach", "Form", nullptr));
        btnAddTable->setText(QCoreApplication::translate("Attach", "\346\267\273\345\212\240\350\241\250", nullptr));
        btnDelTable->setText(QCoreApplication::translate("Attach", "\345\210\240\351\231\244\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("Attach", "\346\240\207\350\256\260:", nullptr));
        labelFlag->setText(QCoreApplication::translate("Attach", "TextLabel", nullptr));
        btnModifyFlag->setText(QCoreApplication::translate("Attach", "\344\277\256\346\224\271", nullptr));
        btnAddRow->setText(QCoreApplication::translate("Attach", "\346\267\273\345\212\240\350\241\214", nullptr));
        btnRemoveRow->setText(QCoreApplication::translate("Attach", "\345\210\240\351\231\244\350\241\214", nullptr));
        btnSave->setText(QCoreApplication::translate("Attach", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Attach: public Ui_Attach {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTACH_H
