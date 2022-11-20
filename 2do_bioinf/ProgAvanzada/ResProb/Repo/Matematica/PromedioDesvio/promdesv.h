#ifndef PROMDESV_H
#define PROMDESV_H

#include <vector>
#include <math.h>
#include <iostream>

class PromDesv
{
public:
    bool VectorVacio=0;
    bool Aviso=0;
    unsigned int NroDatos;
    std::vector <float> DatosCarga;

    PromDesv();

    void CargaDatos();
    float PromCarga();
    float DesvCarga();
    void MostrarPM(float Prom, float Desv);
};

#endif // PROMDESV_H
