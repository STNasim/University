/*!
 *  \class     Interfaz.
 *  \brief     La clase se encarga de conectar las distintas funcionalidades con el usuario
 *  \details   La clase consiste en  una interfaz general que conecta el resto de menús,
 *               en los cuales el usuario puede navegar y ejecutar los distintos comandos que necesite.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 03/06/2020.
 *  \date      Fecha de última modificación: 03/06/2020.
 *  \pre       La clase puede ser utilizada cuando se necesite una interfaz con distintos menús y
 *              el usuario tenga que navegar e interactuar entre ellos.
 *  \bug       Insertar valores númericos muy grandes o caracteres no númericos en ciertos menús puede
 *              provocar que el programa deje de funcionar.
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <QApplication>
#include <iostream>
#include "../Funcionalidades/desempenio.h"
#include "../Funcionalidades/manejoDatos.h"
#include "../JuegoDeMemoria/juegodememoria.h"
#include "../JuegoSaltoCaballo/juegosaltocaballo.h"
#include "../CasosDePrueba/Graficador2D/graficador2d.h"
//using namespace std;

class Interfaz
{
public:
    /*!
     * \brief Interfaz Constructor en el que se pasa el puntero a aplicación y se establece en donde sea necesario,
     *                  tambien se inicializan las variables
     * \param ptrApp Puntero a QApplication
     */
    Interfaz(QApplication *ptrApp=nullptr);

    /*!
     * \brief InterfazInicio Muestra la interfaz de inicio, la cual contiene a los demas menús
     */
    void InterfazInicio();
private:
    void InterfazDatosYGraficas();
    void InterfazMemoria();
    void InterfazCaballo();
    bool pacienteSeleccionado,datosCargados;
    JuegoDeMemoria memoria;
    JuegoSaltoCaballo caballo;
    ManejoDatos datos;
    Desempenio funciones;
    Graficador2D graficador;
};

#endif // INTERFAZ_H
