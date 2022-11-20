#ifndef COMIDA_H
#define COMIDA_H
#include "Constantes.h"

class Comida
{
public:
    Comida();
    bool HayComida(int f, int c);
    int DevolverCantidad(int f, int c);
    int DevolverCantidadTotal();
    void Agregar(int f, int c, int CantidadAgregar);
    int Quitar(int f, int c,int QuiereComer); //Quita una cantidad de comida si es posible
                                                 //y devuelve cuanto se quito
private:
    vector <vector<int>> cantidad;
    bool EstaEnTerritorio(int f, int c);
};

#endif // COMIDA_H
