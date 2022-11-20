#include <QApplication>
#include "interfaz.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    system("chcp 65001");
    Interfaz interfaz(&a);
    interfaz.InterfazInicio();

    return a.exec();
}
