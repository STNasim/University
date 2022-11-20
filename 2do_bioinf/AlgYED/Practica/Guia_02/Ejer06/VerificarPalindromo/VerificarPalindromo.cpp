#include "VerificarPalindromo.h"
#include <iostream>
using namespace std;
bool verificarPalindromo(int &numero)
{
    string cadena,reverso;
    bool palindromo=true;
    cadena=to_string(numero);
    unsigned int i=0;
    while(palindromo && i!=((cadena.size()/2)+1))
    {
        if(cadena[i]!=cadena[cadena.size()-1-i])
            palindromo=false;
        i++;
    }
    return palindromo;
}

int contarPalindromos(vector<int> datos)
{
    int cantidad=0;
    for(unsigned int i=0;i<datos.size();i++)
    {
        if(verificarPalindromo(datos[i]))
            cantidad++;
    }
    return cantidad;
}

void ordenarPalindromos(vector<int> &datos)
{
    vector <int> palindromos, no_palindromos;

    for(unsigned int i=0;i<datos.size();i++)
    {
        if(verificarPalindromo(datos[i]))
            palindromos.push_back(datos[i]);
        else
            no_palindromos.push_back(datos[i]);
    }
    sort(palindromos.begin(),palindromos.end());

    unsigned int j=0;
    for(j=0;j<palindromos.size();j++)
        datos[j]=palindromos[j];

    for(unsigned int i=0;i<no_palindromos.size();i++)
    {
        datos[j]=no_palindromos[i];
        j++;
    }
}
