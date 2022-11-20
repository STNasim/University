/*!
 *  \class     Carta.
 *  \brief     Clase que manipula cartas con figuras que se dibujan a si mismas.
 *  \details   Los objetos carta son capaces de dibujarse y en su interior representar un dibujo, en el caso de que
 *              esten visibles, contienen atributos como si estan visibles, si estan emparejadas y son capaces
 *              de establecer su color de fondo ademas de guardar y devolver un valor de ID.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.1.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 28/05/2020.
 *  \pre       La clase esta diseñada, principalmente, para ser utilizada en un juego de memoria, para el cual se
 *              necesita mostrar y esconder las cartas, emparejarlas mediante un valor de ID
 *              y que estas contengan dibujos para su identificación.
 *  \bug       -
 *  \warning   Tener cuidado que el color de dorso no coincida con el fondo, ya que no se podran diferenciar las cartas
 *              al no estar visibles, algo similar puede suceder cuando la carta sea visible, con su fondo y el color
 *              de la figura que esta tiene.
 *  \copyright GNU Public License.
*/
#ifndef CARTA_H
#define CARTA_H

#include<string>
#include "triangulo.h"
#include "pixel.h"

//using namespace std;
/*!
 * \brief Le asigna a cada tipo de figura un numero como parametro para utilizar a la hora de seleccionarlo
 */
enum figuras {FIG_TRIANGULO = 1, FIG_CUADRADO = 2,FIG_ESPIRAL =3,FIG_ESTRELLA=4, FIG_CIRCULO=5};

class Carta
{
public:
    /*!
     * \brief Carta Construye un objeto Carta recibiendo un ID y su color de dorso,
     *         se llama al otro constructor y los parametros tipo de figura y color se asignan por defecto.
     * \param id: Este valor es el que se asigna como ID a la carta.
     */
    Carta(unsigned id);

    /*!
     * \brief Carta Construye un objeto Carta recibiendo un ID, Tipo de figura y color de figura, ademas,
     *         se inicializan los atributos de emparejamiento y visibilidad como falsos.
     * \param id: Se asigna este valor como ID a la carta.
     * \param pTipoDeFigura: El numero de figura que va a asignarse a la carta
     * \param pColor: Establece el color de fondo de la carta.
     */
    Carta(unsigned id, char pTipoDeFigura, Pixel pColor);

    ~Carta();

    /*!
     * \brief dibujar Grafica la carta dependiendo de visible.
     *                 Si es falso, se dibuja solo su dorso.
     *                 Si es verdadero, se la dibuja junto con su figura asignada
     */
    void dibujar();

    /*!
     * \brief setColorFondo Establecer el color del dorso de la Carta al no ser visible
     * \param color: Un objeto Pixel que contiene la información del color
     */
    void setColorFondo(const Pixel color);

    /*!
     * \brief setFigura Elije el tipo y color de figura que se graficara cuando la carta sea visible.
     * \param pTipoDeFigura: El tipo de figura a dibujar.
     * \param color: El color de la figura.
     */
    void setFigura(char pTipoDeFigura, Pixel color);

    /*!
     * \brief getVisible Verifica si la carta esta visible.
     * \return Devuelve un booleano verdadero o falso segun el atributo visible.
     */
    bool getVisible() const;

    /*!
     * \brief setVisible Establece el parametro visible de la Carta.
     * \param: value El parametro que va a establecerse (verdadero o falso).
     */
    void setVisible(bool value);

    /*!
     * \brief getEstaEmparejada Verifica si la carta esta emparejada.
     * \return Devuelve un verdadero o falso segun el atributo estaEmparejada.
     */
    bool getEstaEmparejada() const;

    /*!
     * \brief setEstaEmparejada Establece el parametro estaEmparejada del objeto.
     * \param value: El parametro a establecerse en el atributo.
     */
    void setEstaEmparejada(bool value);

    /*!
     * \brief getId Devuelve el valor sin signo del atributo ID de la carta.
     */
    unsigned getId() const;

private:
    /*!
     * \brief figura Puntero a la figura que se va a graficar.
     */
    Figura* figura;

    /*!
     * \brief visible Booleano que dice si la carta esta o no visible.
     */
    bool visible;

    /*!
     * \brief estaEmparejada Booleano que dice si la carta esta o no emparejada.
     */
    bool estaEmparejada;

    /*!
     * \brief id ID de la carta, generalmente para determinar si emparejarla o no.
     */
    unsigned id;

    /*!
     * \brief colorDorso Objeto Pixel que determina el color del dorso de la carta.
     */
    Pixel colorDorso;

};

#endif // CARTA_H
