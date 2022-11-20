#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;

class Archivos
{
    ifstream archi;
    map<string,int> meses
    {
        { "Jan", 1 },
        { "Feb", 2 },
        { "Mar", 3 },
        { "Apr", 4 },
        { "May", 5 },
        { "Jun", 6 },
        { "Jul", 7 },
        { "Aug", 8 },
        { "Sep", 9 },
        { "Oct", 10 },
        { "Nov", 11 },
        { "Dec", 12 }
    };
public:
    Archivos();
    void cargarDatosADN(string nombre, vector<pair<string,string>> &secuencias);
    string formattearFecha(string &fecha);
    void CargarDatosProteina(string nombreArchivo, vector<pair<string, string> > &secuencias);
    void cargarCasos(string nombre, string region, string info, vector<pair<string, int>> &vd);
};

#endif // ARCHIVOS_H
