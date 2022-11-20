#include <QCoreApplication>
#include <iostream>
#include <opm.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    float m[3][3];
    float t [3][3];
    float b=0;
    float det=0;
    float Vmax=0;

    cout<<"Ingrese los datos de la matriz"<<endl;

    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            cin>>b;
            m[y][x]=b;
        }
    }
    OpM funciones;

    det=funciones.Det(m);
    Vmax=funciones.Vmax(m);
    funciones.Trans(m,t);

    cout<<"La determinante es: "<<det<<endl;
    cout<<"El valor maximo es: "<<Vmax<<endl;

    for(int j=0;j<3;j++){
        for(int u=0;u<3;u++){
            cout<<t[u][j]<<" ";
        }
        cout<<endl;
    }

    return a.exec();
}
