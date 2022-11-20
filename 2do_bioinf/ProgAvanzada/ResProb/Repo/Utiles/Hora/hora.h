#ifndef HORA_H
#define HORA_H
#include <iostream>
#include <time.h>
#include <ctime>

class Hora
{
public:
    Hora();
    char HoraActual[10];
    void IngresoHora(char HoraUsuario[10]);
    int HoraMayorActual(char HoraUsuario[10]);
    void DifHoraActual(char HoraUsuario[10]);
private:
    void CalcularHoraActual();
};

#endif // HORA_H
