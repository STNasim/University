/*!
 *  \class      Cronometro
 *  \brief      Modelo de cronómetro de alta resolución.
 *  \details    Modelo de cronómetro de alta resolución. Está basado en funciones del espacio
 *              de nombres std::chrono::high_resolution_clock. No debería utilizarse para
 *              aplicaciones de alto rendimiento en cuyo caso se recomienda utilizar
 *              directamente las funciones del estándar.
 *              Esta biblioteca ha sido desarrollada para las clases prácticas de Algoritmos y
 *              Estructuras de Datos de la Facutlad de Ingeniería de la Universidad Nacional de
 *              Entre Ríos.
 *  \author     Jordán F. Insfrán
 *  \version    1.0.0
 *  \date       Fecha de creación: 2020-08-10
 *  \date       Fecha de última modificación: 2020-08-14
 *  \pre        Disponer de biblioteca chrono instalada. La misma corresponde al estándar C++11.
 *  \bug        -
 *  \warning    -
 *  \copyright  Cualquier dato relativo a la licencia bajo la cual esté
 *              enmarcada el código fuente. Ejemplo: GNU Public License.
*/

#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include <chrono>

class Cronometro
{
public:
    Cronometro();

    /*!
     * \brief iniciarCronometro Inicia medición de tiempo
     */
    void iniciarCronometro();

    /*!
     * \brief pararCronometro Finaliza medición de tiempo
     */
    void pararCronometro();

    /*!
     * \brief getDuracionEnSegundos Calcula una diferencia temporal y retorna la duración en segundos
     * \return Duración en segundos.
     */
    double getDuracionEnSegundos();

    /*!
     * \brief getResolucionEnSegundos Retorna la resolución del cronómetro en segundos
     * \return Resolución en segundos
     */
    double getResolucionEnSegundos();

private:
    std::chrono::high_resolution_clock::time_point t1, t2;
    std::chrono::duration<double> time_span;
};

#endif // CRONOMETRO_H
