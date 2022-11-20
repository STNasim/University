#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <fstream>
#include "mundo.h"
using namespace std;

class Archivos
{
public:
    Archivos();
    void GuardarTexto(Mundo &mundo);
    void GuardarBinario(Mundo &mundo);
    void LeerTexto();
    void LeerBinario();
};

#endif // ARCHIVOS_H
