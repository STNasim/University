#ifndef MEZCLA_H
#define MEZCLA_H
#include <iostream>
using namespace std;
template<class Contenedor>
Contenedor mezclar( Contenedor& c1, Contenedor& c2)
{
    Contenedor retorno;
    unsigned int i=0,j=0;
    while( ( i < c1.size() ) && ( j < c2.size() ) ) {
        if( c1[i] <= c2[j]) {
            retorno.push_back(c1[i]);
            i++; }
        else  {
            retorno.push_back(c2[j]);
            j++; }
    }
    while(i < c1.size()) {
        retorno.push_back(c1[i]);
        i++;}
    while(j < c2.size()) {
        retorno.push_back(c2[j]);
        j++;}
    return retorno;
}
template<class Contenedor>  bool esta_ordenado(Contenedor& c)
{
    bool ordenado=true;
    for(unsigned int i=0;i<(c.size()-1) && ordenado;i++)
    {
        if(c[i]>c[i+1])
            ordenado=false;
    }
    return ordenado;
}
#endif // MEZCLA_H
