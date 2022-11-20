#ifndef GENNUMALEATORIO_H
#define GENNUMALEATORIO_H
#include <ctime>
#include <iostream>

class GenNumAleatorio
{
public:

    float numero_real;
    float min, max;
    unsigned int nrocifras;
    GenNumAleatorio();
    float RealAleatorio();
    void CargaDatos();
    void SetDatos(float minset,float maxset,unsigned int nrocifrasset);
};

#endif // GENNUMALEATORIO_H
