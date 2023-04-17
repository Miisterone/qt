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

signals:
    void indexingProgress(int progress);

private:
    QSqlDatabase m_database;
    int m_totalFiles;
};

#endif // FILEINDEXER_H
