#include <QCoreApplication>
#include <iostream>
#include <gennumaleatorio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GenNumAleatorio gna;

    float numero_real;

    gna.CargaDatos();
    numero_real= gna.RealAleatorio();

    std::cout<<numero_real<<std::endl;

    return a.exec();
}
