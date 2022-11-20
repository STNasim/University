#include <QApplication>
#include "manejoDatos.h"
#include "desempenio.h"
#include "../CasosDePrueba/Graficador2D/graficador2d.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ManejoDatos prueba;
    if(prueba.CargarPacientes())
    if(prueba.SeleccionarPaciente(3455555))
//    prueba.GuardarTest('M','4',12);
//    prueba.GuardarTest('M','4',10);
//    prueba.GuardarTest('M','4',6);
    prueba.CargarDatosPaciente();

//    vector <int> prueba;
//    prueba.resize(10);
//    for(int n=0;n<10;n++)
//        prueba[n]=rand()%10;

    Desempenio funcion;
    funcion.CargarDatos(prueba.ObtenerDatosPaciente('M','4'));
//    funcion.CargarDatos(prueba);
    Graficador2D graficador;
    graficador.cargarDibujo(&funcion);
    funcion.MostrarLineal(true);
    funcion.MostrarInterpolada(true);
    graficador.mostrar(500,500);

    exit(0);

    return app.exec();
}
