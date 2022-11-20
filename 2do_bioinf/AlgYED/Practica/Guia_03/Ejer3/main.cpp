#include <QCoreApplication>
#include <iostream>
#include <deque>
#include "Mezcla.h"
#include "../../Repo/EstructurasDeDatos/ArregloDinamico/arreglodin.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {
        cout<<"Este algoritmo presenta una complejidad de O(n+m),"
              "ya que se realizan n y m asignaciones al contenedor que se retorna"<<endl;
        srand (time(0));

        vector <int> vector1,vector2,vector3;
        vector1.resize(100000);
        vector2.resize(100000);

        for(unsigned int i=0;i<100000;i++)
        {
            vector1[i]=rand();
            vector2[i]=rand();
        }

        sort(vector1.begin(),vector1.end());
        sort(vector2.begin(),vector2.end());
        vector3=mezclar(vector1,vector2);

        if(esta_ordenado(vector3))
            cout<<"vector3 esta ordenado"<<endl;
        else
            cout<<"vector3 no esta ordenado"<<endl;


        ArregloDin<int> arr1,arr2,arr3;
        arr1.resize(100000);
        arr2.resize(100000);

        int j=0,k=0;
        for(unsigned int i=0;i<100000;i++)
        {
            arr1[i]=j+rand()%5;
            arr2[i]=k+rand()%3;
            j+=7;
            k+=4;
        }

        arr3=(mezclar(arr1,arr2));
        if(esta_ordenado(arr3))
            cout<<"arr3 esta ordenado"<<endl;
        else
            cout<<"arr3 no esta ordenado"<<endl;


        deque<string> deque1,deque2,deque3;
        deque1.resize(100000);
        deque2.resize(100000);
        for(unsigned int i=0;i<100000;i++)
        {
            deque1[i]=(to_string(rand()));
            deque2[i]=(to_string(rand()));
        }

        sort(deque1.begin(),deque1.end());
        sort(deque2.begin(),deque2.end());
        deque3=mezclar(deque1,deque2);

        if(esta_ordenado(deque3))
            cout<<"deque3 esta ordenado"<<endl;
        else
            cout<<"deque3 no esta ordenado"<<endl;

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
