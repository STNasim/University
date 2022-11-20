#ifndef SHELLSORT_H
#define SHELLSORT_H
template <class Contenedor>
void shellSort(Contenedor &c){
    int i,j,h; Contenedor v;
    v.resize(1);
    int tam=c.size();
    for (h=1; h<=tam/9;h=3*h+1);
    for (; h>0; h/=3)
        for (i=h; i<tam; i+=1){
            v[0]=c[i]; j=i;
            while ((j>=h) && (c[j-h]>v[0])){
                c[j]=c[j-h];
                j-=h;}
            c[j]=v[0];
        }
}
#endif // SHELLSORT_H
