#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::LocalHost,6666)){
        qDebug() << tcpServer->errorString();
        close();
    }
    connect(tcpServer,SIGNAL(newConnection()),
            this,SLOT(sendMessage()));


}

void MainWindow::sendMessage(){
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << (quint16)0;
    out << tr("hello");
    out.device()->seek(0);
    out << (quint16)(block.size()-sizeof(quint16));
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection,SIGNAL(disconnected()),
            clientConnection,SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();
    ui->statuslabel->setText("send message successful!!!");
}

MainWindow::~MainWindow()
{
    delete ui;
}
