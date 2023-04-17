#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connectez le signal à la méthode de mise à jour de la barre de progression
    connect(this, &MainWindow::indexingProgress, this, &MainWindow::updateProgressBar);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateProgressBar(int progress) {
    ui->progressBar->setValue(progress);
}

