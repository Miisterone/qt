#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readServerData);

    model = new QStringListModel(this);
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonConnect_clicked()
{
    QString ipAddress = ui->lineEditIPAddress->text();
    quint16 port = ui->spinBoxPort->value();

    socket->connectToHost(ipAddress, port);
    if (socket->waitForConnected(3000)) {
        qDebug() << "Connected to server";
        ui->labelStatus->setText("Connected");
    } else {
        qDebug() << "Error connecting to server:" << socket->errorString();
        ui->labelStatus->setText("Disconnected");
    }
}

void MainWindow::on_pushButtonSend_clicked()
{
    QString message = ui->lineEditMessage->text();
    if (!message.isEmpty()) {
        QByteArray data = message.toUtf8();
        socket->write(data);
        qDebug() << "Message sent to server:" << message;
    } else {
        qDebug() << "No message to send";
    }
}

void MainWindow::readServerData()
{
    QByteArray data = socket->readAll();
    qDebug() << "Data received from server:" << data;

    QString receivedData = QString::fromUtf8(data);
    serverDataList.append(receivedData);
    model->setStringList(serverDataList);
}

void MainWindow::on_pushButtonSendPath_clicked()
{
    QString message = ui->lineEditPath->text();
    if (!message.isEmpty()) {
        QByteArray data = "PATH "+message.toUtf8();
        socket->write(data);
        qDebug() << "Message sent to server:" << message;
    } else {
        qDebug() << "No message to send";
    }
}

