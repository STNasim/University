#include "OrdenamientosBasicos.h"
template <class T>
void ord_burbuja(ArregloDin<T> &pArr)
{
    if(pArr.size()>1)
    {
        unsigned int n=pArr.size();
        T aux;
        bool salir=false;
        for(unsigned int pasada=1;pasada<n  and !salir;pasada++)
        {
            salir=true;
            for(unsigned int i=0; i<n-pasada; i++)
            {
                if(pArr[i]>pArr[i+1])
                {
                    aux=pArr[i];
                    pArr[i]=pArr[i+1];
                    pArr[i+1]=aux;
                    salir=false;
                }
            }
        }
    }
}
template <class T>
void ord_seleccion(ArregloDin<T> &pArr)
{
    if(pArr.size()>1)
    {
        unsigned int n=pArr.size();
        unsigned selec;
        T aux;
        for(unsigned int pasada=1;pasada<n;pasada++)
        {
            selec=n-pasada;
            for(unsigned int i=0; i<n-pasada; i++)
            {
                if(pArr[selec]<pArr[i])
                {
                    selec=i;
                }
                aux=pArr[n-pasada];
                pArr[n-pasada]=pArr[selec];
                pArr[selec]=aux;
            }
        }
    }
}
template <class T>
void ord_insercion(ArregloDin<T> &pArr)
{
    if(pArr.size()>1)
    {
        T aux;
        for(unsigned int i=1;i<pArr.size();++i)
        {
            aux=pArr[i];
            int j=i-1;
            while(j>=0 and aux<pArr[j])
            {
                pArr[j+1]=pArr[j];
                --j;
            }
            pArr[j+1]=aux;
        }
    }
}

void ord_burbuja(vector<long> &pArr)
{
    if(pArr.size()>1)
    {
        unsigned int n=pArr.size();
        long aux;
        bool salir=false;
        for(unsigned int pasada=1;pasada<n  and !salir;pasada++)
        {
            salir=true;
            for(unsigned int i=0; i<n-pasada; i++)
            {
                if(pArr[i]>pArr[i+1])
                {
                    aux=pArr[i];
                    pArr[i]=pArr[i+1];
                    pArr[i+1]=aux;
                    salir=false;
                }
            }
        }
    }
}

void ord_seleccion(vector<long> &pArr)
{
    if(pArr.size()>1)
    {
        unsigned int n=pArr.size();
        unsigned selec;
        long aux;
        for(unsigned int pasada=1;pasada<n;pasada++)
        {
            selec=n-pasada;
            for(unsigned int i=0; i<n-pasada; i++)
            {
                if(pArr[selec]<pArr[i])
                {
                    selec=i;
                }
                aux=pArr[n-pasada];
                pArr[n-pasada]=pArr[selec];
                pArr[selec]=aux;
            }
        }
    }
}

void ord_insercion(vector<long> &pArr)
{
    if(pArr.size()>1)
    {
        long aux;
        for(unsigned int i=1;i<pArr.size();++i)
        {
            aux=pArr[i];
            int j=i-1;
            while(j>=0 and aux<pArr[j])
            {
                pArr[j+1]=pArr[j];
                --j;
            }
            pArr[j+1]=aux;
        }
    }
}

void ord_insercion(deque<int> &plListaDoble)
{
    if(plListaDoble.size()>1)
    {
        int aux;
        for(unsigned int i=1;i<plListaDoble.size();++i)
        {
            aux=plListaDoble[i];
            int j=i-1;
            while(j>=0 and aux<plListaDoble[j])
            {
                plListaDoble[j+1]=plListaDoble[j];
                --j;
            }
            plListaDoble[j+1]=aux;
        }
    }
}
