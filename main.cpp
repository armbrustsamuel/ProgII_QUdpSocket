/*
Para tanto,  o programa deverá ter duas funções principais:

1- Ao iniciar, ele deverá  criar um socket e iniciar o
monitoramento de uma porta(endereço local), como padrão
usaremos a porta 4242.

2- Deve permitir enviar uma mensagem para um endereço IP
especificado. Caso  o programa também esteja rodando na
máquina destino, este deverá receber a mensagem  exibir
na tela junto com a informação da porta e IP de onde veio
a mensagem para que possa ser respondida.
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

//    return 0;
}
