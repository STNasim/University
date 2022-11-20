#include "graficador2d.h"

#include <QOpenGLFunctions>

Graficador2D::Graficador2D(QApplication *pApp)
{
    if(pApp != nullptr)
        ptr_app = pApp;
    else std::cout<<"Nulo";
    RespuestaUsuario=-1;
}

void Graficador2D::cargarDibujo(Dibujo* pPtr_dib)
{
    if( pPtr_dib != nullptr )
        ptrs_dib.push_back(pPtr_dib);
    determinarDimensiones();
}

void Graficador2D::limpiarDibujos()
{
    ptrs_dib.clear();
}

void Graficador2D::mostrar(int w, int h)
{
    RespuestaUsuario=-1;
    resize(w,h);
    show();
    if(ptr_app != nullptr)
        ptr_app->exec();
}

void Graficador2D::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_S)
        {
            RespuestaUsuario=1;
            close();
        }
    if(event->key() == Qt::Key_N)
        {
            RespuestaUsuario=0;
            close();
        }
}

int Graficador2D::getRespuestaUsuario()
{
    return RespuestaUsuario;
}

void Graficador2D::determinarDimensiones()
{
    if(ptrs_dib.size()>0){
        if(ptrs_dib[0] != nullptr){
            minX = ptrs_dib[0]->getMinX();
            maxX = ptrs_dib[0]->getMaxX();
            minY = ptrs_dib[0]->getMinY();
            maxY = ptrs_dib[0]->getMaxY();

            for(unsigned int i=1; i<ptrs_dib.size(); ++i) {
                if(ptrs_dib[i] != nullptr){
                    if(minX > ptrs_dib[i]->getMinX())
                        minX = ptrs_dib[i]->getMinX();
                    if(maxX < ptrs_dib[i]->getMaxX())
                        maxX = ptrs_dib[i]->getMaxX();
                    if(minY > ptrs_dib[i]->getMinY())
                        minY = ptrs_dib[i]->getMinY();
                    if(maxY < ptrs_dib[i]->getMaxY())
                        maxY = ptrs_dib[i]->getMaxY();
                }
            }
        }
    }
}

void Graficador2D::initializeGL()
{
    glClearColor(1,1,1,0); // fondo blanco
}

void Graficador2D::resizeGL(int w, int h)
{
    determinarDimensiones(); // Se actualizan dimensiones

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( minX, maxX, minY, maxY, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graficador2D::paintGL()
{
    //resizeGL(width(), height());

    glClear(GL_COLOR_BUFFER_BIT);

    for(unsigned int i=0; i<ptrs_dib.size(); ++i){
        if( ptrs_dib[i] != nullptr ){
            ptrs_dib[i]->dibujar();
        }
    }
}

void Graficador2D::setPtr_app(QApplication *value)
{
    ptr_app = value;
}


