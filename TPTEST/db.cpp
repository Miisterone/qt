#include "db.h"

#include <QSqlQuery>
#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>

db::db()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    QDir dir (appDataLocation);
    if(!dir.exists()){
        dir.mkdir(appDataLocation);
        qDebug() << "mkdir" << appDataLocation;
    }

    QString dbPath = appDataLocation+"/db.db";
    qDebug() <<  "dbPath" << dbPath;
    db.setDatabaseName(dbPath);

    if(!db.open()){
        qCritical() << "Unable to open db" << dbPath;
        return;
    }

    QString table = "CREATE TABLE IF NOT EXISTS files("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "filePath STRING,"
                        "fileSize BIGINT,"
                        "fileMTime BIGINT,"
                        "fileLastCheck BIGINT"
                           ")";

    QSqlQuery query;
    query.exec(table);

    if(query.isValid()){
        qWarning() << "Create table" << query.isValid();
        return;
    }
 }
