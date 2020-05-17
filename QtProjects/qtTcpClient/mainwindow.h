#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

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
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
    QString message;
    quint16 blockSize;
};

#endif // MAINWINDOW_H
