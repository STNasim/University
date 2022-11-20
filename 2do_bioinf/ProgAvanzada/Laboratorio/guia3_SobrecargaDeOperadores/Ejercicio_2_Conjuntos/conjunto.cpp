#include "conjunto.h"

Conjunto::Conjunto()
{

}

void Conjunto::operator<<(int elemento)
{
    if(!(*this)(elemento))
        elementos.push_back(elemento);
}

void Conjunto::VolcarEnFlujo(std::ostream &salida)
{
    salida<<"{ ";
    if(elementos.size()>0){
        for(unsigned int x=0;x<elementos.size()-1;x++){
            salida<<elementos[x]<<", ";
        }
    salida<<elementos.back();
    }
    salida<<"}"<<std::endl;
}

void Conjunto::operator>>(int elemento)
{
    unsigned int posicion=0;
    bool pertenece=0;
    for(unsigned int x=0;x<elementos.size();x++)
        if(elemento==elementos[x]){
            pertenece=1;
            posicion=x;
        }
    if(pertenece==1)
        elementos.erase (elementos.begin()+posicion);
}

Conjunto Conjunto::operator+(Conjunto sumando) const
{
    int elemento;
    Conjunto resultado=(*this);
    for(unsigned int x=0;x<sumando.elementos.size();x++){
        elemento=sumando.elementos[x];
        resultado<<elemento;
    }
    return resultado;
}

Conjunto Conjunto::operator*(Conjunto factor) const
{
    int elemento;
    Conjunto resultado=(*this);
    for(unsigned int x=0;x<elementos.size();x++){
        elemento=elementos[x];
        if(!(factor(elemento)))
                resultado>>elemento;
    }
    return resultado;
}

bool Conjunto::operator()(int elemento)
{
    bool pertenece=0;
    for(unsigned int x=0;x<elementos.size();x++)
        if(elemento==elementos[x])
            pertenece=1;
    return pertenece;
}

std::ostream &operator<<(std::ostream &salida, Conjunto &conjunto)
{
    conjunto.VolcarEnFlujo(salida);
    return salida;

}
