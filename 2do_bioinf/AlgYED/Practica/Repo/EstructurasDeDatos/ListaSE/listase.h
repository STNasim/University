#ifndef LISTASE_H
#define LISTASE_H
#include <string>
#include <iostream>
using namespace std;

template<class T>
class ListaSE
{
public:
    ListaSE();
    ~ListaSE();

    void agregar(T elemento);   // agrega al final de la lista.

    // agrega en la posición "pos" de la lista. "pos" debe ser: 0 <= pos <= tamanio
    void agregar(T elemento, unsigned pos);

    void recorrer(void (*fun)(T& val));

    void eliminar(unsigned int pos);

    void eliminar();

    T get(unsigned pos);

    void set(T val, unsigned pos);

    unsigned size();

    void vaciar();

    void unir(ListaSE<T> &lista1,ListaSE<T> &lista2);

    int buscar(T val);

    void ordenar();

private:                    // [Nodo (dato, ptr_sig)] --ptr_sig---> [Otro Nodo]---> x
    // Se define clase Nodo dentro del ámbito de la clase ListaSE.
    class Nodo{
    public:
        T dato;
        Nodo *ptr_sig;
        Nodo(T pDato = T(0), Nodo *pPtr = nullptr){
            dato = pDato;
            ptr_sig = pPtr;
        }
    };

    // Atributos de la lista.
    Nodo *ppn;              // Puntero al primer nodo
    unsigned int tamanio;   // Cantidad actual de elementos
    void dividirRecursivo(ListaSE<T> lista);
    void mezclar(ListaSE<T> &izq, ListaSE<T>&der,ListaSE<T> &A);
};

template<class T>
ListaSE<T>::ListaSE()
{
    ppn = nullptr;
    tamanio = 0;
}

template<class T>
ListaSE<T>::~ListaSE()
{
    Nodo *ptr_aux;
    while( ppn )
    {
        ptr_aux = ppn;
        ppn = ppn->ptr_sig; // En algún momento, para el úlitmo nodo, ptr_sig será NULL.
        delete ptr_aux;
    }
}

template<class T>
void ListaSE<T>::agregar(T elemento)
{
    agregar(elemento, tamanio);
}

template<class T>
void ListaSE<T>::agregar(T elemento, unsigned pos)
{
    // Etapa 1: Validación de la posición "pos"
    // Caso 1: Pos inválida
    if( pos > tamanio )
    {
        throw string("Posición de inserción inválida en agregar().");
    }

    // Etapa 2: Si "pos" es válida, se inserta el nuevo nodo.
    Nodo *ptr_aux = new Nodo(elemento);

    // Caso 1: la lista está vacía.   [ ]
    if( 0 == tamanio )
    {
        ppn = ptr_aux;
    }
    // Caso 2: la lista NO está vacía.   [ val; val; .... ; val ]
    else
    {
        //  Caso 2.1: Insertar al inicio
        if( 0 == pos )
        {
            // Situación previa:
            //      ptr_aux---->[Nodo(elemento, 0)]
            //      ppn--->[Nodo(val1,ptr_sig)]---ptr_sig--->[Nodo(val2,ptr_sig)]--> X
            ptr_aux->ptr_sig = ppn;
            // Situación posterior:
            //      ptr_aux---->[Nodo(elemento, ppn)]--ppn->[Nodo(val1,ptr_sig)]--ptr_sig-->[Nodo(val2,0)]
            ppn = ptr_aux;
            // Situación posterior:
            //      ppn---->[Nodo(elemento, ptr_sig)]--ptr_sig-->[Nodo(val1,ptr_sig)]--ptr_sig-->[Nodo(val2,0)]
        }
        // Caso 2.2: Insertar luego del primer nodo
        else
        {
            // Situación previa:
            //       ptr_aux_2 --
            //                   \      0                                1                                  2
            //       ppn---->[Nodo(elemento, ptr_sig)]--ptr_sig-->[Nodo(val1,ptr_sig)]--ptr_sig--> <insert>[Nodo(val2,0)]
            Nodo* ptr_aux_2 = ppn;

            //                                              ptr_aux_2 --
            //       ppn---->[Nodo(elemento, ptr_sig)]--ptr_sig-->[Nodo(val1,ptr_sig)]--ptr_sig--> <insert>[Nodo(val2,0)]
            for(unsigned i=0; i<pos-1; ++i)
                ptr_aux_2 = ptr_aux_2->ptr_sig;

            //                                         ptr_aux_2 --                     ptr_aux --
            //   ppn---->[Nodo(elemento, ptr_sig)]--ptr_sig-->[Nodo(val1,ptr_sig)]--ptr_sig-->NuevoNodo[]-->[Nodo(val2,0)]
            ptr_aux->ptr_sig = ptr_aux_2->ptr_sig;
            ptr_aux_2->ptr_sig = ptr_aux;
        }
    }
    ++tamanio;
}

template<class T>
void ListaSE<T>::recorrer(void (*fun)(T &))
{
    Nodo *ptr_aux = ppn;
    while( ptr_aux )
    {
        fun(ptr_aux->dato);
        ptr_aux = ptr_aux->ptr_sig; // Mover hacia adelante el puntero.
    }
}

