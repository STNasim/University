#ifndef DIGRAFOPONDERADO_H
#define DIGRAFOPONDERADO_H

#include "digrafo.h"

using namespace std;

template<class T>
class DigrafoPonderado : public Digrafo<T>
{
public:
    DigrafoPonderado();

    // mutaciones
    void agregarArco(T pDato1, T pDato2); // asume peso 1
    void agregarArco(T pDato1, T pDato2, float pPeso);
    void borrarArco(T pDato1, T pDato2);

private:
    Representacion &rep = BaseGrafo<T>::rep;

    // representacion LISTA_ADYACENCIAS
    list<pair<T,list<T>>> &lis_nodos = BaseGrafo<T>::lis_nodos; // lista de pares

    // pesos para grafo ponderado
    map<pair<T,T>, float> &pesos = BaseGrafo<T>::pesos; // mapa: peso = f(arco)
};

template<class T>
DigrafoPonderado<T>::DigrafoPonderado()
{

}

template<class T>
void DigrafoPonderado<T>::agregarArco(T pDato1, T pDato2)
{
    agregarArco(pDato1, pDato2, 1.0f);
}

template<class T>
void DigrafoPonderado<T>::agregarArco(T pDato1, T pDato2, float pPeso)
{
    if( rep == LISTA_ADYACENCIAS ) {
        auto it_fin = lis_nodos.end(); // final de la lista de nodos
        auto it_dato1 = BaseGrafo<T>::buscar(pDato1);
        auto it_dato2 = BaseGrafo<T>::buscar(pDato2);
        if( it_dato1 != it_fin and it_dato2 != it_fin ) {
            // si ambos nodos están en la lista de nodos
            auto& lista_adyacencia = it_dato1->second;
            if( find(lista_adyacencia.begin(), lista_adyacencia.end(), pDato2)
                    == it_dato1->second.end()) {
                // si el arco del dato 1 no se encuentra añadido
                it_dato1->second.push_back(pDato2); // se añade "nodo adyacente".
                pesos[pair<T,T>(pDato1, pDato2)] = pPeso;
            }
        }
    }
}

template<class T>
void DigrafoPonderado<T>::borrarArco(T pDato1, T pDato2)
{
    if( rep == LISTA_ADYACENCIAS ) {
        auto it_1 = BaseGrafo<T>::buscar(pDato1);
        auto it_2 = BaseGrafo<T>::buscar(pDato2);
        auto fin = lis_nodos.end();
        if( it_1 != fin and it_2 != fin ) { // los datos existen en el Grafo
            auto it_borrar = find(it_1->second.begin(), it_1->second.end(), pDato2);
            if( it_borrar != it_1->second.end() ) { // no se puede borrar la posición final
                it_1->second.erase( it_borrar );
                pesos.erase( pair<T,T>(pDato1, pDato2) );
            }
        }
    }
}

#endif
