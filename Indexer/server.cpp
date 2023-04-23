#include "server.h"
#include <QTcpSocket>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Server::Server(QObject *parent): QThread(parent), m_server(new QTcpServer(this)) {
    connect(m_server, &QTcpServer::newConnection, this, &Server::onNewConnection);
}

void Server::start() {
    if (!m_server->listen(QHostAddress::Any, 7007)) {
        qDebug() << "Erreur: le serveur n'a pas pu démarrer";
    } else {
        qDebug() << "Le serveur écoute sur le port" << m_server->serverPort();
    }
}

void Server::createDatabase() {
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("file_index.db");

    if (!m_database.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données:" << m_database.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS files ("
               "path TEXT PRIMARY KEY,"
               "filename TEXT,"
               "size INTEGER,"
               "last_modified TEXT,"
               "created TEXT,"
               "ext TEXT,"
               "type TEXT"
               ")");
}

void Server::run() {
    indexDirectory(m_dirPath);
}

void Server::indexDirectory(const QString &dirPath) {
    QMutexLocker locker(&m_mutex);
    setState(INDEXING);
    locker.unlock();

    QDir dir(dirPath);
    QFileInfoList entries = dir.entryInfoList(
            QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Hidden | QDir::System);

    for (const QFileInfo &entry: entries) {
        locker.relock();

        // Vérifiez si l'indexation doit être mise en pause
        while (m_pauseIndexing) {
            m_pauseWaitCondition.wait(&m_mutex);
        }

        // Vérifiez si l'indexation doit être arrêtée
        if (m_stopIndexing) {
            setState(STOPPED);
            locker.unlock();
            return;
        }

        locker.unlock();

        if (entry.isDir()) {
            indexDirectory(entry.absoluteFilePath());
        } else {
            QSqlQuery query;
            query.prepare("INSERT OR REPLACE INTO files (path, filename, size, last_modified, created, ext, type) "
                          "VALUES (:path, :filename, :size, :last_modified, :created, :ext, :type)");
            query.bindValue(":path", entry.absoluteFilePath());
            query.bindValue(":filename", entry.fileName());
            query.bindValue(":size", entry.size());
            query.bindValue(":last_modified", entry.lastModified().toString(Qt::ISODate));
            query.bindValue(":created", entry.birthTime().toString(Qt::ISODate));
            query.bindValue(":ext", entry.suffix());
            query.bindValue(":type", entry.isDir() ? "directory" : "file");

            if (!query.exec()) {
                qDebug() << "Erreur lors de l'insertion de fichier:" << query.lastError().text();
            }
        }

        m_totalFiles++;
        int progress = static_cast<int>((static_cast<double>(m_totalFiles) / entries.count()) * 100);
        emit indexingProgress(progress);
    }

    locker.relock();
    setState(READY);
}

void Server::startIndexing(const QString &dirPath) {
    m_dirPath = dirPath;
    start();
}

void Server::onNewConnection() {
    QTcpSocket *socket = m_server->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::onDisconnected);
}

void Server::onReadyRead() {
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (!socket) return;
    QByteArray data = socket->readAll();

    // Traitez les données reçues ici
    // Mettez à jour l'état en fonction des actions du client
    // Exemple :
    // setState(STOPPED);
    // setState(PAUSED);
    // setState(QUERYING);
    // setState(RESULTS_AVAILABLE);
}

void Server::onDisconnected() {
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (!socket) return;
    socket->deleteLater();
}

void Server::setState(ServerState state) {
    m_state = state;
    QString statusString;
    switch (state) {
        case INDEXING:
            statusString = "Etat server: indexing";
            break;
        case READY:
            statusString = "Etat server: Indexation done";
            break;
        case STOPPED:
            statusString = "Etat server: Client stopped the indexing";
            break;
        case PAUSED:
            statusString = "Etat server: Client paused the indexing";
            break;
        case QUERYING:
            statusString = "Etat server: A query is in progress";
            break;
        case RESULTS_AVAILABLE:
            statusString = "Etat server: The query is finished and some results are waiting";
            break;
    }
    emit serverStatusChanged(statusString);
}

void Server::pauseIndexing() {
    QMutexLocker locker(&m_mutex);
    m_pauseIndexing = true;
    setState(PAUSED);
}

void Server::stopIndexing() {
    QMutexLocker locker(&m_mutex);
    m_stopIndexing = true;
    setState(STOPPED);
}

void Server::resumeIndexing() {
    QMutexLocker locker(&m_mutex);
    m_pauseIndexing = false;
    setState(INDEXING);
    m_pauseWaitCondition.wakeOne();
}

void Server::searchFiles(const QString &searchText) {
    QList<QVariantMap> results;

    QSqlQuery query;
    query.prepare("SELECT * FROM files WHERE filename LIKE :searchText");
    query.bindValue(":searchText", "%" + searchText + "%");

    if (query.exec()) {
            while (query.next()) {
            QVariantMap fileData;
            fileData["path"] = query.value("path");
            fileData["filename"] = query.value("filename");
            fileData["size"] = query.value("size");
            fileData["last_modified"] = query.value("last_modified");
            fileData["created"] = query.value("created");
            fileData["ext"] = query.value("ext");
            fileData["type"] = query.value("type");

            results.append(fileData);
            }
    } else {
            qDebug() << "Erreur lors de la recherche de fichiers:" << query.lastError().text();
    }

    emit searchResults(results);
}
