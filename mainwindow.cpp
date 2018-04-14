#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std; // to remove

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    socket->close();
}

void MainWindow::readyRead() {

    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    QString port = QString::number(senderPort);

    this->ui->recebidoField->clear();
    this->ui->recebidoField->setText(buffer);
    this->ui->recebidoField->append("Sender: " +sender.toString());
    this->ui->recebidoField->append("Port: " + port);

}

void MainWindow::initSocket() {
    socket = new QUdpSocket(this);

    socket->bind(QHostAddress::LocalHost, 4242);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MainWindow::send(QString msg){

    QByteArray Data;
    Data.append(msg);

    QHostAddress sender;
    quint16 senderPort;

    sender.setAddress(this->ui->ipField->text());
    senderPort = this->ui->portField->text().toInt();

    cout << sender.toString().toStdString() << endl;
    cout << QString::number(senderPort).toStdString() << endl;

    socket->writeDatagram(Data, sender, senderPort);
}

void MainWindow::on_pushButton_pressed()
{
    initSocket();

    QString msg = this->ui->mensagemField->text();

    send(msg);

}

/*QUdpSocket Class*/

//void Server:initSocket()
//{
//    updSocket = new QUpdSocket(this);
//    updSocket->bind(QHostAddress::LocalHost, 7755);

//    connect(updSocket, SIGNAL(readyRead()),
//            this, SLOT(readPendingDatagrams()));
//}

//void Server::readPendingDatagrams()
//{
//    while( updSocket->hasPendingDatagrams()) {
//        QByteArray datagram;
//        datagram.resize(updSocket->pendingDatagramSize());
//        QHostAddress sender;
//        quint16 senderPort;

//        updSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

//        processTheDataGram(datagram);
//    }
//}
