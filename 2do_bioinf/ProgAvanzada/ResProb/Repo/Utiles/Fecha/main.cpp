#include <QCoreApplication>
#include "fecha.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Fecha Fec;
    char FechaUsuario[10];
    Fec.IngresoFecha(FechaUsuario);
    Fec.DifFechaActual(FechaUsuario);
    Fec.FechaMayorActual(FechaUsuario);


    return a.exec();
}
