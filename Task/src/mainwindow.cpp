#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("3D Lab task");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_clicked()
{
    process = new QProcess();
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
    process->start(scriptPath);
    if(!process->waitForStarted()){
        ui->label->setText("Can't run script");
    }
    process->waitForReadyRead();
    const QByteArray data1 = process->readLine();
    process->waitForReadyRead();
    const QByteArray data2 = process->readLine();
    if(process->waitForFinished()){
        displayData(data1, data2);
    }
}

void MainWindow::displayData(const QByteArray &data1, const QByteArray &data2)
{
    QString strLab(data1);
    QString strIP(data2);

    //removed "\n" and others white space
    strLab = strLab.simplified();
    strIP = strIP.simplified();

    ui->label->setText(strLab + ", " + strIP);
}
