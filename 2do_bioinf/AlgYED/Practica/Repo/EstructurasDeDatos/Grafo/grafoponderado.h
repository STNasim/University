#ifndef GRAFOPONDERADO_H
#define GRAFOPONDERADO_H

#include <vector>

#include "grafo.h"

using namespace std;

template<class T>
class GrafoPonderado : public Grafo<T>
{
public:
    GrafoPonderado();

    // mutaciones
    void agregarArco(T pDato1, T pDato2); // asume peso 1
    void agregarArco(T pDato1, T pDato2, float pPeso);
    void borrarArco(T pDato1, T pDato2);

private:
    Representacion &rep = BaseGrafo<T>::rep;

    // representacion MATRICIAL
    vector<vector<bool>> &matAdy = BaseGrafo<T>::matAdy;

    // pesos para grafo ponderado
    map<pair<T,T>, float> &pesos = BaseGrafo<T>::pesos; // mapa: peso = f(arco)
};

template<class T>
GrafoPonderado<T>::GrafoPonderado()
{

}

template<class T>
void GrafoPonderado<T>::agregarArco(T pDato1, T pDato2)
{
    agregarArco(pDato1, pDato2, 1.0f);
}

template<class T>
void GrafoPonderado<T>::agregarArco(T pDato1, T pDato2, float pPeso)
{
    if( rep == MATRICIAL ){
        int pos1 = BaseGrafo<T>::getPosNodo(pDato1);
        int pos2 = BaseGrafo<T>::getPosNodo(pDato2);
        if( -1 != pos1 and -1 != pos2 ) { // ambos datos son nodos del grafo
            matAdy[pos1][pos2] = true;
            matAdy[pos2][pos1] = true;
            pesos[pair<T,T>(pDato1, pDato2)] = pPeso;
            pesos[pair<T,T>(pDato2, pDato1)] = pPeso;
        }
    }
}

template<class T>
void GrafoPonderado<T>::borrarArco(T pDato1, T pDato2)
{
    if( rep == MATRICIAL ) {
        int pos1 = BaseGrafo<T>::getPosNodo(pDato1);
        int pos2 = BaseGrafo<T>::getPosNodo(pDato2);
        if( -1 != pos1 and -1 != pos2 ) { // el arco podría existir ya que ambos nodos existen
            matAdy[pos1][pos2] = false;
            matAdy[pos2][pos1] = false;
            pesos.erase( pair<T,T>(pDato1, pDato2) );
            pesos.erase( pair<T,T>(pDato2, pDato1) );
        }
    }
}

#endif // GRAFOPONDERADO_H
