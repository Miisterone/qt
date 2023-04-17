#ifndef FILEINDEXER_H
#define FILEINDEXER_H

#include <QObject>
#include <QSqlDatabase>

class FileIndexer : public QObject {
    Q_OBJECT

public:
    explicit FileIndexer(QObject *parent = nullptr);
    void createDatabase();
    void indexDirectory(const QString &dirPath);

private:
    QSqlDatabase m_database;
};

#endif // FILEINDEXER_H
