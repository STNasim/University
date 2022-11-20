#include "rectangulo.h"

#include <QOpenGLFunctions>

#include <cmath>

Rectangulo::Rectangulo(float pCx, float pCy, float pBase, float pAltura, float pAng)
{
    cx = pCx;
    cy = pCy;
    base = pBase;
    altura = pAltura;
    ang = pAng;

    float diag = sqrt(base*base+altura*altura);
    minX = double(cx-diag/2);
    maxX = double(cx+diag/2);
    minY = double(cy-diag/2);
    maxY = double(cy+diag/2);
}

float Rectangulo::getCx() const
{
    return cx;
}

void Rectangulo::setCx(float value)
{
    cx = value;
}

float Rectangulo::getCy() const
{
    return cy;
}

void Rectangulo::setCy(float value)
{
    cy = value;
}

float Rectangulo::getBase() const
{
    return base;
}

void Rectangulo::setBase(float value)
{
    base = value;
}

float Rectangulo::getAltura() const
{
    return altura;
}

void Rectangulo::setAltura(float value)
{
    altura = value;
}

float Rectangulo::getAng() const
{
    return ang;
}

void Rectangulo::setAng(float value)
{
    ang = value;
}

void Rectangulo::dibujar()
{
    glColor3f(0, 1, 0);
    glPushMatrix();{
        glTranslatef(cx,cy,0);
        glRotatef(ang,0,0,1);
        glScalef(base,altura,1);
        glTranslatef(-0.5,-0.5,0);
        glBegin(GL_POLYGON);{
            glVertex3f(0,0, 0); // plano z = 0
            glVertex3f(1,0, 0); // plano z = 0
            glVertex3f(1,1, 0); // plano z = 0
            glVertex3f(0,1, 0); // plano z = 0
        }glEnd();
    }glPopMatrix();
}








