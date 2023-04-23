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
               "last_modified TEXT,"
               "created TEXT,"
               "ext TEXT,"
               "type TEXT"
               ")");
}

void FileIndexer::indexDirectory(const QString &dirPath) {
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
    }
}
