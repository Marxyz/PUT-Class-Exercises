#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList kierunki;
    kierunki<<"Automatyka i Robotyka"<<"Informatyka"<<"Zip";
    ui->comboBox->addItems(kierunki);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonDodaj_clicked()
{
    Student student;
    student.imie = ui->lineName->text();
    student.nazwisko = ui->lineNazwisko->text();
    student.email = ui->lineEmail->text();
    student.indeks = ui->lineIndeks->text();
    student.kobieta = ui->radioPlec->isChecked();
    student.ukonczoneStudia = ui->checkBox->isChecked();
    student.kierunek = ui->comboBox->currentText();
    student.notatka = ui->plainTextEdit->toPlainText();
    studenci.push_back(student);
    ui->listWidget->addItem(student.imie + " "+ student.nazwisko);


}

void MainWindow::on_pushButtonUsun_clicked()
{
    ui->listWidget->currentItem()->setHidden(true);
}
