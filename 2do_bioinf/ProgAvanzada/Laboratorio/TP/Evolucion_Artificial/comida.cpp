#include "comida.h"

Comida::Comida()
{
   cantidad.resize(maxfilas);
   for(int fil=0;fil<maxfilas;fil++)
       cantidad[fil].resize(maxcolumnas);
}

bool Comida::HayComida(int f, int c)
{
    bool retorno=false;
    if(EstaEnTerritorio(f,c) and (cantidad[f][c]!=0))
        retorno=true;
    return retorno;
}


int Comida::DevolverCantidad(int f, int c)
{
    int retorno=0;
    if(EstaEnTerritorio(f,c))
    {
        retorno=cantidad[f][c];
    }
    return retorno;
}

int Comida::DevolverCantidadTotal()
{
    int acumulador=0;
    for(uint fil=0;fil<cantidad.size();fil++)
    {
        for(uint col=0;col<cantidad[0].size();col++)
        {
            acumulador+=cantidad[fil][col];
        }
    }
    return acumulador;
}

void Comida::Agregar(int f, int c, int CantidadAgregar)
{
    if(EstaEnTerritorio(f,c))
    {
        int CantidadPrueba=cantidad[f][c]+CantidadAgregar;
        if(CantidadPrueba<=MaxComida)
            cantidad[f][c]=CantidadPrueba;
        else
            cantidad[f][c]=MaxComida;
    }
}

int Comida::Quitar(int f, int c, int QuiereComer)
{
    int retorno=0;
    if(EstaEnTerritorio(f,c))
    {
        int CantidadPrueba=cantidad[f][c]-QuiereComer;
        if(CantidadPrueba>=0)
        {
            cantidad[f][c]=CantidadPrueba;
            retorno=QuiereComer;
        }
        else
        {
            cantidad[f][c]=0;
            retorno=cantidad[f][c];
        }
    }

    return retorno;
}





bool Comida::EstaEnTerritorio(int Nf, int Nc)
{
    return (Nf>=0 and Nf<(int)maxfilas and Nc>=0 and Nc<(int)maxcolumnas);
}
