/*!
 *  \class     Cuadrado.
 *  \brief     Genera un objeto Cuadrado que se puede dibujar a si mismo
 *  \details   La clase genera una figura con forma de cuadrado, de color dado por el objeto Pixel que recibe como
 *              parámetro en su constructor(esto lo hereda de la clase ancestra), ademas puede dibujarse
 *              llamando a su metodo dibujar
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 00/00/2020.
 *  \pre       La clase es altamente reutilizable para cualquier ocasión en la que se necesite dibujar un cuadrado y no
 *              se requieran realizar cuadrados con distintas dimensiones.
 *  \bug       -
 *  \warning   Todo objeto instanciado de esta clase siempre tendrá las mismas dimensiones
 *              y el unico parametro modificable es su color.
 *  \copyright GNU Public License.
*/
#ifndef CUADRADO_H
#define CUADRADO_H

#include "figura.h"

class Cuadrado: public Figura
{
public:
    /*!
     * \brief Cuadrado Construye el objeto Cuadrado, y, mediante el constructor de la clase ancestra,
     *          se le asigna su color
     * \param pColor: Color de la figura en forma de un objeto de tipo Pixel
     */
    Cuadrado(Pixel pColor);
    ~Cuadrado();
    /*!
     * \brief dibujar Grafica la figura
     */
    void dibujar();
};

#endif // CUADRADO_H
