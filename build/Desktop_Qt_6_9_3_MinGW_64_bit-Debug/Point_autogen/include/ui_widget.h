/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *textFilePath;
    QTextEdit *textEdit;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSelect;
    QPushButton *showExce;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *Hard;
    QCheckBox *Soft;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *textSavePath;
    QLabel *savePath;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnExportPath;
    QPushButton *showCSV;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *defaultPathCheck;
    QLabel *workThreadState;
    ClickableLabel *IntroLabel;
    QPushButton *btnAttach;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QProgressBar *progressBar;
    QPushButton *btnExport;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(490, 351);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(490, 351));
        Widget->setMaximumSize(QSize(490, 351));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        widget_4 = new QWidget(Widget);
        widget_4->setObjectName("widget_4");
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 9, -1, 9);
        textFilePath = new QLabel(widget_2);
        textFilePath->setObjectName("textFilePath");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textFilePath->sizePolicy().hasHeightForWidth());
        textFilePath->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(textFilePath);

        textEdit = new QTextEdit(widget_2);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(5);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy3);
        textEdit->setMinimumSize(QSize(0, 23));
        textEdit->setMaximumSize(QSize(16777215, 23));
        QFont font;
        font.setPointSize(7);
        textEdit->setFont(font);
        textEdit->setAcceptRichText(false);

        horizontalLayout_2->addWidget(textEdit);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName("widget_7");
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setObjectName("verticalLayout");
        btnSelect = new QPushButton(widget_7);
        btnSelect->setObjectName("btnSelect");
        sizePolicy.setHeightForWidth(btnSelect->sizePolicy().hasHeightForWidth());
        btnSelect->setSizePolicy(sizePolicy);
        btnSelect->setMinimumSize(QSize(75, 23));
        btnSelect->setMaximumSize(QSize(75, 23));

        verticalLayout->addWidget(btnSelect);

        showExce = new QPushButton(widget_7);
        showExce->setObjectName("showExce");

        verticalLayout->addWidget(showExce);


        horizontalLayout_2->addWidget(widget_7);


        verticalLayout_2->addWidget(widget_2);

        widget = new QWidget(widget_4);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(9, -1, 9, -1);
        Hard = new QCheckBox(widget);
        Hard->setObjectName("Hard");
        sizePolicy.setHeightForWidth(Hard->sizePolicy().hasHeightForWidth());
        Hard->setSizePolicy(sizePolicy);
        Hard->setChecked(true);
        Hard->setAutoExclusive(true);

        horizontalLayout->addWidget(Hard);

        Soft = new QCheckBox(widget);
        Soft->setObjectName("Soft");
        sizePolicy.setHeightForWidth(Soft->sizePolicy().hasHeightForWidth());
        Soft->setSizePolicy(sizePolicy);
        Soft->setAutoExclusive(true);

        horizontalLayout->addWidget(Soft);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        textSavePath = new QLabel(widget_3);
        textSavePath->setObjectName("textSavePath");
        sizePolicy1.setHeightForWidth(textSavePath->sizePolicy().hasHeightForWidth());
        textSavePath->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(textSavePath);

        savePath = new QLabel(widget_3);
        savePath->setObjectName("savePath");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(8);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(savePath->sizePolicy().hasHeightForWidth());
        savePath->setSizePolicy(sizePolicy4);
        savePath->setStyleSheet(QString::fromUtf8("bk"));
        savePath->setLineWidth(-2);

        horizontalLayout_3->addWidget(savePath);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName("widget_8");
        verticalLayout_3 = new QVBoxLayout(widget_8);
        verticalLayout_3->setObjectName("verticalLayout_3");
        btnExportPath = new QPushButton(widget_8);
        btnExportPath->setObjectName("btnExportPath");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnExportPath->sizePolicy().hasHeightForWidth());
        btnExportPath->setSizePolicy(sizePolicy5);
        btnExportPath->setMinimumSize(QSize(75, 23));
        btnExportPath->setMaximumSize(QSize(75, 23));

        verticalLayout_3->addWidget(btnExportPath);

        showCSV = new QPushButton(widget_8);
        showCSV->setObjectName("showCSV");

        verticalLayout_3->addWidget(showCSV);


        horizontalLayout_3->addWidget(widget_8);


        verticalLayout_2->addWidget(widget_3);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        defaultPathCheck = new QCheckBox(widget_5);
        defaultPathCheck->setObjectName("defaultPathCheck");
        sizePolicy2.setHeightForWidth(defaultPathCheck->sizePolicy().hasHeightForWidth());
        defaultPathCheck->setSizePolicy(sizePolicy2);
        defaultPathCheck->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        horizontalLayout_4->addWidget(defaultPathCheck);

        workThreadState = new QLabel(widget_5);
        workThreadState->setObjectName("workThreadState");

        horizontalLayout_4->addWidget(workThreadState, 0, Qt::AlignmentFlag::AlignLeft);

        IntroLabel = new ClickableLabel(widget_5);
        IntroLabel->setObjectName("IntroLabel");
        sizePolicy.setHeightForWidth(IntroLabel->sizePolicy().hasHeightForWidth());
        IntroLabel->setSizePolicy(sizePolicy);
        IntroLabel->setMinimumSize(QSize(80, 0));
        IntroLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        IntroLabel->setOpenExternalLinks(false);

        horizontalLayout_4->addWidget(IntroLabel);

        btnAttach = new QPushButton(widget_5);
        btnAttach->setObjectName("btnAttach");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy6.setHorizontalStretch(25);
        sizePolicy6.setVerticalStretch(25);
        sizePolicy6.setHeightForWidth(btnAttach->sizePolicy().hasHeightForWidth());
        btnAttach->setSizePolicy(sizePolicy6);
        btnAttach->setMaximumSize(QSize(25, 25));

        horizontalLayout_4->addWidget(btnAttach);


        verticalLayout_2->addWidget(widget_5);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName("widget_6");
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        progressBar = new QProgressBar(widget_6);
        progressBar->setObjectName("progressBar");
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMinimumSize(QSize(340, 23));
        progressBar->setValue(0);

        horizontalLayout_5->addWidget(progressBar);

        btnExport = new QPushButton(widget_6);
        btnExport->setObjectName("btnExport");
        sizePolicy.setHeightForWidth(btnExport->sizePolicy().hasHeightForWidth());
        btnExport->setSizePolicy(sizePolicy);
        btnExport->setMinimumSize(QSize(75, 23));
        btnExport->setMaximumSize(QSize(60, 23));
        QFont font1;
        font1.setPointSize(9);
        btnExport->setFont(font1);

        horizontalLayout_5->addWidget(btnExport);


        verticalLayout_2->addWidget(widget_6);


        gridLayout->addWidget(widget_4, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        textFilePath->setText(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\350\267\257\345\276\204:", nullptr));
        btnSelect->setText(QCoreApplication::translate("Widget", "\346\265\217\350\247\210", nullptr));
        showExce->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272", nullptr));
        Hard->setText(QCoreApplication::translate("Widget", "\347\241\254\350\277\236\346\216\245", nullptr));
        Soft->setText(QCoreApplication::translate("Widget", "\350\275\257\350\277\236\346\216\245", nullptr));
        textSavePath->setText(QCoreApplication::translate("Widget", "\347\224\237\346\210\220\350\267\257\345\276\204:", nullptr));
        savePath->setText(QString());
        btnExportPath->setText(QCoreApplication::translate("Widget", "\346\265\217\350\247\210", nullptr));
        showCSV->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272", nullptr));
        defaultPathCheck->setText(QCoreApplication::translate("Widget", "\350\256\276\344\270\272\351\273\230\350\256\244", nullptr));
        workThreadState->setText(QCoreApplication::translate("Widget", "\347\255\211\345\276\205", nullptr));
        IntroLabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-style:italic; text-decoration: underline; color:#0000ff;\">\344\275\277\347\224\250\350\257\264\346\230\216</span></a></p></body></html>", nullptr));
        btnAttach->setText(QCoreApplication::translate("Widget", ">>", nullptr));
        btnExport->setText(QCoreApplication::translate("Widget", "\347\224\237\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
