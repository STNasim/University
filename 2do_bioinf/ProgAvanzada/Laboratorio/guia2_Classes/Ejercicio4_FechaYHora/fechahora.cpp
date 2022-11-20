#include "fechahora.h"

FechaHora::FechaHora()
{
    time_t rawtime;
    time (&rawtime);
    TiempoActual = *localtime (&rawtime);
}

void FechaHora::MostarFecha()
{
    std::cout<<"La fecha actual es "<<1900+TiempoActual.tm_year<<'/'<<TiempoActual.tm_mon+1<<'/'<<TiempoActual.tm_mday<<std::endl;
}

void FechaHora::MostarHora()
{
    std::cout<<"La hora es: "<<TiempoActual.tm_hour<<':'<<TiempoActual.tm_min<<':'<<TiempoActual.tm_sec<<std::endl;
}
