/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "display.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    Display *play;
    QGroupBox *horizontalGroupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *box_right;
    QVBoxLayout *verticalLayout_3;
    QLabel *code;
    QSpacerItem *verticalSpacer;
    QGroupBox *box_left;
    QVBoxLayout *verticalLayout_2;
    QLabel *BarcodeImg;
    QGroupBox *horizontalGroupBox1;
    QHBoxLayout *horizontalLayout;
    QPushButton *start;
    QPushButton *close;
    QCheckBox *checkBox;
    QSlider *focusValue;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1036, 628);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 991, 551));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String("QGroupBox#groupBox { \n"
"     border: 2px solid gray; \n"
"     border-radius: 3px; \n"
" } \n"
"QGroupBox::title { \n"
"    background-color: transparent;\n"
"     subcontrol-position: top left; /* position at the top left*/ \n"
"     padding:3 3px;\n"
"	 font: 20pt \"Ubuntu\";\n"
" } "));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setCheckable(false);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        play = new Display(groupBox);
        play->setObjectName(QStringLiteral("play"));
        play->setMinimumSize(QSize(640, 480));
        play->setMaximumSize(QSize(640, 480));
        play->setBaseSize(QSize(640, 480));
        play->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(play);

        horizontalGroupBox = new QGroupBox(groupBox);
        horizontalGroupBox->setObjectName(QStringLiteral("horizontalGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalGroupBox->sizePolicy().hasHeightForWidth());
        horizontalGroupBox->setSizePolicy(sizePolicy1);
        horizontalGroupBox->setMinimumSize(QSize(300, 200));
        horizontalGroupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(horizontalGroupBox);
        verticalLayout->setSpacing(30);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        box_right = new QGroupBox(horizontalGroupBox);
        box_right->setObjectName(QStringLiteral("box_right"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(box_right->sizePolicy().hasHeightForWidth());
        box_right->setSizePolicy(sizePolicy2);
        box_right->setMinimumSize(QSize(0, 100));
        box_right->setMaximumSize(QSize(300, 16777215));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        box_right->setFont(font1);
        box_right->setStyleSheet(QLatin1String("QGroupBox#box_right { \n"
"     border: 2px solid gray; \n"
"     border-radius: 3px; \n"
" } "));
        verticalLayout_3 = new QVBoxLayout(box_right);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        code = new QLabel(box_right);
        code->setObjectName(QStringLiteral("code"));

        verticalLayout_3->addWidget(code);


        verticalLayout->addWidget(box_right);

        verticalSpacer = new QSpacerItem(10, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        box_left = new QGroupBox(horizontalGroupBox);
        box_left->setObjectName(QStringLiteral("box_left"));
        box_left->setMaximumSize(QSize(300, 300));
        box_left->setFont(font1);
        box_left->setStyleSheet(QLatin1String("QGroupBox#box_left { \n"
"     border: 2px solid gray; \n"
"     border-radius: 3px; \n"
" } "));
        verticalLayout_2 = new QVBoxLayout(box_left);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        BarcodeImg = new QLabel(box_left);
        BarcodeImg->setObjectName(QStringLiteral("BarcodeImg"));
        sizePolicy2.setHeightForWidth(BarcodeImg->sizePolicy().hasHeightForWidth());
        BarcodeImg->setSizePolicy(sizePolicy2);
        BarcodeImg->setMinimumSize(QSize(0, 100));
        BarcodeImg->setMaximumSize(QSize(300, 200));
        QFont font2;
        font2.setPointSize(13);
        BarcodeImg->setFont(font2);

        verticalLayout_2->addWidget(BarcodeImg);


        verticalLayout->addWidget(box_left);

        horizontalGroupBox1 = new QGroupBox(horizontalGroupBox);
        horizontalGroupBox1->setObjectName(QStringLiteral("horizontalGroupBox1"));
        horizontalLayout = new QHBoxLayout(horizontalGroupBox1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        start = new QPushButton(horizontalGroupBox1);
        start->setObjectName(QStringLiteral("start"));
        start->setMinimumSize(QSize(75, 50));
        start->setMaximumSize(QSize(75, 50));
        start->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(start);

        close = new QPushButton(horizontalGroupBox1);
        close->setObjectName(QStringLiteral("close"));
        close->setMinimumSize(QSize(75, 50));
        close->setMaximumSize(QSize(75, 50));
        close->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(close);


        verticalLayout->addWidget(horizontalGroupBox1);

        checkBox = new QCheckBox(horizontalGroupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(true);

        verticalLayout->addWidget(checkBox);

        focusValue = new QSlider(horizontalGroupBox);
        focusValue->setObjectName(QStringLiteral("focusValue"));
        focusValue->setEnabled(true);
        focusValue->setMaximum(255);
        focusValue->setValue(100);
        focusValue->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(focusValue);


        horizontalLayout_2->addWidget(horizontalGroupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1036, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera view :", 0));
        horizontalGroupBox->setTitle(QString());
        box_right->setTitle(QApplication::translate("MainWindow", "Decode Result:", 0));
        code->setText(QString());
        box_left->setTitle(QApplication::translate("MainWindow", "Barcode image:", 0));
        BarcodeImg->setText(QString());
        start->setText(QApplication::translate("MainWindow", "Start", 0));
        close->setText(QApplication::translate("MainWindow", "Close", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Disable AutoFocus", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
