#ifndef BUSQUEDADICOTOMICA_H
#define BUSQUEDADICOTOMICA_H
#include <vector>
#include "../../EstructurasDeDatos/ArregloDinamico/arreglodin.h"

template <class T>
int busqueda_dicotomica_Arrdin (ArregloDin<T> pArr, T param);
int busqueda_dicotomica_Vector (vector<long> pVector, long param);

#endif // BUSQUEDADICOTOMICA_H
