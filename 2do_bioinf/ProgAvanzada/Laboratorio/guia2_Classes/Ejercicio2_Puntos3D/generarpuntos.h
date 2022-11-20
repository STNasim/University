#ifndef GENERARPUNTOS_H
#define GENERARPUNTOS_H
#include <iostream>
#include <math.h>

class GenerarPuntos
{
public:
    GenerarPuntos();
    float x;
    float y;
    float z;
    float x2;
    float y2;
    float z2;
    void ModificarObjetos();
    void DistanciaOrigen();
    void DistanciaEntrePuntos(float &x2,float &y2, float &z2);
    void DatosPuntoComparar(float &x2,float &y2, float &z2);
};

#endif // GENERARPUNTOS_H
