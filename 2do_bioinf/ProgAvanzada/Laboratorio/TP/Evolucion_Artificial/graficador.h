#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include "mundo.h"
#include <QTimer>


class Graficador : public QOpenGLWidget
{
    Q_OBJECT
public:
    Graficador(Mundo *mundo = nullptr,QApplication* pptrApp = nullptr);
    void simular();
protected:
    void resizeGL(int w, int h);
    void paintGL();
    void initializeGL();
private:
    void keyPressEvent(QKeyEvent *event);
    QApplication *ptrApp;
    Mundo *ptrmundo;
    QTimer temporizador;
private slots:
    void actualizar();
};


#endif // GRAFICADOR_H
