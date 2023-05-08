#include "server.h"
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Server::Server(QObject *parent) : QThread(parent) {}

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

    QString absoluteFilePath = QFileInfo(m_database.databaseName()).absoluteFilePath();
    qDebug() << "Db created at path:" << absoluteFilePath;
}

void Server::indexDirectory(const QString &dirPath) {
    QDir dir(dirPath);
    QFileInfoList entries = dir.entryInfoList(
        QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Hidden | QDir::System);

    for (const QFileInfo &entry: entries) {

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

        if (m_totalFiles == entries.count()) {
            qDebug() << "Indexation terminée.";
        }
    }
}

QVariantMap Server::searchFile(const QString &fileName) {
    QSqlQuery query;
    query.prepare("SELECT * FROM files WHERE filename = :filename");
    query.bindValue(":filename", fileName);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche de fichier:" << query.lastError().text();
        return QVariantMap();
    }

    if (query.next()) {
        QVariantMap fileData;
        fileData["path"] = query.value("path");
        fileData["filename"] = query.value("filename");
        fileData["size"] = query.value("size");
        fileData["last_modified"] = query.value("last_modified");
        fileData["created"] = query.value("created");
        fileData["ext"] = query.value("ext");
        fileData["type"] = query.value("type");
        return fileData;
    } else {
        qDebug() << "Fichier non trouvé";
            return QVariantMap();
    }
}
