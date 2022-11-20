/*!
 *  \class     Figura.
 *  \brief     Clase abstracta que se encarga de generalizar metodos y atributos para las clases derivadas.
 *  \details   La clase tiene un constructor para establecer el objeto Pixel y un metodo dibujar.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 00/00/2020.
 *  \pre       La clase es utilizable si se necesita graficar variedad de figuras distintas y se quiera generalizar
 *              ciertos aspectos comunes a las figuras, en este caso establecer su color y dibujarlas.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef FIGURA_H
#define FIGURA_H

#include <QOpenGLFunctions>

#include "pixel.h"

class Figura
{
public:
    /*!
     * \brief Figura Constructor que establece el parametro color
     * \param color: Objeto Pixel que contiene un color
     */
    Figura(Pixel color);
    /*!
     * \brief dibujar Metodo virtual puro que se definira en cada clase derivada
     */
    virtual void dibujar()=0;
    virtual ~Figura();

protected:
    /*!
     * \brief color Color de la figura en forma de un objeto Pixel
     */
    Pixel color;
};

#endif // FIGURA_H