template<class T>
void ListaSE<T>::eliminar(unsigned int pos)
{
    if(pos<tamanio)
    {
        Nodo *ptr_aux=ppn;
        if(pos==0)
        {
            ppn=ppn->ptr_sig;
            delete ptr_aux;
        }
        else
        {
            Nodo *ptr_aux_2;
            for(unsigned int i=0; i<pos-1; ++i)
                ptr_aux = ptr_aux->ptr_sig;
            if(ptr_aux->ptr_sig==nullptr)
            {
                delete ptr_aux;
            }
            else
            {
                ptr_aux_2=ptr_aux->ptr_sig;
                ptr_aux->ptr_sig=ptr_aux_2->ptr_sig;
                delete ptr_aux_2;
            }
        }
        tamanio--;
    }
    else
        throw string("Posición inválida en eliminar().");
}

template<class T>
void ListaSE<T>::eliminar()
{
    eliminar(tamanio-1);
}

template<class T>
T ListaSE<T>::get(unsigned pos)
{
    if( pos > tamanio )
    {
        throw string("Posición de inserción inválida en agregar().");
    }
    else
    {
        Nodo *ptr_aux=ppn;
        for(unsigned int i=0; i<pos; ++i)
            ptr_aux = ptr_aux->ptr_sig;
        return ptr_aux->dato;
    }
}

template<class T>
void ListaSE<T>::set(T val, unsigned pos)
{
    if( pos > tamanio )
    {
        throw string("Posición de inserción inválida en agregar().");
    }
    else
    {
        Nodo *ptr_aux=ppn;
        for(unsigned int i=0; i<pos; ++i)
            ptr_aux = ptr_aux->ptr_sig;
        ptr_aux->dato=val;
    }
}

template<class T>
unsigned ListaSE<T>::size()
{
    return tamanio;
}

template<class T>
void ListaSE<T>::vaciar()
{
    if(ppn!=nullptr)
        for(int i=tamanio-1;i>-1;i--)
            this->eliminar(i);
    tamanio=0;
}

template<class T>
void ListaSE<T>::unir(ListaSE<T> &lista1, ListaSE<T> &lista2)
{
    vaciar();
    unsigned int i=0;
    for(;i<lista1.size();i++)
        agregar(lista1.get(i),i);
    for(unsigned int j=0;j<lista2.size();j++)
        agregar(lista2.get(j),i+j);
    tamanio=lista1.size()+lista2.size();
}

template<class T>
int ListaSE<T>::buscar(T val)
{
    bool encontrado=false;
    int indice=0;
    unsigned int i=0;
    for(;i<size() && !encontrado;i++)
    {
        if(get(i)==val)
        {
            encontrado=true;
            indice=i;
        }
    }
    if(!encontrado)
        indice=-1;
    return indice;
}

template<class T>
void ListaSE<T>::ordenar()
{
    if(tamanio>=2)
    {
    ListaSE<T> izq, der;
    dividirLista(*this,(tamanio/2)-1,izq,der);
    izq.ordenar();
    der.ordenar();
    mezclar(izq,der,*this);
    }
}

template<class T>
void ListaSE<T>::mezclar(ListaSE<T> &izq, ListaSE<T>&der,ListaSE<T> &salida)
{
    unsigned int i=0,j=0,k=0;
    while(i<izq.size() && j<der.size())
    {
        if(izq.get(i)<=der.get(j))
        {
            salida.set(izq.get(i),k);
            i++;
        }
        else
        {
            salida.set(der.get(j),k);
            j++;
        }
        k++;
    }
    while(i<izq.size())
    {
        salida.set(izq.get(i),k);
        i++;
        k++;
    }
    while(j<der.size())
    {
        salida.set(der.get(j),k);
        j++;
        k++;
    }
}

template<class T>
void copiarLista(ListaSE<T> &origen, ListaSE<T> &destino)
{
    if(origen.size()==destino.size())
        for(unsigned int i=0;i<origen.size();i++)
            destino.set(origen.get(i),i);

    if(origen.size()<destino.size())
    {
        for(unsigned int i=0;i<origen.size();i++)
            destino.set(origen.get(i),i);
        for(unsigned int i=destino.size()-1;i>origen.size()-1;i--)
            destino.eliminar(i);
    }
    if(origen.size()>destino.size())
    {
        for(unsigned int i=0;i<destino.size();i++)
            destino.set(origen.get(i),i);
        for(unsigned int i=destino.size();i<origen.size();i++)
            destino.agregar(origen.get(i),i);
    }
}

template<class T>
void dividirLista(ListaSE<T> &origen, unsigned int pos,ListaSE<T> &destino1, ListaSE<T> &destino2)
{
    if(pos==0 && origen.size()==0)
    {
        destino1.vaciar();
        destino2.vaciar();
    }
    if(pos<origen.size())
    {
        ListaSE<T> aux;
        copiarLista(origen,aux);
        destino1.vaciar();
        destino2.vaciar();
        unsigned int i=0;
        for(;i<=pos;i++)
        {
            destino1.agregar(aux.get(i));

        }
        for(;i<aux.size();i++)
        {
            destino2.agregar(aux.get(i));
        }
    }
}

#endif // LISTASE_H
