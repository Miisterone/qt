#include "mainwindow.h"
#include <QApplication>

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTimer>
#include <iostream>

void createDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("file_index.db");

    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS files ("
               "path TEXT PRIMARY KEY,"
               "filename TEXT,"
               "size INTEGER,"
               "last_modified TEXT"
               ")");

    // Affiche le chemin de la base de données
    QFileInfo dbFileInfo(db.databaseName());
    qDebug() << "La base de données se trouve à:" << dbFileInfo.absoluteFilePath();
}

void indexDirectory(const QString &dirPath, int *indexedFileCount) {
    QDir dir(dirPath);
    QFileInfoList entries = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Hidden | QDir::System);

    for (const QFileInfo &entry : entries) {
        if (entry.isDir()) {
            indexDirectory(entry.absoluteFilePath(), indexedFileCount);
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
            } else {
                (*indexedFileCount)++;
            }
        }
    }
}

int countFiles(const QString &dirPath) {
    int fileCount = 0;
    QDir dir(dirPath);
    QFileInfoList entries = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Hidden | QDir::System);

    for (const QFileInfo &entry : entries) {
        if (entry.isDir()) {
            fileCount += countFiles(entry.absoluteFilePath());
        } else {
            fileCount++;
        }
    }

    return fileCount;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString dirPath = "C:\\Users\\Joris\\Documents\\Qt\\TPTEST";

    if (argc > 1) {
        dirPath = argv[1];
    }

    MainWindow w;
    w.show();

    qDebug() << "Indexation du répertoire:" << dirPath;

    createDatabase();

    int totalFileCount = countFiles(dirPath);
    qDebug() << "Nombre total de fichiers à indexer:" << totalFileCount;

    int indexedFileCount = 0;

       indexDirectory(dirPath, &indexedFileCount);
       std::cout << std::endl; // Passer à la ligne suivante

       qDebug() << "Indexation terminée.";

       return 0;
}
