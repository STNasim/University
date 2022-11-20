#ifndef GRAFOS_ALGORITMOS_AVANZADOS_H
#define GRAFOS_ALGORITMOS_AVANZADOS_H
#include "../../EstructurasDeDatos/Grafo/grafoponderado.h"
#include "../../EstructurasDeDatos/Grafo/digrafoponderado.h"
#include <queue>
#include <algorithm>

template<class T>
vector<pair<T,float>> Dijkstra(GrafoPonderado<T> &g,T nodoInicial)
{
    //Suponemos que el nodo se encuentra en el grafo
    vector<pair<T,float>> retorno;
    if(g.getRep()==MATRICIAL)
    {
        map<T,float> recorridos;
        queue<T> cola;
        map<T, bool> visitados;
        vector<T> nodos=g.getNodos();

        for(unsigned int i=0;i<nodos.size();i++)
        {
            recorridos[nodos[i]]=INT_MAX;
            visitados[nodos[i]]=false;
        }
        recorridos[nodoInicial]=0;
        cola.push(nodoInicial);
        while(!cola.empty())
        {
            T actual=cola.front();
            cola.pop();
            if(!visitados[actual])
            {
                visitados[actual]=true;
                vector<T> vecinos=g.getVecinos(actual);
                for(T vecino: vecinos)
                {
                    if(!visitados[vecino])
                    {
                        float peso=g.getPesoArco(actual,vecino);
                        if(recorridos[actual]+peso<recorridos[vecino])
                        {
                            recorridos[vecino]=recorridos[actual]+peso;
                            cola.push(vecino);
                        }
                    }
                }
            }
        }
        retorno.resize(nodos.size());
        for(unsigned int i=0;i<recorridos.size();i++)
            retorno[i]=(pair<T,int>(nodos[i],recorridos[nodos[i]]));
    }
    return retorno;
}

//template<class T>
//void ordenar(list<pair<pair<T,T>,float>> &pArr)
//{
//    unsigned int n=pArr.size();
//    long aux;
//    bool salir=false;
//    for(unsigned int pasada=1;pasada<n  and !salir;pasada++)
//    {
//        salir=true;
//        for(unsigned int i=0; i<n-pasada; i++)
//        {
//            if(pArr[i].second>pArr[i+1].second)
//            {
//                aux=pArr[i];
//                pArr[i]=pArr[i+1];
//                pArr[i+1]=aux;
//                salir=false;
//            }
//        }
//    }
//}

template<class T>
GrafoPonderado<T> Kruskal(GrafoPonderado<T> &g)
{
    GrafoPonderado<T> gKruskal;
    vector<pair<T,T>> arcos=g.getArcos();
    list<pair<float,pair<T,T>>> tabla;

    for(unsigned int i=0;i<arcos.size();i++)
        tabla.push_back(pair<float,pair<T,T>>(g.getPesoArco(arcos[i].first,arcos[i].second),arcos[i]));
    tabla.sort();

    vector<T> nodos=g.getNodos();
    for(T nodo :nodos)
        gKruskal.agregarNodo(nodo);

    for( auto par : tabla )
        if(!gKruskal.nodosConectados(par.second))
            gKruskal.agregarArco(par.second.first,par.second.second,par.first);

    return gKruskal;
}

#endif // GRAFOS_ALGORITMOS_AVANZADOS_H
