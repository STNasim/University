#include "cuadrado.h"

Cuadrado::Cuadrado(Pixel pColor) : Figura(pColor)
{

}

Cuadrado::~Cuadrado()
{

}

void Cuadrado::dibujar()
{
    // grafica
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_QUADS);
    // Dibuja
    glVertex2f(0.2f,0.2f);
    glVertex2f(0.8f,0.2f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.2f,0.8f);
    glEnd();
    glPopMatrix();
}
