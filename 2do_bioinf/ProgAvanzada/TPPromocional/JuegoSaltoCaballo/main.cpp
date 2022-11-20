#include <QApplication>
#include "juegosaltocaballo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    JuegoSaltoCaballo juego(&a);
    juego.SeleccionarNivel(3);
    juego.IniciarJuego();

    cout<<juego.ObtenerNivelSuperado()<<endl;
    cout<<juego.ObtenerTiempoSuperado()<<endl;
    return a.exec();
}
