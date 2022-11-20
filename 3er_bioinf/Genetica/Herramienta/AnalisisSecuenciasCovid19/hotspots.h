#ifndef HOTSPOTS_H
#define HOTSPOTS_H

#include <QWidget>
#include <QDialog>
#include <QTextBlock>
#include <iostream>
#include <set>
#include "graph.h"
using namespace std;

namespace Ui {
class Hotspots;
}

class Hotspots : public QDialog
{
    Q_OBJECT

public:
    explicit Hotspots(QWidget *parent = nullptr);
    void setup(string f1, string f2, vector<pair<string, string> > &hs);
    void analizar();
    vector<float> calcularHotspots(vector<pair<string, string> > sec);
    ~Hotspots();



private slots:
//    void on_spinBoxReng_valueChanged(int arg1);

private:
    Ui::Hotspots *ui;
    string fechaIni, fechaFin;
    vector<pair<string,string>> secuencias;
    int reng;

    void findFecha(unsigned &j, unsigned &k);
};

#endif // HOTSPOTS_H
