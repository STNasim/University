#include "generarpuntos.h"

GenerarPuntos::GenerarPuntos()
{
    std::cout<<"Ingrese las coordenadas x,y,z del punto, por separado"<<std::endl;
    std::cin>>x>>y>>z;
}

void GenerarPuntos::ModificarObjetos()
{
    std::cout<<"Ingrese las coordenadas x,y,z del punto, por separado"<<std::endl;
    std::cin>>x>>y>>z;
}

void GenerarPuntos::DistanciaOrigen()
{
    float Distancia=0;
    Distancia=sqrt((x*x)+(y*y)+(z*z));
    std::cout<<"La distancia al origen es de "<<Distancia<<std::endl;
}

void GenerarPuntos::DistanciaEntrePuntos(float &x2,float &y2, float &z2)
{
    float Distancia=0;
    if(x==x2 and y==y2 and z==z2)
        std::cout<<"Los puntos son iguales por lo tanto la distancia es 0"<<std::endl;
    else{
        x2-=x;
        y2-=y;
        z2-=z;
        Distancia=sqrt((x2*x2)+(y2*y2)+(z2*z2));
        std::cout<<"La distancia entre los puntos es de "<<Distancia<<std::endl;
    }
}

void GenerarPuntos::DatosPuntoComparar(float &x2,float &y2, float &z2)
{
    x2=x;
    y2=y;
    z2=z;
}
