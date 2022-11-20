#include <QCoreApplication>
#include "complejos.h"
#include <iostream>

void MostarComplejo(Complejos w);

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Complejos a,aconj,b,r;

    a.setParteReal(10);
    a.setParteImaginaria(5);
    b.setParteReal(3);
    b.setParteImaginaria(8);
    std::cout<<"Los numeros a y b son: "<<std::endl;
    MostarComplejo(a);
    MostarComplejo(b);

    r=a+b;
    std::cout<<"La suma de a+b es: "<<std::endl;
    MostarComplejo(r);

    aconj=!a;
    std::cout<<"El conjugado de a es: "<<std::endl;
    MostarComplejo(aconj);

    if(a<b)
        std::cout<<"El complejo a es menor que b"<<std::endl;
    else
        std::cout<<"El complejo a no es menor que b;"<<std::endl;

    r=a*b;
    std::cout<<"El producto de los complejos es: ";
    MostarComplejo(r);

    std::cout<<"El complejo a antes de incrementar es: ";
    MostarComplejo(a);
    ++a;
    std::cout<<"el numero a incrementado es: ";
    MostarComplejo(a);

    std::cout<<"El complejo a predrecrementado es: ";
    MostarComplejo(--a);

    std::cout<<"El complejo b posdrecrementado es: ";
    r=b--;
    MostarComplejo(r);
    std::cout<<"y b: ";
    MostarComplejo(b);

    return app.exec();
}

void MostarComplejo(Complejos w){
    std::cout<<w.getParteReal()<<" "<<w.getParteImaginaria()<<"i"<<std::endl;
}
