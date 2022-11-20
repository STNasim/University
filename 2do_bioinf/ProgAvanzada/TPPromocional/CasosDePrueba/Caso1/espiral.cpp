#include "espiral.h"
#include "math.h"

Espiral::Espiral(Pixel pColor) : Figura(pColor)
{

}

Espiral::~Espiral()
{

}

void Espiral::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    float theta=0;
    double x,y,a,b;
    a=0.05;
    b=0.08;
    x = a*pow(exp(1),(double)b*theta)*cos(theta);
    y = a*pow(exp(1),(double)b*theta)*sin(theta);
    glPushMatrix();
    glTranslatef(0.5f,0.5f,0);
    for(int i=0;i<1000;i++)
    {
        glBegin(GL_LINES);
        theta = 0.025*i;
        glVertex2f(x,y);
        glVertex2f(a*pow(exp(1), (double)b*theta)*cos(theta), a*pow(exp(1), (double)b*theta)*sin(theta));

        x = a*pow(exp(1), (double)b*theta)*cos(theta);
        y = a*pow(exp(1), (double)b*theta)*sin(theta);
    }
    glEnd();
    glPopMatrix();
}
