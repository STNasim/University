#ifndef BASEGRAFO_H
#define BASEGRAFO_H

#include <vector>
#include <list>
#include <iterator>
#include <ostream>
#include <map>
#include <queue>

using namespace std;

enum Representacion {MATRICIAL, LISTA_ADYACENCIAS, LISTA_ARCOS};
enum TipoGrafo {DIRIGIDO, NO_DIRIGIDO};

template<class T>
class BaseGrafo
{
public:
    BaseGrafo();

    // mutaciones
    void agregarNodo(T pDato);
    void borrarNodo(T pDato);
    virtual void agregarArco(T pDato1, T pDato2) = 0;  // no hay implementación de este método en esta clase.
    virtual void borrarArco(T pDato1, T pDato2) = 0;
    void limpiar();

    // obtención de información
    unsigned int getOrden();
    unsigned int getNumeroArcos();
    bool existeNodo(T pDato);
    bool nodosConectados(pair<T,T> par);
    vector<T> getVecinos(T pDato);
    vector<T> getNodosConArcosIncidentes(T pDato);
    vector<T> getNodos();
    vector<pair<T,T>> getArcos();
    virtual unsigned int getGrado() = 0;

    // específico para grafos ponderados.
    float getPesoArco(T pDato1, T pDato2); // TODO: que el peso sea genérico

    // métodos auxiliares
    void volcarEnFlujo(ostream& pOut);
    Representacion getRep() const;
    TipoGrafo getTipoGrafo();

protected:
    TipoGrafo tipoGrafo;

    // representación matricial
    Representacion rep;
    vector<T> nodos;
    vector<vector<bool>> matAdy;
    unsigned int N;
    unsigned int orden;
    int getPosNodo(T pDato);

    // representación por lista de adyacencias
    list<pair<T, list<T>>> lis_nodos;
    typename list<pair<T, list<T>>>::iterator buscar( T pDato );

    // pesos para grafo ponderado
    map<pair<T,T>, float> pesos; // mapa: peso = f(arco) // TODO: que el peso sea genérico

private:

};

template<class T>
BaseGrafo<T>::BaseGrafo()
{
    orden = 0;
    N = 100;
}

template<class T>
void BaseGrafo<T>::agregarNodo(T pDato)
{
    if( rep == MATRICIAL ) {
        // añadir el nodo la Lista de nodos
        if(orden < N)
            nodos[orden++] = pDato;
    }

    if( rep == LISTA_ADYACENCIAS ) {
        auto it = BaseGrafo<T>::buscar( pDato );
        if( it == lis_nodos.end() ) {  // Si NO está agregado... agregar...
            auto par = pair<T, list<T>>( pDato, list<T>() );
            lis_nodos.push_back( par );
        }
    }
}

template<class T>
unsigned int BaseGrafo<T>::getOrden()
{
    unsigned int resp_orden = 0;
    if( rep == MATRICIAL )
        resp_orden = orden;

    if( rep == LISTA_ADYACENCIAS )
        resp_orden = lis_nodos.size();

    return resp_orden;
}

template<class T>
unsigned int BaseGrafo<T>::getNumeroArcos()
{
    unsigned int arcos=0;
    if(rep == MATRICIAL and tipoGrafo == NO_DIRIGIDO )
    {
        unsigned int f, c;
        for(f = 0; f<orden; ++f)
            for(c = f; c<orden; ++c)
                if( matAdy[f][c] )
                    arcos++;
    }

    if( rep == LISTA_ADYACENCIAS and tipoGrafo == NO_DIRIGIDO )
    {
        for( auto& par : lis_nodos )
        {
            auto it=par.second.begin();
            while(it!=par.second.end() && *it<=par.first)
            {
                arcos++;
                it++;
            }
        }
    }

    if( rep == LISTA_ADYACENCIAS and tipoGrafo == DIRIGIDO )
    {
        for( auto& par : lis_nodos )
            arcos+=par.second.size();
    }

    if(rep==MATRICIAL and tipoGrafo== DIRIGIDO)
    {
        unsigned int f, c;
        for(f = 0; f<orden; ++f)
            for(c = 0; c<orden; ++c)
                if( matAdy[f][c] )
                    arcos++;
    }
    return arcos;
}

