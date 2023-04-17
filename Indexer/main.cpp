#include <QApplication>
#include "fileindexer.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString dirPath = "C:\\";

    if (argc > 1) {
        dirPath = argv[1];
    }

    qDebug() << "Indexation du répertoire:" << dirPath;

    FileIndexer indexer;
    indexer.createDatabase();
    indexer.indexDirectory(dirPath);

    qDebug() << "Indexation terminée.";

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
