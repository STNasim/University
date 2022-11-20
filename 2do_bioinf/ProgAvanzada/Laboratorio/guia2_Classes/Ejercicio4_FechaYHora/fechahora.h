#ifndef FECHAHORA_H
#define FECHAHORA_H
#include <time.h>
#include <iostream>

class FechaHora
{
public:
    FechaHora();
    tm TiempoActual;
    void MostarFecha();
    void MostarHora();
};

#endif // FECHAHORA_H
