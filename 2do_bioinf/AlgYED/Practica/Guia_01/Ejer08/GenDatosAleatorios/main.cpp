#include <QCoreApplication>
#include <iostream>
using namespace std;

#include "GeneradorDatosAleatorios.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GenerarDesordenadosUniforme(100);

    ifstream archi;
    archi.open("../Datos.bin",ios::binary);
    if(archi.is_open())
    {
        char extraccion;

        archi.read(&extraccion,sizeof(char));
        cout<<extraccion<<endl;

        archi.read(&extraccion,sizeof(char));
        cout<<extraccion<<endl;

        int lec;
        archi.read((char*)&lec,sizeof(lec));

        cout<<lec<<endl;
        long lectura;
        for(int i=0;i<100;i++)
        {
            archi.read((char*)&lectura,sizeof(lectura));
            cout<<lectura<<endl;
        }
    }
    archi.close();
    return a.exec();
}
