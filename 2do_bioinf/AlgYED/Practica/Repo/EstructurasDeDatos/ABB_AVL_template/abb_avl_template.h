#ifndef ABB_AVL_TEMPLATE_H
#define ABB_AVL_TEMPLATE_H

#include "../ArbolBinarioBusqueda/abb.h"

namespace abb_avl_template {

using namespace std;

template<class Q>
class TNodo_AVL{
public:
    Q dato; // dato almacenado en el nodo
    short fb;  // Nodos hoja, por defecto tienen factor de balance 0 (fb = 0).
    TNodo_AVL *izq, *der; // izq: datos menores, der: datos mayores
    TNodo_AVL(const Q& pDato, TNodo_AVL* pptr_izq = nullptr, TNodo_AVL* pptr_der = nullptr){
        dato = pDato; izq = pptr_izq; der = pptr_der; fb = 0;
    }
    string to_string() {
        string cad = std::to_string(dato); cad += '(' + std::to_string(fb) + ')';
        return cad;
    }
};

template<class S, class Nodo_AVL = TNodo_AVL<S>>
class ABB_AVL : public ABB<S, Nodo_AVL>
{
public:
    ABB_AVL();

    void agregar(const S& pDato);
    void borrar(const S& pDato);

private:
    // para simplificar notación
    Nodo_AVL* &raiz = ABB<S, Nodo_AVL>::raiz;
    unsigned int &N = ABB<S, Nodo_AVL>::N;

    Nodo_AVL* agregar_recursivo(Nodo_AVL* pRaiz, const S& pDato);
    Nodo_AVL* borrar_recursivo(Nodo_AVL* pRaiz, const S& pDato);

    void setFB(Nodo_AVL* &pPtr_nodo);
    short getFB(Nodo_AVL* &pPtr_nodo);

