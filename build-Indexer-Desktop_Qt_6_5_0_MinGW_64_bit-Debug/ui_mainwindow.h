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
#include <QtWidgets/QListWidget>
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
    QProgressBar *progressBar;
    QPushButton *startButton;
    QLabel *serverStatusLabel;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QLabel *serverStatusLabel_2;
    QPushButton *resumeButton;
    QLineEdit *searchLineEdit;
    QListWidget *resultsListWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(583, 397);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(30, 140, 118, 23));
        progressBar->setValue(0);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(30, 60, 51, 24));
        serverStatusLabel = new QLabel(centralwidget);
        serverStatusLabel->setObjectName("serverStatusLabel");
        serverStatusLabel->setGeometry(QRect(30, 100, 231, 31));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(90, 60, 51, 24));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(210, 60, 51, 24));
        serverStatusLabel_2 = new QLabel(centralwidget);
        serverStatusLabel_2->setObjectName("serverStatusLabel_2");
        serverStatusLabel_2->setGeometry(QRect(60, 20, 131, 31));
        resumeButton = new QPushButton(centralwidget);
        resumeButton->setObjectName("resumeButton");
        resumeButton->setGeometry(QRect(150, 60, 51, 24));
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(30, 190, 113, 24));
        resultsListWidget = new QListWidget(centralwidget);
        resultsListWidget->setObjectName("resultsListWidget");
        resultsListWidget->setGeometry(QRect(220, 110, 351, 231));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 583, 21));
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
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        serverStatusLabel->setText(QCoreApplication::translate("MainWindow", "Etat server:", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        serverStatusLabel_2->setText(QCoreApplication::translate("MainWindow", "Button pour l'indexing", nullptr));
        resumeButton->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
