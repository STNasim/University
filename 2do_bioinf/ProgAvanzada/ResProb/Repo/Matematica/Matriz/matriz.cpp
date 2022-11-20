#include "matriz.h"

Matriz::Matriz()
{

}

void Matriz::ExtraerDesdeFlujo(istream &pEntrada){

}

void Matriz::VolcarEnFlujo(ostream &pSalida)
{

}

void Matriz::operator=(string pStrMatriz)
{

}

//void operator>>(istream &entrada, Matriz pM)
//{
//    pM.ExtraerDesdeFlujo(entrada);
//}

istream &operator>>(istream &pEntrada, Matriz &pM)
{
    pM.ExtraerDesdeFlujo(pEntrada);
    return pEntrada;
}

ostream &operator<<(ostream &pSalida, Matriz pM)
{
    pM.VolcarEnFlujo(pSalida);
    return pSalida;
}
