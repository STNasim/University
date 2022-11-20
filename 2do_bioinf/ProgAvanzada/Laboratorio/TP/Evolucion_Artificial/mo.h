#ifndef MO_H
#define MO_H
#include "comida.h"
#include "cromosoma.h"
#include "Constantes.h"
class MO
{
private:
    int energia;
    int edad;
    int f,c;
    int direccion;
    bool EstaEnTerritorio(int Nf,int Nc);
    Cromosoma cromosoma;
    Cromosoma DevolverCromosoma();
public:
    MO();
    void Mover(Comida &comida);
    void Comer(Comida &comida); //Se quita una cantidad de comida de la posicion y se agrega energia
    void Hijo(MO MO1,MO MO2);
    bool Estavivo();

    int DevolverInteligencia();

    int getEnergia() const;
    int getEdad() const;
    int getF() const;
    int getC() const;
};

#endif // MO_H
