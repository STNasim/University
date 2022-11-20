#ifndef ORDENAMIENTOSBASICOS_H
#define ORDENAMIENTOSBASICOS_H
#include <vector>
#include "../../EstructurasDeDatos/ArregloDinamico/arreglodin.h"
#include <deque>

template <class T>
void ord_burbuja(ArregloDin<T> &pArr);
template <class T>
void ord_seleccion(ArregloDin<T> &pArr);
template <class T>
void ord_insercion(ArregloDin<T> &pArr);

void ord_burbuja(vector<long> &pArr);
void ord_seleccion(vector<long> &pArr);
void ord_insercion(vector<long> &pArr);

void ord_insercion(deque<int> &plListaDoble);

#endif // ORDENAMIENTOSBASICOS_H
