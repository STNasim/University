#include <QApplication>
#include "ctime"
#include "testcartas.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);
        srand(static_cast<unsigned int>(time(nullptr)));

        TestCartas test;
        test.seleccionaMazo();
        test.repartirCartas();
    }
    catch(...)
    {
        cout<<"Error en la ejecucion"<<endl;
    }
    return 0;
}
