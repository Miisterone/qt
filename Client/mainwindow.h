#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonConnect_clicked();
    void on_pushButtonSend_clicked();
    void on_pushButtonSendPath_clicked();
    void readServerData();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QStringListModel *model;
    QStringList serverDataList;

};

#endif // MAINWINDOW_H
