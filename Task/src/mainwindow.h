#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QProcess>
#include <QDir>
#include <QCoreApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *process;
    const QString scriptPath = QDir::currentPath() + "/../script/my_script.sh";
};

#endif // MAINWINDOW_H
