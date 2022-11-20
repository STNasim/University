#include "termometro.h"

Termometro::Termometro()
{
    srand(time(0));
}

float Termometro::MostarTemperatura()
{
    Conversor conversor;
    return conversor.convertir();
}

