#include <QCoreApplication>
#include <opmatriciales.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    OpMatriciales OpMat;

    OpMat.Ingreso();
    OpMat.Determinante();
    OpMat.ValorMax();
    OpMat.Transpuesta();
    OpMat.MostrarResultados();

    return a.exec();
}
