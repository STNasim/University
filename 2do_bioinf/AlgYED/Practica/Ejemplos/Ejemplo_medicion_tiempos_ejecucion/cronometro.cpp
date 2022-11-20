#include "cronometro.h"

Cronometro::Cronometro()
{

}

void Cronometro::iniciarCronometro()
{
    t1 = std::chrono::high_resolution_clock::now();
}

void Cronometro::pararCronometro()
{
    t2 = std::chrono::high_resolution_clock::now();
}

double Cronometro::getDuracionEnSegundos()
{
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    return time_span.count();
}

double Cronometro::getResolucionEnSegundos()
{
    auto numerador = std::chrono::high_resolution_clock::period::num;
    auto denominador = std::chrono::high_resolution_clock::period::den;
    return double(numerador)/denominador;
}
