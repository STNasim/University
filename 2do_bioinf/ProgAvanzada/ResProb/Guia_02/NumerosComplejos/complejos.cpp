#include "complejos.h"

Complejos::Complejos()
{

}

void Complejos::setParteReal(float value)
{
    ParteReal = value;
}

void Complejos::setParteImaginaria(float value)
{
    ParteImaginaria = value;
}

float Complejos::getParteReal() const
{
    return ParteReal;
}

float Complejos::getParteImaginaria() const
{
    return ParteImaginaria;
}

Complejos Complejos::operator+(Complejos sumando)
{
    Complejos resultado;
    resultado.ParteReal=ParteReal+sumando.getParteReal();
    resultado.ParteImaginaria=ParteImaginaria+(sumando.getParteImaginaria());
    return resultado;
}

Complejos Complejos::operator!()
{
    Complejos resultado;
    resultado.ParteImaginaria=ParteImaginaria*(-1);
    resultado.ParteReal=ParteReal;
    return resultado;

}

bool Complejos::operator<(Complejos comparador)
{
    float modulo_comparador1=sqrt((getParteReal()*getParteReal()+getParteImaginaria()*getParteImaginaria()));
    float modulo_comparador2=sqrt((comparador.getParteReal()*comparador.getParteReal()+comparador.getParteImaginaria()*comparador.getParteImaginaria()));
    if(modulo_comparador1<modulo_comparador2)
        return true;
    else
        return false;
}

Complejos Complejos::operator*(Complejos Factor)
{
    Complejos resultado;

    resultado.ParteReal=ParteReal*Factor.getParteReal()+ParteImaginaria*Factor.getParteImaginaria()*(-1);
    resultado.ParteImaginaria=ParteReal*Factor.getParteImaginaria()+ParteImaginaria*Factor.getParteReal();

    return resultado;
}

Complejos Complejos::operator++()
{
    ParteReal++;
    ParteImaginaria++;
    return *this;
}

Complejos Complejos::operator--()
{
    ParteReal--;
    ParteImaginaria--;
    return *this;
}

Complejos Complejos::operator--(int a)
{
    Complejos res= *this;
    --*this;
    return res;
}
