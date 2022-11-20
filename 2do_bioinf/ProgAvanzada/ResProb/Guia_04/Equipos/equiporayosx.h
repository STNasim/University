#ifndef EQUIPORAYOSX_H
#define EQUIPORAYOSX_H
#include "equipo.h"

class EquipoRayosX:public Equipo
{
public:
    EquipoRayosX();
    int getTipo() override;
    ~EquipoRayosX() override;
};

#endif // EQUIPORAYOSX_H
