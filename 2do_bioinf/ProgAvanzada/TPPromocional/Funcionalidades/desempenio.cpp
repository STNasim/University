#include "desempenio.h"
#include <QOpenGLFunctions>
#include <math.h>
#include <algorithm>

float newton(std::vector <int> puntos, float xi)
{
    int n=puntos.size();
    std::vector <std::vector<float>> b;
    float yi;
    float xt;
    b.resize(n);
    for(int p=0;p<n;p++)
        b[p].resize(n);

    for (int i=0;i<n;i++)
    {
        b[i][0]=puntos[i];
    }

    for(int j=1;j<n;j++)
        for(int i=0;i<n-j;i++)
            b[i][j]=(b[i+1][j-1]-b[i][j-1])/j;

    xt=1;
    yi=b[0][0];
    for(int j=0;j<n-1;j++)
    {
        xt=xt*(xi-j);
        yi=yi+b[0][j+1]*xt;
    }

    return yi;
}
Desempenio::Desempenio()
{
    maxX=2;
    minX=-0.5;
    minY=-0.5;
    maxY=2;
    lineal=false;
    interpolada=false;
}

void Desempenio::dibujar()
{
    //Fondo
    glColor3f(0.5f,0.5f,0.5f);
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glVertex2f(maxX,0);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(maxX,maxY);
    glVertex2f(0,maxY);
    glEnd();
    glPopMatrix();

    //Ejes
    glColor3f(0.0f,0.0f,0.0f);
    glPushMatrix();
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,0);
    glVertex2f(0,maxY);
    glVertex2f(0,0);
    glVertex2f(maxX,0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0,maxY);
    glVertex2f(-0.5,maxY-0.5);
    glVertex2f(0.5,maxY-0.5);
    glVertex2f(maxX,0);
    glVertex2f(maxX-0.5,0.5);
    glVertex2f(maxX-0.5,-0.5);
    glPopMatrix();
    glEnd();

    //Grilla
    glColor3f(0.5f,0.5f,0.5f);
    glPushMatrix();
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int n=1;n<maxX;n++)
    {
        glVertex2f(n,0);
        glVertex2f(n,maxY);
    }
    for(int n=1;n<maxY;n++)
    {
        glVertex2f(0,n);
        glVertex2f(maxX,n);
    }
    glPopMatrix();
    glEnd();

    //Discos Naranjas
    glColor3f(1.0f,0.5f,0.0f);
    for(int n=0;n<(int)puntos.size();n++)
    {
        glPushMatrix();
        glTranslatef(n+1,puntos[n],0);
        glBegin(GL_POLYGON);
        for(int i =0; i <= 500; i++)
        {
            double angle = 2 * M_PI * i / 500;
            double x = cos(angle)/10;
            double y = sin(angle)/10;
            glVertex2d(x,y);
        }
        glEnd();
        glPopMatrix();
    }

    //Borde azul
    glColor3f(0.0f,0.0f,1.0f);
    for(int n=0;n<(int)puntos.size();n++)
    {
        glPushMatrix();
        glTranslatef(n+1,puntos[n],0);
        glBegin(GL_LINE_LOOP);
        for(int i =0; i <= 300; i++)
        {
            double angle = 2 * M_PI * i / 300;
            double x = cos(angle)/10;
            double y = sin(angle)/10;
            glVertex2d(x,y);
        }
        glEnd();
        glPopMatrix();
    }

    //Rectas Valores
    //Maxima
    glLineWidth(2);
    it = max_element(begin(puntos),end(puntos));
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0,*it);
    glVertex2f(maxX,*it);

    //Minima
    it= min_element(puntos.begin(),puntos.end());
    glVertex2f(0,*it);
    glVertex2f(maxX,*it);

    //Media
    float aux=0;
    for(int n=0;n<(int)puntos.size();n++)
        aux+=puntos[n];
    aux/=(float)puntos.size();
    glVertex2f(0,aux);
    glVertex2f(maxX,aux);
    glEnd();
    glPopMatrix();

    //Unir Puntos
    if(interpolada)
    {
        if(puntos.size()<3)
            lineal=true;
        else
        {
            glColor3f(1.0,0.0,0.0);
            glPushMatrix();
            glBegin(GL_LINES);
            for(int n=0;n<(int)puntos.size()-1;n++)
            {
                for(int i=0;i<20;i++)
                {
                    glVertex2f(n+0.05*i+1,newton(puntos,n+0.05*i));
                }
            }
            glEnd();
            glPopMatrix();
        }
    }
    if(lineal)
    {
        glColor3f(0.0,0.0,1.0);
        glLineWidth(3);
        glPushMatrix();
        glBegin(GL_LINES);
        for(int n=0;n<(int)puntos.size()-1;n++)
        {
            glVertex2f(n+1,puntos[n]);
            glVertex2f(n+2,puntos[n+1]);
        }
        glEnd();
        glPopMatrix();
    }
}

void Desempenio::CargarDatos(std::vector<int> aux)
{
    puntos.resize(aux.size());
    for(int n=0;n<(int)aux.size();n++)
        puntos[n]=aux[n];
    maxX=puntos.size()+1;
    maxY=puntos[0]+1;
    for(int n=1;n<(int)puntos.size();n++)
        if(puntos[n]>maxY)
            maxY=puntos[n];
    maxY++;
}

void Desempenio::MostrarLineal(bool aux)
{
    lineal=aux;
}

void Desempenio::MostrarInterpolada(bool aux)
{
    interpolada=aux;
}
