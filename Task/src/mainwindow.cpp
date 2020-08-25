#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_clicked()
{
    process = new QProcess();
    process->start(scriptPath);
    process->waitForReadyRead();
    const QByteArray data1 = process->readLine();
    process->waitForReadyRead();
    const QByteArray data2 = process->readLine();
    if(process->waitForFinished()){
        ui->label->setText(QString(data1) + QString(data2));
    }
}
