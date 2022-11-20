#ifndef DIGRAFO_H
#define DIGRAFO_H

#include "basegrafo.h"

template<class T>
class Digrafo : public BaseGrafo<T>
{
public:
    Digrafo(Representacion representacion=LISTA_ADYACENCIAS);

    void agregarArco(T pDato1, T pDato2);
    void borrarArco(T pDato1, T pDato2);

    unsigned int getGradoSalidaNodo(T pDato);
    unsigned int getGradoEntradaNodo(T pDato);
    unsigned int getGradoNodo(T pDato);
    unsigned int getGradoSalida();
    unsigned int getGradoEntrada();
    unsigned int getGrado();
    unsigned int getCantArcos();

private:
    Representacion &rep                 = BaseGrafo<T>::rep;
    TipoGrafo &tipoGrafo                = BaseGrafo<T>::tipoGrafo;
    list<pair<T, list<T>>> &lis_nodos   = BaseGrafo<T>::lis_nodos;
    vector<T> &nodos                = BaseGrafo<T>::nodos;
    vector<vector<bool>> &matAdy    = BaseGrafo<T>::matAdy;
    unsigned int &N                 = BaseGrafo<T>::N;
    unsigned int &orden             = BaseGrafo<T>::orden;
};

template<class T>
Digrafo<T>::Digrafo(Representacion representacion)
{
    tipoGrafo = DIRIGIDO;
    rep = representacion;
    if( representacion == MATRICIAL ) {
        nodos.resize(N, 0);
        matAdy.resize(N, vector<bool>(N, false));
    }
}

template<class T>
void Digrafo<T>::agregarArco(T pDato1, T pDato2)
{
    if(rep == LISTA_ADYACENCIAS) {
        auto it_fin = lis_nodos.end(); // final de la lista de nodos
        auto it_dato1 = BaseGrafo<T>::buscar(pDato1);
        auto it_dato2 = BaseGrafo<T>::buscar(pDato2);
        if( it_dato1 != it_fin and it_dato2 != it_fin ) {
            // si ambos nodos están en la lista de nodos
            if( find(it_dato1->second.begin(), it_dato1->second.end(), pDato2)   // si el arco del dato 1 no se encuentra añadido
                    == it_dato1->second.end()) {
                it_dato1->second.push_back(pDato2); // se añade "nodo adyacente".
            }
        }
    }
    if(rep == MATRICIAL){
        int pos1, pos2;
        pos1 = BaseGrafo<T>::getPosNodo(pDato1);
        pos2 = BaseGrafo<T>::getPosNodo(pDato2);

        if( -1 != pos1 and -1 != pos2 )
            matAdy[pos1][pos2] = true;
    }
}

template<class T>
unsigned int Digrafo<T>::getGradoSalidaNodo(T pDato)
{
    unsigned grado_salida = 0;

    if(rep == MATRICIAL)
    {
        int pos = BaseGrafo<T>::getPosNodo(pDato);
        if( -1 != pos )
        {
            int fila = pos;
            for(bool relacion : matAdy[fila])
                if(relacion)
                    ++grado_salida;
        }
    }

    if(rep == LISTA_ADYACENCIAS)
    {
        auto it = BaseGrafo<T>::buscar(pDato);
        if( it != lis_nodos.end() )
            grado_salida = it->second.size(); // tamaño de la lista de nodos adyacentes.
    }

    return grado_salida;
}

template<class T>
unsigned int Digrafo<T>::getGradoEntradaNodo(T pDato)
{
    unsigned grado_entrada = 0;

    if(rep == MATRICIAL)
    {
        int pos = BaseGrafo<T>::getPosNodo(pDato);
        if( -1 != pos )
        {
            int col = pos;
            for(unsigned int fila=0;fila<orden;fila++)
            {
                if(matAdy[fila][col])
                    grado_entrada++;
            }
        }
    }

    if(rep == LISTA_ADYACENCIAS){
        // no hace falta saltar el propio nodo ya que este podría apuntar a sí mismo y debe sumarse como una entrada más (del nodo hacia sí mismo).
        for( auto& par : lis_nodos ) {
            auto ini = par.second.begin();  // inicio lista de adyacencias
            auto fin = par.second.end();    // fin lista de adyacencias
            if( find(ini, fin, pDato) != fin )
                ++grado_entrada;
        }
    }

    return grado_entrada;
}

