#include "modelo.h"

Modelo::Modelo()
{
    std::cout<<"Ingrese el nombre con un punto al final"<<std::endl;
    std::getline(std::cin,Nombre,'.');
    std::cout<<"Ingrese la posicion"<<std::endl;
    std::cin>>Posicion;
    std::cout<<"Ingrese la velocidad"<<std::endl;
    std::cin>>Velocidad;
}

void Modelo::MostarAtributos()
{
    std::cout<<"El nombre del corredor es: "<<Nombre<<std::endl;
    std::cout<<"La posicion del corredor es: "<<Posicion<<std::endl;
    std::cout<<"La velocidad del corredor es: "<<Velocidad<<std::endl;
}

void Modelo::HacerCorrer(float Tiempo)
{
    Posicion+=(Velocidad*Tiempo);
}

float Modelo::getVelocidad() const
{
    return Velocidad;
}

float Modelo::getPosicion() const
{
    return Posicion;
}

std::string Modelo::getNombre() const
{
    return Nombre;
}
