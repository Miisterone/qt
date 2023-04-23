#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
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
    void start();

    enum ServerState {
        INDEXING,
        READY,
        STOPPED,
        PAUSED,
        QUERYING,
        RESULTS_AVAILABLE
    };

    void createDatabase();
    void indexDirectory(const QString &dirPath);
    void startIndexing(const QString &dirPath);
    void setState(ServerState state);

public slots:
    void pauseIndexing();
    void stopIndexing();
    void resumeIndexing();
    void searchFiles(const QString &searchText);

protected:
    void run() override;

signals:
     void indexingProgress(int progress);
     void serverStatusChanged(const QString &status);
      void searchResults(const QList<QVariantMap> &results);

private slots:
    void onNewConnection();
    void onReadyRead();
    void onDisconnected();

private:
    QTcpServer *m_server;
    ServerState m_state = READY;
    QSqlDatabase m_database;
    int m_totalFiles = 0;
    bool m_pauseIndexing = false;
    bool m_stopIndexing = false;
    QMutex m_mutex;
    QWaitCondition m_pauseWaitCondition;
    QString m_dirPath;
};

#endif
