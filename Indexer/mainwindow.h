#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void startIndexing(const QString &dirPath);
    void pauseIndexing();
    void resumeIndexing();
    void stopIndexing();
    void searchFiles(const QString &searchText);

public slots:
    void indexingProgress(int progress);
    void updateServerStatus(const QString &status);
    void displaySearchResults(const QList<QVariantMap> &results);

private slots:
    void on_progressBar_valueChanged(int value);
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_stopButton_clicked();
    void on_resumeButton_clicked();
    void on_searchLineEdit_textChanged(const QString &text);

private:
    Ui::MainWindow *ui;
};

#endif
