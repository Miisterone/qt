#include <QApplication>
#include "mainwindow.h"
#include "fileindexer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString dirPath = "/Users/jean-philippehuc/Documents/REPO/qt/Indexer";

    if (argc > 1) {
        dirPath = argv[1];
    }

    qDebug() << "Indexation du répertoire:" << dirPath;

    FileIndexer indexer;
    indexer.createDatabase();

    MainWindow mainWindow;
    // Connectez le signal de progression de FileIndexer au signal de MainWindow
    QObject::connect(&indexer, &FileIndexer::indexingProgress, &mainWindow, &MainWindow::indexingProgress);
    mainWindow.show();

    indexer.indexDirectory(dirPath);

    qDebug() << "Indexation terminée.";

    return app.exec();
}
