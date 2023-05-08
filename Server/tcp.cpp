#include "tcp.h"
#include "server.h"
#include <QTcpSocket>
#include <QRegularExpression>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

Tcp::Tcp(QObject *parent): QTcpServer(parent){
}

void Tcp::startServer(quint16 port)
{
    if (listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on port" << port;
    } else {
        qDebug() << "Error starting server:" << errorString();
    }
}

QStringList stringToList(QString line) {
    QStringList list;
    QRegularExpression rx("\"([^\"]*)\"");
    int         pos = 0;
    QRegularExpressionMatch match;

    while ((match = rx.match(line, pos)).hasMatch()) {
        list << match.captured(0);
        pos = match.capturedEnd(0);
    }
    for (auto l : qAsConst(list)) {
        QString ol = l;
        l.replace(" ", "<SPC>");
        line.replace(ol, l);
    }

    list.clear();
    QStringList tmp = line.split(' ');
    for (auto l : qAsConst(tmp)) {
        if (l.isEmpty())
            continue;

        list << l.replace("<SPC>", " ");
    }

    return list;
}

void Tcp::handleNewConnection()
{
    QTcpSocket *clientSocket = nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Tcp::readClientData);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Tcp::clientDisconnected);
    qDebug() << "New client connected";
}

void Tcp::readClientData()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        qDebug() << "Error: Invalid client socket";
        return;
    }

    QByteArray data = clientSocket->readAll();


    QString dataString = QString::fromUtf8(data);
    QStringList commandList = stringToList(dataString);

    // Si le client envoie un path spécial
    if (commandList.size() == 2 && commandList[0].toUpper() == "PATH") {
        SetPath(commandList[1]);
    }

    // Si la commande est "INDEXER START", commencez l'indexation avec le chemin actuel
    if (commandList.size() == 2 && commandList[0].toUpper() == "INDEXER" && commandList[1].toUpper() == "START") {
        startIndexing();
    }

    // Si la commande est "SEARCH nom du ficher"
    if (commandList.size() == 2 && commandList[0].toUpper() == "SEARCH") {
        QString fileName = commandList[1];
        Server server;
        QVariantMap fileData = server.searchFile(fileName);
        if (!fileData.isEmpty()) {
            QByteArray responseData;
            QDataStream stream(&responseData, QIODevice::WriteOnly);
            stream << fileData;
            clientSocket->write(responseData);
            qDebug() << "File data sent to client:" << fileData;
        } else {
            clientSocket->write("File not found");
            qDebug() << "File not found";
        }
    } else {
        clientSocket->write("Message received");
    }

    clientSocket->write("Message received");
}

void Tcp::clientDisconnected()
{
    qDebug() << "Client disconnected";
}

void Tcp::SetPath(QString _path){
    dirPath = _path;
    qDebug() << "Path changed" << dirPath;
}

QString Tcp::GetPath() {
    qDebug() << "Path par défaut de l'indexation: " << dirPath;
        return dirPath;
}

void Tcp::startIndexing() {
    qDebug() << "Starting indexing process...";
    qDebug() << GetPath();
    Server server;
    server.indexDirectory(dirPath);
}
