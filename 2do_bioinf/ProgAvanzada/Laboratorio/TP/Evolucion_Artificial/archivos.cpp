#include "archivos.h"

Archivos::Archivos()
{
    ofstream archi;
    archi.open("Datos.txt",ios::trunc);
    archi.close();
    archi.open("Datos.bin",ios::trunc);
    archi.close();
}

void Archivos::GuardarTexto(Mundo &mundo)
{
    ofstream archi;
    archi.open("Datos.txt",ios::app);
    archi<<"Epoca: "<<mundo.GetTiempo()<<endl;
    archi<<"Comida Total: "<<mundo.ComidaTotal()<<endl;
    for(int o=0;o<mundo.CantidadSembradores();o++)
    {
        archi<<"Sembrador "<<o<<": "<<"Fila "<<mundo.FilaSembrador(o)<<" Columna "<<mundo.ColumnaSembrador(o)<<endl;
    }
    archi.close();
}

void Archivos::GuardarBinario(Mundo &mundo)
{
    int escritura;
    fstream archi;
    archi.open("Datos.bin",ios::binary | ios::out | ios::app);
    escritura=mundo.GetTiempo();
    archi.write((char *) &escritura,sizeof(escritura));
    escritura=mundo.ComidaTotal();
    archi.write((char *) &escritura,sizeof(escritura));
    escritura=mundo.CantidadSembradores();
    archi.write((char*) &escritura,sizeof(escritura));
    for(int l=0;l<mundo.CantidadSembradores();l++)
    {
        escritura=mundo.FilaSembrador(l);
        archi.write((char *) &escritura,sizeof(escritura));
        escritura=mundo.ColumnaSembrador(l);
        archi.write((char *) &escritura,sizeof(escritura));
    }
}

void Archivos::LeerTexto()
{
    ifstream archi;
    string lectura;
    archi.open("Datos.txt");
    if(archi.is_open())
        while(!archi.eof())
        {
            getline(archi,lectura,'\n');
            cout<<lectura<<endl;
        }
    archi.close();
}

void Archivos::LeerBinario()
{
    fstream archi;
    archi.open("Datos.bin",ios::binary | ios::in );
    if(archi.is_open())
    {
        archi.seekg(0);
        int contenido=0; //tamaño
        while(archi.read((char *)&contenido,sizeof(contenido)))
        {
            cout<<"Epoca: "<<contenido<<endl;
            archi.read((char *)&contenido,sizeof(contenido));
            cout<<"Comida Total: "<<contenido<<endl;
            archi.read((char *)&contenido,sizeof(contenido));
            int aux=contenido;
            for(int o=0;o<aux;o++)
            {
                cout<<"Sembrador "<<o<<": "<<"Fila ";
                archi.read((char *)&contenido,sizeof(contenido));
                cout<<contenido;
                cout<<" Columna ";
                archi.read((char *)&contenido,sizeof(contenido));
                cout<<contenido<<endl;
            }
            cout<<endl;
        }
        archi.close();
    }
}
