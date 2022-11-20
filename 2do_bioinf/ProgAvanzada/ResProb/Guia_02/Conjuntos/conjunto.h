#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <iostream>
#include <vector>

class Conjunto
{
public:
    Conjunto();
    void VolcarEnFlujo(std::ostream &salida);
    std::vector<int> getElementos() const;
    void setElementos(const std::vector<int> &value);
    void operator<<(Conjunto a_agregar);
    void operator>>(Conjunto a_restar);
    bool operator()(int a);

private:
    std::vector <int> elementos;
};

std::ostream& operator<<(std::ostream& salida,Conjunto a);

#endif // CONJUNTO_H
