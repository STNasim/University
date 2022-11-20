#include <QCoreApplication>

#include <iostream>
#include <string>

#include "listase.h"

using namespace std;

void mostrar(float &val);

void multiplicarX2(float  &val);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    system("chcp 65001");
    try {
        ListaSE<float> lis,lis_2,lis_3,lis_4;

        lis.agregar(1.2);       // [ 1.2 ]
        lis.agregar(2.3);       // [ 1.2; 2.3 ]
        lis.agregar(3.4, 0);    // [ 3.4; 1.2; 2.3 ]
        lis.agregar(4.5, 0);    // [ 4.5; 3.4; 1.2; 2.3 ]
        //    0    1    2    3    4
        lis.agregar(5.6, 1);    // [ 4.5; 5.6; 3.4; 1.2; 2.3 ]
        lis.agregar(99, 5);     // [ 4.5; 5.6; 3.4; 1.2; 2.3; 99 ]

        lis.eliminar(0); // [ 5.6; 3.4; 1.2; 2.3; 99 ]
        lis.eliminar(3); // [ 5.6; 3.4; 1.2; 99 ]
        lis.eliminar(); // [ 5.6; 3.4; 1.2 ]

        cout << "Lista: ";
        lis.recorrer(mostrar);
        cout << endl << endl;

        cout<<"El valor en la pos 1 es: "<<lis.get(1)<<endl;

        lis.set(2.5,2);
        cout << "Lista: ";
        lis.recorrer(mostrar);
        cout << endl << endl;

        cout<<"size lista 1: "<<lis.size()<<endl;

        copiarLista(lis,lis_2);
        cout<<"Lista 2: ";lis_2.recorrer(mostrar);cout<<"Tamaño de lista: "<<lis_2.size();cout<<endl;

        lis_3.agregar(5);
        lis_3.agregar(6);
        lis_3.agregar(7);
        lis_3.agregar(2);
        lis_3.agregar(1);

        copiarLista(lis,lis_3);
        cout<<"Lista 3: ";lis_3.recorrer(mostrar);cout<<"Tamaño de lista: "<<lis_3.size();cout<<endl;

        lis_4.agregar(9);
        lis_4.agregar(1);
        lis_4.agregar(7);

        copiarLista(lis,lis_4);
        cout<<"Lista 4: ";lis_4.recorrer(mostrar);cout<<"Tamaño de lista: "<<lis_4.size();cout<<endl;

        lis_4.vaciar();
        cout<<"Lista 4: ";lis_4.recorrer(mostrar);cout<<"Tamaño de lista: "<<lis_4.size();cout<<endl;

        lis_3.unir(lis,lis_2);
        cout<<"Lista 3: ";lis_3.recorrer(mostrar);cout<<"Tamaño de lista: "<<lis_3.size();cout<<endl;

        dividirLista(lis_3,4,lis,lis_2);
        cout << "Lista: ";
        lis.recorrer(mostrar);cout<<"Tamaño de lista: "<<lis.size();
        cout<<"Lista 2: ";lis_2.recorrer(mostrar);cout<<"Tamaño de lista: "<<lis_2.size();cout<<endl;

        cout<<"Buscar 2.5 en lista3: "<<lis_3.buscar(2.5)<<endl;
        cout<<"Buscar 5.213 en lista3: "<<lis_3.buscar(5.213)<<endl;

        lis_3.ordenar();
        cout<<"Lista 3: ";lis_3.recorrer(mostrar);cout<<endl;

    }
    catch (string mensaje) {
        cout << "Error: " << mensaje << endl;
    }
    catch (...) {
        cout << "Error indefinido..." << endl;
    }

    cout << "Prueba finalizada..." << endl;
    return a.exec();
}

void mostrar(float &val){
    cout << val << "; ";
}
