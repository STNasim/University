#include "Segundero.h"

Segundero::Segundero()
{
    tiempoParada=0;
}

bool Segundero::EstaIniciado()
{
    bool retorno=false;
    if(cronometro.isValid() or tiempoParada!=0)
        retorno=true;
    return retorno;
}

void Segundero::IniciarCronometro()
{
    if(!cronometro.isValid())
        cronometro.start();
}

void Segundero::MostrarTiempo()
{
    if(cronometro.isValid() and tiempoParada==0)
        std::cout<<"Tiempo transcurrido: "<<cronometro.elapsed()/1000.000<<" segundos";
    if(cronometro.isValid() and tiempoParada!=0)
        std::cout<<"Tiempo transcurrido: "<<cronometro.elapsed()/1000.000+tiempoParada<<" segundos";
    if(!cronometro.isValid() and tiempoParada!=0)
        std::cout<<"Tiempo transcurrido: "<<tiempoParada<<" segundos";
    if(!cronometro.isValid() and tiempoParada==0)
        std::cout<<"No se inicio el cronometro";
}

void Segundero::PararCronometro()
{
    tiempoParada+=cronometro.elapsed()/1000.000;
    cronometro.invalidate();
}

float Segundero::ObtenerTiempo()
{
    float retorno=0;
    if(cronometro.isValid() and tiempoParada==0)
        retorno=cronometro.elapsed()/1000.000;
    if(cronometro.isValid() and tiempoParada!=0)
        retorno=cronometro.elapsed()/1000.000+tiempoParada;
    if(!cronometro.isValid() and tiempoParada!=0)
        retorno=tiempoParada;
    return retorno;
}

float Segundero::ObtenerTiempoYReinicar()
{
    float retorno=ObtenerTiempo();
    tiempoParada=0;
    cronometro.restart();
    return retorno;
}
