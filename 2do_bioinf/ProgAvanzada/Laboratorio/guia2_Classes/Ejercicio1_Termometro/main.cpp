#include <QCoreApplication>
#include "termometro.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Termometro termometro;

    for(int Repetidor=0;Repetidor<5;Repetidor++)
    std::cout<<termometro.MostarTemperatura()<<std::endl;

    return a.exec();
}
