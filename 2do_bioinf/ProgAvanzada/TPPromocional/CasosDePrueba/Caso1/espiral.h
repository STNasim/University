/*!
 *  \class     Espiral.
 *  \brief     Genera un objeto Espiral que se puede dibujar a si mismo.
 *  \details   La clase genera una figura en forma de Espiral logaritmico, de color dado por el objeto Pixel
 *              que recibe como parámetro en su constructor(esto lo hereda de la clase ancestra),
 *              ademas puede dibujarse llamando a su metodo dibujar.
 *  \author    Desconocido. Link: http://techtutorials95.blogspot.com/2015/05/opengl-making-spirals.html.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 15/05/2015.
 *  \date      Fecha de última modificación: 23/05/2020.
 *  \pre       La clase es altamente reutilizable para cualquier ocasión en la que se necesite graficar un espiral y
 *              no se requieran multiples espirales con distintas dimensiones.
 *  \bug       -
 *  \warning   Todo objeto instanciado de esta clase siempre tendrá las mismas dimensiones
 *              y el unico parametro modificable es su color.
 *  \copyright GNU Public License.
*/
#ifndef ESPIRAL_H
#define ESPIRAL_H

#include "figura.h"

class Espiral: public Figura
{
public:
    /*!
     * \brief Espiral Construye el objeto Cuadrado, y, mediante el constructor de la clase ancestra,
     *         se le asigna su color
     * \param pColor: Color de la figura en forma de un objeto de tipo Pixel
     */
    Espiral(Pixel pColor);
    ~Espiral();
    /*!
     * \brief dibujar Grafica la figura
     */
    void dibujar();
};

#endif // ESPIRAL_H
