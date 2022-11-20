/*!
 *  \class     Desempeño.
 *  \brief     La clase se encarga de graficar una función de desempeño mediante puntos
 *  \details   La gráfica mostrada cuenta de ejes, una grilla y un fondo con un gradiente gris a blanco. Los puntos
 *              se grafican mediante discos naranjas con bordes azules. Se representan tambien, rectas que representan
 *              el valor máximo, mínimo y el valor medio de los puntos cargados. Finalmente, tambien permite seleccionar
 *              si se quiere unir los puntos mediante lineas o mediante una función interpolada.
 *  \author    Jimeneze JC. link: https://www.youtube.com/watch?v=uKiNxSz6PhE
 *  \author    Salim Nasim.
 *  \version   1.1.
 *  \date      Fecha de creación: 30/05/2020.
 *  \date      Fecha de última modificación: 31/05/2020.
 *  \pre       La clase puede ser utilizada siempre que se necesite una gráfica de puntos y basta solamente con
 *              ingresarlos para que esta los muestre.
 *  \bug       -
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef DESEMPENIO_H
#define DESEMPENIO_H
#include <QApplication>
#include "../CasosDePrueba/Graficador2D/dibujo.h"
#include <vector>
//using namespace std;
class Desempenio : public Dibujo
{

public:
    /*!
     * \brief DesempenioLineal Se inicializan los valores mínimos y maximos de coordenadas y tambien los booleanos
     *                          que determinan si mostrar o no las uniones lineales o interpoladas
     */
    Desempenio();

    /*!
     * \brief dibujar Dibuja todo el gráfico con sus respectivos parámetros
     */
    void dibujar() override;

    /*!
     * \brief CargarDatos Se cargan los datos de los puntos que se quieren graficar
     * \param aux Datos en forma de vector de numeros enteros
     */
    void CargarDatos(std::vector <int> aux);

    /*!
     * \brief MostrarLineal Establece si mostrar o no las uniones de los puntos mediante lineas
     * \param aux booleano verdadero falso segun si se desea grafica o no
     */
    void MostrarLineal(bool aux);

    /*!
     * \brief MostrarInterpolada Establece si mostrar o no las uniones de los puntos mediante interpolaciones
     * \param aux booleano verdadero falso segun si se desea grafica o no
     */
    void MostrarInterpolada(bool aux);

private:
    bool lineal;
    bool interpolada;
    std::vector <int> puntos;
    std::vector <int>::iterator it;
};

#endif // DESEMPENIO_H
