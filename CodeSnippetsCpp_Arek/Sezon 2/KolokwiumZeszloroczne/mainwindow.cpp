#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->actionPolacz,SIGNAL(triggered(bool)),this,SLOT(Polacz()));
    connect(this->ui->pushButton_Wyslij,SIGNAL(clicked(bool)),this,SLOT(Wyslij()));
    connect(this->ui->actionZapisz,SIGNAL(triggered(bool)),this,SLOT(SaveIp()));
    connect(this->ui->actionWczytaj,SIGNAL(triggered(bool)),this,SLOT(LoadIp()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SczytajEmitowanePrzezServerWartosci(float temperatura,QString pogoda)
{
    this->ui->plainTextEdit->appendPlainText(pogoda);
    this->ui->lineEdit_TempInfo->setText(QString::number(temperatura));
}

void MainWindow::LoadIp()
{

    _loadFilePath = QFileDialog::getOpenFileName(this,tr("Choose file to open"),tr(""),tr("Text Files (*txt)"));
    if(_loadFilePath.isEmpty())
    {
        return;
    }
    QFile file(_loadFilePath);
    bool opened = file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(opened)
    {
        QTextStream stream(&file);
        this->_ipAdress =  stream.readLine();
        this->_port = stream.readLine().toInt();
    }
    file.close();
}

void MainWindow::SaveIp()
{
    _saveFilePath = QFileDialog::getSaveFileName(this,tr("Choose file to save"),tr(""),tr("Text Files (*txt)"));
    if(_saveFilePath.isEmpty())
    {
        return;
    }
    QFile file(_saveFilePath);
    bool opened = file.open(QIODevice::WriteOnly|QIODevice::Text);
    if(opened)
    {
        QTextStream stream(&file);
        stream << _ipAdress << "\n" << _port;
    }

    file.close();
}

void MainWindow::Wyslij()
{
    int miesiac = ui->lineEdit_Miesiac->text().toInt();
    int dzien = ui->lineEdit_Dzien->text().toInt();
    int pora;
    if (ui->radioButton_Rano->isChecked())
    {
        pora = 1;
    }
    if (ui->radioButton_Poludnie->isChecked())
    {
        pora = 2;
    }
    if (ui->radioButton_Wieczor->isChecked())
    {
        pora = 3;
    }

    delete this->_serverClient;
    this->_serverClient = new ServerClient(_ipAdress,_port);
    connect(this,SIGNAL(ZapytajSerwer(int,int,int)),this->_serverClient,SLOT(OdbierzSygnalOdKlienta(int,int,int)));
    connect(this->_serverClient,SIGNAL(EmitujWartosci(float,QString)),this,SLOT(SczytajEmitowanePrzezServerWartosci(float,QString)));
    emit ZapytajSerwer(dzien,miesiac,pora);
}

void MainWindow::Polacz()
{
    this->_connectDialog = new ConnectDialog();
    connect(_connectDialog,SIGNAL(ButtonSend()),this,SLOT(DialogButtonSend()));
    _connectDialog->show();
}

void MainWindow::DialogButtonSend()
{
    this->_ipAdress = _connectDialog->ipAddress;
    this->_port = _connectDialog->port;


}

