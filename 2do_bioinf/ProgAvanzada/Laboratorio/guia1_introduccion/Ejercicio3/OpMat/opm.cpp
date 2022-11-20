#include "opm.h"

OpM::OpM()
{

}

float OpM::Det(float v[][3])
{
    float det=0;
    det= (v[0][0]*((v[1][1]*v[2][2])-(v[2][1]*v[1][2])));
    det-= (v[0][1]*((v[1][0]*v[2][2])-(v[1][2]*v[2][0])));
    det+= (v[0][2]*((v[1][0]*v[2][1])-(v[1][1]*v[2][0])));
    return det;
}

float OpM::Vmax(float v[][3])
{
    float max=v[0][0];

    for(int p=0;p<3;p++){
        for(int l=0;l<3;l++)
            if(v[l][p]>max){
                max=v[l][p];
            }
    }
    return max;
}

void OpM::Trans(float v[][3], float t[][3])
{
    for(int y=0;y<3;y++){
        for(int z=0;z<3;z++)
            t[z][y]=v[y][z];
    }
}
