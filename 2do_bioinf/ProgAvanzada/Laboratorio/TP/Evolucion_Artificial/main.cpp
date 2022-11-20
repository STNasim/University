#include <QApplication>
#include "mundo.h"
#include <iostream>
#include "archivos.h"
#include "graficador.h"
using namespace std;

void PruebaArchivos(Mundo &mundo, Archivos &archivos,int iteraciones=5)
{
    for(int o=0;o<iteraciones;o++)
    {
        int ingreso;
        cout<<"Ingrese 0 para guardar en texto 1 para guardar en binario, 2 para guardar en ambos o 3 para no guardar"<<endl;
        cin>>ingreso;
        while(ingreso!=0 and ingreso!=1 and ingreso!=2 and ingreso!=3)
        {
            cout<<"El numero es incorrecto"<<endl;
            cin>>ingreso;
        }
        if(ingreso==0)
            archivos.GuardarTexto(mundo);
        if(ingreso==1)
            archivos.GuardarBinario(mundo);
        if(ingreso==2)
        {
            archivos.GuardarTexto(mundo);
            archivos.GuardarBinario(mundo);
        }
        mundo.Vivir();
    }
    archivos.LeerTexto();
    archivos.LeerBinario();
}

int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    Mundo mundo;
    Graficador graficador(&mundo);
    graficador.simular();
    int ID=0;
    int tiempoVida=0;
    mundo.MOQueMasVivio(ID,tiempoVida);
    cout<<"El MO que mas vivio es el "<<ID<<" con un tiempo de vida de: "<<tiempoVida<<endl;
    mundo.MOQueMenosVivio(ID,tiempoVida);
    cout<<"El MO que menos vivio es el "<<ID<<" con un tiempo de vida de: "<<tiempoVida<<endl;

    Archivos archivos;
    PruebaArchivos(mundo,archivos);
    return a.exec();
}
