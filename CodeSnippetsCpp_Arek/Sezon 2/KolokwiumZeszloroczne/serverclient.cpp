#include "serverclient.h"

ServerClient::ServerClient(QString IpAdress, int Port,QObject *parent) : QObject(parent)
{
    this->_ipAdress = IpAdress;
    this->_port = Port;
    _tcpSocket = new QTcpSocket();
}

bool ServerClient::Connect()
{
    _tcpSocket->connectToHost(_ipAdress,_port);
    bool connected = _tcpSocket->waitForConnected();
    return connected;
}

void ServerClient::OdbierzSygnalOdKlienta(int dzien, int miesiac, int pora)
{
    if(Connect())
    {
        if (pora == 1)
        {
            QString text = "XDDDDDDDDDDDDDDD";
            ServerData data;
            data.Id = 1;
            data.Size = text.size();
            strcpy(data.Content,text.toLatin1().data());

            _tcpSocket->write((char*)&data,sizeof data);
            if(_tcpSocket->waitForBytesWritten())
            {
                _tcpSocket->disconnectFromHost();
                _tcpSocket->waitForDisconnected();
                return;
            }

        }
        if (pora == 2)
        {
            ServerData sendData,recvdData;
            sendData.Id = 2;
            _tcpSocket->write((char*)&sendData,sizeof sendData);
            if(_tcpSocket->waitForBytesWritten())
            {

                if(_tcpSocket->waitForReadyRead())
                {
                    _tcpSocket->read((char*)&recvdData,sizeof recvdData);
                    _tcpSocket->waitForReadyRead();
                    _tcpSocket->disconnectFromHost();
                    _tcpSocket->waitForDisconnected();
                    return;
                }
            }
        }
    }
}
