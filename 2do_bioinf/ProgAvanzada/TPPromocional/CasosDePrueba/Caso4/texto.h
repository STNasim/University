/*!
 *  \class     Texto.
 *  \brief     Clase que dibuja un texto o frase en una ventana
 *  \details   El constructor recibe la frase, las coordenadas y el color del texto,
 *              una vez creado solo puede modificarse su color.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 00/00/2020.
 *  \pre       Puede ser usada cuando se quiera graficar una frase de texto
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef TEXTO_H
#define TEXTO_H

#include <string>
#include <QOpenGLContext>

#include "../Graficador2D/dibujo.h"

//using namespace std;

class Texto : public Dibujo
{
public:
    /*!
     * \brief Texto Constructor que guarda los atributos a usar para luego dibujar
     * \param pFrase Frase a dibujar
     * \param pX Coordenada X donde posicionar el texto
     * \param pY Coordenada Y donde posicionar el texto
     * \param pR Intensidad de color rojo en formato RGB
     * \param pG Intensidad de verde rojo en formato RGB
     * \param pB Intensidad de azul rojo en formato RGB
     */
    Texto(std::string pFrase, int pX, int pY, float pR=1, float pG=0, float pB=0);

    /*!
     * \brief setColor Permite modificar el color del texto
     * \param pR Intensidad de color rojo en formato RGB
     * \param pG Intensidad de verde rojo en formato RGB
     * \param pB Intensidad de azul rojo en formato RGB
     */
    void setColor(float pR=1, float pG=0, float pB=0);

    /*!
     * \brief dibujar Dibuja el texto
     */
    void dibujar() override;

private:
    std::string frase;
    int posX, posY;
    std::vector<float> color;

    // parámetros de texto
    unsigned int tamTexto = 10;
    unsigned int anchoLineaTexto = 2; // En pixeles

    // Métodos auxiliares
    void dibujarTexto(std::string pTexto, float pX=0, float pY=0, unsigned char pTam=10);
};

#endif // TEXTO_H
