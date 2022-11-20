#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;

class Matriz
{
public:
    Matriz();

    void ExtraerDesdeFlujo(istream &pEntrada);
    void VolcarEnFlujo(ostream &pSalida);
    void operator=(string pStrMatriz);
};

//void operator>>(istream &entrada,Matriz pM);
istream& operator>>(istream &pEntrada,Matriz &pM);

ostream& operator<<(ostream &pSalida,Matriz pM);

#endif // MATRIZ_H
