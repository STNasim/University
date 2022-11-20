#ifndef GRAFOS_ALGORITMOS_H
#define GRAFOS_ALGORITMOS_H

#include <map>
#include <queue>
#include <stack>
#include "../../EstructurasDeDatos/Grafo/grafo.h"
#include "../../EstructurasDeDatos/Grafo/digrafo.h"

template<class T>
vector<T> recorrerEnAnchura( BaseGrafo<T>& pG, T pDato ) {
    vector<T> recorrido;

    if( pG.existeNodo(pDato) ) {
        // variables auxiliares
        enum Estado { EN_ESPERA, ENFILADO, PROCESADO };
        map<T, Estado> estados;
        queue<T> fila;
        vector<T> vecinos;
        T actual = pDato;

        // paso 1: marcar todos los nodos como "En espera"
        for( T& nodo : pG.getNodos() )
            estados[nodo] = EN_ESPERA;

        // paso 2: inicializar la fila y agregar el primer dato
        fila.push( actual );
        estados[actual] = ENFILADO;

        while( !fila.empty() ) {
            actual = fila.front();
            fila.pop();
            vecinos = pG.getVecinos(actual);
            sort(vecinos.begin(), vecinos.end()); // , greater<T>());
            for( T& vecino : vecinos )
                if( EN_ESPERA == estados[vecino] ) {
                    fila.push( vecino );
                    estados[vecino] = ENFILADO;
                }
            estados[actual] = PROCESADO;
            recorrido.push_back(actual);
        }

    }

    return recorrido;
}
//template<class T>
//vector<T> recorrerEnProfundidadRecursivo( BaseGrafo<T>& pG, T pDato )
//{

//}

template<class T>
vector<T> recorrerEnProfundidad( BaseGrafo<T>& pG, T pDato )
{
    vector<T> recorrido;

    if( pG.existeNodo(pDato) ) {
        // variables auxiliares
        enum Estado { EN_ESPERA, ENFILADO, PROCESADO };
        map<T, Estado> estados;
        stack<T> pila;
        vector<T> vecinos;
        T actual = pDato;

        for( T& nodo : pG.getNodos() )
            estados[nodo] = EN_ESPERA;

        pila.push( actual );
        estados[actual] = ENFILADO;

        while( !pila.empty() ) {
            actual = pila.top();
            pila.pop();
            if(PROCESADO!=estados[actual])
            {
            vecinos = pG.getVecinos(actual);
            sort(vecinos.begin(), vecinos.end()); // , greater<T>());
            for(int i=vecinos.size()-1;i>=0;i-- )
            {
                T vecino=vecinos[i];
                if( PROCESADO != estados[vecino] )
                {
                    pila.push( vecino );
                    estados[vecino] = ENFILADO;
                }
            }
            estados[actual] = PROCESADO;
            recorrido.push_back(actual);
            }
        }

    }

    return recorrido;
}

#endif // GRAFOS_ALGORITMOS_H
