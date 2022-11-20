#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <time.h>
#include <ctime>

class Fecha
{
public:
    Fecha();
    void IngresoFecha(char FechaUsuario[10]);
    int FechaMayorActual(char FechaUsuario[10]);
    void DifFechaActual(char FechaUsuario[10]);
private:
    void CalcularFechaActual();
    int FechaMayorActualReturn(char FechaUsuario[10]);
    char FechaActual[11];
    int DiasMes[12]{31,28,31,30,31,30,31,31,30,31,30,31};
};

#endif // FECHA_H
