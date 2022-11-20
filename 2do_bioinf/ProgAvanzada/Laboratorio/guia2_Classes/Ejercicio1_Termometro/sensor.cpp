#include "sensor.h"

Sensor::Sensor()
{

}

float Sensor::sensar()
{
    GenNumAleatorio GNA;
    GNA.SetDatos(0,5,2);
    float NumAleatorio=GNA.RealAleatorio();
    return NumAleatorio;
}
