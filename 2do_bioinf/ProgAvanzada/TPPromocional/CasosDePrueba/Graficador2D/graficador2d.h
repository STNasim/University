/*!
 *  \class     Graficador.
 *  \brief     Clase que recibe dibujos y los grafica en una ventana.
 *  \details   La clase guarda punteros a dibujos en un vector y en base a estos puede calcular las dimensiones óptimas
 *              para el graficador y representarlos. Tambien tiene un evento de tecla para captar una respuesta del
 *              usuario y un método que la devuelve.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.1.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 26/05/2020.
 *  \pre       Puede utilizarse cuando se necesiten graficar múltiples figuras y se quiera simplificar a la hora de
 *              cargarlas y dibujarlas.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef GRAFICADOR2D_H
#define GRAFICADOR2D_H

#include <QApplication>
#include <QOpenGLWidget>
#include <deque>
#include <QKeyEvent>
#include <iostream>
#include "..\Caso4\solversaltocaballo.h"

#include "dibujo.h"

//using namespace std;

class Graficador2D : public QOpenGLWidget
{

public:
    /*!
     * \brief Graficador2D Se crea el objeto y se asigna el puntero a la aplicación
     * \param pApp Puntero a la aplicación
     */
    Graficador2D(QApplication* pApp);

    /*!
     * \brief Graficador2D Constructor vacio
     */
    Graficador2D(){};

    /*!
     * \brief cargarDibujo Se agrega un dibujo al final del vector de punteros de dibujo
     * \param pPtr_dib Puntero al dibujo a cargar
     */
    void cargarDibujo( Dibujo* pPtr_dib );

    /*!
     * \brief limpiarDibujos Se eliminan todos los dibujos cargados en el vector
     */
    void limpiarDibujos();

    /*!
     * \brief mostrar Se inicia la ventana y se grafican los dibujos que haya almacenados
     * \param w Ancho de la ventana
     * \param h Largo de la ventana
     */
    void mostrar(int w, int h);

    /*!
     * \brief getRespuestaUsuario Devuelve un número dependiendo de la interacción del usuario
     * \return Un número tipo int
     */

    int getRespuestaUsuario();

    /*!
     * \brief setPtr_app Establece el puntero a la aplicación
     * \param value Puntero a QApplication
     */
    void setPtr_app(QApplication *value);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int RespuestaUsuario;

    std::deque<Dibujo*> ptrs_dib; // Dibujos que se han de "dibujar"
    double minX, maxX, minY, maxY;

    // Métodos auxiliares
    void determinarDimensiones();

    // Métodos a redefinir
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    QApplication* ptr_app; // Permite controlar la aplicación.
};

#endif // GRAFICADOR2D_H
