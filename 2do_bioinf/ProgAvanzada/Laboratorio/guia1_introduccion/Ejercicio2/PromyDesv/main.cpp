#include <QCoreApplication>
#include <iostream>
#include <desvyprom.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    float prom=0;
    float desv=0;
    float v[10]{0};
    cout<<"Ingrese los datos"<<endl;
    for(int x=0;x<10;x++)
       cin>>v[x];

    DesvyProm DyP;

    DyP.DP(v,prom,desv);

    cout<<"El promedio es: "<<prom<<endl;
    cout<<"El desvio es: "<<desv<<endl;

    return a.exec();
}
