#include "GeneradorDatosAleatorios.h"
#include <iostream>
using namespace std;
void GenerarOrdenados(int cant)
{
    ofstream archi;
    archi.open("../Datos.bin",ios::binary | ios::trunc);
    vector <long> datos;
    datos.resize(cant);

    default_random_engine generador(time(0));
    normal_distribution<double> dist_norm(0,500000000);
    for(int i=0;i<cant;i++)
    {
        datos[i]=dist_norm(generador);
    }
    bool repet=false;
    sort(datos.begin(),datos.end());
    for(int i=0;i<cant-1;i++ and !repet)
    {
        if(datos[i]==datos[i+1])
        {
            repet=true;
        }
    }
    char rep;
    if(repet)
        rep='1';
    else
        rep='0';
    archi.write(&rep,sizeof(rep));
    rep='o';
    archi.write(&rep,sizeof(rep));
    archi.write((char*)&cant,sizeof(cant));
    archi.write((char*)&datos[0],sizeof (datos[0])*cant);

    archi.close();
}

void GenerarQuasiOrdenados(int cant)
{
    ofstream archi;
    archi.open("../Datos.bin",ios::binary | ios::trunc);

    vector <long> datos;
    datos.resize(cant);
    default_random_engine generador(time(0));
    normal_distribution<double> dist_norm(0,500000000);
    for(int i=0;i<cant;i++)
    {
        datos[i]=dist_norm(generador);
    }
    bool repet=false;
    sort(datos.begin(),datos.end());
    for(int i=0;i<cant-1;i++ and !repet)
    {
        if(datos[i]==datos[i+1])
        {
            repet=true;
        }
    }
    for(int i=0;i<cant-3;i+=(cant/(cant/3)))
    {
        long aux=datos[i];
        datos[i]=datos[i+1];
        datos[i+1]=aux;
    }
    char rep;
    if(repet)
        rep='1';
    else
        rep='0';
    archi.write(&rep,sizeof(rep));
    rep='c';
    archi.write(&rep,sizeof(rep));
    archi.write((char*)&cant,sizeof(cant));
    archi.write((char*)&datos[0],sizeof (datos[0])*cant);

    archi.close();
}

void GenerarDesordenadosNormal(int cant)
{
    ofstream archi;
    archi.open("../Datos.bin",ios::binary | ios::trunc);

    vector <long> datos;
    datos.resize(cant);
    default_random_engine generador(time(0));
    normal_distribution<double> dist_norm(0,500000000);
    for(int i=0;i<cant;i++)
    {
        datos[i]=dist_norm(generador);
    }
    bool repet=false;
    vector <long> aux=datos;
    sort(aux.begin(),aux.end());
    for(int i=0;i<cant-1;i++ and !repet)
    {
        if(aux[i]==aux[i+1])
        {
            repet=true;
        }
    }
    char rep;
    if(repet)
        rep='1';
    else
        rep='0';
    archi.write(&rep,sizeof(rep));
    rep='u';
    archi.write(&rep,sizeof(rep));
    archi.write((char*)&cant,sizeof(cant));
    archi.write((char*)&datos[0],(sizeof (datos[0])*cant));

    archi.close();
}

void GenerarDesordenadosUniforme(int cant)
{
    ofstream archi;
    archi.open("../Datos.bin",ios::binary | ios::trunc);

    vector <long> datos;
    datos.resize(cant);
    default_random_engine generador(time(0));
    uniform_int_distribution<long> dist_uniform(-1000000000,1000000000);
    for(int i=0;i<cant;i++)
    {
        datos[i]=dist_uniform(generador);
    }
    bool repet=false;
    vector <long> aux=datos;
    sort(aux.begin(),aux.end());
    for(int i=0;i<cant-1;i++ and !repet)
    {
        if(aux[i]==aux[i+1])
        {
            repet=true;
        }
    }
    char rep;
    if(repet)
        rep='1';
    else
        rep='0';
    archi.write(&rep,sizeof(rep));
    rep='u';
    archi.write(&rep,sizeof(rep));
    archi.write((char*)&cant,sizeof(cant));
    archi.write((char*)&datos[0],(sizeof (datos[0])*cant));

    archi.close();
}
