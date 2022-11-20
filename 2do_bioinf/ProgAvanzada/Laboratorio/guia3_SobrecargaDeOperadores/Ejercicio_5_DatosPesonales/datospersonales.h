#ifndef DATOSPERSONALES_H
#define DATOSPERSONALES_H
#include <fstream>
#include <iostream>
#include <vector>

class DatosPersonales
{
public:
    DatosPersonales();

    std::string getApellido() const;
    void setApellido(const std::string &value);

    int getFechaDeNacimiento() const;
    void setFechaDeNacimiento(int value);

    void setNombre(const std::string &value);

    void setSexo(char value);

    void setDNI(int value);

private:
    std::string nombre;
    std::string apellido;
    char sexo;
    int DNI;
    int FechaDeNacimiento;
};

#endif // DATOSPERSONALES_H
