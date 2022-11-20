#include "triangulo.h"

Triangulo::Triangulo(Pixel pColor) : Figura(pColor)
{

}

void Triangulo::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f,0.2f);
    glVertex2f(0.8f,0.2f);
    glVertex2f(0.5f,0.8f);
    glEnd();
    glPopMatrix();
}

Triangulo::~Triangulo()
{

}
