#include <QCoreApplication>
#include <iostream>
#include "listadecontactos.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {
        //IMPORTANTE
        //MODIFICAR std::to_string(dato) a std::to_string(dato.clave) en nodo AVL
        ListaDeContactos agenda;
        agenda.agregar(43245,"nasim@hotmail.com","Nasim");
        agenda.agregar(52342,"juan@hotmail.com","Juan");
        agenda.agregar(43249,"pedro@hotmail.com","Pedro");
        agenda.mostrar();
        agenda.borrar(43249);
        cout<<"Despues de borrar 43249: "<<endl;
        agenda.mostrar();
        agenda.modificar(43245,25432);
        cout<<"Despues de modificar 43245"<<endl;
        agenda.mostrar();
    }
    catch (string mje)
    {
        cout << "Error: " << mje << endl;
    }
    catch (...)
    {
        cout << "Error indeterminado..." << endl;
    }
    cout << "Fin de la prueba..." << endl;

    return a.exec();
}
