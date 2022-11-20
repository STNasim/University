#include "desvyprom.h"
#include "math.h"

DesvyProm::DesvyProm()
{

}

void DesvyProm::DP(float v[], float &prom, float &desv)
{
    float a=0;
    float b=0;
    for(int x=0;x<10;x++){
        a+=v[x];
    }
    prom=a/10;

    for(int y=0;y<10;y++){
        b+=((v[y]-prom)*(v[y]-prom));
    }
    desv= sqrt(b/10);

    }
