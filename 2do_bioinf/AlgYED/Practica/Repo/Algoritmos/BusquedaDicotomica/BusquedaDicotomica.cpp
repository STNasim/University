#include "BusquedaDicotomica.h"

template <class T>
int busqueda_dicotomica(ArregloDin<T> pArr, T param)
{
    bool salir=false;
    unsigned int pos=pArr.getTamanio()/2;
    unsigned int despl=pos;
    int retorno=0;
    while (!salir)
    {
        if(pArr[pos]==param)
        {
            salir=true;
            retorno=pos;
        }
        if(pArr[pos]<param)
        {
            despl/=2;
            pos+=(despl);
        }
        if(pArr[pos]>param)
        {
            despl/=2;
            pos-=(despl);
        }
        if(despl<1)
        {
            salir=true;
            retorno=-1;
        }
    }
    return retorno;
}

int busqueda_dicotomica_Vector(vector<long> pVector, long param)
{
    bool salir=false;
    unsigned int pos=pVector.size()/2;
    unsigned int despl=pos;
    int retorno=0;
    while (!salir)
    {
        if(pVector[pos]==param)
        {
            salir=true;
            retorno=pos;
        }
        if(pVector[pos]<param)
        {
            despl/=2;
            pos+=(despl);
        }
        if(pVector[pos]>param)
        {
            despl/=2;
            pos-=(despl);
        }
        if(despl<1)
        {
            salir=true;
            retorno=-1;
        }
    }
    return retorno;
}
