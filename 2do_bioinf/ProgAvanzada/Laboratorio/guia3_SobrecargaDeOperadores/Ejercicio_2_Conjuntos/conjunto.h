#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <vector>
#include <iostream>

class Conjunto
{
public:
    Conjunto();
    void operator<<(int elemento);
    void VolcarEnFlujo(std::ostream &salida);
    void operator>>(int elemento);
    Conjunto operator+(Conjunto sumando) const;
    Conjunto operator*(Conjunto factor) const;
    bool operator()(int elemento);

private:
    std::vector <int> elementos;
};

std::ostream &operator<<(std::ostream &salida,Conjunto &conjunto);

#endif // CONJUNTO_H
