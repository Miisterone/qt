/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditIPAddress;
    QSpinBox *spinBoxPort;
    QPushButton *pushButtonConnect;
    QLabel *labelStatus;
    QLineEdit *lineEditMessage;
    QPushButton *pushButtonSend;
    QLineEdit *lineEditPath;
    QPushButton *pushButtonSendPath;
    QLabel *label;
    QLabel *label_2;
    QListView *listView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1125, 512);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEditIPAddress = new QLineEdit(centralwidget);
        lineEditIPAddress->setObjectName("lineEditIPAddress");
        lineEditIPAddress->setGeometry(QRect(20, 20, 113, 24));
        spinBoxPort = new QSpinBox(centralwidget);
        spinBoxPort->setObjectName("spinBoxPort");
        spinBoxPort->setGeometry(QRect(141, 20, 61, 25));
        spinBoxPort->setMaximum(10000);
        spinBoxPort->setValue(7007);
        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName("pushButtonConnect");
        pushButtonConnect->setGeometry(QRect(220, 20, 80, 24));
        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(310, 20, 111, 21));
        lineEditMessage = new QLineEdit(centralwidget);
        lineEditMessage->setObjectName("lineEditMessage");
        lineEditMessage->setGeometry(QRect(20, 190, 113, 24));
        pushButtonSend = new QPushButton(centralwidget);
        pushButtonSend->setObjectName("pushButtonSend");
        pushButtonSend->setGeometry(QRect(150, 190, 80, 24));
        lineEditPath = new QLineEdit(centralwidget);
        lineEditPath->setObjectName("lineEditPath");
        lineEditPath->setGeometry(QRect(20, 100, 113, 24));
        pushButtonSendPath = new QPushButton(centralwidget);
        pushButtonSendPath->setObjectName("pushButtonSendPath");
        pushButtonSendPath->setGeometry(QRect(150, 100, 80, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 381, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 150, 381, 31));
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(440, 10, 661, 441));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1125, 21));
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
        lineEditIPAddress->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        labelStatus->setText(QString());
        lineEditMessage->setText(QCoreApplication::translate("MainWindow", "Commande", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        lineEditPath->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        pushButtonSendPath->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Path custom (Le path par d\303\251faut cible le dossier document)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Commande (indexer start,etc)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
