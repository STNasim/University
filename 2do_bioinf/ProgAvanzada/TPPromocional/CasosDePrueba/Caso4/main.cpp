#include <QApplication>

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "../Caso2/Segundero.h"
#include "tablero.h"
#include "caballo.h"
#include "texto.h"
#include "../Graficador2D/graficador2d.h"
#include "solversaltocaballo.h"

using namespace std;

//Solucion generarUnaSolucionDesde(int f, int c, int cantFil, int cantCol);

//void salta(int xinic, int yinic, int nsalto, Solucion& sol, bool& hay_solucion);
//void desplazaCaballo(int f, int c, Solucion& sol);

int main(int argc, char *argv[])
{
    try{
        QApplication app(argc, argv);

        system("chcp 65001");
        srand(unsigned(time(nullptr)));
        system("CLS");
        // Se indica tamaño de tablero y posición inicial del caballo
        unsigned cantFil = 8;
        unsigned cantCol = 8;
        unsigned filInicial = 1;
        unsigned colInicial = 1;

        // Se crea graficador
        Graficador2D graficador(&app);

        // Se crea dibujo de un tablero
        Tablero dib_tablero(cantFil, cantCol);

        // Se carga dibujo de tablero en graficador
        graficador.cargarDibujo( &dib_tablero );

        // Se crea un solver para generar una solución del problema del caballo
        SolverSaltoCaballo solver;

        // Se indica al solver que se desea imprimir el resultado por consola para testeos
        solver.setImprimirSolucion(true); // false: para no imprimir
        solver.setMostrarPosicionesIncorrectas(false);

        // Se establece un tiempo límite de 10 segundos para encontrar la solución (para evitar demoras!)
        solver.setFinalizarPorTiempo(true); // Se debe habilitar opción. (Si es falsa, el algoritmo busca sin parar hasta encontrar una solución; y puede demorar un largo tiempo)
        solver.setLimiteDeTiempo(2); // En segundos. Si coloca 0, todo será incorrecto, excepto posición inicial.

        // Se crea una solución en blanco que será rellenada por el solver.
        Solucion sol;

        //Se genera trayecto de un caballo por todos los cuadros de un tablero de ajedrez
        sol = solver.generarUnaSolucionDesde(filInicial, colInicial, cantFil, cantCol);

        //Se muestran algunos parámetros de la solución
        cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;

        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            graficador.cargarDibujo( &(sol.texto_posiciones[i]) );
        }

        //Se cargan los dibujos del caballo en su posición inicial y final
        graficador.cargarDibujo( &sol.caballo_inicial );
        graficador.cargarDibujo( &sol.caballo_final );

        Segundero cronometro;


        cout<<"Presione S para indicar que la solución es correcta y N para incorrecta"<<endl;
        //Se muestra el gráfico y se inicia el cronometro
        cronometro.IniciarCronometro();
        graficador.mostrar(400,400);

        //Se muestra la respuesta del usuario y el tiempo
        cronometro.MostrarTiempo();cout<<endl;
        if(graficador.getRespuestaUsuario()==1)
            cout<<"Eligio correcta"<<endl;
        else if(graficador.getRespuestaUsuario()==0)
            cout<<"Eligio incorrecta"<<endl;
            else
                cout<<"No se introdujo respuesta"<<endl;

        if(!sol.correcta){
            solver.setMostrarPosicionesIncorrectas(true);
            sol = solver.getSol(); // Se retorna solución con nuevos colores

            graficador.limpiarDibujos();
            graficador.cargarDibujo( &dib_tablero );
            for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
                graficador.cargarDibujo( &(sol.texto_posiciones[i]) );
            }
            //Se cargan los dibujos del caballo en su posición inicial y final
            graficador.cargarDibujo( &sol.caballo_inicial );
            graficador.cargarDibujo( &sol.caballo_final );
            //Se muestra el gráfico
            graficador.mostrar(400, 400);
        }
    }
    catch(...)
    {
        cout<<"Error en la ejecucion"<<endl;
    }
    //return app.exec();
    return 0;
}
