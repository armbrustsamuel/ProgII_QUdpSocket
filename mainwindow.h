#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QUdpSocket>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void send(QString msg);
    void initSocket();

private slots:
    void on_pushButton_pressed();
    void readyRead();

private:
    Ui::MainWindow *ui;
    QUdpSocket * socket;
};

#endif // MAINWINDOW_H
