#include "mundo.h"
Mundo::Mundo()
{
    srand(time(0));
    MOs.resize(NMOs);
    sembradores.resize(Nsembra);
    tiempo=0;
    ID=0;
}

void Mundo::Vivir()
{
    for(uint l=0;l<sembradores.size();l++)
    {
        sembradores[l].Sembrar(comida);
        sembradores[l].Mover();
    }
    for(uint r=0;r<MOs.size();r++)
    {
        MOs[r].Comer(comida);
        MOs[r].Mover(comida);
    }
    if(tiempo%movimientosparareproducir==0 and CantidadMOvivos()>1 and tiempo>0)
        LlamarReproduccion();
    tiempo++;
}

void Mundo::LlamarReproduccion()
{
    int IDpadre1=0;
    int IDpadre2=0;
    for(uint p=0;p<MOs.size();p++)
        if(!MOs[p].Estavivo())
        {
            TiempoDeVidaMOs.insert(pair<int,int>(MOs[p].getEdad(),ID));
            bool buscarPadre1=true;
            bool buscarPadre2=true;
            while(buscarPadre1)
            {
                IDpadre1=rand()%MOs.size();
                if(MOs[IDpadre1].Estavivo())
                    buscarPadre1=false;
            }
            while(buscarPadre2)
            {
                IDpadre2=rand()%MOs.size();
                if(MOs[IDpadre2].Estavivo()and IDpadre2!=IDpadre1)
                    buscarPadre2=false;
            }
            MOs[p].Hijo(MOs[IDpadre1],MOs[IDpadre2]);
            ID++;
        }
}

int Mundo::CantidadMO()
{
    return MOs.size();
}

int Mundo::CantidadSembradores()
{
    return sembradores.size();
}

int Mundo::InteligenciaColonia()
{
    int inteligenciaPromedio=0;
    for(uint m=0;m<MOs.size();m++)
        inteligenciaPromedio+=MOs[m].DevolverInteligencia();
    inteligenciaPromedio/=(float)MOs.size();
    return inteligenciaPromedio;
}

void Mundo::Finalizar()
{
    for(int i=0;i<CantidadMO();i++)
    {
        TiempoDeVidaMOs.insert(pair<int,int>(MOs[i].getEdad(),ID));
        ID++;
    }
}

int Mundo::GetTiempo()
{
    return tiempo;
}

int Mundo::ComidaTotal()
{
    return comida.DevolverCantidadTotal();
}

bool Mundo::HayComida(int f, int c)
{
    return comida.HayComida(f,c);
}

int Mundo::FilaSembrador(int ID)
{
    return sembradores[ID].DevolverFila();
}

int Mundo::ColumnaSembrador(int ID)
{
    return sembradores[ID].DevolverColumna();
}

int Mundo::FilaMO(int ID)
{
    return MOs[ID].getF();
}

int Mundo::ColumnaMO(int ID)
{
    return MOs[ID].getC();
}

int Mundo::EnergiaMO(int ID)
{
    return MOs[ID].getEnergia();
}

int Mundo::MOEstaVivo(int ID)
{
    return MOs[ID].Estavivo();
}

void Mundo::MOQueMasVivio(int &ID, int &TiempoVida)
{
    it=TiempoDeVidaMOs.end();
    it--;
    TiempoVida=it->first;
    ID=it->second;
}

void Mundo::MOQueMenosVivio(int &ID, int &TiempoVida)
{
    it=TiempoDeVidaMOs.begin();
//    while (it->first<eInicial) Si se quiere omitir a los muertos por cerrar la simulación
//        it++;
    TiempoVida=it->first;
    ID=it->second;
}

#include <iostream>
using namespace std;

void Mundo::MostrarSTL()
{
    it=TiempoDeVidaMOs.begin();
    while(it!=TiempoDeVidaMOs.end())
    {
        cout<<"ID: "<<it->second<<"   "<<"Tiempo: "<<it->first<<endl;
        it++;
    }
}


int Mundo::CantidadMOvivos()
{
    int cantidad=0;
    for(uint r=0;r<MOs.size();r++)
    {
        if(MOs[r].Estavivo())
            cantidad++;
    }
    return cantidad;
}
