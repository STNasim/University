#include "texto.h"

#include <QPainterPath>
#include <QOpenGLFunctions>
#include <QPainter> // Para función texto
#include <QString>  // Para función texto
#include <algorithm>

//using namespace std;

Texto::Texto(std::string pFrase, int pX, int pY, float pR, float pG, float pB){
    frase = pFrase;
    posX = pX;
    posY = pY;

    // color rgb
    color.resize(3);
    color[0]=pR;
    color[1]=pG;
    color[2]=pB;
}

void Texto::dibujar()
{
    dibujarTexto(frase, posX + 0.5, posY + 0.5, 10);
}

void Texto::setColor(float pR, float pG, float pB)
{
    color[0]=pR;
    color[1]=pG;
    color[2]=pB;
}

void Texto::dibujarTexto(std::string pTexto, float pX, float pY, unsigned char pTam)
{
    float escala = 0.05f;
    QFont fuente("Arial", pTam);
    QString qTexto(pTexto.c_str());
    //QPointF posicion(pX, -pY/escala);
    QPointF posicion(0, 0);

    glLineWidth(anchoLineaTexto);
    QPainterPath camino;
    camino.addText(posicion, fuente, qTexto);
    QList<QPolygonF> poligonos = camino.toSubpathPolygons();
    std::vector<float> coordenadasX, coordenadasY; // Vectores para centrar texto en coordenada (0, 0)
    float x, y; // Auxiliares
    for (QList<QPolygonF>::iterator i = poligonos.begin(); i != poligonos.end(); i++){
        for (QPolygonF::iterator p = (*i).begin(); p != i->end(); p++){
            x = escala*p->rx(); y = -escala*p->ry();
            coordenadasX.push_back(x);
            coordenadasY.push_back(y);
        }
    }
    // Centrado de caracter en coordenada (0, 0)
    float coordx_min, coordx_max, coordy_min, coordy_max;
    coordx_min = *min_element(coordenadasX.begin(),coordenadasX.end());
    coordx_max = *max_element(coordenadasX.begin(),coordenadasX.end());
    coordy_min = *min_element(coordenadasY.begin(),coordenadasY.end());
    coordy_max = *max_element(coordenadasY.begin(),coordenadasY.end());

    float tx, ty, cx, cy;
    cx = (coordx_max+coordx_min)/2;
    cy = (coordy_max+coordy_min)/2;
    tx = -cx + pX;
    ty = -cy + pY;

    glColor3f(color[0],color[1],color[2]);
    glPushMatrix();{
        glTranslatef(tx, ty, 0);

        for (QList<QPolygonF>::iterator i = poligonos.begin(); i != poligonos.end(); i++){
            glBegin(GL_LINE_STRIP);{
                for (QPolygonF::iterator p = (*i).begin(); p != i->end(); p++){
                    x = escala*p->rx(); y = -escala*p->ry();
                    glVertex3f(x, y, 0);
                }
            }
            glEnd();
        }
    }
    glPopMatrix();
    glLineWidth(1);
}

