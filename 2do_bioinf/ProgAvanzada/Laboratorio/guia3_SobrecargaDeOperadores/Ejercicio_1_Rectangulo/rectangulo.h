#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <iostream>

class Rectangulo
{
public:
    Rectangulo();

    float getBase() const;
    void setBase(float value);

    float getAltura() const;
    void setAltura(float value);

    void CalcularArea();
    float getArea() const;

    Rectangulo operator+(Rectangulo sumando);
    bool operator==(Rectangulo comparador);
    bool operator!();

private:
    float base;
    float altura;
    float area;
};

#endif // RECTANGULO_H
