#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "dibujo.h"

class Rectangulo : public Dibujo
{
public:
    Rectangulo(float pCx, float pCy,
               float pBase, float pAltura,
               float pAng);

    float getCx() const;
    void setCx(float value);

    float getCy() const;
    void setCy(float value);

    float getBase() const;
    void setBase(float value);

    float getAltura() const;
    void setAltura(float value);

    float getAng() const;
    void setAng(float value);

    // Métodos virtuales heredados de Dibujo
    void dibujar();

private:
    float cx, cy, base, altura, ang;
};

#endif // RECTANGULO_H
