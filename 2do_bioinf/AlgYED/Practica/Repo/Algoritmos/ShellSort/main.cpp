#include <QCoreApplication>
#include <iostream>
#include "../../EstructurasDeDatos/ArregloDinamico/arreglodin.h"
#include "ShellSort.h"
#include <deque>
using namespace std;

template<class Contenedor>  bool esta_ordenado(Contenedor& c)
{
    bool ordenado=true;
    for(unsigned int i=0;i<(c.size()-1) && ordenado;i++)
    {
        if(c[i]>c[i+1])
            ordenado=false;
    }
    return ordenado;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        srand (time(0));

        vector<long long> vec;
        vec.resize(100000);
        for(unsigned int i=0;i<vec.size();i++)
        {
            vec[i]=rand();
        }
        shellSort(vec);
        if(esta_ordenado(vec))
            cout<<"vector ordenado"<<endl;
        else
            cout<<"vector no ordenado"<<endl;

        ArregloDin<long long> arr;
        arr.resize(100000);
        for(unsigned int i=0;i<arr.size();i++)
        {
            arr[i]=rand();
        }
        shellSort(arr);
        if(esta_ordenado(arr))
            cout<<"arreglo din ordenado"<<endl;
        else
            cout<<"arreglo no ordenado"<<endl;

        deque<long long> deq;
        deq.resize(100000);
        for(unsigned int i=0;i<deq.size();i++)
        {
            deq[i]=rand();
        }
        shellSort(deq);
        if(esta_ordenado(deq))
            cout<<"Deque ordenado"<<endl;
        else
            cout<<"Deque no ordenado"<<endl;
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
