#ifndef MERGESORT_H
#define MERGESORT_H

template <class Contenedor> void mezclar( Contenedor& c1, Contenedor& c2, Contenedor &c3)
{
    unsigned int i=0,j=0,k=0;
    while( ( i < c1.size() ) && ( j < c2.size() ) ) {
        if( c1[i] <= c2[j]) {
            c3[k]=c1[i];
            i++;
            k++; }
        else  {
            c3[k]=c2[j];
            j++;
            k++; }
    }
    while(i < c1.size()) {
        c3[k]=c1[i];;
        i++;
        k++;}
    while(j < c2.size()) {
        c3[k]=c2[j];
        j++;
        k++;}
}

template <class Contenedor>void mergeSort(Contenedor &c)
{
    int tam=c.size();
    if(tam<=1){return;}
    int mitad = tam / 2;
    Contenedor izq;
    izq.resize(mitad);
    Contenedor der;
    der.resize(tam-mitad);
    for(int i=0;i<mitad;i++)
        izq[i] = c[i];
    for(int i=mitad;i<tam;i++)
        der[i-mitad] = c[i];
    mergeSort(izq);
    mergeSort(der);
    mezclar(izq, der,c);
}

#endif // MERGESORT_H
