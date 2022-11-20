#include "promydesv.h"
#include "math.h"
#include <iostream>
using namespace std;

PromyDesv::PromyDesv()
{

}

float PromyDesv::DP(float v[], int tam)
{
    float a=0;
    float b=0;
    float prom=0;
    float desv=0;
    for(int x=0;x<tam;x++){
        a+=v[x];
    }
    prom=float (a/tam);

    for(int y=0;y<tam;y++){
        b+=((v[y]-prom)*(v[y]-prom));
    }
    desv= sqrt(b/tam);
    return desv;
}

float PromyDesv::P(float v[], int tam)
{
    float prom=0;
    float a=0;
    for(int x=0;x<tam;x++){
        a+=v[x];
    }
    prom=(float)a/(float)tam;
    return prom;
}
