#include "graficador.h"

Graficador::Graficador(Mundo *pmundo, QApplication *pptrApp)
{
    ptrmundo=pmundo;
    ptrApp=pptrApp;
    connect(&temporizador,SIGNAL(timeout()),this,SLOT(actualizar()));
    temporizador.start(250);
}

void Graficador::simular()
{
    resize(500,500);
    show();
    ptrApp->exec();
    ptrmundo->Finalizar();
}

void Graficador::resizeGL(int w, int h)
{
    float margenX=(maxcolumnas)/7.00;
    float margenY=(maxfilas)/7.00;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-margenX,maxcolumnas-1+margenX,-margenY,maxfilas-1+margenY,-1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graficador::paintGL()
{
    float margenX=(maxcolumnas-1)/10.00;
    float margenY=(maxfilas-1)/10.00;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    //Limites
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-margenX,-margenY);
    glVertex2f(-margenX,maxcolumnas-1+margenY);
    glVertex2f(maxfilas-1+margenX,maxcolumnas-1+margenY);
    glVertex2f(maxfilas-1+margenX,-margenY);
    glEnd();
    //Comida
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(0.0,1.0,0.0);
    for(int f=0;f<maxfilas;f++)
        for(int c=0;c<maxcolumnas;c++)
            if(ptrmundo->HayComida(f,c))
                glVertex2i(c,f);
    glEnd();
    //Sembradores
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,1.0);
    for(int i=0;i<ptrmundo->CantidadSembradores();i++)
        glVertex2i(ptrmundo->ColumnaSembrador(i),ptrmundo->FilaSembrador(i));
    glEnd();
    //MOs
    glPointSize(7);
    glBegin(GL_POINTS);
    for(int i=0;i<ptrmundo->CantidadMO();i++)
    {
        if(ptrmundo->MOEstaVivo(i))
        {
        glColor3f(1.0*ptrmundo->EnergiaMO(i)/eMaxMO,0.0,0.0);
        glVertex2i(ptrmundo->ColumnaMO(i),ptrmundo->FilaMO(i));
        }
    }
    glEnd();
    glPopMatrix();
}

void Graficador::initializeGL()
{
    glClearColor(1,1,1,0.0f);
}

void Graficador::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_S)
        {
            if(temporizador.isActive())
                temporizador.stop();
            else
                temporizador.start(250);
        }
}

void Graficador::actualizar()
{
    update();
    ptrmundo->Vivir();
    temporizador.start(250);
}
