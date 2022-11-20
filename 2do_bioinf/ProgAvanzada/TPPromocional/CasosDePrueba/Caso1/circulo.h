/*!
 *  \class     Circulo.
 *  \brief     Genera un objeto Circulo que se puede dibujar a si mismo.
 *  \details   La clase genera una figura con forma de Circulo, de color dado por el objeto Pixel que recibe como
 *              parámetro en su constructor(esto lo hereda de la clase ancestra), ademas puede dibujarse
 *              llamando a su metodo dibujar.
 *  \author    Usuario de stackoverflow "Codemaker"
 *              (link: https://stackoverflow.com/questions/22444450/drawing-circle-with-opengl)
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 28/05/2020.
 *  \date      Fecha de última modificación: 28/05/2020.
 *  \pre       La clase es utilizable cuando se quiera graficar un circulo y no se
 *              requiera dibujar circulos de distintas dimensiones.
 *  \bug       -
 *  \warning   Todo objeto instanciado de esta clase siempre tendrá las mismas dimensiones
 *              y el unico parametro modificable es su color.
 *  \copyright GNU Public License.
*/
#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"

class Circulo : public Figura
{
public:
    /*!
     * \brief Circulo Construye el objeto circulo, y, mediante el constructor de la clase ancestra,
     *          se le asigna su color
     * \param pColor: Color de la figura en forma de un objeto de tipo Pixel
     */
    Circulo(Pixel pColor);
    ~Circulo();
    /*!
     * \brief dibujar Grafica la figura
     */
    void dibujar();
};

#endif // CIRCULO_H
