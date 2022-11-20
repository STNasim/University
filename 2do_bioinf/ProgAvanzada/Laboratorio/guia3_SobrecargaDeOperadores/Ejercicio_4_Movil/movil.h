#ifndef MOVIL_H
#define MOVIL_H
#include <iostream>

class Movil
{
public:
    Movil();

    int getPosicion() const;
    void setPosicion(int value);
    int getMeta() const;
    void setMeta(int value);
    Movil operator++();
    Movil operator++(int a);
    Movil operator--();
    Movil operator--(int a);
    bool operator!();
    bool operator==(Movil comparador);

private:
    int posicion=0;
    int meta=0;
};

#endif // MOVIL_H
