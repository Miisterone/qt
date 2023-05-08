#ifndef TCP_H
#define TCP_H

#include <QTcpServer>
#include <QStandardPaths>
#include <QSqlDatabase>

class Tcp : public QTcpServer
{
    Q_OBJECT
public:
    explicit Tcp(QObject *parent = nullptr);
    void startServer(quint16 port);
    QString GetPath();
    void searchFile(const QString &fileName);

public slots:
    void handleNewConnection();
    void readClientData();
    void clientDisconnected();

private:
    QSqlDatabase m_database;
    void startIndexing();
    QString dirPath = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).value(0, QString());
    void SetPath(QString path);
};

#endif
