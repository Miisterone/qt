#include "fileindexer.h"
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

FileIndexer::FileIndexer(QObject *parent) : QObject(parent) {
}

void FileIndexer::createDatabase() {
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
               "last_modified TEXT"
               ")");
}

void FileIndexer::indexDirectory(const QString &dirPath) {
    QDir dir(dirPath);
    QFileInfoList entries = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Hidden | QDir::System);

    for (const QFileInfo &entry : entries) {
        if (entry.isDir()) {
            indexDirectory(entry.absoluteFilePath());
        } else {
            QSqlQuery query;
            query.prepare("INSERT OR REPLACE INTO files (path, filename, size, last_modified) "
                          "VALUES (:path, :filename, :size, :last_modified)");
            query.bindValue(":path", entry.absoluteFilePath());
            query.bindValue(":filename", entry.fileName());
            query.bindValue(":size", entry.size());
            query.bindValue(":last_modified", entry.lastModified().toString(Qt::ISODate));

            if (!query.exec()) {
                qDebug() << "Erreur lors de l'insertion de fichier:" << query.lastError().text();
            }
        }
    }
}
