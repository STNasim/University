#include "cromosoma.h"

Cromosoma::Cromosoma()
{
    genes.resize(8);
    for(int n=0;n<8;n++)
        genes[n]=rand()%8;
}

int Cromosoma::MedirInteligencia()
{
    int inteligencia=0;
    for(int n=0;n<8;n++)
        if(genes[n]==n)
            inteligencia++;
    return inteligencia;
}

int Cromosoma::DevolverGen(int Ngen)
{
    int retorno=-1;
    if(GenPertenece(Ngen))
        retorno=genes[Ngen];
    return retorno;
}

void Cromosoma::Reescribir(Cromosoma cromosoma1, Cromosoma cromosoma2)
{
    int corte=(rand()%7)+1;
        for(int n=0;n<corte;n++)
            genes[n]=cromosoma1.DevolverGen(n);
        for(int n=corte;n<8;n++)
            genes[n]=cromosoma2.DevolverGen(n);
    if(rand()/((float)RAND_MAX)*100 < probMutacion)
        Mutar();
}

bool Cromosoma::GenPertenece(int Ngen)
{
    return(Ngen>=0 and Ngen<8);
}

void Cromosoma::Mutar()
{
    int lugar=rand()%8;
    genes[lugar]=rand()%8;
}
