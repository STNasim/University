#include "rectangulo.h"

Rectangulo::Rectangulo()
{

}

float Rectangulo::getBase() const
{
    return base;
}

void Rectangulo::setBase(float value)
{
    base = value;
}

float Rectangulo::getAltura() const
{
    return altura;
}

void Rectangulo::setAltura(float value)
{
    altura = value;
}

float Rectangulo::getArea() const
{
    return area;
}

void Rectangulo::CalcularArea()
{
    area=base*altura;
}

Rectangulo Rectangulo::operator+(Rectangulo sumando)
{
    Rectangulo resultado;
    resultado.base=base+sumando.base;
    resultado.altura=altura+sumando.altura;
    return resultado;
}

bool Rectangulo::operator==(Rectangulo comparador)
{
    bool resultado=0;
    if(getArea()==comparador.getArea())
        resultado=1;
    return resultado;
}

bool Rectangulo::operator!()
{
    bool resultado=0;
    if(base==altura)
        resultado=1;
    return resultado;
}

