/*!
 *  \class     JuegoDeLaMemoria.
 *  \brief     Clase que simula el juego de la memoria, que consiste
 *              en encontrar todas las cartas con sus respectivos pares
 *  \details   El objeto selecciona un mazo con cartas y es capaz de repartirlas en la mesa, voltearlas
 *              y ademas, se encarga de los principales comandos de graficación
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.1.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 26/05/2020.
 *  \pre       Se utiliza cuando se quiera simular un juego de memoria con cartas.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef JUEGODELAMEMORIA_H
#define JUEGODELAMEMORIA_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QTimer>

#include "carta.h"
#include "mesa.h"

class JuegoDeLaMemoria: public QOpenGLWidget
{
    // Necesario para definir slot/signal
    Q_OBJECT
public:
    /*!
     * \brief JuegoDeLaMemoria Crea el juego de memoria, establece el puntero a la aplicación, los margenes,
     *                          los punteros con los cuales se seleccionan las cartas y ademas,
     *                          vincula el temporizador al volteo de las cartas
     * \param pptrApp Puntero a la aplicación de QT
     */
    JuegoDeLaMemoria(QApplication* pptrApp = nullptr);
    ~JuegoDeLaMemoria();

    /*!
     * \brief seleccionaMazo Se colocan la cantidad de pares a utilizar en un mazo
     * \param pares Se selecciona la cantidad de pares que se quiere en el mazo
     */
    void seleccionaMazo(int pares=6);

    /*!
     * \brief repartirCartas Utilizando el mazo y una distribucion, se reparten las cartas sobre la mesa y
     *                        se inicia la aplicación que las muestra en una ventana
     * \param filas Cantidad de filas en las que se quiere repartir
     * \param columnas Cantidad de columnas en las que se quiere repartir
     */
    void repartirCartas(int filas=4, int columnas=3);

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
    Carta* cartasSeleccionadas[2];

    // Tablero de cartas
    Mesa mesaConCartas;

    // Espacio de graficación
    double margen;
    double anchoMesaConCartas;
    double altoMesaConCartas;

    int coordenadaAPosicionCuantizada(double pCoord, double limite);

    // Temporizador
    QTimer temporizador;

private slots:
    // Da vuelta las cartas
    void voltearCartas();
};

#endif // JUEGODELAMEMORIA_H
