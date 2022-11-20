#include <QCoreApplication>
#include "rectangulo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Rectangulo rectangulo1;
    Rectangulo rectangulo2;
    Rectangulo rectangulo3;

    rectangulo1.setBase(7);
    rectangulo1.setAltura(3);
    rectangulo2.setBase(3);
    rectangulo2.setAltura(5);
    rectangulo1.CalcularArea();
    rectangulo2.CalcularArea();

    rectangulo3=rectangulo1+rectangulo2;
    std::cout<<"La suma de los rectangulos 1 y 2 es: "<<std::endl;
    std::cout<<"Base: "<<rectangulo3.getBase()<<std::endl;
    std::cout<<"Altura: "<<rectangulo3.getAltura()<<std::endl;

    if(rectangulo1==rectangulo2)
        std::cout<<"Las areas de 1 y 2 son iguales"<<std::endl;
    else
        std::cout<<"Las areas de 1 y 2 son distintas"<<std::endl;

    if(!rectangulo1)
        std::cout<<"El rectangulo 1 es cuadrado"<<std::endl;
    else
        std::cout<<"El rectangulo 1 no es cuadrado"<<std::endl;

    return a.exec();
}
