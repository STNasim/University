/*!
 *  \class     Tablero.
 *  \brief     Clase que dibuja un tablero con casillas negras y blancas intercaladas, similar al de ajedrez.
 *  \details   El constructor de la clase recibe el tamaño del tablero o este se establece en 8x8 por defecto
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 00/00/2020.
 *  \pre       Es utilizable cuando se necesite graficar un tablero.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef TABLERO_H
#define TABLERO_H

#include "../Graficador2D/dibujo.h"

class Tablero : public Dibujo
{
public:
    /*!
     * \brief Tablero Constructor que establece el tamaño en 8x8 por defecto
     */
    Tablero();

    /*!
     * \brief Tablero Constructor que recibe los parametros de fila y columna que se quieren asignar al tablero
     * \param pCantFil Cantidad de filas
     * \param pCantCol Cantidad de columnas
     */
    Tablero(unsigned int pCantFil, unsigned int pCantCol);

    void SetDimensiones(int filas, int columnas);

    /*!
     * \brief dibujar Aplica los comandos necesarios para graficar el tablero cargado
     */
    void dibujar() override;

private:
    // Atributos
    unsigned int cantFilas, cantColumnas;
    // Métodos auxiliares
    void dibujarCuadrado(float x1, float y1, float lado);
    void dibujarRectangulo(float x1, float y1, float lado1, float lado2);
};

#endif // TABLERO_H
