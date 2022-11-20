#include <QCoreApplication>
#include "generarpuntos.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GenerarPuntos Punto3D1;
    GenerarPuntos Punto3D2;
    GenerarPuntos Punto3D3;
    int Ingreso=0;
    int Ingreso2=0;
    int Ingreso3=0;
    float x2,y2,z2;
    while(Ingreso!=99){
        std::cout<<"1.Modificar valores de las coordenadas"<<std::endl<<"2.Calcular la distancia al origen"<<std::endl<<"3.Calcular la distancia a otro punto"<<std::endl<<"99.Salir"<<std::endl;
        std::cin>>Ingreso;
        while(Ingreso!=1 and Ingreso!=2 and Ingreso!=3 and Ingreso!=99){
            std::cout<<"Introduzca el numero nuevamente"<<std::endl;
            std::cin>>Ingreso;
        }
        if(Ingreso==1){
            std::cout<<"Ingrese el numero del punto que desea modificar"<<std::endl;
            std::cin>>Ingreso2;
            while(Ingreso2!=1 and Ingreso2!=2 and Ingreso2!=3){
                std::cout<<"Ingrese el numero nuevamente"<<std::endl;
                std::cin>>Ingreso2;
            }
        if(Ingreso2==1)
            Punto3D1.ModificarObjetos();
        if(Ingreso2==2)
            Punto3D2.ModificarObjetos();
        if(Ingreso2==3)
            Punto3D3.ModificarObjetos();

        }
        if(Ingreso==2){
            std::cout<<"Ingrese el numero del punto que desea calcular"<<std::endl;
            std::cin>>Ingreso2;
            while(Ingreso2!=1 and Ingreso2!=2 and Ingreso2!=3){
                std::cout<<"Ingrese el numero nuevamente"<<std::endl;
                std::cin>>Ingreso2;
            }
        if(Ingreso2==1)
            Punto3D1.DistanciaOrigen();
        if(Ingreso2==2)
            Punto3D2.DistanciaOrigen();
        if(Ingreso2==3)
            Punto3D3.DistanciaOrigen();
        }
        if(Ingreso==3){
            std::cout<<"Ingrese el numero del primer punto que desea calcular"<<std::endl;
            std::cin>>Ingreso2;
            while(Ingreso2!=1 and Ingreso2!=2 and Ingreso2!=3){
                std::cout<<"Ingrese el numero nuevamente"<<std::endl;
                std::cin>>Ingreso2;
            }
        std::cout<<"Ingrese el numero del segundo punto que desea calcular"<<std::endl;
        std::cin>>Ingreso3;
        while(Ingreso3!=1 and Ingreso3!=2 and Ingreso3!=3){
            std::cout<<"Ingrese el numero nuevamente"<<std::endl;
            std::cin>>Ingreso3;
        }
        if(Ingreso3==1)
            Punto3D1.DatosPuntoComparar(x2,y2,z2);
        if(Ingreso3==2)
            Punto3D2.DatosPuntoComparar(x2,y2,z2);
        if(Ingreso3==3)
            Punto3D3.DatosPuntoComparar(x2,y2,z2);
        if(Ingreso2==1)
            Punto3D1.DistanciaEntrePuntos(x2,y2,z2);
        if(Ingreso2==2)
            Punto3D2.DistanciaEntrePuntos(x2,y2,z2);
        if(Ingreso2==3)
            Punto3D3.DistanciaEntrePuntos(x2,y2,z2);
        }
        Ingreso2=0;
        Ingreso3=0;
    }

    return a.exec();
}
