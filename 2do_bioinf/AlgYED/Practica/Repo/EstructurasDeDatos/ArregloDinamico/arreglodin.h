#ifndef ARREGLODIN_H
#define ARREGLODIN_H
#include <iostream>
using namespace std;

template <class T>
class ArregloDin
{
public:
    ~ArregloDin();
    ArregloDin();
    void agregar(T pValor);
    void resize(unsigned int pTamNuevo, T pVal=0);
    T getValor(unsigned int i);
    T& operator[](unsigned int i);
    unsigned int size();
    void push_back(T pValor);
    void operator=(ArregloDin asignado);

private:
    T* ptr_datos;
    unsigned int tam;
    unsigned int capacidad;
};

template <class T>
void mostrarArr(ArregloDin<T> &pArr);
template <class T>
ArregloDin<T>::ArregloDin()
{
    ptr_datos=nullptr;
    tam=0;
    capacidad=1;
}

template <class T>
ArregloDin<T>::~ArregloDin()
{
    if(nullptr!=ptr_datos)
        delete[]ptr_datos;
}

template <class T>
void ArregloDin<T>::agregar(T pValor)
{
    if(ptr_datos==nullptr)
    {
        ptr_datos = new T[1];
        tam=1;
        ptr_datos[0]=pValor;
    }
    else
    {
        if(tam+1>capacidad)
        {
            capacidad*=2;
            T* ptr_aux= new T[capacidad];
            for(unsigned int i=0;i<tam;i++)
            {
                ptr_aux[i]=ptr_datos[i];
            }
            ptr_aux[tam]=pValor;
            delete []ptr_datos;
            ptr_datos= ptr_aux;
        }
        else
            ptr_datos[tam]=pValor;
        tam++;
    }
}
template <class T>
void ArregloDin<T>::resize(unsigned int pTamNuevo, T pVal)
{
    if(pTamNuevo>=0 and pTamNuevo!=tam)
    {
        if(ptr_datos==nullptr)
        {
            while(capacidad<pTamNuevo)
                capacidad*=2;
            ptr_datos=new T[capacidad];
            for(unsigned int i=0;i<tam;i++)
                ptr_datos[i]=pVal;
        }
        else{
            if(pTamNuevo>tam)
            {
                while(capacidad<pTamNuevo)
                    capacidad*=2;
                T* ptr_aux= new T [capacidad];
                unsigned int i;
                for(i=0;i<tam;i++)
                {
                    ptr_aux[i]=ptr_datos[i];
                }
                for(;i<pTamNuevo;i++)
                    ptr_aux[i]=pVal;
                delete[]ptr_datos;
                ptr_datos=ptr_aux;
            }
        }
        tam=pTamNuevo;
    }
}
template <class T>
T ArregloDin<T>::getValor(unsigned int i)
{
    return ptr_datos[i];
}
template <class T>
T& ArregloDin<T>::operator[](unsigned int i)
{
    return ptr_datos[i];
}
template <class T>
unsigned int ArregloDin<T>::size()
{
    return tam;
}
template <class T>
void ArregloDin<T>::push_back(T pValor)
{
    agregar(pValor);
}
template <class T>
void ArregloDin<T>::operator=(ArregloDin asignado)
{
    resize(asignado.tam);
    for(unsigned int i=0;i<tam;i++)
        ptr_datos[i]=asignado.ptr_datos[i];
}
template <class T>
void mostrarArr(ArregloDin<T> &pArr)
{
    cout<<"Arreglo: [";
    for(unsigned int i=0;i<pArr.size();i++)
    {
        cout<<pArr.getValor(i);
        if(i!=pArr.size()-1)
            cout<<",";
    }
    cout<<"]";
}
#endif // ARREGLODIN_H
