#ifndef EQUIPOINCUBADORA_H
#define EQUIPOINCUBADORA_H
#include "equipo.h"

class EquipoIncubadora:public Equipo
{
public:
    EquipoIncubadora();
    int getTipo() override;
    ~EquipoIncubadora() override;
};

#endif // EQUIPOINCUBADORA_H
