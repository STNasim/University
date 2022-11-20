#ifndef SEMBRADOR_H
#define SEMBRADOR_H
#include "Constantes.h"
#include "comida.h"

class Sembrador
{
private:
    int f,c;
    int direccion;
    bool EstaEnTerritorio(int Nf,int Nc);
public:
    Sembrador();
    void Mover();
    void Sembrar(Comida &comida);
    int DevolverFila();
    int DevolverColumna();
};

#endif // SEMBRADOR_H
