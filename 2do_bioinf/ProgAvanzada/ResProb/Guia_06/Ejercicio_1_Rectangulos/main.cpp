#include <QCoreApplication>

#include "graficador2d.h"
#include "rectangulo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QApplication app(argc, argv);
    Rectangulo rect;
    Graficador2D graficador;

    graficador.cargarDibujo(&rect);
    graficador.mostar();

    return a.exec();
}
