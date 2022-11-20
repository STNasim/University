#include "sembrador.h"
#include <iostream>
using namespace std;

Sembrador::Sembrador()
{
    f=rand()%maxfilas;
    c=rand()%maxcolumnas;
    direccion=(rand()%8);
}

void Sembrador::Mover()
{
    bool buscarPosicionNueva=true;
    while (buscarPosicionNueva){
        if (rand()/((float)RAND_MAX)*100 < aleDirSembra)
            direccion=(rand()%8);
        int f_prueba, c_prueba;
        f_prueba=f+mov_relativo[direccion].f;
        c_prueba=c+mov_relativo[direccion].c;
        if (EstaEnTerritorio (f_prueba, c_prueba )){
            f=f_prueba;
            c=c_prueba;
            buscarPosicionNueva=false;
        }
        else{
            direccion=(rand()%8);
        }
    }
}

void Sembrador::Sembrar(Comida &comida)
{
    if(EstaEnTerritorio(f,c))
        comida.Agregar(f,c,cantSiembra);
}

int Sembrador::DevolverFila()
{
    return f;
}

int Sembrador::DevolverColumna()
{
    return c;
}







bool Sembrador::EstaEnTerritorio(int Nf, int Nc)
{
    return (Nf>=0 and Nf<(int)maxfilas and Nc>=0 and Nc<(int)maxcolumnas);
}
