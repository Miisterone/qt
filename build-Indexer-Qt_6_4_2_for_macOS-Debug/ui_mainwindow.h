/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QLineEdit *lineEdit;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(596, 234);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 90, 100, 32));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(310, 60, 121, 20));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(100, 30, 91, 20));
        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(200, 30, 91, 20));
        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(380, 30, 85, 20));
        checkBox_5 = new QCheckBox(centralwidget);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(310, 30, 85, 20));
        checkBox_6 = new QCheckBox(centralwidget);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setGeometry(QRect(100, 60, 51, 20));
        checkBox_7 = new QCheckBox(centralwidget);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setGeometry(QRect(200, 60, 61, 20));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 100, 113, 21));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(160, 120, 118, 23));
        progressBar->setValue(24);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 596, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "LAST_MODIFIED", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "MAX_SIZE", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "MIN_SIZE", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "CREATED", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "SIZE", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "EXT", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "TYPE", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
