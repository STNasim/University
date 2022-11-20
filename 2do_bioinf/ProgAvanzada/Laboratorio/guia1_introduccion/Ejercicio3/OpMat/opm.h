#ifndef OPM_H
#define OPM_H


class OpM
{
public:
    OpM();
    float Det(float v[][3]);
    float Vmax(float v[][3]);
    void Trans(float v[][3],float t[][3]);
};

#endif // OPM_H
