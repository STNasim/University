/*!
 *  \class     Test Cartas.
 *  \brief     Clase que permite probar distintos aspectos de las cartas
 *  \details   La clase consiste en seleccionar una carta de la mesa y con un click, voltearla, ademas de permitir
 *              seleccionar el mazo de cartas que se quiere repartir.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 28/05/2020.
 *  \pre       La clase esta diseñada, principalmente, para manipular objetos de tipo Carta y distribuirlos.
 *  \bug       -
 *  \warning   Para poder repartir las cartas se tiene que proveer una distribucion valida en relación al mazo tambien
 *              dado, puede darse normalemente muchos casos en que no sea posible repartirlas.
 *  \copyright GNU Public License.
*/
#ifndef TESTCARTAS_H
#define TESTCARTAS_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QTimer>

#include "..\Caso1\carta.h"
#include "..\Caso1\mesa.h"

class TestCartas: public QOpenGLWidget
{
    // Necesario para definir slot/signal
    Q_OBJECT
public:
    /*!
     * \brief TestCartas Establece el puntero a la aplicación, los margenes
     *                    y se inicializa el puntero para seleccionar carta
     * \param pptrApp Puntero a la aplicación de QT
     */
    TestCartas(QApplication* pptrApp = nullptr);
    ~TestCartas();

    /*!
     * \brief seleccionaMazo Se colocan las cartas a utilizar en un mazo
     */
    void seleccionaMazo();

    /*!
     * \brief repartirCartas Utilizando el mazo y una distribucion, se reparten las cartas sobre la mesa y
     *                        se inicia la aplicación que las muestra en una ventana
     */
    void repartirCartas();

protected:
    //Metodos heredados de QOpenGLWidget
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    //Eventos
    void mousePressEvent(QMouseEvent *event);

private:

    /*!
     * \brief ptrApp Puntero a una aplicación
     */
    QApplication* ptrApp;

    // Mazo de cartas
    vector<Carta*> mazoDeCartas;

    // Cartas seleccionadas por el paciente
    Carta* cartaSeleccionada;

    // Tablero de cartas
    Mesa mesaConCartas;

    // Espacio de graficación
    double margen;
    double anchoMesaConCartas;
    double altoMesaConCartas;

    int coordenadaAPosicionCuantizada(double pCoord, double limite);

private slots:
    // Da vuelta las cartas
    void voltearCarta();
};

#endif // TESTCARTAS_H
