#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
struct Student{
    QString imie;
    QString nazwisko;
    QString email;
    QString indeks;
    bool kobieta;
    bool ukonczoneStudia;
    QString kierunek;
    QString notatka;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonDodaj_clicked();

    void on_pushButtonUsun_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Student> studenci;

};

#endif // MAINWINDOW_H
