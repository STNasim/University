#include <QCoreApplication>
#include "BusquedaDicotomica.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    ArregloDin prueba;

//    prueba.agregar(1);
//    prueba.agregar(2);
//    prueba.agregar(3);
//    prueba.agregar(4);
//    prueba.agregar(5);
//    prueba.agregar(6);
//    prueba.agregar(7);
//    prueba.agregar(8);
//    prueba.agregar(9);

//    int retorno=busqueda_dicotomica_Arrdin(prueba,5);

    vector<int> prueba;

    prueba.push_back(-1);
    prueba.push_back(2);
    prueba.push_back(6);
    prueba.push_back(9);
    prueba.push_back(13);
    prueba.push_back(15);
    prueba.push_back(18);
    prueba.push_back(21);
    prueba.push_back(31);

    int retorno=busqueda_dicotomica_Vector(prueba,15);

    cout<<retorno;

    return a.exec();
}
