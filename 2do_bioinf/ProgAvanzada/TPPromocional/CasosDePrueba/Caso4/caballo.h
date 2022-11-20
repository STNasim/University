/*!
 *  \class     Caballo.
 *  \brief     Clase que dibuja una figura semejante a un caballo de ajedrez.
 *  \details   El constructor de la clase recibe como parametros una posición inicial, que puede ser modificado
 *               mediante su método, tambien puede modificarse su color en formato RGB y dibujarlo
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 00/00/2020.
 *  \pre       Es utilizable cuando se necesite graficar un caballo de ajedrez.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef CABALLO_H
#define CABALLO_H

#include "../Graficador2D/dibujo.h"

class Caballo : public Dibujo
{
public:
    /*!
     * \brief Caballo Constructor del caballo que recibe sus coordenadas de posición
     * \param pPosX Coordenada X donde posicionar al caballo
     * \param pPosY Coordenada Y donde posicionar al caballo
     */
    Caballo(int pPosX = 0, int pPosY = 0);
    /*!
     * \brief setPosicion Modifica la posición
     * \param pX Coordenada X
     * \param pY Coordenada Y
     */
    void setPosicion(int pX, int pY);

    /*!
     * \brief setColor Establece el color del caballo
     * \param pR Intensidad de color rojo en formato RGB
     * \param pG Intensidad de verde rojo en formato RGB
     * \param pB Intensidad de azul rojo en formato RGB
     */
    void setColor(float pR, float pG, float pB);

    /*!
     * \brief dibujar Grafica el caballo cargado
     */
    void dibujar() override;

private:
    float posX, posY; // posición
    float cR, cG, cB; // color
};

#endif // CABALLO_H
