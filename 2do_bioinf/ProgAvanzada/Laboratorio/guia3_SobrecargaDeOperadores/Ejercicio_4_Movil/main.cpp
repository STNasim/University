#include <QCoreApplication>
#include "movil.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Movil Movil1,Movil2,aux;

    Movil1.setPosicion(0);
    Movil1.setMeta(2);
    Movil2.setPosicion(3);
    Movil2.setMeta(10);
    std::cout<<"La posicion del movil1 es "<<Movil1.getPosicion()<<" y la meta "<<Movil1.getMeta()<<std::endl;
    std::cout<<"La posicion del movil2 es "<<Movil2.getPosicion()<<" y la meta "<<Movil2.getMeta()<<std::endl;

    aux=++Movil1;
    std::cout<<"La posicion del movil1 al  pre incrementar es: "<<aux.getPosicion()
             <<" que es igual a "<<Movil1.getPosicion()<<std::endl;
    aux=Movil1++;
    std::cout<<"La posicion del movil1 antes de posincrementar es "<<aux.getPosicion()
             <<" y la posicion al posincrementar es "<<Movil1.getPosicion()<<std::endl;

    aux=--Movil2;
    std::cout<<"La posicion del movil2 al pre decrementar es: "<<aux.getPosicion()
             <<" que es igual a "<<Movil2.getPosicion()<<std::endl;
    aux=Movil2--;
    std::cout<<"La posicion del movil2 antes de posdecrementar es "<<aux.getPosicion()
             <<" y la posicion al posdecrementar es "<<Movil2.getPosicion()<<std::endl;

    if(!Movil1)
        std::cout<<"El movil1 alcanzo la meta"<<std::endl;
    else
        std::cout<<"El movil1 no alcanzo la meta"<<std::endl;
    if(!Movil2)
        std::cout<<"El movil2 alcanzo la meta"<<std::endl;
    else
        std::cout<<"El movil2 no alcanzo la meta"<<std::endl;

    if(Movil1==Movil2)
        std::cout<<"Los 2 moviles tienen la misma distancia hacia la meta"<<std::endl;
    else
        std::cout<<"Los 2 moviles no tienen la misma distancia hacia la meta"<<std::endl;

    return a.exec();
}
