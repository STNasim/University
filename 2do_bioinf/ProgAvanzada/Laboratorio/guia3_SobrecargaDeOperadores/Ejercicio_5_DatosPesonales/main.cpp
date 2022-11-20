#include <QCoreApplication>
#include "datospersonales.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::ifstream archi;
    archi.open("DatosPersonales.txt");

    DatosPersonales Datos1,Datos2,Datos3;
    std::string string1,string2,string3;

    if(archi.is_open())
//        archi>>Datos1>>Datos2>>Datos3;
        archi>>Datos1;

    return a.exec();
}
