#include "estrella.h"

Estrella::Estrella(Pixel pColor) : Figura(pColor)
{

}

Estrella::~Estrella()
{

}

void Estrella::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_TRIANGLES);

    glVertex2f(0.8,0.1);
    glVertex2f(0.5,0.9);
    glVertex2f(0.4,0.4);

    glVertex2f(0.2,0.1);
    glVertex2f(0.5,0.9);
    glVertex2f(0.6,0.4);

    glVertex2f(0.9,0.6);
    glVertex2f(0.1,0.6);
    glVertex2f(0.5,0.35);

    glEnd();
    glPopMatrix();

}
