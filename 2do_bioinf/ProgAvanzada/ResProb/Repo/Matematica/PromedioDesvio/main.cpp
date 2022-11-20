#include <QCoreApplication>
#include <promdesv.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PromDesv PM;

    PM.CargaDatos();
    PM.MostrarPM(PM.PromCarga(),PM.DesvCarga());

    return a.exec();
}
