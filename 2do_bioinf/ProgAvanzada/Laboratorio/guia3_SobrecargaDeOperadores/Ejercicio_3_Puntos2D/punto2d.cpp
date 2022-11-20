#include "punto2d.h"

Punto2D::Punto2D()
{

}

b Punto2D::getColumna() const
{
    return columna;
}

void Punto2D::setColumna(const b &value)
{
    columna = value;
}

Punto2D Punto2D::operator+(Punto2D sumando)
{
    Punto2D resultado;
    resultado.fila=fila+sumando.fila;
    resultado.columna=columna+sumando.columna;
    return resultado;
}

bool Punto2D::operator==(Punto2D comparador)
{
    bool iguales=0;
    if(fila==comparador.fila and columna==comparador.columna)
        iguales=1;
    return iguales;
}

bool Punto2D::operator!=(Punto2D comparador)
{
    bool distintos=(!((*this)==comparador));

    return distintos;
}

bool Punto2D::operator<(Punto2D comparador)
{
    bool menor=0;
    if(fila<comparador.fila and columna<comparador.columna)
        menor=1;
    return menor;
}

b Punto2D::getFila() const
{
    return fila;
}

void Punto2D::setFila(const b &value)
{
    fila = value;
}
