/*!
 *  \class     Segundero.
 *  \brief     Clase que simula un cronometro en segundos.
 *  \details   El segundero es capaz de cronometrar un tiempo hasta que sea parado, tambien puede devolver el tiempo
 *              mientras este sigue cronometrando y ademas es capaz de reiniciarse.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 26/05/2020.
 *  \date      Fecha de última modificación: 26/05/2020.
 *  \pre       Es utilizable siempre que se necesite de cronometrar un tiempo en segundos
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef SEGUNDERO_H
#define SEGUNDERO_H
#include <QElapsedTimer>
#include <iostream>

class Segundero
{
public:
    /*!
     * \brief Segundero Se crea el objeto y se inicializa el tiempoParada en un valor 0.
     */
    Segundero();

    /*!
     * \brief EstaIniciado Sirve para conocer si en algun momento se inició el cronometro.
     * \return True o False segun el estado del cronometro
     */
    bool EstaIniciado();

    /*!
     * \brief IniciarCronometro El cronometro comienza a contar el tiempo
     */
    void IniciarCronometro();

    /*!
     * \brief MostrarTiempo Muestra el tiempo en la consola, o avisa que le cronometro no se inicio
     */
    void MostrarTiempo();

    /*!
     * \brief PararCronometro Se detiene el cronometro en el momento en que se llame al método
     */

    void PararCronometro();

    /*!
     * \brief ObtenerTiempo Se devuelve el tiempo que tiene actualmente el cronometro o del momento donde se paró
     * \return Número flotante de 3 decimales
     */
    float ObtenerTiempo();

    /*!
     * \brief ObtenerTiempoYReinicar Llama a la funcion de obtener tiempo y reinicia el cronometro y el tiempo de parada.
     * \return Número flotante de 3 decimales
     */
    float ObtenerTiempoYReinicar();
private:
    float tiempoParada;
    QElapsedTimer cronometro;
};

#endif // SEGUNDERO_H
