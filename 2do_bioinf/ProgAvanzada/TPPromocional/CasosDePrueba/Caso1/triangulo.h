/*!
 *  \class     Triangulo.
 *  \brief     Genera un objeto Triangulo que se puede dibujar a si mismo.
 *  \details   La clase genera una figura con forma de triangulo, de color dado por el objeto Pixel que recibe como
 *              parámetro en su constructor(esto lo hereda de la clase ancestra), ademas puede dibujarse
 *              llamando a su metodo dibujar.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 23/05/2020.
 *  \pre       La clase es altamente reutilizable para cualquier ocasión en la que se necesite dibujar un triangulo y no
 *              se requieran realizar triangulos con distintas dimensiones.
 *  \bug       -
 *  \warning   Todo objeto instanciado de esta clase siempre tendrá las mismas dimensiones
 *              y el unico parametro modificable es su color.
 *  \copyright GNU Public License.
*/
#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figura.h"

class Triangulo: public Figura
{
public:
    /*!
     * \brief Triangulo Construye el objeto Cuadrado, y, mediante el constructor de la clase ancestra,
     *          se le asigna su color
     * \param pColor: Color de la figura en forma de un objeto de tipo Pixel
     */
    Triangulo(Pixel pColor);
    ~Triangulo();
    /*!
     * \brief dibujar Grafica la figura
     */
    void dibujar();
};

#endif // TRIANGULO_H
