#include "equipo.h"

Equipo::Equipo()
{

}

Equipo::Equipo(string pNombre, int pNumeroSerie)
{
    Nombre=pNombre;
    NumeroSerie=pNumeroSerie;
}

void Equipo::setNombre(string nuevoNombre)
{
    Nombre=nuevoNombre;
}

string Equipo::getNombre()
{
    return Nombre;
}

void Equipo::setNumeroSerie(int nuevoNumero)
{
    NumeroSerie=nuevoNumero;
}

int Equipo::getNumeroSerie()
{
    return NumeroSerie;
}

int Equipo::getTipo()
{
    return -1;
}

Equipo::~Equipo()
{

}
