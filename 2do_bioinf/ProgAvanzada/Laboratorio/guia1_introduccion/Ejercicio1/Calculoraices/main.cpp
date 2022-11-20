#include <QCoreApplication>
#include <calraices.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    calraices CR;

    CR.LeerDatos();
    CR.CalculoRaices();
    CR.MostrarDatos();

    return a.exec();
}
