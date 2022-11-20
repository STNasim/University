#include <QCoreApplication>
#include "punto2d.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Punto2D punto1, punto2,punto3;

    punto1.setColumna(2);
    punto1.setFila(5);
    punto2.setColumna(6);
    punto2.setFila(4);
    std::cout<<"El punto1 tiene las coordenadas: ("<<punto1.getColumna()<<","<<punto1.getFila()<<")"<<std::endl;
    std::cout<<"El punto2 tiene las coordenadas: ("<<punto2.getColumna()<<","<<punto2.getFila()<<")"<<std::endl;

    punto3=punto1+punto2;
    std::cout<<"El punto3 tiene las coordenadas: ("<<punto3.getColumna()<<","<<punto3.getFila()<<")"<<std::endl;

    if(punto1==punto2)
        std::cout<<"Los puntos estan en la misma posicion"<<std::endl;

    if(punto1!=punto2)
        std::cout<<"Los puntos estan en posiciones distintas"<<std::endl;

    if(punto1<punto2)
        std::cout<<"El punto1 tiene menor fila y columna que el punto2"<<std::endl;
    else
        std::cout<<"El punto1 no tiene menor fila y columna que el punto2"<<std::endl;

    return a.exec();
}
