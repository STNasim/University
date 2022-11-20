#include "movil.h"

Movil::Movil()
{

}

int Movil::getPosicion() const
{
    return posicion;
}

void Movil::setPosicion(int value)
{
    posicion = value;
}

int Movil::getMeta() const
{
    return meta;
}

void Movil::setMeta(int value)
{
    meta = value;
}

Movil Movil::operator++()
{
    posicion++;
    return (*this);
}

Movil Movil::operator++(int a)
{
    Movil resultado=(*this);
    ++(*this);
    return resultado;
}

Movil Movil::operator--()
{
    posicion--;
    return (*this);
}

Movil Movil::operator--(int a)
{
    Movil resultado=(*this);
    --(*this);
    return resultado;
}

bool Movil::operator!()
{
    bool alcanzo=0;
    if(posicion>=meta)
        alcanzo=1;
    return alcanzo;
}

bool Movil::operator==(Movil comparador)
{
    bool mismadistancia=0;
    if ((meta-posicion)==(comparador.meta-comparador.posicion))
        mismadistancia=1;
    return mismadistancia;
}
