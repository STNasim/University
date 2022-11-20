#include <QCoreApplication>
#include <iostream>
#include "abb_biselado.h"
using namespace std;


int main(int argc, char *argv[])
{
    using namespace abb_bis_template;
    QCoreApplication a(argc, argv);
    try
    {
        ABB_BIS<int> abb;
        abb.setBiselado(true);
        cout<<"Agrego 10"<<endl;
        abb.agregar(10);
        cout<<abb<<endl;
        cout<<"Agrego 80"<<endl;
        abb.agregar(80);
        cout<<abb<<endl;
        cout<<"Agrego 50"<<endl;
        abb.agregar(50);
        cout<<abb<<endl;
        cout<<"Agrego 40"<<endl;
        abb.agregar(40);
        cout<<abb<<endl;
        cout<<"Agrego 20"<<endl;
        abb.agregar(20);
        cout<<abb<<endl;
        cout<<"Agrego 100"<<endl;
        abb.agregar(100);
        cout<<abb<<endl;
        cout<<"Agrego -10"<<endl;
        abb.agregar(-10);
        cout<<abb<<endl;
        cout<<"Agrego -50"<<endl;
        abb.agregar(-50);
        cout<<abb<<endl;
        cout<<"Agrego 30"<<endl;
        abb.agregar(30);
        cout<<abb<<endl;
        cout<<"Agrego 120"<<endl;
        abb.agregar(120);
        cout<<abb<<endl;
        cout<<"Busco 40"<<endl;
        abb.buscar(40);
        cout<<abb<<endl;
        cout<<"Busco 30"<<endl;
        abb.buscar(30);
        cout<<abb<<endl;
        cout<<"Borro 120"<<endl;
        abb.borrar(120);
        cout<<abb<<endl;
        cout<<"Borro -30"<<endl;
        abb.borrar(-30);
        cout<<abb<<endl;


        ABB_BIS<int> abb2,abb3;

        abb2.agregar(5);
        abb2.agregar(4);
        abb2.agregar(3);
        abb2.agregar(2);
        abb2.agregar(1);

        cout<<"abb2 :"<<endl;
        cout<<abb2<<endl;

        cout<<"abb2 biselando(5): "<<endl;
        abb2.setBiselado(true);
        abb2.buscar(5);
        cout<<abb2<<endl;

        abb3.agregar(5);
        abb3.agregar(4);
        abb3.agregar(3);
        abb3.agregar(2);
        abb3.agregar(1);

        cout<<"abb3 :"<<endl;
        cout<<abb3<<endl;

        cout<<"abb3 move to root(5): "<<endl;
        abb3.setBiselado(false);
        abb3.buscar(5);
        cout<<abb3<<endl;
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
