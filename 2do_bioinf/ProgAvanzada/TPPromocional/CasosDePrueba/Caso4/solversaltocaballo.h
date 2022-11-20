/*!
 *  \class     SolverSaltoCaballo.
 *  \brief     Clase que intenta resolver el problema del camino del caballo para cualquier tamaño de tablero.
 *  \details   La clase cuenta con una clase solución donde se almacena la información que se obtiene a medida que se
 *              resuelve el problema en el tablero. Puede limitarse el tiempo que se quiere intentar resolver el tablero
 *              y tambien elegir si mostrar o no los casillero incorrectos en la solución.
 *  \author    Insfrán Jordán.
 *  \author    Salim Nasim.
 *  \version   1.0.
 *  \date      Fecha de creación: 00/00/2020.
 *  \date      Fecha de última modificación: 30/05/2020.
 *  \pre       La clase es especifica a ser utilizada cuando se busque intentar resolver el problema del camino del
 *              caballo pero no se necesite siempre una solución que sea correcta.
 *  \bug       Para algunos valores de filas y columnas iniciales no se muestran los números de las casillas y la
 *              solución se establece como incorrecta
 *  \warning   -
 *  \copyright GNU Public License.
*/
#ifndef SOLVERSALTOCABALLO_H
#define SOLVERSALTOCABALLO_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "caballo.h"
#include "texto.h"

//using namespace std;

// Clase para almacenar información de una solución del problema del salto del caballo
//  (Representa un agrupamiento de información, por lo que no requiere atributos privados)
class Solucion{
public:
    Caballo caballo_inicial, caballo_final;
    std::vector<bool> posiciones_correctas; // true donde el salto del caballo es correcto
    std::vector<Texto> texto_posiciones;
    std::vector<int> tablero; // tablero como un arreglo 1D
    bool correcta;
    Solucion(int filIni=0, int colIni=0){
        caballo_inicial.setPosicion(colIni, filIni);
        correcta = false;
    }
};

// Clase para encontrar una solución del problema del salto del caballo
class SolverSaltoCaballo{
public:
    SolverSaltoCaballo();

    // Setters Habilitadores
    /*!
     * \brief setFinalizarPorTiempo Se dice si se quiere limitar el tiempo para la resolución o no.
     * \param pBandera Un true o false que indica el valor a asignar.
     */
    void setFinalizarPorTiempo(bool pBandera);     // Habilita la finalización por tiempo.

    /*!
     * \brief setImprimirSolucion Se elige si imprimir o no la solución por consola
     * \param pBandera True o false que indicará el valor a asignar
     */
    void setImprimirSolucion(bool pBandera);       // Habilita que se imprima solución por consola.
    /*!
     * \brief setMostrarPosicionesIncorrectas Permite seleccionar si mostrar o no las posiciones
     *                                         incorrectas de la solución
     * \param pBandera True o false segun corresponda a asignar
     */
    void setMostrarPosicionesIncorrectas(bool pBandera); // Habilita que se pinten con color diferente posiciones incorrectas (para testeos)

    // Setters
    /*!
     * \brief setLimiteDeTiempo Establece el limite de tiempo a la resolución
     * \param segundos Tiempo en forma de variable int a asignar
     */
    void setLimiteDeTiempo(unsigned int segundos); // Limita el tiempo para obtener solución.

    /*!
     * \brief setColorCaballoInicial Se modifica el color del caballo inicial
     * \param pR Intensidad de color rojo en formato RGB
     * \param pG Intensidad de verde rojo en formato RGB
     * \param pB Intensidad de azul rojo en formato RGB
     */
    void setColorCaballoInicial(float pR=0, float pG=0.5, float pB=0);

    /*!
     * \brief setColorCaballoFinal Se modifica el color del caballo final
     * \param pR Intensidad de color rojo en formato RGB
     * \param pG Intensidad de verde rojo en formato RGB
     * \param pB Intensidad de azul rojo en formato RGB
     */
    void setColorCaballoFinal(float pR=0, float pG=1, float pB=0);

    // Otros métodos
    /*!
     * \brief generarUnaSolucionDesde Genera la solución para el problema segun la posición inicial y el tamaño dado
     * \param pF Fila inicial
     * \param pC Columna inicial
     * \param pCantFil Cantidad de filas del tablero
     * \param pCantCol Cantidad de columnas
     * \return Objeto de tipo solución con la información obtenida en la resolución
     */
    Solucion generarUnaSolucionDesde(int pF, int pC, int pCantFil, int pCantCol);

    /*!
     * \brief getSol Devuelve la solución guardada
     * \return Objeto de tipo solución con la información de la resolución
     */
    Solucion getSol() const; // Permite retornar nuevamente la última solución encontrada.

    ~SolverSaltoCaballo();

private:
    int c_inicial,sol_retornada;
    int cantFil, cantCol;
    int* tablero;
    int dfila[8];
    int dcol[8];
    Solucion sol; // Una solución al problema (puede ser correcta o incorrecta)
    bool volcarSolucionEnConsola;

    // Parámetros varios
    std::vector<float> colorCabInicial, colorCabFinal;
    bool resaltarPosicionesIncorrectas;

    // Métodos privados
    void salta(int xinic, int yinic, int nsalto);
    void imprimirSolucion(); // Imprime solución por consola

    // Variables auxiliares de algoritmo recursivo
    bool salir;

    // Variables para finalizar por límite de tiempo
    bool finalizar_por_tiempo;
    bool mostrar_solucion_mas_profunda;
    unsigned int tiempo_limite; // En segundos
};

#endif // SOLVERSALTOCABALLO_H
