#include <QApplication>

#include "rectangulo.h"
#include "graficador2d.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    float cx = 5, cy = 10, b = 6, a = 2, ang = 30; // ang en grados sexagesimals
    Rectangulo rect(cx, cy, b, a, ang); // Supondremos que Un Rectángulo es un Dibujo

    Graficador2D graficador( &app );

    graficador.cargarDibujo( &rect ); // Se pasa la "dirección de memoria" del dibujo

    // Se define tamaño de ventana y se muestra:
    graficador.mostrar(400, 400);

    return app.exec();
}
