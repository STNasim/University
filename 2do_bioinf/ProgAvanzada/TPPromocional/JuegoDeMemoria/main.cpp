#include <QApplication>
#include "juegodememoria.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    JuegoDeMemoria juego;

    juego.ElegirNivel(1);
    juego.ElegirColorFondo(0.5,0.5,0.5);
    juego.MostrarAlInicio(true);
    juego.TiempoMostrarAlInicio(3);
    juego.IniciarJuego();

    return a.exec();
}
