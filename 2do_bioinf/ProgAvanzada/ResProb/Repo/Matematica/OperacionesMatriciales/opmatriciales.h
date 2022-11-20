#ifndef OPMATRICIALES_H
#define OPMATRICIALES_H
#include <iostream>
using namespace std;

class OpMatriciales
{
public:
    float Matriz[3][3];
    float Trans [3][3];
    float Det=1;
    float Vmax=1;
    bool IngresoDatos=0;
    bool CalDet=0;
    bool CalVmax=0;
    bool CalTrans=0;
    bool Aviso=0;
    OpMatriciales();

    void Ingreso();
    float Determinante();
    float ValorMax();
    void Transpuesta();
    void MostrarResultados();
};

#endif // OPMATRICIALES_H
