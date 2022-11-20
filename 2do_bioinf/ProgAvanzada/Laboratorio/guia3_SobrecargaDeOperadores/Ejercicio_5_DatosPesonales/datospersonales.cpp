#include "datospersonales.h"

DatosPersonales::DatosPersonales()
{

}

std::string DatosPersonales::getApellido() const
{
    return apellido;
}

void DatosPersonales::setApellido(const std::string &value)
{
    apellido = value;
}

int DatosPersonales::getFechaDeNacimiento() const
{
    return FechaDeNacimiento;
}

void DatosPersonales::setFechaDeNacimiento(int value)
{
    FechaDeNacimiento = value;
}

void DatosPersonales::setNombre(const std::string &value)
{
    nombre = value;
}

void DatosPersonales::setSexo(char value)
{
    sexo = value;
}

void DatosPersonales::setDNI(int value)
{
    DNI = value;
}
