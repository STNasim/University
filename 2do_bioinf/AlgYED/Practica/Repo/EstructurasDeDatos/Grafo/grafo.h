#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

#include "basegrafo.h"

using namespace std;

template<class T>
class Grafo : public BaseGrafo<T>
{
public:
    Grafo(Representacion representacion=MATRICIAL);

    void agregarArco(T pDato1, T pDato2);
    unsigned int getCantArcos();
    void borrarArco(T pDato1, T pDato2);
    unsigned int getGradoNodo(T pDato);
    unsigned int getGrado();

private:
    Representacion &rep             = BaseGrafo<T>::rep;
    TipoGrafo &tipoGrafo            = BaseGrafo<T>::tipoGrafo;
    vector<T> &nodos                = BaseGrafo<T>::nodos;
    list<pair<T, list<T>>> &lis_nodos   = BaseGrafo<T>::lis_nodos;
    vector<vector<bool>> &matAdy    = BaseGrafo<T>::matAdy;
    unsigned int &N                 = BaseGrafo<T>::N;
    unsigned int &orden             = BaseGrafo<T>::orden;
};

template<class T>
Grafo<T>::Grafo(Representacion representacion)
{
    tipoGrafo = NO_DIRIGIDO;
    rep = representacion;
    if( representacion == MATRICIAL ) {
        nodos.resize(N, 0);
        matAdy.resize(N, vector<bool>(N, false));
    }
}

template<class T>
void Grafo<T>::agregarArco(T pDato1, T pDato2)
{
    if(rep == MATRICIAL){
        int pos1, pos2;
        pos1 = BaseGrafo<T>::getPosNodo(pDato1);
        pos2 = BaseGrafo<T>::getPosNodo(pDato2);

        if( -1 != pos1 and -1 != pos2 ){ // ambos datos son nodos del grafo
            matAdy[pos1][pos2] = true;
            matAdy[pos2][pos1] = true;
        }
    }
    if(rep == LISTA_ADYACENCIAS)
    {
        auto it_fin = lis_nodos.end();
        auto it_dato1 = BaseGrafo<T>::buscar(pDato1);
        auto it_dato2 = BaseGrafo<T>::buscar(pDato2);
        if( it_dato1 != it_fin and it_dato2 != it_fin ) {
            if( find(it_dato1->second.begin(), it_dato1->second.end(), pDato2)
                    == it_dato1->second.end()) {
                it_dato1->second.push_back(pDato2);
                it_dato2->second.push_back(pDato1);
            }
        }
    }
}

template<class T>
unsigned int Grafo<T>::getCantArcos()
{
    int cant_arcos = 0;
    if(rep == MATRICIAL){
        unsigned int f, c;
        for(f=0; f<orden; ++f)
            for(c=f; c<orden; ++c)
                if( matAdy[f][c] )
                    ++cant_arcos;
    }
    return cant_arcos;
}

template<class T>
void Grafo<T>::borrarArco(T pDato1, T pDato2)
{
    if( rep == MATRICIAL ){
        // se corren nodos
        int pos1 = BaseGrafo<T>::getPosNodo(pDato1);
        int pos2 = BaseGrafo<T>::getPosNodo(pDato2);
        if( -1 != pos1 and -1 != pos2 ) { // los datos exsiten
            matAdy[pos1][pos2] = false;
            matAdy[pos2][pos1] = false;
        }
    }
    if(rep== LISTA_ADYACENCIAS)
    {
        auto it_fin = lis_nodos.end(); // final de la lista de nodos
        auto it_dato1 = BaseGrafo<T>::buscar(pDato1);
        auto it_dato2 = BaseGrafo<T>::buscar(pDato2);
        if( it_dato1 != it_fin and it_dato2 != it_fin ) {
            auto& lista_adyacencia = it_dato1->second;
            auto it_borrar = find(lista_adyacencia.begin(), lista_adyacencia.end(),
                                  pDato2);
            if( it_borrar != it_dato1->second.end() )
            {
                lista_adyacencia.erase( it_borrar );

                lista_adyacencia = it_dato2->second;
                it_borrar = find(lista_adyacencia.begin(), lista_adyacencia.end(),
                                 pDato1);
                if( it_borrar != it_dato2->second.end() )
                    lista_adyacencia.erase( it_borrar );
            }
        }
    }
}

template<class T>
unsigned int Grafo<T>::getGradoNodo(T pDato)
{
    unsigned grado = 0;
    if(rep == MATRICIAL)
    {
        int pos = BaseGrafo<T>::getPosNodo(pDato);
        if( -1 != pos ) { // el dato existe en el Grafo
            // como el grafo es NO dirigido, se toma la fila ó la columna y se cuentan sus vecinos.
            int fila = pos;
            for(bool relacion : matAdy[fila])
                if(relacion)
                    ++grado;
        }
    }
    if(rep==LISTA_ADYACENCIAS)
    {
        auto it=BaseGrafo<T>::buscar(pDato);
        if(it!=lis_nodos.end())
            grado=it->second.size();
    }
    return grado;
}

template<class T>
unsigned int Grafo<T>::getGrado()
{
    unsigned int grado = 0, aux_grado;
    if(rep==MATRICIAL)
    {
        for(unsigned int i=0; i<orden; ++i) {
            aux_grado = getGradoNodo(nodos[i]);
            if( grado < aux_grado )
                grado = aux_grado;
        }
    }
    if(rep==LISTA_ADYACENCIAS)
    {
        for(auto it : lis_nodos)
        {
            aux_grado=it.second.size();
            if( grado < aux_grado )
                grado = aux_grado;
        }
    }

    return grado;
}

#endif // GRAFO_H