template<class T>
unsigned int Digrafo<T>::getGradoNodo(T pDato)
{
    unsigned int grado = 0, aux_grado_salida, aux_grado_entrada;

    aux_grado_salida = getGradoSalidaNodo(pDato);
    aux_grado_entrada = getGradoEntradaNodo(pDato);

    if( grado < aux_grado_salida ) grado = aux_grado_salida;
    if( grado < aux_grado_entrada ) grado = aux_grado_entrada;

    return grado;
}

template<class T>
unsigned int Digrafo<T>::getGradoSalida()
{
    unsigned grado_salida = 0, aux;

    if(rep == MATRICIAL){
        for( auto&nodo :nodos)
        {
            aux= getGradoSalidaNodo(nodo);
            if(grado_salida<aux)
                grado_salida=aux;
        }
    }

    if(rep == LISTA_ADYACENCIAS){
        for( auto& par : lis_nodos )
        {
            aux = getGradoSalidaNodo(par.first);
            if( grado_salida < aux )
                grado_salida = aux;
        }
    }

    return grado_salida;
}

template<class T>
unsigned int Digrafo<T>::getGradoEntrada()
{
    unsigned grado_entrada = 0, aux;
    if(rep == MATRICIAL){
        for( auto&nodo :nodos)
        {
            aux= getGradoEntradaNodo(nodo);
            if(grado_entrada<aux)
                grado_entrada=aux;
        }
    }

    if(rep == LISTA_ADYACENCIAS){
        for( auto& par : lis_nodos ) {
            aux = getGradoEntradaNodo(par.first);
            if( grado_entrada < aux )
                grado_entrada = aux;
        }
    }

    return grado_entrada;
}

template<class T>
unsigned int Digrafo<T>::getGrado()
{
    unsigned int grado = 0, aux_grado_salida, aux_grado_entrada;
    aux_grado_salida = getGradoSalida();
    aux_grado_entrada = getGradoEntrada();

    if( grado < aux_grado_salida ) grado = aux_grado_salida;
    if( grado < aux_grado_entrada ) grado = aux_grado_entrada;

    return grado;
}

template<class T>
unsigned int Digrafo<T>::getCantArcos()
{
    int cant_arcos = 0;

    if( rep == LISTA_ADYACENCIAS and tipoGrafo == DIRIGIDO ){
        for( auto& par : lis_nodos ) {
            auto& lista_de_adyacencia = par.second;
            cant_arcos += lista_de_adyacencia.size();
        }
    }

    return cant_arcos;
}

template<class T>
void Digrafo<T>::borrarArco(T pDato1, T pDato2)
{
    if( rep == LISTA_ADYACENCIAS){
        auto it_fin = lis_nodos.end(); // final de la lista de nodos
        auto it_dato1 = BaseGrafo<T>::buscar(pDato1);
        auto it_dato2 = BaseGrafo<T>::buscar(pDato2);
        if( it_dato1 != it_fin and it_dato2 != it_fin ) {
            auto& lista_adyacencia = it_dato1->second;
            auto it_borrar = find(lista_adyacencia.begin(), lista_adyacencia.end(),
                                  pDato2);
            if( it_borrar != it_dato1->second.end() )
                lista_adyacencia.erase( it_borrar );
        }
    }
    if( rep == MATRICIAL ){
        int pos1 = BaseGrafo<T>::getPosNodo(pDato1);
        int pos2 = BaseGrafo<T>::getPosNodo(pDato2);
        if( -1 != pos1 and -1 != pos2 )
            matAdy[pos1][pos2] = false;
    }
}





#endif // DIGRAFO_H

