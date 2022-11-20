#include "juegodelamemoria.h"

#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <iostream>
JuegoDeLaMemoria::JuegoDeLaMemoria(QApplication *pptrApp)
{
    ptrApp = pptrApp;

    margen = 0.1;

    cartasSeleccionadas[0] = nullptr;
    cartasSeleccionadas[1] = nullptr;

    connect(&temporizador, SIGNAL(timeout()), this, SLOT(voltearCartas()));
}

JuegoDeLaMemoria::~JuegoDeLaMemoria()
{
    for (unsigned int i=0; i<mazoDeCartas.size(); ++i)
        if(mazoDeCartas[i] != nullptr)
            delete mazoDeCartas[i];
}

void JuegoDeLaMemoria::seleccionaMazo(int pares)
{
    if(pares>=1)
    {
        mazoDeCartas.push_back(new Carta(1, FIG_CUADRADO, {1.0,0.0,0.0}));
        mazoDeCartas.push_back(new Carta(1, FIG_CUADRADO, {1.0,0.0,0.0}));
    }
    if(pares>=2)
    {
        mazoDeCartas.push_back(new Carta(2, FIG_TRIANGULO, {1.0,0.0,0.0}));
        mazoDeCartas.push_back(new Carta(2, FIG_TRIANGULO, {1.0,0.0,0.0}));
    }
    if(pares>=3)
    {
        mazoDeCartas.push_back(new Carta(3, FIG_ESTRELLA, {0.0,0.0,1.0}));
        mazoDeCartas.push_back(new Carta(3, FIG_ESTRELLA, {0.0,0.0,1.0}));
    }
    if(pares>=4)
    {
        mazoDeCartas.push_back(new Carta(4, FIG_ESPIRAL, {0.0,0.0,1.0}));
        mazoDeCartas.push_back(new Carta(4, FIG_ESPIRAL, {0.0,0.0,1.0}));
    }
    if(pares>=5)
    {
        mazoDeCartas.push_back(new Carta(5, FIG_ESTRELLA, {0.0,1.0,0.0}));
        mazoDeCartas.push_back(new Carta(5, FIG_ESTRELLA, {0.0,1.0,0.0}));
    }
    if(pares>=6)
    {
        mazoDeCartas.push_back(new Carta(6, FIG_ESPIRAL, {0.0,1.0,0.0}));
        mazoDeCartas.push_back(new Carta(6, FIG_ESPIRAL, {0.0,1.0,0.0}));
    }
}

void JuegoDeLaMemoria::repartirCartas(int filas, int columnas)
{
    mesaConCartas.repartirCartas(filas,columnas,mazoDeCartas,false);
    resize(500,500);
    show();
    ptrApp->exec();
}

void JuegoDeLaMemoria::initializeGL()
{
    glClearColor(0.5f,0.6f,0.5f,0.0f);
}

void JuegoDeLaMemoria::resizeGL(int w, int h)
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

void JuegoDeLaMemoria::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();{
        glTranslated(margen,margen,0);
        mesaConCartas.dibujar();
    }glPopMatrix();
}

void JuegoDeLaMemoria::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && cartasSeleccionadas[1] == nullptr)
    {
        double posX = event->x() * anchoMesaConCartas / width() - margen;
        double posY = (height() - event->y()) * altoMesaConCartas / height() - margen;
        int cx = coordenadaAPosicionCuantizada(posX, anchoMesaConCartas);
        int cy = coordenadaAPosicionCuantizada(posY, altoMesaConCartas);
        if (cx>=0 && cy>=0
                && !mesaConCartas(unsigned(cy),unsigned(cx))->getEstaEmparejada()
                && !mesaConCartas(unsigned(cy),unsigned(cx))->getVisible()) {
            if (cartasSeleccionadas[0] == nullptr) {
                cartasSeleccionadas[0] = mesaConCartas(unsigned(cy),unsigned(cx));
            } else {
                cartasSeleccionadas[1] = mesaConCartas(unsigned(cy),unsigned(cx));
                // Verificar si son iguales
                if (cartasSeleccionadas[0]->getId() == cartasSeleccionadas[1]->getId()) {
                    // Marcamos que las encontramos
                    cartasSeleccionadas[0]->setEstaEmparejada(true);
                    cartasSeleccionadas[1]->setEstaEmparejada(true);
                    // Ya no estan seleccionadas
                    cartasSeleccionadas[0] = nullptr;
                    cartasSeleccionadas[1] = nullptr;
                } else {
                    // Activar timer
                    temporizador.start(1000);
                }
            }
            mesaConCartas(unsigned(cy),unsigned(cx))->setVisible(true);
            update();
        }
    }
}

int JuegoDeLaMemoria::coordenadaAPosicionCuantizada(double pCoord, double limite)
{
    int posicion = -1;
    if (pCoord > 0 && pCoord < limite - margen){
        int c = static_cast<int>(pCoord / 1.1);
        double d = pCoord - c * 1.1;
        if (d < 1) posicion = c;
    }
    return posicion;
}

void JuegoDeLaMemoria::voltearCartas()
{
    temporizador.stop();
    // Se dan vuelta las cartas
    cartasSeleccionadas[0]->setVisible(false);
    cartasSeleccionadas[1]->setVisible(false);
    // Ya no estan seleccionadas
    cartasSeleccionadas[0] = nullptr;
    cartasSeleccionadas[1] = nullptr;
    update();
}
