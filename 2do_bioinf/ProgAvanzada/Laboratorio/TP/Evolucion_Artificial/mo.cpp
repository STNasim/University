#include "mo.h"


MO::MO()
{
    f=rand()%maxfilas;
    c=rand()%maxcolumnas;
    direccion=rand()%8;
    edad=0;
    energia=eInicial;
}

void MO::Mover(Comida &comida)
{
    if(Estavivo())
    {
        bool Buscarposicion=true;
        int dir=0;
        while(Buscarposicion and dir<8)
        {
            if(comida.HayComida(f+mov_relativo[dir].f,c+mov_relativo[dir].c) and
               EstaEnTerritorio(f+mov_relativo[cromosoma.DevolverGen(dir)].f,c+mov_relativo[cromosoma.DevolverGen(dir)].c))
            {
                    f=f+mov_relativo[cromosoma.DevolverGen(dir)].f;
                    c=c+mov_relativo[cromosoma.DevolverGen(dir)].c;
                    direccion=cromosoma.DevolverGen(dir);
                    Buscarposicion=false;
            }
            else
                 dir++;
        }
        while(Buscarposicion)
        {
               if(rand()/((float)RAND_MAX)*100 < aleDirMO)
                   direccion=rand()%8;
               if(EstaEnTerritorio(f+mov_relativo[direccion].f,c+mov_relativo[direccion].c))
               {
                   f=f+mov_relativo[direccion].f;
                   c=c+mov_relativo[direccion].c;
                   Buscarposicion=false;
               }
               else
                   direccion=rand()%8;
        }
        energia-=eNecMueve;
        edad++;
    }
}

void MO::Comer(Comida &comida)
{
    if(Estavivo() and comida.HayComida(f,c))
    {
        int vaComer=cCome;
        if(cCome+energia>eMaxMO)
            vaComer=eMaxMO-energia;
        energia+=comida.Quitar(f,c,vaComer);
    }
}

void MO::Hijo(MO MO1, MO MO2)
{
    cromosoma.Reescribir(MO1.DevolverCromosoma(),MO2.DevolverCromosoma());
    energia=eInicial;
    direccion=rand()%8;
    edad=0;
}

bool MO::Estavivo()
{
    return (energia>0);
}

int MO::DevolverInteligencia()
{
    return cromosoma.MedirInteligencia();
}





int MO::getEnergia() const
{
    return energia;
}

int MO::getEdad() const
{
    return edad;
}

int MO::getF() const
{
    return f;
}

int MO::getC() const
{
    return c;
}

Cromosoma MO::DevolverCromosoma()
{
    return cromosoma;
}

bool MO::EstaEnTerritorio(int Nf, int Nc)
{
    return (Nf>=0 and Nf<(int)maxfilas and Nc>=0 and Nc<(int)maxcolumnas);
}
