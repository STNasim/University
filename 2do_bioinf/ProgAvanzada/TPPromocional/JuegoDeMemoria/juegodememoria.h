/*!
 *  \class     JuegoDeMemoria.
 *  \brief     Clase que simula el juego de la memoria, que consiste
 *              en encontrar todas las cartas con sus respectivos pares.
 *  \details   El objeto selecciona un mazo con cartas en base al nivel y es capaz de repartirlas en la mesa, voltearlas
 *              y ademas, se encarga de los principales comandos de graficación.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.2.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 03/06/2020.
 *  \pre       Se utiliza cuando se quiera simular un juego de memoria con cartas.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef JUEGODEMEMORIA_H
#define JUEGODEMEMORIA_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QTimer>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include "..\CasosDePrueba\Caso2\Segundero.h"
#include "..\CasosDePrueba\Caso1\carta.h"
#include "..\CasosDePrueba\Caso1\mesa.h"

class JuegoDeMemoria : public QOpenGLWidget
{
    // Necesario para definir slot/signal
    Q_OBJECT
public:
    /*!
     * \brief JuegoDeLaMemoria Crea el juego de memoria, establece el puntero a la aplicación, los margenes,
     *                          los punteros con los cuales se seleccionan las cartas y ademas,
     *                          vincula el temporizador al volteo de las cartas.
     * \param pptrApp Puntero a la aplicación de QT.
     */
    JuegoDeMemoria(QApplication* pptrApp = nullptr);
    ~JuegoDeMemoria();

    /*!
     * \brief InciarJuego Inicia el juego de memoria
     */
    void IniciarJuego();

    /*!
     * \brief ElegirNivel Permite elegir el nivel inicial
     * \param value Valor del nivel a iniciar, por defecto 1
     */
    void ElegirNivel(int value=1);

    /*!
     * \brief ElegirTiempoAlFallar Permite seleccionar el tiempo que las tarjetas estan volteadas cuando se seleccionen
     *                              2 tarjetas diferentes
     * \param tiempo Tiempo en segundos que se quiere establecer
     */
    void ElegirTiempoAlFallar(float tiempo=1);

    /*!
     * \brief ElegirColorFondo Permite elegir el fondo de la mesa al graficar
     * \param pRojo Parametro de color rojo en el formato RGB
     * \param pVerde Parametro de color verde en el formato RGB
     * \param pAzul Parametro de color azul en el formato RGB
     */
    void ElegirColorFondo(float pRojo=0.5f,float pVerde=0.6f, float pAzul=0.5f);

    /*!
     * \brief MostrarAlInicio Establece si mostrar o no las cartas al comienzo del nivel
     * \param parametro booleano verdadero o falso a guardar
     */
    void MostrarAlInicio(bool parametro);

    /*!
     * \brief TiempoMostrarAlInicio Establece el tiempo que las cartas permanecen visibles al iniciar el nivel
     * \param tiempo Cantidad de tiempo en segundos que se quieren visualizar
     */
    void TiempoMostrarAlInicio(int tiempo);

    /*!
     * \brief ObtenerNivel Devuelve el ultimo nivel que se resolvió correctamente
     * \return int con el valor del nivel
     */
    int ObtenerNivelSuperado();

    /*!
     * \brief ObtenerTiempoNivelSuperado Devuelve el tiempo del ultimo nivel superador
     * \return flotante de 3 decimales
     */
    float ObtenerTiempoNivelSuperado();

    /*!
     * \brief SetPuntero Establece el puntero a la QApplication
     * \param pPtrApp Puntero a aplicación
     */
    void SetPuntero(QApplication *pPtrApp);

protected:
    //Metodos heredados de QOpenGLWidget
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    //Eventos
    void mousePressEvent(QMouseEvent *event);

private:

    void Reiniciar();
    /*!
     * \brief seleccionaMazo Se colocan las cartas a utilizar en un mazo
     * \param pares Se selecciona la cantidad de pares que se quiere en el mazo
     */
    void seleccionaMazo();

    /*!
     * \brief repartirCartas Utilizando el mazo y una distribucion, se reparten las cartas sobre la mesa y
     *                        se inicia la aplicación que las muestra en una ventana, al finalizar, se muestra
     *                        el tiempo transcurrido desde el primer evento click.
     * \param filas Cantidad de filas en las que se quiere repartir.
     * \param columnas Cantidad de columnas en las que se quiere repartir.
     */
    void repartirCartas();

    bool mostrarAlIniciar;
    float tiempoNivelSuperado;
    float tiempoMostrar;
    float miliSegundosAlFallar;
    float rojo,verde,azul;
    int nivel,nivelInicial,nivelSuperado,filas,columnas;
    /*!
     * \brief ptrApp Puntero a una aplicación
     */
    QApplication* ptrApp;

    // Mazo de cartas
    std::vector<Carta*> mazoDeCartas;

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
    QTimer temporizadorMostrar;

    // Cronometro
    Segundero cronometro;

private slots:
    // Da vuelta las cartas
    void voltearCartas();
    void EsconderCartas();
};

#endif // JUEGODEMEMORIA_H
