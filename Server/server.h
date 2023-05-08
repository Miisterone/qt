
#ifndef SERVER_H
#define SERVER_H

#include <QSqlDatabase>
#include <QMutex>
#include <QWaitCondition>
#include <QObject>
#include <QThread>
#include <QVariant>

class Server : public QThread
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);

    void createDatabase();
    void indexDirectory(const QString &dirPath);
    void startIndexing(const QString &dirPath);
    QVariantMap searchFile(const QString &fileName);

signals:
    void indexingProgress(int progress);
    void serverStatusChanged(const QString &status);

private:
    QSqlDatabase m_database;
    int m_totalFiles = 0;
    QString m_dirPath;
};

#endif
