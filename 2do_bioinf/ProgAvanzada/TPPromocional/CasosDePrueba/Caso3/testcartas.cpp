#include "testcartas.h"

#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <iostream>
TestCartas::TestCartas(QApplication *pptrApp)
{
    ptrApp = pptrApp;

    margen = 0.1;

    cartaSeleccionada = nullptr;

}

TestCartas::~TestCartas()
{
    for (unsigned int i=0; i<mazoDeCartas.size(); ++i)
        if(mazoDeCartas[i] != nullptr)
            delete mazoDeCartas[i];
}

void TestCartas::seleccionaMazo()
{
    mazoDeCartas.push_back(new Carta(1,(rand()%5)+1, {1.0,0.0,0.0}));
    mazoDeCartas.push_back(new Carta(2,(rand()%5)+1, {1.0,0.0,0.0}));
    mazoDeCartas.push_back(new Carta(3,(rand()%5)+1, {1.0,0.0,0.0}));
    mazoDeCartas.push_back(new Carta(4,(rand()%5)+1, {1.0,0.0,0.0}));
}

void TestCartas::repartirCartas()
{
    mesaConCartas.repartirCartas(2,2,mazoDeCartas,true);
    resize(500,500);
    show();
    ptrApp->exec();
}

void TestCartas::initializeGL()
{
    glClearColor(0.5f,0.6f,0.5f,0.0f);
}

void TestCartas::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Se define espacio de graficación
    anchoMesaConCartas = mesaConCartas.getCantColumnas() + (mesaConCartas.getCantColumnas() - 1) * 0.1 + 2 * margen;
    altoMesaConCartas = mesaConCartas.getCantFilas() + (mesaConCartas.getCantFilas() -1) * 0.1 + 2 * margen;
    glOrtho(0, anchoMesaConCartas, 0, altoMesaConCartas, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void TestCartas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();{
        glTranslated(margen,margen,0);
        mesaConCartas.dibujar();
    }glPopMatrix();
}

void TestCartas::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        double posX = event->x() * anchoMesaConCartas / width() - margen;
        double posY = (height() - event->y()) * altoMesaConCartas / height() - margen;
        int cx = coordenadaAPosicionCuantizada(posX, anchoMesaConCartas);
        int cy = coordenadaAPosicionCuantizada(posY, altoMesaConCartas);
        if (cx>=0 && cy>=0)
        {
            cartaSeleccionada = mesaConCartas(unsigned(cy),unsigned(cx));
            voltearCarta();
        }
        update();
    }
}

int TestCartas::coordenadaAPosicionCuantizada(double pCoord, double limite)
{
    int posicion = -1;
    if (pCoord > 0 && pCoord < limite - margen){
        int c = static_cast<int>(pCoord / 1.1);
        double d = pCoord - c * 1.1;
        if (d < 1) posicion = c;
    }
    return posicion;
}

void TestCartas::voltearCarta()
{
    // Se dan vuelta las cartas
    cartaSeleccionada->setVisible(!cartaSeleccionada->getVisible());
    // Ya no esta seleccionadas
    cartaSeleccionada = nullptr;
    update();
}
