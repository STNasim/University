#include "circulo.h"
#include "math.h"

Circulo::Circulo(Pixel pColor) : Figura(pColor)
{

}

Circulo::~Circulo()
{

}

void Circulo::dibujar()
{
    glColor3f(color.rojo,color.verde,color.azul);
    glPushMatrix();
    glTranslatef(0.5f,0.5f,0);
    glBegin(GL_POLYGON);
         for(int i =0; i <= 300; i++){
             double angle = 2 * M_PI * i / 300;
             double x = cos(angle)/3;
             double y = sin(angle)/3;
             glVertex2d(x,y);
         }
    glEnd();
    glPopMatrix();
}
