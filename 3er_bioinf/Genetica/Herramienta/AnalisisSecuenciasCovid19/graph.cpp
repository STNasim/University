#include "graph.h"


Graph::Graph(QWidget *parent) : QOpenGLWidget(parent)
{
    ancho=50;
    alto=50;
    grafico=0;
}

void Graph::setGraficoTipo(int g)
{
    grafico=g;
}

void Graph::loadHotspots(vector<float> hs, int n)
{
    this->hs=hs;
    reng=n;
}

void Graph::loadAnalisis(vector<int>& v, vector<float> &f)
{
    var=v; ejeH=f;
}

void Graph::loadMarcaVertical(vector<float> &vert)
{
    this->vert=vert;
}

void Graph::setMarcaVertical(bool v)
{
    marcaVertical=v;
}

void Graph::drawHotspots()
{
    unsigned size=hs.size();
    double c=0.8;
    double w=double(reng*ancho*1.0/size);
    for(int k=0;k<reng;++k){
        for(unsigned i=0;i<size/reng;++i){
            c=hs[k*size/reng+i];
            glPushMatrix();{
                glTranslated(double(1.0*i*reng*ancho/size), -k*alto/(reng+1), 0);
                glScaled(w,1,0);
                glColor3d(1.0-c, 0.5-c, 0.5-c);
                glBegin(GL_POLYGON);{
                    glVertex2d(0.5,alto-2);
                    glVertex2d(0.5,alto-4);
                    glVertex2d(1.5,alto-4);
                    glVertex2d(1.5,alto-2);
                }glEnd();
            }glPopMatrix();
        }
    }
    for(unsigned i=0;i<=(size%reng);++i){
        c=hs[size-(size%reng)+i];
        glPushMatrix();{
            glTranslated(double(1.0*i*reng*ancho/size), -reng*alto/(reng+1), 0);
            glScaled(w,1,0);
            glColor3d(1.0-c, 0.8-c, 0.8-c);
            glBegin(GL_POLYGON);{
                glVertex2d(0.5,alto-2);
                glVertex2d(0.5,alto-4);
                glVertex2d(1.5,alto-4);
                glVertex2d(1.5,alto-2);
            }glEnd();
        }glPopMatrix();
    }
}

void Graph::drawAnalisis()
{
    unsigned i, n=var.size(); double posH, posV;
    maxV=*max_element(var.begin(),var.end());
    maxH=*max_element(ejeH.begin(),ejeH.end());
    // Ejes
    glPushMatrix();{
        glLineWidth(1);
        glColor3f(0.1, 0.2, 0.2);
        glBegin(GL_LINES);{ //horizontal
            glVertex2d(0,0);
            glVertex2d(ancho,0);
        }glEnd();
        glBegin(GL_LINES);{ //vertical
            glVertex2d(0,0);
            glVertex2d(0,alto);
        }glEnd();
    }glPopMatrix();

    // Graph
    glEnable(GL_POINT_SMOOTH);
    for(i=0;i<n;++i) {
        glPushMatrix();{
            glLineWidth(3);
            glColor3f(0.8-i*1.0/n, 0.2+i*1.0/n, 0.2);
            glPointSize(9);
            glBegin(GL_POINTS);{
                posH=ejeH[i]==0?0:ejeH[i]*1.0*ancho/maxH;
                posV=var[i]==0?0:var[i]*1.0*alto/maxV;
                glVertex2f(posH,posV);
            }glEnd();
        }glPopMatrix();
    }
    glPushMatrix();{
        glBegin(GL_LINE_STRIP);{
            for(i=0;i<n-1;++i) {
                glColor3f(0.8-i*1.0/n, 0.2+i*1.0/n, 0.2);
                posH=ejeH[i]==0?0:ejeH[i]*1.0*ancho/maxH;
                posV=var[i]==0?0:var[i]*1.0*alto/maxV;
                glVertex2d(posH,posV);
                posH=ejeH[i+1]==0?0:ejeH[i+1]*1.0*ancho/maxH;
                posV=var[i+1]==0?0:var[i+1]*1.0*alto/maxV;
                glVertex2d(posH,posV);
            }
        }glEnd();
    }glPopMatrix();
    if (marcaVertical) drawAnalisisVertical();
}

void Graph::drawAnalisisVertical()
{
    if(vert.size()>0){
        maxH=*max_element(vert.begin(),vert.end());
        glPushMatrix();{
            glColor3f(0.1, 0.2, 0.2);
            glLineWidth(1);
            for(unsigned i=0;i<vert.size();++i) {
                glBegin(GL_LINES);{
                    glVertex2d(vert[i]*ancho/maxH,0);
                    glVertex2d(vert[i]*ancho/maxH,alto);
                }
            }glEnd();
        }glPopMatrix();
    }
}

void Graph::initializeGL()
{
    glClearColor(0.98f, 0.99f, 1.0f, 0.0f);
}

void Graph::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, ancho+3, -3, alto+1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graph::paintGL()
{
    resizeGL(width(),height());
    if (grafico==0) drawAnalisis(); // Analisis de Variacion
    else if (grafico==1) drawHotspots(); // Hotspots
}
