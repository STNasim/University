#include <QCoreApplication>
#include "conjunto.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Conjunto A, B, C, D;

    A<<1;A<<2;A<<3;
    B<<3;B<<4;B<<5;B<<3;

    std::cout<<"Los elementos de A son: "<<A;
    std::cout<<"Los elementos de B son: "<<B;

    A>>2;
    std::cout<<"Los elementos de A son: "<<A;

    C=A+B;
    std::cout<<"La suma de A y B es: "<<C;

    D=A*B;
    std::cout<<"La interseccion de A y b es: "<<D;

    return app.exec();
}
