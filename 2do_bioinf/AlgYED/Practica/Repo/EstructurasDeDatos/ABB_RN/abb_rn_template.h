#ifndef ABB_RN_TEMPLATE_H
#define ABB_RN_TEMPLATE_H

#include <iostream>
#include <string>

#include "../ArbolBinarioBusqueda/abb.h"

namespace abb_rn_template {

// Fuente original: https://github.com/anandarao/Red-Black-Tree

using namespace std;

// función global auxiliar para intercambiar contenido de dos variables
template<class T> void intercambiar(T& a, T& b) { T aux = a; a = b; b = aux; }

enum Color {ROJO, NEGRO, DOBLE_NEGRO}; // 0, 1, 2

template<class Q>
class Nodo_RN{
public:
    Q dato;
    Color color;
    Nodo_RN *izq, *der, *ant; // izquierda, derecha, antecesor
    Nodo_RN(Q pDato) { dato=pDato; izq=der=ant=nullptr; color=ROJO; }
    string to_string() {
        return std::to_string(dato) + '(' + (color==ROJO?'R':(color==NEGRO?'N':'N')) + ')';
    }
};

template<class T, class Nodo_RN = Nodo_RN<T>>
class ABB_RN : public ABB<T, Nodo_RN>
{
public:
    ABB_RN();

    unsigned int getNodosRojos();
    unsigned int getNodosNegros();
    // operaciones para mutar
    void agregar(const T& pDato);
    void borrar(const T &pDato);

    // operaciones para obtener información
    unsigned int getAlturaNegra();
    unsigned int nodosHastaCambiarAlturaNegra();
private:
    // simplificación de notación
    Nodo_RN*& raiz = ABB<T, Nodo_RN>::raiz;
    unsigned int& N = ABB<T, Nodo_RN>::N;

    void getNodosRojosRecursivo(Nodo_RN *pRaiz, unsigned int &contador);
    void getNodosNegrosRecursivo(Nodo_RN *pRaiz, unsigned int &contador);

