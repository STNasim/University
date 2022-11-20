#include <QCoreApplication>
#include <VerificarPalindromo.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int o=3746;
    int i=6;
    srand (time(0));
    if(verificarPalindromo(o))
        cout<<"o es palindromo"<<endl;
    else
        cout<<"o no es palindromo"<<endl;

    if(verificarPalindromo(i))
        cout<<"i es palindromo"<<endl;
    else
        cout<<"i no es palindromo"<<endl;

    vector <int> datos;

    cout<<"Ingrese la cantidad de datos ";
    unsigned int ingreso;
    cin>>ingreso;

    datos.resize(ingreso);

    for(unsigned int i=0;i<datos.size();i++)
    {
        datos[i]=rand();
        cout<<datos[i]<<", ";
    }
    cout<<endl;
    cout<<"Hay "<<contarPalindromos(datos)<<" numeros palindromos"<<endl;

    ordenarPalindromos(datos);

    for(unsigned int i=0;i<datos.size();i++)
    {
        cout<<datos[i]<<", ";
    }

    return a.exec();
}
