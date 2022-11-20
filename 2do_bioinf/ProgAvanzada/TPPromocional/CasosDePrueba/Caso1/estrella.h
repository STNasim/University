/*!
 *  \class     Estrella.
 *  \brief     Genera un objeto Estrella que se puede dibujar a si mismo.
 *  \details   La clase genera una figura con forma de Estrella, de color dado por el objeto Pixel que recibe como
 *              parámetro en su constructor(esto lo hereda de la clase ancestra), ademas puede dibujarse
 *              llamando a su metodo dibujar.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 23/05/2020.
 *  \date      Fecha de última modificación: 23/05/2020.
 *  \pre       La clase es utilizable cuando no se necesite una gran exactitud en la forma de la estrella y no se
 *              requiera dibujar estrellas de distintas dimensiones.
 *  \bug       -
 *  \warning   Todo objeto instanciado de esta clase siempre tendrá las mismas dimensiones
 *              y el unico parametro modificable es su color.
 *  \copyright GNU Public License.
*/
#ifndef ESTRELLA_H
#define ESTRELLA_H

#include "figura.h"

class Estrella: public Figura
{
public:
    /*!
     * \brief Espiral Construye el objeto Cuadrado, y, mediante el constructor de la clase ancestra,
     *         se le asigna su color
     * \param pColor: Color de la figura en forma de un objeto de tipo Pixel
     */
    Estrella(Pixel pColor);
    ~Estrella();
    /*!
     * \brief dibujar Grafica la figura
     */
    void dibujar();
};

#endif // ESTRELLA_H
