#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connectdialog.h"
#include "serverclient.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void ZapytajSerwer(int dzien,int miesiac, int pora);
private slots:

    void Wyslij();
    void Polacz();
    void DialogButtonSend();

private:

    QString _ipAdress;
    int _port;
    ServerClient* _serverClient;
    ConnectDialog* _connectDialog;
    bool _connected;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
