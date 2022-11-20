#include "conversor.h"

Conversor::Conversor()
{

}

float Conversor::convertir()
{
    Sensor sensor;
    float Resultado=0;
    Resultado=(-20+(((120-(-20))/(5-0))*(sensor.sensar()-0)));
    return Resultado;
}
