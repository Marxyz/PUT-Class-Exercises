#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->actionPolacz,SIGNAL(triggered(bool)),this,SLOT(Polacz()));
    connect(this->ui->pushButton_Wyslij,SIGNAL(clicked(bool)),this,SLOT(Wyslij()));
    connect(this,SIGNAL(IpAdressAndPortGot()),this,SLOT(ConnectToServerClient()));
    connect(this,SIGNAL(ZapytajSerwer(int,int,int)),this->_serverClient,SLOT(OdbierzSygnalOdKlienta(int,int,int)));


}

MainWindow::~MainWindow()
{
    delete ui;
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
    delete this->_serverClient;
    this->_serverClient = new ServerClient(_ipAdress,_port);
    connect(this,SIGNAL(ZapytajSerwer(int,int,int)),this->_serverClient,SLOT(OdbierzSygnalOdKlienta(int,int,int)));

}

