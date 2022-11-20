#ifndef PUNTO2D_H
#define PUNTO2D_H
#include <iostream>

typedef unsigned int b;
class Punto2D
{
public:
    Punto2D();
    b fila;
    b columna;
    b getFila() const;
    void setFila(const b &value);
    b getColumna() const;
    void setColumna(const b &value);
    Punto2D operator+(Punto2D sumando);
    bool operator==(Punto2D comparador);
    bool operator!=(Punto2D comparador);
    bool operator<(Punto2D comparador);
};

#endif // PUNTO2D_H
