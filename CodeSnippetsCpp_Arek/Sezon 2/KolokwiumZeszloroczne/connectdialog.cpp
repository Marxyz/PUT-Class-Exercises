#include "connectdialog.h"
#include "ui_connectdialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    connect(this->ui->pushButton_Polacz,SIGNAL(clicked(bool)),this,SLOT(Polacz()));
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::Polacz()
{
    this->ipAddress = this->ui->lineEdit_Ip_Address->text();
    this->port = this->ui->lineEdit_Port->text().toInt();
    emit ButtonSend();
    this->close();
}
