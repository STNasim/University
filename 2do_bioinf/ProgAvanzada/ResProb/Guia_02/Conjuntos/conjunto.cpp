#include "conjunto.h"

Conjunto::Conjunto()
{

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
    salida<<"}";
}

std::vector<int> Conjunto::getElementos() const
{
    return elementos;
}

void Conjunto::setElementos(const std::vector<int> &value)
{
    elementos = value;
}

void Conjunto::operator<<(Conjunto a_agregar)
{
    for(unsigned int x=0;x<a_agregar.elementos.size();x++){
        if((*this)(a_agregar.elementos[x]))
            (*this)<<a_agregar.elementos[x];
    }
}

void Conjunto::operator>>(Conjunto a_restar)
{

}

bool Conjunto::operator()(int a)
{
    bool pertenece=false;
    for(unsigned int x=0;x<elementos.size()and(!pertenece);x++)
        if (elementos[x]==a)
            pertenece=true;
    return pertenece;
}

std::ostream &operator<<(std::ostream &salida, Conjunto a)
{
    a.VolcarEnFlujo(salida);
    return salida;
}
