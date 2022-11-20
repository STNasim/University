#ifndef CROMOSOMA_H
#define CROMOSOMA_H
#include "Constantes.h"

class Cromosoma
{
public:
    Cromosoma();
    int MedirInteligencia();
    int DevolverGen(int Ngen);
    void Reescribir(Cromosoma cromosoma1,Cromosoma cromosoma2);

private:
    vector < int > genes;
    void Mutar();
    bool GenPertenece(int Ngen);
};

#endif // CROMOSOMA_H
