#ifndef CALRAICES_H
#define CALRAICES_H
#include <fstream>
#include <iostream>
#include <math.h>

class calraices
{
public:
    float a,b,c,ParteReal1,ParteReal2,ParteImaginaria1,ParteImaginaria2;
    bool Imaginarias=0;
    calraices();
    void LeerDatos();
    void CalculoRaices();
    void MostrarDatos();
};

#endif // CALRAICES_H
