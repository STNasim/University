/*!
 *  \class     JuegoSaltoCaballo.
 *  \brief     Consiste en un juego en el que el usuario debe adivinar si el recorrido mostrado es correcto no
 *  \details   La clase permite seleccionar un nivel inicial, el cual aumenta cuando se responde correctamente. Mediante
 *              un evento de presionar una tecla, se toma la respuesta del usuario y se le indica si es correcta o
 *              errónea. Tambien permite conocer el nivel máximo superado y el tiempo tardado en el último nivel.
 *  \author    Salim Nasim.
 *  \version   1.1.
 *  \date      Fecha de creación: 26/05/2020.
 *  \date      Fecha de última modificación: 03/06/2020.
 *  \pre       La clase puede ser utilizada cuando se necesite usar el juego
 *              a modo de prueba para obtener estadísticas de tiempo y nivel
 *  \bug       Para algunos valores de filas y columnas iniciales no se muestran los números de las casillas y la
 *              solución se establece como incorrecta
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef JUEGOSALTOCABALLO_H
#define JUEGOSALTOCABALLO_H
#include "..\CasosDePrueba\Caso4\solversaltocaballo.h"
#include "..\CasosDePrueba\Graficador2D\graficador2d.h"
#include "..\CasosDePrueba\Caso4\tablero.h"
#include "..\CasosDePrueba\Caso2\Segundero.h"


class JuegoSaltoCaballo
{
public:
    /*!
     * \brief JuegoSaltoCaballo Constructor que establece el puntero del graficador y se inicializan las variables
     * \param pPtrApp Puntero a la app
     */
    JuegoSaltoCaballo(QApplication *pPtrApp=nullptr);

    /*!
     * \brief SeleccionarNivel Permite establecer el nivel inical del juego
     * \param valor número de nivel en el cual inciar
     */

    void SeleccionarNivel(int valor=1);

    /*!
     * \brief ObtenerNivelSuperado Devuelve el último nivel superado por el usuario
     * \return int con el valor del último nivel superado o 0
     */

    int ObtenerNivelSuperado();

    /*!
     * \brief ObtenerTiempoSuperado Devuelve el tiempo del ultimo nivel superado
     * \return float con el tiempo o 0
     */
    float ObtenerTiempoSuperado();

    /*!
     * \brief IniciarJuego Comienza el juego desde el nivel inicial y continua hasta que se cierra el
     *                      programa o no se recibe ninguna respuesta por parte del usuario
     */
    void IniciarJuego();

    /*!
     * \brief SetPuntero Establece el puntero a la QApplication
     * \param pPtrApp Puntero a la aplicación
     */
    void SetPuntero(QApplication *pPtrApp);

private:
    void Reiniciar();
    bool CargarDatosSegunNivel();
    void CargarNivel();
    void ProcesarResultados();
    unsigned filaInicial,columnaInicial,cantFilas,cantColumnas;
    int nivel,nivelInicial,nivelSuperado;
    bool resultadoTestCorrecto,salir;
    float tiempoUltimoJuego;
    Segundero cronometro;
    Solucion sol;
    SolverSaltoCaballo solver;
    Tablero dibujoTablero;
    Graficador2D graficador;
};

#endif // JUEGOSALTOCABALLO_H
