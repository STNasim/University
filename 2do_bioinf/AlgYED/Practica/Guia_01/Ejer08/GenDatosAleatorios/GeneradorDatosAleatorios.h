#ifndef GENERADORDATOSALEATORIOS_H
#define GENERADORDATOSALEATORIOS_H
#include <vector>
#include <fstream>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

void GenerarOrdenados(int cant);
void GenerarQuasiOrdenados(int cant);
void GenerarDesordenadosNormal(int cant);
void GenerarDesordenadosUniforme(int cant);

#endif // GENERADORDATOSALEATORIOS_H
