#include <QCoreApplication>
#include "modelo.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Modelo Corredor1;
    Modelo Corredor2;
    Modelo Corredor3;
    int Ingreso=0;
    int Ingreso2=0;
    float Tiempo;
    while(Ingreso!=99){
        std::cout<<"1.Mostar atributos del corredor"<<std::endl<<"2.Hacer correr"<<std::endl<<"99.Salir"<<std::endl;
        std::cin>>Ingreso;
        while(Ingreso!=1 and Ingreso !=2 and Ingreso !=99){
            std::cout<<"Ingrese el numero nuevamente"<<std::endl;
            std::cin>>Ingreso;
        }
        if(Ingreso==99)
            exit(0);
        std::cout<<"Ingrese el numero del corredor o 4 para aplicar a todos"<<std::endl;
        std::cin>>Ingreso2;
        while(Ingreso2!=1 and Ingreso2 !=2 and Ingreso2 !=3 and Ingreso2!=4){
            std::cout<<"Ingrese el numero nuevamente"<<std::endl;
            std::cin>>Ingreso2;
        }
        if (Ingreso==2){
            std::cout<<"Ingrese el tiempo que correra"<<std::endl;
            std::cin>>Tiempo;
        }
        if (Ingreso2==1){
            if(Ingreso==1)
                Corredor1.MostarAtributos();
            if(Ingreso==2)
                Corredor1.HacerCorrer(Tiempo);
        }
        if (Ingreso2==2){
            if(Ingreso==1)
                Corredor2.MostarAtributos();
            if(Ingreso==2)
                Corredor2.HacerCorrer(Tiempo);
        }
        if (Ingreso2==3){
            if(Ingreso==1)
                Corredor3.MostarAtributos();
            if(Ingreso==2)
                Corredor3.HacerCorrer(Tiempo);
        }
        if(Ingreso2==4){
            if(Ingreso==1){
                Corredor1.MostarAtributos();
                Corredor2.MostarAtributos();
                Corredor3.MostarAtributos();
            }
            if(Ingreso==2){
                Corredor1.HacerCorrer(Tiempo);
                Corredor2.HacerCorrer(Tiempo);
                Corredor3.HacerCorrer(Tiempo);
            }
        }
    }
    return a.exec();
}
