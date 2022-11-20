/*!
 *  \class     Dibujo.
 *  \brief     Clase abstracta que generaliza aspectos en comunes con distintos dibujos.
 *  \details   La clase se utiliza para tener un tipo especifico de objeto para distintas formas y figuras a graficar,
 *              y otorga los métodos getter y atributos de sus coordenadas minimas y maximas.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 00/00/2020.
 *  \pre       Es util usarala cuando se busca generalizar distintos dibujos a enviar a un graficador.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef DIBUJO_H
#define DIBUJO_H

class Dibujo
{
public:
    /*!
     * \brief Dibujo Constructor vacío
     */
    Dibujo();

    /*!
     * \brief dibujar Metodo virtual puro
     */
    virtual void dibujar() = 0;

    /*!
     * \brief getMinX Consigue la mínima coordenada X necesaria para visualizar correctamente el dibujo
     * \return
     */
    double getMinX();

    /*!
     * \brief getMinX Consigue la máxima coordenada X necesaria para visualizar correctamente el dibujo
     * \return
     */
    double getMaxX();

    /*!
     * \brief getMaxX Consigue la mínima coordenada Y necesaria para visualizar correctamente el dibujo
     * \return
     */
    double getMinY();

    /*!
     * \brief getMinX Consigue la minima coordenada Y necesaria para visualizar correctamente el dibujo
     * \return
     */
    double getMaxY();

    /*!
     * \brief ~Dibujo Destructor virtual de la clase
     */
    virtual ~Dibujo() {}

protected:
    double minX, maxX, minY, maxY;

private:
};

#endif // DIBUJO_H
