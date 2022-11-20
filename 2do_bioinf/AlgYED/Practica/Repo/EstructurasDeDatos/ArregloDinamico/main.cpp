#include <QCoreApplication>
#include <iostream>
#include <arreglodin.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ArregloDin<int> arr,arr2;

    mostrarArr(arr);
    cout<<endl;

    arr.agregar(1);
    arr.agregar(2);
    arr.agregar(9);

    mostrarArr(arr);
    cout<<endl;
    cout<<arr.size()<<endl;

    arr.resize(10);

    mostrarArr(arr);
    cout<<endl;
    cout<<arr.size()<<endl;

    arr.resize(15,-20); //Se modifica el tamaño y ademas se inicializan los nuevos valores en -20

    mostrarArr(arr);
    cout<<endl;
    cout<<arr.size()<<endl;

    arr2=arr;

    mostrarArr(arr2);

    cout<<"Finalizado";
    return a.exec();
}