template<class T>
void BaseGrafo<T>::borrarNodo(T pDato)
{
    if( rep == MATRICIAL ) {
        // se corren nodos
        int pos = getPosNodo(pDato);
        if( -1 != pos ) { // el dato exsite
            unsigned int f, c, i;
            // se corren columnas
            for(c = pos; c<orden-1; ++c)
                for(f = 0; f<orden; ++f)
                    matAdy[f][c] = matAdy[f][c+1];
            // se limpia última columna
            for(f = 0; f<orden; ++f)
                matAdy[f][orden-1] = false;

            // se corren filas
            for(f = pos; f<orden-1; ++f)
                for(c = 0; c<orden; ++c)
                    matAdy[f][c] = matAdy[f+1][c];
            // se limpia última columna
            for(f = 0; f<orden; ++f)
                matAdy[f][orden-1] = false;

            // se corren nodos
            for(i=pos; i<orden-1; ++i)
                nodos[i] = nodos[i+1];

            --orden;
        }
    }

    if( rep == LISTA_ADYACENCIAS ) {
        auto it = buscar( pDato );
        auto it_fin = lis_nodos.end();
        if( it != it_fin ) {
            lis_nodos.erase( it ); // borra nodo.
            // borrar arcos que inciden en el nodo
            for( auto& par : lis_nodos ) {
                auto it_borrar = find( par.second.begin(), par.second.end(), pDato );
                if( it_borrar != par.second.end() )
                    par.second.erase( it_borrar );
            }
        }
    }

    // específico para grafos ponderados
    if( pesos.size() > 0 ) {
        // se borran pesos de arcos, si tenían al nodo borrado como un extremo
        auto it  = pesos.begin();
        while( it != pesos.end() ) {
            if( it->first.first == pDato or it->first.second == pDato ) {
                pesos.erase( it );
                it = pesos.begin();
            }
            ++it;
        }
    }
}

template<class T>
void BaseGrafo<T>::limpiar()
{
    if( tipoGrafo == NO_DIRIGIDO and rep == MATRICIAL ) {
        // TODO
    }

    if( tipoGrafo == DIRIGIDO and rep == LISTA_ADYACENCIAS ) {
        lis_nodos.clear();
    }
}

template<class T>
vector<T> BaseGrafo<T>::getNodos()
{
    vector<T> aux_nodos;

    if( rep == MATRICIAL ) {
        // se copian tantos nodos como sea el orden del grafo.
        copy(nodos.begin(), nodos.begin() + orden,  // desde donde copiar
             back_inserter(aux_nodos));             // donde colocar
    }

    if( rep == LISTA_ADYACENCIAS ) {
        for( auto& par : lis_nodos )  // "para cada elemento del contenedor"
            aux_nodos.push_back( par.first );
    }

    return aux_nodos;
}

template<class T>
vector<T> BaseGrafo<T>::getVecinos(T pDato)
{
    vector<T> vecinos;

    if(rep == MATRICIAL) {
        int pos = getPosNodo(pDato);
        if( -1 != pos ) { // el dato existe en el Grafo
            unsigned int f = static_cast<unsigned int>(pos), c;
            for(c=0; c<orden; ++c)
                if( matAdy[f][c] )
                    vecinos.push_back(nodos[c]);
        }
    }

    if(rep == LISTA_ADYACENCIAS) {
        auto it = buscar(pDato);
        auto it_fin = lis_nodos.end();
        if( it != it_fin ) // el dato existe en el Grafo
            copy(it->second.begin(), it->second.end(), back_inserter(vecinos)); // vecinos son los nodos adyacentes
    }

    return vecinos;
}

template<class T>
vector<T> BaseGrafo<T>::getNodosConArcosIncidentes(T pDato)
{
    vector<T> nodosRetorno;

    if(rep == MATRICIAL) {
        int pos = getPosNodo(pDato);
        if( -1 != pos ) { // el dato existe en el Grafo
            unsigned int c = static_cast<unsigned int>(pos), f;
            for(f=0; f<orden; ++f)
                if( matAdy[f][c] )
                    nodosRetorno.push_back(nodos[f]);
        }
    }

    if(rep == LISTA_ADYACENCIAS) {
        auto it = buscar(pDato);
        auto it_fin = lis_nodos.end();
        if( it != it_fin ) // el dato existe en el Grafo
        {
            for( auto& par : lis_nodos )
            {
                auto it_buscar = find( par.second.begin(), par.second.end(), pDato );
                if( it_buscar != par.second.end() )
                    nodosRetorno.push_back(par.first);
            }
        }
    }

    return nodosRetorno;
}

template<class T>
vector<pair<T, T> > BaseGrafo<T>::getArcos()
{
    vector<pair<T,T>> arcos;

    if(rep == MATRICIAL && tipoGrafo==NO_DIRIGIDO)
    {
        unsigned int f, c;
        for(f = 0; f<orden; ++f)
            for(c = f; c<orden; ++c)
                if( matAdy[f][c] )
                    arcos.push_back( pair<T,T>( nodos[f], nodos[c] ) );
    }
    if(rep == MATRICIAL && tipoGrafo==DIRIGIDO)
    {
        unsigned int f, c;
        for(f = 0; f<orden; ++f)
            for(c = 0; c<orden; ++c)
                if( matAdy[f][c] )
                    arcos.push_back( pair<T,T>( nodos[f], nodos[c] ) );
    }
    if( rep == LISTA_ADYACENCIAS) {
        for( auto& par : lis_nodos )        // un nodo
            for( auto& nodo : par.second )  // adyacentes al nodo
                arcos.push_back( pair<T,T>(par.first, nodo) ); // arco
    }

    return arcos;
}

