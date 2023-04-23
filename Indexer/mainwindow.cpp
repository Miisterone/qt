#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(this, &MainWindow::indexingProgress, this, &MainWindow::indexingProgress);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::on_searchLineEdit_textChanged);

    QPushButton *startButton = findChild<QPushButton *>("startButton");
    QPushButton *pauseButton = findChild<QPushButton *>("pauseButton");
    QPushButton *stopButton = findChild<QPushButton *>("stopButton");
    QPushButton *resumeButton = findChild<QPushButton *>("resumeButton");

    if (startButton) {
        connect(startButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked);
    } else {
        qWarning() << "startButton non trouvé. Assurez-vous qu'il est ajouté et correctement nommé dans Qt Designer.";
    }

    if (pauseButton && stopButton) {
        connect(pauseButton, &QPushButton::clicked, this, &MainWindow::on_pauseButton_clicked);
        connect(stopButton, &QPushButton::clicked, this, &MainWindow::on_stopButton_clicked);
    } else {
        qWarning()
                << "pauseButton ou stopButton non trouvé. Assurez-vous qu'ils sont ajoutés et correctement nommés dans Qt Designer.";
    }

    if (resumeButton) {
        connect(resumeButton, &QPushButton::clicked, this, &MainWindow::on_resumeButton_clicked);
    } else {
        qWarning() << "resumeButton non trouvé. Assurez-vous qu'il est ajouté et correctement nommé dans Qt Designer.";
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::indexingProgress(int progress) {
    on_progressBar_valueChanged(progress);
}

void MainWindow::on_progressBar_valueChanged(int value) {
    ui->progressBar->setValue(value);
}

void MainWindow::updateServerStatus(const QString &status) {
    QLabel *statusLabel = findChild<QLabel *>("serverStatusLabel");

    if (statusLabel) {
        statusLabel->setText(status);
    } else {
        qWarning()
                << "serverStatusLabel non trouvé. Assurez-vous qu'il est ajouté et correctement nommé dans Qt Designer.";
    }
}

void MainWindow::on_searchLineEdit_textChanged(const QString &text) {
    emit searchFiles(text);
}

void MainWindow::on_startButton_clicked() {
    emit startIndexing("C:\\Users\\miist\\Documents");
}

void MainWindow::on_pauseButton_clicked() {
    emit pauseIndexing();
}

void MainWindow::on_stopButton_clicked() {
    emit stopIndexing();
}

void MainWindow::on_resumeButton_clicked() {
    emit resumeIndexing();
}

void MainWindow::displaySearchResults(const QList<QVariantMap> &results) {
    ui->resultsListWidget->clear();

    for (const QVariantMap &fileData : results) {
        QString itemText = QString("Path: %1\nFilename: %2\nSize: %3\nLast Modified: %4\nCreated: %5\nExtension: %6\nType: %7")
                               .arg(fileData["path"].toString())
                               .arg(fileData["filename"].toString())
                               .arg(fileData["size"].toString())
                               .arg(fileData["last_modified"].toString())
                               .arg(fileData["created"].toString())
                               .arg(fileData["ext"].toString())
                               .arg(fileData["type"].toString());

        QListWidgetItem *item = new QListWidgetItem(itemText);
        ui->resultsListWidget->addItem(item);
    }
}

