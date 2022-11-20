#ifndef RADIXSORT_H
#define RADIXSORT_H
#include <iostream>
#include <vector>
using namespace std;

int calcularIndice(unsigned digito,long long numero)
{
    unsigned int factor=1;
    for(unsigned int j=0;j<digito;j++)
    {
        factor*=10;
    }
    return ((numero/factor)%10);
}

template <class Contenedor> void ordenar(Contenedor &origen, Contenedor &destino, unsigned digito)
{
    vector<unsigned int> numeros;
    numeros.resize(10,0);

    for(unsigned int i=0;i<origen.size();i++)
        numeros[calcularIndice(digito,origen[i])]++;
    for(unsigned int i=1;i<numeros.size();i++)
        numeros[i]+=numeros[i-1];
    for(int i=origen.size()-1;i>=0;i--)
    {
        unsigned int indice=calcularIndice(digito,origen[i]);
        numeros[indice]--;
        destino[numeros[indice]]=origen[i];
    }
}

template<class Contenedor> void ord_residuos(Contenedor& c)
{
    auto maximo=c[0];
    for(unsigned int i=1;i<c.size();i++)
    {
        if(c[i]>maximo)
            maximo=c[i];
    }
    unsigned int digitos=0;
    while(maximo!=0)
    {
        maximo/=10;
        digitos++;
    }

    Contenedor aux;
    aux.resize(c.size());

    for(unsigned int j=0;j<digitos-1;j++)
    {
        ordenar(c,aux,j);
        j++;
        ordenar(aux,c,j);
    }
    if(digitos%2==1)
    {
        ordenar(c,aux,digitos-1);
        for(unsigned int i=0;i<aux.size();i++)
        {
            c[i]=aux[i];
        }
        //c=aux; Por alguna razón no funciona. El programa crashea al finalizar la función
    }
}

unsigned int calcularIndiceString(unsigned int digito, string aux)
{
    unsigned int retorno=0;
    if(digito < aux.size())
        retorno=(unsigned int)(unsigned char)aux[digito];
    return retorno;
}

template <class Contenedor> void ordenarString(Contenedor &origen, Contenedor &destino, unsigned int digito)
{
    int caracteres [257];
    for(unsigned int i=0;i<257;i++)
    {
        caracteres[i]=0;
    }
    for(unsigned int i=0;i<origen.size();i++)
        caracteres[calcularIndiceString(digito,origen[i])]++;
    for(unsigned int i=1;i<257;i++)
        caracteres[i]+=caracteres[i-1];
    for(int i=origen.size()-1;i>=0;i--)
    {
        unsigned int indice=calcularIndiceString(digito,origen[i]);
        caracteres[indice]--;
        destino[caracteres[indice]]=origen[i];
    }
}

template<class Contenedor> void ord_residuosString(Contenedor& c)
{
    auto maximo=c[0].size();
    for(unsigned int i=1;i<c.size();i++)
    {
        if(c[i].size()>maximo)
            maximo=c[i].size();
    }
    unsigned int digitos=maximo;
    Contenedor aux;
    aux.resize(c.size(),"");
        for(int j=digitos;j>=0;j--)
        {
            ordenarString(c,aux,j);
            j--;
            ordenarString(aux,c,j);
        }
        if(digitos%2==1)
        {
            ordenarString(c,aux,0);
            for(unsigned int i=0;i<c.size();i++)
            {
                c[i]=aux[i];
            }
        }
}

#endif // RADIXSORT_H
