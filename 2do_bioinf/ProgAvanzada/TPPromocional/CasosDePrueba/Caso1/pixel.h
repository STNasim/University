/*!
 *  \class     Pixel.
 *  \brief     Clase que se encarga de simplificar la asignacion de colores.
 *  \details   Consiste en tres atributos (rojo, verde y azul) que simbolizan un color en formato RGB y que son
 *              ingresados al construir el objeto. De no ser ingresados, el color por defecto es el negro.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 00/00/2020.
 *  \pre       La clase puede ser utilizable siempre que se busque simplificar el pasaje del valor de un color en RGB.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
public:
    /*!
     * \brief Pixel Construye el objeto con los parametros de color rojo, verde,azul y los guarda en variables float
     * \param pR: Valor de la cantidad de color rojo
     * \param pG: Valor de la cantidad de color verde
     * \param pB: Valor de la cantidad de color azul
     */
    Pixel(float pR=0.0f, float pG=0.0f, float pB=0.0f)
    { rojo = pR; verde = pG; azul = pB;}

    float rojo, verde, azul;
};

#endif // PIXEL_H
