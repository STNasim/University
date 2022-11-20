#ifndef GRAPH_H
#define GRAPH_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QApplication>
#include <vector>
#include <iostream>
using namespace std;

class Graph : public QOpenGLWidget
{
    Q_OBJECT
    int ancho, alto;
    int grafico;
    vector<float> hs;
    vector<int> var; //variacion
    vector<float> ejeH; //eje Horizontal
    vector<float> vert;
    int reng;
    int maxV, maxH;
    bool marcaVertical=false;
public:
    Graph(QWidget* parent=nullptr);
    void setGraficoTipo(int g);
    void loadHotspots(vector<float> hs, int n);
    void loadAnalisis(vector<int> &v, vector<float> &f);
    void loadMarcaVertical(vector<float> &vert);
    void setMarcaVertical(bool v);
    void drawHotspots();
    void drawAnalisis();
    void drawAnalisisVertical();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
};

#endif // GRAPH_H
