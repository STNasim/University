#ifndef MODELO_H
#define MODELO_H
#include <iostream>
class Modelo
{
public:
    Modelo();
    void MostarAtributos();
    void HacerCorrer(float Tiempo);

    float getVelocidad() const;

    float getPosicion() const;

    std::string getNombre() const;

private:
    std::string Nombre;
    float Velocidad;
    float Posicion;
};

#endif // MODELO_H
