#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <vector>
#include "stdlib.h"
using namespace std;

typedef unsigned int  uint;

//Limites
const int maxfilas=100;//100
const int maxcolumnas=100;//100

// MOs
const int NMOs = 80;//80 // Cantidad inicial de MO.
const int eInicial = 80;//80 // Energía con que nace cada MO.
const int eMaxMO = 200;//200 // Máximo de energía en cada MO.
const int cCome = 20;//20 // Comida que comen los MO.
const int eNecMueve = 1; // Comida que consumen para moverse.

// Sembradores
const int Nsembra = 40;//40 // Cantidad inicial de Sembradores.
const int cantSiembra = 50;//50 // Comida que ponen los Sembradores.

// Evolución
const int movimientosparareproducir = 5;//10 // Movimientos antes de reproducirse.
const float probMutacion = 2.0; // Probabilidad de mutaciones

// Movimiento
const float aleDirSembra = 5.0; // Probabilidad de que el sembrador cambie de direccion
const float aleDirMO = 5.0; // Probabilidad de que el MO cambie de direccion si no hay comida

// Comida
const int MaxComida = 20;//200 // Máximo de comida en cada celda

struct Posicion
{ int f,c; };
const vector < Posicion > mov_relativo={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

#endif // CONSTANTES_H
