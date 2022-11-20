#ifndef ABB_BISELADO_H
#define ABB_BISELADO_H

#include "../ArbolBinarioBusqueda/abb.h"

namespace abb_bis_template {

using namespace std;

template<class Q>
class Nodo_BIS{
public:
    Q dato; // dato almacenado en el nodo
    Nodo_BIS *izq, *der, *ant; // izq: datos menores, der: datos mayores
    Nodo_BIS(const Q& pDato, Nodo_BIS* pptr_ant =nullptr, Nodo_BIS* pptr_izq = nullptr, Nodo_BIS* pptr_der = nullptr){
        dato = pDato; izq = pptr_izq; der = pptr_der;ant=pptr_ant;
    }
    string to_string(){
        return std::to_string(dato);
    }
};

template<class S, class Nodo_BIS = Nodo_BIS<S>>
class ABB_BIS : public ABB<S, Nodo_BIS>
{
public:
    ABB_BIS(){biselado=true;}

    void agregar(const S& pDato);
    void borrar(const S& pDato);
    bool buscar(const S& pDato);
    void setBiselado(bool pDato);

private:
    // para simplificar notación
    Nodo_BIS* &raiz = ABB<S, Nodo_BIS>::raiz;
    unsigned int &N = ABB<S, Nodo_BIS>::N;

    void RSI(Nodo_BIS* pPtr);
    void RSD(Nodo_BIS* pPtr);