    Nodo_AVL* RSI(Nodo_AVL* pRaiz); // recibe el pivote
    Nodo_AVL* RSD(Nodo_AVL* pRaiz); // recibe el pivote
    Nodo_AVL* RDID(Nodo_AVL* pRaiz); // recibe el pivote
    Nodo_AVL* RDDI(Nodo_AVL* pRaiz); // recibe el pivote
};

// sobrecarga global de operador binario
template<class S>
ostream& operator<<(ostream& pOut, ABB_AVL<S>& pAbb) {
    pAbb.volcarEnFlujo( pOut );
    return pOut;
}

template<class S, class Nodo_AVL>
ABB_AVL<S, Nodo_AVL>::ABB_AVL()
{ }

template<class S, class Nodo_AVL>
void ABB_AVL<S, Nodo_AVL>::agregar(const S &pDato)
{
    //ABB<S, Nodo_AVL>::raiz = agregar_recursivo( ABB<S, Nodo_AVL>::raiz, pDato );
    // Nodo_AVL* &raiz = ABB<S, Nodo_AVL>::raiz;

    raiz = agregar_recursivo( raiz, pDato );

}

template<class S, class Nodo_AVL>
void ABB_AVL<S, Nodo_AVL>::borrar(const S &pDato)
{
    raiz = borrar_recursivo( raiz, pDato );
}

template<class S, class Nodo_AVL>
Nodo_AVL* ABB_AVL<S, Nodo_AVL>::agregar_recursivo(Nodo_AVL *pRaiz, const S &pDato)
{
    // para simplificar notación
    Nodo_AVL* &p = pRaiz;
    const S &d = pDato;

    if( pRaiz == nullptr ) { // árbol vacío a partir de pptr
        Nodo_AVL* temp = new Nodo_AVL( d );
        ++N;
        return temp;
    }
    else { // árbol NO vacío a partir de pptr
        // Etapa 1: añadir nodo
        if( d > p->dato )
            p->der = agregar_recursivo( p->der, d );
        else if( d < p->dato )
            p->izq = agregar_recursivo( p->izq, d );

        // Etapa 2: verificar FBs, y corregir con rotaciones si hace falta
        setFB( p );
        if( p->fb > 1 ) {
            if( p->der->fb >= 0 )
                return RSI( p );
            else
                return RDDI( p );
        } else {
            if( p->fb < -1 ) {
                if( p->izq->fb <= 0 )
                    return RSD( p );
                else
                    return RDID( p );
            }
        }
    }
    return p;
}

template<class S, class Nodo_AVL>
Nodo_AVL *ABB_AVL<S, Nodo_AVL>::borrar_recursivo(Nodo_AVL *pRaiz, const S &pDato)
{
    // para simplificar notación
    Nodo_AVL* &p = pRaiz;
    const S &d = pDato;

    Nodo_AVL* nueva_raiz = nullptr;

    if( p ) {
        if(d < p->dato){
            p->izq = borrar_recursivo(p->izq, d);
            nueva_raiz = p; // importante
        }
        else if(d > p->dato){
            p->der = borrar_recursivo(p->der, d);
            nueva_raiz = p; // importante
        }
        else {
            Nodo_AVL* izq = p->izq;
            Nodo_AVL* der = p->der;
            if( !der ){         // hay 0 ó 1 descendiente izquierdo únicamente
                delete p;
                N -= 1;
                p = izq;
                // nueva_raiz = pRaiz;
            }
            else {
                if( !izq ){     // hay 0 ó 1 descendiente derecho únicamente
                    delete p;
                    N -= 1;
                    p = der;
                    // nueva_raiz = der;
                }
                else{           // hay 2 descendientes
                    //if( ABB<S, Nodo_AVL>::opcionBorrado == MAYOR_DE_MENORES ) {
                    while( izq->der ) izq = izq->der;
                    p->dato = izq->dato;
                    p->izq = borrar_recursivo(p->izq, izq->dato);
                    nueva_raiz = p; // importante porque si no hay rotaciones, nunca se asigna el valor de retorno.
                    //}
                    //if( ABB<S, Nodo_AVL>::opcionBorrado == MENOR_DE_MAYORES ) {
                    //    while( der->izq ) der = der->izq;
                    //    p->dato = der->dato;
                    //    p->der = borrar_recursivo(p->der, der->dato);
                    //    nueva_raiz = p; // importante porque si no hay rotaciones, nunca se asigna el valor de retorno.
                    //}
                }
            }
        }
        // *********************************
        // Rotaciones
        // *********************************
        if( p ) {
            setFB( p );
            if( p->fb < -1 ){  // < es importante
                if( p->izq->fb <= 0  ){     // fb == -1 ó fb == 0
                    nueva_raiz = RSD( p );
                } else {
                    //p->izq = RSI( p->izq );
                    //nueva_raiz = RSD( p );
                    nueva_raiz = RDID( p );
                }
            } else {
                if( p->fb > 1 ){ // > es importante
                    if( p->der->fb >= 0  ){ // fb == +1 ó fb == 0
                        nueva_raiz = RSI( p );
                    } else {
                        //p->der = RSD( p->der );
                        //nueva_raiz = RSI( p );
                        nueva_raiz = RDDI( p );
                    }
                }
            }
        }
    }
    return nueva_raiz;
}

template<class S, class Nodo_AVL>
void ABB_AVL<S, Nodo_AVL>::setFB(Nodo_AVL *&pPtr_nodo)
{
    if( pPtr_nodo ) {
        unsigned int h_der = 0, h_izq = 0;
        h_izq = ABB<S, Nodo_AVL>::getAltura_recursivo( pPtr_nodo->izq );
        h_der = ABB<S, Nodo_AVL>::getAltura_recursivo( pPtr_nodo->der );
        pPtr_nodo->fb = h_der - h_izq;
    }
}

template<class S, class Nodo_AVL>
short ABB_AVL<S, Nodo_AVL>::getFB(Nodo_AVL *&pPtr_nodo)
{
    short res = 0;
    if( pPtr_nodo ) res = pPtr_nodo->fb;
    return res;
}

template<class S, class Nodo_AVL>
Nodo_AVL* ABB_AVL<S, Nodo_AVL>::RSI(Nodo_AVL *pRaiz)
{
    Nodo_AVL* nueva_raiz = pRaiz->der;
    pRaiz->der = nueva_raiz->izq;
    nueva_raiz->izq = pRaiz;
    setFB( nueva_raiz->izq );
    setFB( nueva_raiz );
    return nueva_raiz;
}

template<class S, class Nodo_AVL>
Nodo_AVL *ABB_AVL<S, Nodo_AVL>::RSD(Nodo_AVL *pRaiz)
{

    Nodo_AVL* nueva_raiz = pRaiz->izq;
    pRaiz->izq = nueva_raiz->der;
    nueva_raiz->der = pRaiz;
    setFB( nueva_raiz->der );
    setFB( nueva_raiz );
    return nueva_raiz;
}

template<class S, class Nodo_AVL>
Nodo_AVL *ABB_AVL<S, Nodo_AVL>::RDID(Nodo_AVL *pRaiz)
{
    pRaiz->izq = RSI( pRaiz->izq );
    pRaiz = RSD( pRaiz );
    return pRaiz;
}

template<class S, class Nodo_AVL>
Nodo_AVL *ABB_AVL<S, Nodo_AVL>::RDDI(Nodo_AVL *pRaiz)
{
    pRaiz->der = RSD( pRaiz->der );
    pRaiz = RSI( pRaiz );
    return pRaiz;
}

} // fin namespace

#endif // ABB_AVL_TEMPLATE_H
