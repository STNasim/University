#include "promdesv.h"
#include <iostream>
using namespace std;

PromDesv::PromDesv()
{

}

void PromDesv::CargaDatos()
{
    float Ingreso;

    cout<<"Ingrese numero de datos ";
    cin>>NroDatos;
    DatosCarga.resize(NroDatos);
    if(!DatosCarga.empty()){
        cout<<"Ingrese los datos ";
        for(float o=0;o<NroDatos;o++){
            cin>>Ingreso;
            DatosCarga[o]=Ingreso;
        }
    }
}

float PromDesv::PromCarga()
{
    if(!DatosCarga.empty()){
        float acumulador=0;

        for(float i=0;i<DatosCarga.size();i++){
        acumulador+=DatosCarga[i];
        }
        return (acumulador/DatosCarga.size());
    }
    else{
        if(Aviso!=1){
        cout<<"No hay datos cargados";
        VectorVacio=1;
        Aviso=1;
        }
    return 0;
    }
}

float PromDesv::DesvCarga()
{
    float Prom=PromCarga();
    if (VectorVacio==1){
        return 0;
    }
    float Acumulador=0;
    for(float y=0;y<DatosCarga.size();y++){
    Acumulador+=((DatosCarga[y]-Prom)*(DatosCarga[y]-Prom));
    }
    return (sqrt(Acumulador/DatosCarga.size()));

}

void PromDesv::MostrarPM(float Prom, float Desv)
{
    if (VectorVacio==0){
    cout<<"El promedio es: "<<Prom<<endl;
    cout<<"El desvio es: "<<Desv<<endl;
    }
}