template<class T>
bool BaseGrafo<T>::existeNodo(T pDato)
{
    bool existe = false;

    if( rep == MATRICIAL )
        existe = -1 != getPosNodo( pDato );

    if( rep == LISTA_ADYACENCIAS )
        existe = buscar( pDato ) != lis_nodos.end();

    return existe;
}

template<class T>
bool BaseGrafo<T>::nodosConectados(pair<T,T> par)
{
    bool retorno=false;
    if(existeNodo(par.first) && par.second)
    {
        if(rep==MATRICIAL)
        {
            map<T, bool> visitados;
            queue<T> cola;

            for(unsigned int i=0;i<nodos.size();i++)
                visitados[nodos[i]]=false;

            cola.push(par.first);
            while(!cola.empty())
            {
                T actual=cola.front();
                cola.pop();
                if(!visitados[actual])
                {
                    visitados[actual]=true;
                    vector<T> vecinos=getVecinos(actual);
                    for(T vecino: vecinos)
                    {
                        if(vecino==par.second)
                        {
                            retorno=true;
                            while(!cola.empty())
                                cola.pop();
                        }
                        else if(!visitados[vecino])
                            cola.push(vecino);
                    }
                }
            }
        }
    }
    return retorno;
}

template<class T>
float BaseGrafo<T>::getPesoArco(T pDato1, T pDato2)
{
    float peso = 1.0f; // peso 1 por defecto

    auto it = pesos.find( pair<T,T>(pDato1, pDato2) );
    if( it != pesos.end() )
        peso = it->second;

    return peso;
}

template<class T>
void BaseGrafo<T>::volcarEnFlujo(ostream &pOut)
{
    if(rep == MATRICIAL){
        // mostrar nodos
        unsigned int i, j;
        //        pOut << "Nodos:" << endl << '\t';
        //        for(i=0;i<orden; ++i){
        //            pOut << nodos[i] << ends;
        //        }
        //        pOut << endl << endl;

        // mostrar matriz de adyacencia
        pOut <<  '\t';
        for(i=0;i<orden; ++i)
            pOut <<  '\t' << nodos[i];
        pOut << endl;

        for(i=0;i<orden; ++i){
            pOut <<  '\t' << nodos[i];
            for(j=0;j<orden; ++j){
                pOut << '\t' << matAdy[i][j] << ends;
            }
            pOut << endl;
        }
    }

    if(rep == LISTA_ADYACENCIAS){
        // mostrar lista de adyacencias
        pOut << "Lista de adyacencias:" << endl;
        for( auto par : lis_nodos ) {
            pOut << '\t' << par.first << ": ";
            for( auto nodo_adyacente : par.second )
                pOut << nodo_adyacente << ", ";
            pOut << endl;
        }
    }

    // si hay pesos, mostrarlos
    if( pesos.size() > 0 ) {
        pOut << endl;
        pOut << "Pesos:" << endl;
        for( auto par : pesos ) {
            auto& arco = par.first;
            auto& peso = par.second;
            pOut << '\t' << arco.first << " -> " << arco.second
                 << ": " << peso << endl;
        }
        pOut << endl;
    }
}

template<class T>
Representacion BaseGrafo<T>::getRep() const
{
    return rep;
}

template<class T>
TipoGrafo BaseGrafo<T>::getTipoGrafo()
{
    return tipoGrafo;
}

template<class T>
int BaseGrafo<T>::getPosNodo(T pDato)
{
    int pos = -1;
    //    for(int i=0; i<orden && pos != i-1; ++i)
    //        if(nodos[i] == pDato)
    //            pos = i;

    for(unsigned int i=0; i<orden; ++i)
        if(nodos[i] == pDato){
            pos = static_cast<int>(i);
            break;
        }
    return pos;
}

template<class T>
typename list<pair<T, list<T>>>::iterator BaseGrafo<T>::buscar(T pDato)
{
    auto it = lis_nodos.begin();
    auto it_fin = lis_nodos.end(); // apunta "¡después!" del último elemento de la lista
    while( it != it_fin )
        if( it->first == pDato )
            break;
        else
            ++it;
    return it;
}

template<class T>
ostream& operator<<(ostream& out, pair<T,T> par){
    out << "( " << par.first << ", " << par.second << " )";
    return out;
}

template<class T>
ostream& operator<<(ostream& out, BaseGrafo<T>& pG){
    pG.volcarEnFlujo(out);
    return out;
}

#endif // BASEGRAFO_H
