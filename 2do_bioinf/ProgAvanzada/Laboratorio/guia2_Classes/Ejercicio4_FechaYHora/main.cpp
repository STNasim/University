#include <QCoreApplication>
#include "fechahora.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FechaHora Reloj;
    Reloj.MostarFecha();
    Reloj.MostarHora();

    return a.exec();
}
