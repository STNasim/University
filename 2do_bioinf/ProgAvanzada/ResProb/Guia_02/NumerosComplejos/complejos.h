#ifndef COMPLEJOS_H
#define COMPLEJOS_H
#include <math.h>

class Complejos
{
public:
    Complejos();

    void setParteReal(float value);
    void setParteImaginaria(float value);
    float getParteReal() const;
    float getParteImaginaria() const;
    Complejos operator+(Complejos sumando);
    Complejos operator!();
    bool operator<(Complejos comparador);
    Complejos operator*(Complejos Factor);
    Complejos operator++();
    Complejos operator--();
    Complejos operator--(int a);

private:
    float ParteReal;
    float ParteImaginaria;
};

#endif // COMPLEJOS_H
