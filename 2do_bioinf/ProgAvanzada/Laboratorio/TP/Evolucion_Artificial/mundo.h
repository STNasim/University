#ifndef MUNDO_H
#include "comida.h"
#include "sembrador.h"
#include "mo.h"
#include "Constantes.h"
#include <vector>
#include <time.h>
#include <algorithm>
#include <map>
#define MUNDO_H

using namespace std;

class Mundo
{
private:
    multimap<int,int>TiempoDeVidaMOs;
    multimap<int,int>::iterator it;
    int tiempo; //Iteraciones transcurridas
    int ID; //ID a asignar a los MOs cuando se guarden en la STL
    vector < MO > MOs;
    vector < Sembrador > sembradores;
    Comida comida;
    int CantidadMOvivos();

public:
    Mundo(); //Constructor que establece los parametros iniciales del mundo

    void Vivir(); // Ordena mover, comer, sembrar y reproducir
    void LlamarReproduccion();
    int CantidadMO();
    int CantidadSembradores();
    int InteligenciaColonia();


    void Finalizar();
    int GetTiempo();
    int ComidaTotal();
    bool HayComida(int f, int c);
    int FilaSembrador(int ID);
    int ColumnaSembrador(int ID);
    int FilaMO(int ID);
    int ColumnaMO(int ID);
    int EnergiaMO(int ID);
    int MOEstaVivo(int ID);
    void MOQueMasVivio(int &ID, int &TiempoVida);
    void MOQueMenosVivio(int &ID, int &TiempoVida);


    void MostrarSTL();
};

#endif // MUNDO_H
