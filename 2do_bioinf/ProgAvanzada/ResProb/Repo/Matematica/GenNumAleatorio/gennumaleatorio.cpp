#include "gennumaleatorio.h"

GenNumAleatorio::GenNumAleatorio()
{
}

float GenNumAleatorio::RealAleatorio()
{

    float respuesta=rand()/(RAND_MAX-1);

    respuesta= (float)(rand())/(RAND_MAX-1);

    respuesta= min+ respuesta*(max-min);

    float factor=1.0f;

    for(float i=0;i<nrocifras;i++)
        factor *=10.0f;

    respuesta *= factor;

    respuesta= (int) respuesta;
    respuesta= respuesta/factor;

    return respuesta;
}

void GenNumAleatorio::CargaDatos()
{
    std::cout<<"Ingrese el valor minimo ";
    std::cin>>min;
    std::cout<<"Ingrese el valor maximo ";
    std::cin>>max;
    std::cout<<"Ingrese el numero de cifras ";
    std::cin>>nrocifras;
}

void GenNumAleatorio::SetDatos(float minset, float maxset, unsigned int nrocifrasset)
{
    min=minset;
    max=maxset;
    nrocifras=nrocifrasset;
}

