/*!
 *  \class     Mesa.
 *  \brief     Clase que se encarga de modelar una mesa, que es donde se encontraran las cartas.
 *  \details   El objeto mesa, ademas de dibujarse, tiene multiples funcionalidades respecto a un conjunto de objetos
 *              carta, puede juntarlas en un mazo, mezclarlas y repartirlas por la mesa. Tambien tiene sobrecargado
 *              el operador "()" el cual devuelve un puntero la carta perteneciente a la distribucion de la mesa.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.1.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 28/05/2020.
 *  \pre       La clase esta diseñada, principalmente, para manipular objetos de tipo Carta y distribuirlos.
 *  \bug       -
 *  \warning   Para poder repartir las cartas se tiene que proveer una distribucion valida en relación al mazo tambien
 *              dado, puede darse normalemente muchos casos en que no sea posible repartirlas.
 *  \copyright GNU Public License.
*/
#ifndef MESA_H
#define MESA_H

#include <stdio.h>

#include "carta.h"

class Mesa
{
public:
    /*!
     * \brief Mesa No hacer ninguna acción mas que crear el objeto
     */
    Mesa();
    ~Mesa();

    /*!
     * \brief Rellena la mesa con las cartas recibidas en mazoDeCartas
     * \param pCantFilas: cantidad de filas
     * \param pCantColumnas: cantidad de columnas
     * \param mazoDeCartas: mazo de cartas a repartir
     * \param estado: Establece le estado inicial de las cartas (visible o no visible)
     */
    void repartirCartas(unsigned pCantFilas, unsigned pCantColumnas, std::vector<Carta*> mazoDeCartas,bool estado);

    /*!
     * \brief Mezcla las cartas para comenzar una nueva partida
     */
    void mezclarCartas();

    /*!
     * \brief operator () Retorna la carta que se encuentra en una posición fila-columna
     * \param fil: fila seleccionada
     * \param col: columna seleccionada
     * \return Puntero a la carta seleccionada
     */
    Carta* operator()(unsigned fil, unsigned col);

    /*!
     * \brief dibujar Grafica la mesa y le ordena a las cartas dentro de la distribución a graficarse
     */
    void dibujar();

    /*!
     * \brief TodasLasCartasEmparejadas Verifica que todas las cartas de la distribución esten emparejadas
     * \return Booleano verdadero o falso segun corresponda
     */
    bool TodasLasCartasEmparejadas();

    /*!
     * \brief getCantFilas Devuelve cantidad de filas de la distribución
     */
    unsigned getCantFilas() const;

    /*!
     * \brief getCantColumnas Devuelve cantidad de columnas de la distribución
     */
    unsigned getCantColumnas() const;

    /*!
     * \brief MostrarCartas Muestra todas las cartas
     */
    void MostrarCartas();

    /*!
     * \brief EsconderCartas Esconde todas las cartas
     */
    void EsconderCartas();

private:
    /*!
     * \brief cantFilas Cantidad de filas de la distribución
     */
    unsigned cantFilas;

    /*!
     * \brief cantColumnas Cantidad de columnas de la distribución
     */
    unsigned cantColumnas;

    /*!
     * \brief distribucionDeCartas Vector de vectores donde se guardan los punteros a cada carta, en "dos dimensiones"
     */
    std::vector<std::vector<Carta*>> distribucionDeCartas;

    /*!
     * \brief mazoDeCartas Vector donde se guardan los punteros a las cartas, en "una sola dimensión"
     */
    std::vector<Carta*> mazoDeCartas;
};

#endif // MESA_H
