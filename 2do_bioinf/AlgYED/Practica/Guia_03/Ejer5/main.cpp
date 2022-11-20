#include <QCoreApplication>
#include "../../Repo/Algoritmos/RadixSort/RadixSort.h"
#include "../../Repo/EstructurasDeDatos/ArregloDinamico/arreglodin.h"
#include "../../Ejemplos/Ejemplo_medicion_tiempos_ejecucion/cronometro.h"
#include <fstream>
#include <iostream>
using namespace std;

template<class Contenedor>  bool esta_ordenado(Contenedor& c)
{
    bool ordenado=true;
    for(unsigned int i=0;i<(c.size()-1) && ordenado;i++)
    {
        if(c[i]>c[i+1])
            ordenado=false;
    }
    return ordenado;
}

string printRandomString(int n)
{
    const int MAX = 26;
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                           'h', 'i', 'j', 'k', 'l', 'm', 'n',
                           'o', 'p', 'q', 'r', 's', 't', 'u',
                           'v', 'w', 'x', 'y', 'z' };

    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % MAX];

    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {
        srand(time(0));

        ArregloDin<string> arreglo;
        unsigned int elementos=1;
        Cronometro crono;
        ofstream salida;
        salida.open("../Datos.csv",ios::trunc);
        salida<<"elementos;Tiempo\n";

        for(unsigned int i=0;i<5;i++)
        {
            elementos*=10;

            arreglo.resize(elementos,"");
            for(unsigned int i=0;i<arreglo.size();i++)
            {
                arreglo[i]=printRandomString(rand()%150);
            }
            crono.iniciarCronometro();
            ord_residuosString(arreglo);
            crono.pararCronometro();
            string auxiliar=(to_string(elementos))+";"+to_string(crono.getDuracionEnSegundos())+"\n";
            while(auxiliar.find('.')!=string::npos)
            {
                auxiliar.replace(auxiliar.find('.'),1,",");
            }
            salida<<auxiliar;
            cout<<"Finalizado un bucle"<<endl;
        }
        salida.close();
    }
    catch (string mje)
    {
        cout << "Error: " << mje << endl;
    }
    catch (...)
    {
        cout << "Error indeterminado..." << endl;
    }
    cout << "Fin de la prueba..." << endl;
    return a.exec();
}