    Nodo_BIS * borrar_recursivo_BIS(Nodo_BIS *pRaiz, const S &pDato);
    Nodo_BIS* datoAnterior(const S &pDato);
    void mover(Nodo_BIS* pRaiz);
    void biselar(Nodo_BIS* pRaiz);
    void moveToRoot(Nodo_BIS *pRaiz);
    bool biselado;
};

template<class S>
ostream& operator<<(ostream& pOut, ABB_BIS<S>& pAbb){
    pAbb.volcarEnFlujo( pOut );
    return pOut;
}

template<class S, class Nodo_BIS>
void ABB_BIS<S,Nodo_BIS>::agregar(const S &pDato)
{
    if(nullptr==raiz)
    {
        raiz = new Nodo_BIS( pDato );
        N++;
    }
    else
    {
        Nodo_BIS *aux=raiz;
        bool insertado=false;
        while(!insertado)
        {
            if(pDato>aux->dato)
            {
                if(nullptr==aux->der)
                {
                    aux->der= new Nodo_BIS(pDato,aux);
                    aux=aux->der;
                    insertado=true;
                }
                else
                    aux=aux->der;
            }
            else
                if(nullptr==aux->izq)
                {
                    aux->izq=new Nodo_BIS(pDato,aux);
                    aux=aux->izq;
                    insertado=true;
                }
                else
                    aux=aux->izq;
        }
        mover(aux);
        N++;
    }
}

template<class S, class Nodo_BIS>
void ABB_BIS<S,Nodo_BIS>::borrar(const S &pDato)
{
    if(raiz)
    {
        Nodo_BIS *aux=datoAnterior(pDato);
        if(aux->izq)
            if(aux->izq->dato==pDato)
                aux->izq=borrar_recursivo_BIS(aux->izq,pDato);
        if(aux->der)
            if(aux->der->dato==pDato)
                aux->der=borrar_recursivo_BIS(aux->der,pDato);
        mover(aux);
    }
    else throw "Arbol vacio";
}

template<class S, class Nodo_BIS>
bool ABB_BIS<S,Nodo_BIS>::buscar(const S &pDato)
{
    if(raiz)
    {
        bool encontrado=false;
        Nodo_BIS *aux=raiz;
        Nodo_BIS *aux2=nullptr;
        while(aux && !encontrado)
        {
            if(aux->dato==pDato)
                encontrado=true;
            else
                if(aux->dato>pDato)
                {
                    aux2=aux;
                    aux=aux->izq;
                }
                else
                {
                    aux2=aux;
                    aux=aux->der;
                }
        }
        if(encontrado)
            mover(aux);
        else
            mover(aux2);
        return encontrado;
    }
    else throw "Arbol vacio";
}

template<class S, class Nodo_BIS>
void ABB_BIS<S,Nodo_BIS>::setBiselado(bool pDato)
{
    biselado=pDato;
}

template<class S, class Nodo_BIS>
void ABB_BIS<S, Nodo_BIS>::RSI(Nodo_BIS *pPtr)
{
    Nodo_BIS *desc_der = pPtr->der;
    pPtr->der = desc_der->izq;

    if (pPtr->der != nullptr)
        pPtr->der->ant = pPtr;

    desc_der->ant = pPtr->ant;

    if (pPtr->ant == nullptr)
        raiz = desc_der;
    else
        if (pPtr == pPtr->ant->izq)
            pPtr->ant->izq = desc_der;
        else
            pPtr->ant->der = desc_der;

    desc_der->izq = pPtr;
    pPtr->ant = desc_der;
}

template<class S, class Nodo_BIS>
void ABB_BIS<S, Nodo_BIS>::RSD(Nodo_BIS *pPtr)
{
    Nodo_BIS *desc_izq = pPtr->izq;
    pPtr->izq = desc_izq->der;

    if (pPtr->izq != nullptr)
        pPtr->izq->ant = pPtr;

    desc_izq->ant = pPtr->ant;

    if (pPtr->ant == nullptr)
        raiz = desc_izq;
    else
        if (pPtr == pPtr->ant->izq)
            pPtr->ant->izq = desc_izq;
        else
            pPtr->ant->der = desc_izq;

    desc_izq->der = pPtr;
    pPtr->ant = desc_izq;
}

template<class S, class Nodo_BIS>
Nodo_BIS *ABB_BIS<S,Nodo_BIS>::borrar_recursivo_BIS(Nodo_BIS *pRaiz, const S &pDato)
{
    Nodo_BIS* nueva_raiz = nullptr;

    if( pRaiz ){
        if( pDato == pRaiz->dato ) { // encontrado... hay que eliminar el nodo
            Nodo_BIS *izq, *der;
            izq = pRaiz->izq;
            der = pRaiz->der;
            if( !izq and !der ) { // no hay descendientes
                delete pRaiz;
                --N;
            }
            if( !izq and der ) { // hay un descendiente
                nueva_raiz = der;
                nueva_raiz->ant=pRaiz->ant;
                delete pRaiz;
                --N;
            }
            if( izq and !der ) { // hay un descendiente
                nueva_raiz = izq;
                nueva_raiz->ant=pRaiz->ant;
                delete pRaiz;
                --N;
            }
            if( der and izq ) { // hay dos descendientes
                // se elige el mayor de los menores
                while ( izq->der ) izq = izq->der;
                pRaiz->dato = izq->dato;
                pRaiz->izq = borrar_recursivo_BIS( pRaiz->izq, izq->dato );
                nueva_raiz = pRaiz;
            }
        }
        else {
            if( pDato < pRaiz->dato )
                pRaiz->izq = borrar_recursivo_BIS( pRaiz->izq, pDato );
            else
                pRaiz->der = borrar_recursivo_BIS( pRaiz->der, pDato ); // caso >
            nueva_raiz = pRaiz;
        }
    }
    return nueva_raiz;
}

template<class S, class Nodo_BIS>
Nodo_BIS *ABB_BIS<S,Nodo_BIS>::datoAnterior(const S &pDato)
{
    if(raiz)
    {
        bool encontrado=false;
        Nodo_BIS *aux=raiz;
        Nodo_BIS *aux2=nullptr;
        while(aux && !encontrado)
        {
            if(aux->dato==pDato)
                encontrado=true;
            else
                if(aux->dato>pDato)
                {
                    aux2=aux;
                    aux=aux->izq;
                }
                else
                {
                    aux2=aux;
                    aux=aux->der;
                }
        }
        return aux2;
    }
    else throw "Arbol vacio";
}


template<class S, class Nodo_BIS>
void ABB_BIS<S,Nodo_BIS>::mover(Nodo_BIS *pRaiz)
{
    if(pRaiz)
    {
        if(biselado)
            biselar(pRaiz);
        else
            moveToRoot(pRaiz);
    }
}

template<class S, class Nodo_BIS>
void ABB_BIS<S, Nodo_BIS>::biselar(Nodo_BIS *pRaiz)
{
    while(pRaiz!=raiz)
    {
        Nodo_BIS* padre=pRaiz->ant;
        Nodo_BIS* abuelo=padre->ant;
        if(raiz==padre)
        {
            if(padre->izq==pRaiz)
                RSD(pRaiz->ant);
            else
                RSI(pRaiz->ant);
        }
        else
        {
            if(padre->izq==pRaiz)
            {
                if(abuelo->izq==padre)
                {
                    //izq/izq
                    RSD(abuelo);
                    RSD(padre);
                }
                else
                {
                    //izq/der
                    RSD(padre);
                    RSI(abuelo);
                }
            }
            else
            {
                if(abuelo->izq==padre)
                {
                    //der/izq
                    RSI(padre);
                    RSD(abuelo);
                }
                else
                {
                    //der/der
                    RSI(abuelo);
                    RSI(padre);
                }
            }
        }
    }
}

template<class S, class Nodo_BIS>
void ABB_BIS<S,Nodo_BIS>::moveToRoot(Nodo_BIS *pRaiz)
{
    while(pRaiz!=raiz)
    {
        Nodo_BIS* padre=pRaiz->ant;
        if(padre->izq==pRaiz)
            RSD(pRaiz->ant);
        else
            RSI(pRaiz->ant);
    }
}

}
#endif // ABB_BISELADO_H
