#include <QApplication>
#include "mainwindow.h"
#include "server.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString dirPath = "C:\\Users\\miist\\Documents";

    if (argc > 1) {
        dirPath = argv[1];
    }

    qDebug() << "Indexation du répertoire:" << dirPath;

    MainWindow mainWindow;
    Server server;
    server.createDatabase();

    QObject::connect(&mainWindow, &MainWindow::searchFiles, &server, &Server::searchFiles);
    QObject::connect(&server, &Server::searchResults, &mainWindow, &MainWindow::displaySearchResults);

    mainWindow.show();

    QObject::connect(&server, &Server::indexingProgress, &mainWindow, &MainWindow::indexingProgress);
    QObject::connect(&server, &Server::serverStatusChanged, &mainWindow, &MainWindow::updateServerStatus);

    QObject::connect(&mainWindow, &MainWindow::startIndexing, &server, &Server::indexDirectory);
    QObject::connect(&mainWindow, &MainWindow::pauseIndexing, &server, &Server::pauseIndexing);
    QObject::connect(&mainWindow, &MainWindow::resumeIndexing, &server, &Server::resumeIndexing);
    QObject::connect(&mainWindow, &MainWindow::stopIndexing, &server, &Server::stopIndexing);

    return app.exec();
}
