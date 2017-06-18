#ifndef SERVERCLIENT_H
#define SERVERCLIENT_H

#include <QObject>
#include <QTcpSocket>
struct ServerData
{
    int Id;
    int Size;
    char Content[100];
};
class ServerClient : public QObject
{
    Q_OBJECT
public:
    explicit ServerClient(QString IpAdress, int Port, QObject *parent = 0);
    bool Connect();

signals:
    void EmitujWartosci(float temperatura, QString Pogoda);
public slots:

    void OdbierzSygnalOdKlienta(int dzien,int miesiac, int pora);

private:

    QString _ipAdress;
    int _port;
    QTcpSocket* _tcpSocket;
};

#endif // SERVERCLIENT_H