    // métodos útiles
    void RSI(Nodo_RN *&pPtr); // arregla antecesores
    void RSD(Nodo_RN *&pPtr); // arregla antecesores
    void arreglarInsercion(Nodo_RN *&pPtr);
    void arreglarBorrado(Nodo_RN *&pPtr);
    int getColor(Nodo_RN* pPtr);               // <<==== hubo que quitar &
    void setColor(Nodo_RN *&pPtr, Color pColor);
    Nodo_RN* agregar_recursivo(Nodo_RN *&pRaiz, Nodo_RN *&pPtr);
    Nodo_RN* borrar_recursivo(Nodo_RN *&pRaiz, int pDato);
    unsigned int getAlturaNegra(Nodo_RN *pPtr);
};

// impresión del ABB_RN
template<class S>
ostream& operator<<(ostream& pOut, ABB_RN<S>& pAbb){
    pAbb.volcarEnFlujo( pOut );
    return pOut;
}

template<class T, class Nodo_RN>
ABB_RN<T, Nodo_RN>::ABB_RN() {
    // raiz = nullptr;
}

template<class T, class Nodo_RN>
unsigned int ABB_RN<T,Nodo_RN>::getNodosRojos()
{
    if(raiz)
    {
        unsigned int contador=0;
        getNodosRojosRecursivo(raiz,contador);
        return contador;
    }
    else
        throw "Arbol vacio";
}

template<class T, class Nodo_RN>
unsigned int ABB_RN<T,Nodo_RN>::getNodosNegros()
{
    if(raiz)
    {
        unsigned int contador=0;
        getNodosNegrosRecursivo(raiz,contador);
        return contador;
    }
    else
        throw "Arbol vacio";
}

template<class T, class Nodo_RN>
int ABB_RN<T, Nodo_RN>::getColor(Nodo_RN *pPtr) {
    if ( !pPtr )
        return NEGRO;
    return pPtr->color;
}

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::setColor(Nodo_RN *&pPtr, Color pColor) {
    if (pPtr == nullptr)
        return;
    pPtr->color = pColor;
}

template<class T, class Nodo_RN>
Nodo_RN* ABB_RN<T, Nodo_RN>::agregar_recursivo(Nodo_RN *&pRaiz, Nodo_RN *&pPtr) {
    if (pRaiz == nullptr)
        return pPtr;

    if (pPtr->dato < pRaiz->dato) {
        pRaiz->izq = agregar_recursivo(pRaiz->izq, pPtr);
        pRaiz->izq->ant = pRaiz;  // "antecesor" del nodo recién insertado
    } else
        if (pPtr->dato > pRaiz->dato) { // No hay nodos repetidos
            pRaiz->der = agregar_recursivo(pRaiz->der, pPtr);
            pRaiz->der->ant = pRaiz;   // "antecesor" del nodo recién insertado
        }
        else {
            // el nodo ya estaba. Se libera memoria y se lo establece a "nullptr"
            delete pPtr; // aquí NO corresponde colocar: --N; porque el nodo nunca se agregó.
            pPtr = nullptr;
        }
    return pRaiz;
}

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::agregar(const T &pDato) {
    Nodo_RN *nodo = new Nodo_RN(pDato);
    raiz = agregar_recursivo(raiz, nodo);
    if( nodo ) {
        ++N;
        arreglarInsercion(nodo);
    }
}

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::RSI(Nodo_RN *&pPtr) {
    Nodo_RN *desc_der = pPtr->der;
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

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::RSD(Nodo_RN *&pPtr) {
    Nodo_RN *desc_izq = pPtr->izq;
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

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::arreglarInsercion(Nodo_RN *&pPtr) {
    Nodo_RN *padre = nullptr;
    Nodo_RN *abuelo = nullptr;
    while (pPtr != raiz && getColor(pPtr) == ROJO && getColor(pPtr->ant) == ROJO) {
        padre = pPtr->ant;
        abuelo = padre->ant;
        if (padre == abuelo->izq) {
            Nodo_RN *tio = abuelo->der;
            if (getColor(tio) == ROJO) { // recoloreo y listo!
                setColor(tio, NEGRO);
                setColor(padre, NEGRO);
                setColor(abuelo, ROJO);
                pPtr = abuelo;
            } else {                     // recoloreo y rotación
                if (pPtr == padre->der) {
                    RSI(padre);
                    pPtr = padre;
                    padre = pPtr->ant;
                }
                RSD(abuelo);
                intercambiar(padre->color, abuelo->color);
                pPtr = padre;
            }
        } else {
            Nodo_RN *tio = abuelo->izq;
            if (getColor(tio) == ROJO) { // recoloreo y listo!
                setColor(tio, NEGRO);
                setColor(padre, NEGRO);
                setColor(abuelo, ROJO);
                pPtr = abuelo;
            } else {                     // recoloreo y rotación
                if (pPtr == padre->izq) {
                    RSD(padre);
                    pPtr = padre;
                    padre = pPtr->ant;
                }
                RSI(abuelo);
                intercambiar(padre->color, abuelo->color);
                pPtr = padre;
            }
        }
    }
    setColor(raiz, NEGRO);
}

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::arreglarBorrado(Nodo_RN *&pPtr) {
    if (pPtr == nullptr)
        return;

    if (pPtr == raiz) {
        raiz = nullptr;
        return;
    }

    if (getColor(pPtr) == ROJO                      // recoloreo y listo!
            || getColor(pPtr->izq) == ROJO
            || getColor(pPtr->der) == ROJO) {
        Nodo_RN *sucesor = pPtr->izq != nullptr ? pPtr->izq : pPtr->der;

        if (pPtr == pPtr->ant->izq) {
            pPtr->ant->izq = sucesor;
            if (sucesor != nullptr)
                sucesor->ant = pPtr->ant;
            setColor(sucesor, NEGRO);
            delete (pPtr);
            --N;
        } else {
            pPtr->ant->der = sucesor;
            if (sucesor != nullptr)
                sucesor->ant = pPtr->ant;
            setColor(sucesor, NEGRO);
            delete (pPtr);
            --N;
        }
    } else {                        // ======> recoloreo y rotación
        Nodo_RN *hermano = nullptr; // (del nodo apuntado por "ptr")
        Nodo_RN *padre = nullptr;
        Nodo_RN *ptr = pPtr;
        setColor(ptr, DOBLE_NEGRO);
        while (ptr != raiz && getColor(ptr) == DOBLE_NEGRO) {
            padre = ptr->ant;
            if (ptr == padre->izq) {
                hermano = padre->der;
                if (getColor(hermano) == ROJO) {
                    setColor(hermano, NEGRO);
                    setColor(padre, ROJO);
                    RSI(padre);
                } else {
                    // PROBLEMA: el hermano podría ser "nullptr" (esto es un nodo NEGRO).
                    if( hermano ) {
                        if (getColor(hermano->izq) == NEGRO && getColor(hermano->der) == NEGRO) {
                            setColor(hermano, ROJO);
                            if(getColor(padre) == ROJO)
                                setColor(padre, NEGRO);
                            else
                                setColor(padre, DOBLE_NEGRO);
                            ptr = padre;
                        } else {
                            if (getColor(hermano->der) == NEGRO) {
                                setColor(hermano->izq, NEGRO);
                                setColor(hermano, ROJO);
                                RSD(hermano);
                                hermano = padre->der;
                            }
                            setColor(hermano, padre->color);
                            setColor(padre, NEGRO);
                            setColor(hermano->der, NEGRO);
                            RSI(padre);
                            break;
                        }
                    }  else break;
                }
            } else {
                hermano = padre->izq;
                if (getColor(hermano) == ROJO) {
                    setColor(hermano, NEGRO);
                    setColor(padre, ROJO);
                    RSD(padre);
                } else {
                    // PROBLEMA: el hermano podría ser "nullptr" (esto es un nodo NEGRO).
                    if( hermano ) {
                        if (getColor(hermano->izq) == NEGRO && getColor(hermano->der) == NEGRO) {
                            setColor(hermano, ROJO);
                            if (getColor(padre) == ROJO)
                                setColor(padre, NEGRO);
                            else
                                setColor(padre, DOBLE_NEGRO);
                            ptr = padre;
                        } else {
                            if (getColor(hermano->izq) == NEGRO) {
                                setColor(hermano->der, NEGRO);
                                setColor(hermano, ROJO);
                                RSI(hermano);
                                hermano = padre->izq;
                            }
                            setColor(hermano, padre->color);
                            setColor(padre, NEGRO);
                            setColor(hermano->izq, NEGRO);
                            RSD(padre);
                            break;
                        }
                    } else break;
                }
            }
        }
        if (pPtr == pPtr->ant->izq)
            pPtr->ant->izq = nullptr;
        else
            pPtr->ant->der = nullptr;
        delete(pPtr);
        --N;
        setColor(raiz, NEGRO);
    }
}

// MOSTRAR ALTERNATIVA CON MÚLTIPLES "RETURN". Queda más limpio el código.

template<class T, class Nodo_RN>
Nodo_RN* ABB_RN<T, Nodo_RN>::borrar_recursivo(Nodo_RN *&pRaiz, int pDato) {
    if (pRaiz == nullptr)
        return pRaiz;

    if (pDato < pRaiz->dato)
        return borrar_recursivo(pRaiz->izq, pDato);

    if (pDato > pRaiz->dato)
        return borrar_recursivo(pRaiz->der, pDato);

    if (pRaiz->izq == nullptr || pRaiz->der == nullptr)
        return pRaiz;

    Nodo_RN *temp = ABB<T, Nodo_RN>::getNodoMenor(pRaiz->der);
    pRaiz->dato = temp->dato;
    return borrar_recursivo(pRaiz->der, temp->dato);
}

//template<class T, class Nodo_RN>
//Nodo_RN* ABB_RN<T, Nodo_RN>::borrar_recursivo(Nodo_RN *&pRaiz, int pDato) {
//    Nodo_RN* ptr_resp = nullptr;

//    if ( !pRaiz ) {
//        if (pDato < pRaiz->dato)
//            ptr_resp = borrar_recursivo(pRaiz->izq, pDato);
//        else
//            if (pDato > pRaiz->dato)
//                ptr_resp = borrar_recursivo(pRaiz->der, pDato);
//            else
//                if (pRaiz->izq == nullptr || pRaiz->der == nullptr)
//                    ptr_resp = pRaiz;
//                else {
//                    Nodo_RN *temp = getNodoMin(pRaiz->der); // menor de los mayores.
//                    pRaiz->dato = temp->dato;
//                    ptr_resp = borrar_recursivo(pRaiz->der, temp->dato);
//                }
//    }

//    return ptr_resp;
//}

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::borrar(const T& pDato) {
    Nodo_RN *ptr = borrar_recursivo(raiz, pDato);
    arreglarBorrado(ptr);
}

template<class T, class Nodo_RN>
unsigned int ABB_RN<T, Nodo_RN>::getAlturaNegra()
{
    return getAlturaNegra( raiz );
}

template<class T, class Nodo_RN>
unsigned int ABB_RN<T, Nodo_RN>::nodosHastaCambiarAlturaNegra()
{
    if(raiz)
    {
        unsigned int alturaNegra=getAlturaNegra();
        unsigned int cantidadMaxima=1;
        for(unsigned int i=0;i<alturaNegra;i++)
            cantidadMaxima*=4;
        cantidadMaxima--;
        return cantidadMaxima-N;
    }
    else throw "Arbol vacio";
}

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::getNodosRojosRecursivo(Nodo_RN *pRaiz, unsigned int &contador)
{
    if(pRaiz->color==ROJO)
        contador++;
    if(pRaiz->izq)
        getNodosRojosRecursivo(pRaiz->izq,contador);
    if(pRaiz->der)
        getNodosRojosRecursivo(pRaiz->der,contador);
}

template<class T, class Nodo_RN>
void ABB_RN<T, Nodo_RN>::getNodosNegrosRecursivo(Nodo_RN *pRaiz, unsigned int &contador)
{
    if(pRaiz->color!=ROJO)
        contador++;
    if(pRaiz->izq)
        getNodosNegrosRecursivo(pRaiz->izq,contador);
    if(pRaiz->der)
        getNodosNegrosRecursivo(pRaiz->der,contador);
}

template<class T, class Nodo_RN>
unsigned int ABB_RN<T, Nodo_RN>::getAlturaNegra(Nodo_RN *pPtr) {
    unsigned int altura_negra = 0;
    while ( pPtr ) {
        if (getColor(pPtr) == NEGRO)
            ++altura_negra;
        pPtr = pPtr->izq;
    }
    return altura_negra;
}

} // fin namespace

#endif // ABB_RN_TEMPLATE_H
