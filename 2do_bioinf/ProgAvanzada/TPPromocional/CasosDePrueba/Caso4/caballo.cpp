#include "caballo.h"

#include <QOpenGLFunctions>

Caballo::Caballo(int pPosX, int pPosY)
{
    posX = pPosX;
    posY = pPosY;

    // Se ajustó dibujo para que quepa en recuadro de 1x1
    minX = 0;
    maxX = 1;
    minY = 0;
    maxY = 1;

    // Limites de dibujo original trasladado al centro de un cuadrado
    //    minX = 0;
    //    maxX = 224;
    //    minY = 0;
    //    maxY = 224;

    // Limites de dibujo original
    //    minX = 0;
    //    maxX = 134;
    //    minY = 0;
    //    maxY = 224;

    // Color por defecto
    cR=0.5f;  cG=1.0f;  cB=0.1f;
}

void Caballo::setPosicion(int pX, int pY)
{
    posX = pX;  posY = pY;
}

void Caballo::setColor(float pR, float pG, float pB)
{
    cR = pR; cG = pG; cB = pB;
}

void Caballo::dibujar()
{
    glPushMatrix();{
        glTranslatef(posX,posY,0); // Traslación para centrar
        glScalef(1.0f/224,1.0f/224,1.0f); // Escala para dimensionar a un recuadro de 1x1
        glTranslatef(37,0,0); // Traslación para centrar
        glPushMatrix();{
            // Transformaciones
            glTranslatef(0,224,0);
            glScalef(1,-1,1);
            // Dibujo
            glColor3f(cR, cG, cB);
            // Base
            glBegin(GL_POLYGON);{
                glVertex2f(27 ,224);
                glVertex2f(128,224);
                glVertex2f(128,192);
                glVertex2f(27 ,192);
            }glEnd();
            // Cuerpo
            glLineWidth(2);
            glBegin(GL_LINE_LOOP);{
                glVertex2f(118,187);
                glVertex2f(115,164);
                glVertex2f(131,118);
                glVertex2f(134,97);
                glVertex2f(130,67);
                glVertex2f(122,45);
                glVertex2f(105,31);
                glVertex2f(91,22);
                glVertex2f(81,19);
                glVertex2f(67,0);
                glVertex2f(66,18);
                glVertex2f(55,22);
                glVertex2f(56,31);
                glVertex2f(39,38);
                glVertex2f(36,44);
                glVertex2f(1,76);
                glVertex2f(2,83);
                glVertex2f(0,91);
                glVertex2f(7,99);
                glVertex2f(15,100);
                glVertex2f(26,101);
                glVertex2f(37,92);
                glVertex2f(44,88);
                glVertex2f(58,95);
                glVertex2f(69,94);
                glVertex2f(76,93);
                glVertex2f(54,118);
                glVertex2f(41,134);
                glVertex2f(32,151);
                glVertex2f(26,166);
                glVertex2f(31,177);
                glVertex2f(35,187);
            }glEnd();
            glLineWidth(1);
        }glPopMatrix();
    }glPopMatrix();
}
