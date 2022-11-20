#ifndef ANALISISVAR_H
#define ANALISISVAR_H

#include <QWidget>
#include <QDialog>
#include "graph.h"
#include "archivos.h"
using namespace std;

namespace Ui {
class AnalisisVar;
}

class AnalisisVar : public QDialog
{
    Q_OBJECT

public:
    explicit AnalisisVar(QWidget *parent = nullptr);
    ~AnalisisVar();
    void setup(bool proteina, int mat, vector<pair<string,string>> &sec);
    void analizar();

private slots:
    void on_comboBoxEjeX_currentIndexChanged(const QString &arg1);

    void on_comboBoxMarcaVert_currentIndexChanged(int index);

private:
    Ui::AnalisisVar *ui;
    bool proteina;
    string filename;
    int matriz;
    vector<pair<string,string>> secuencias;
    vector<int> var;
    vector<float> ejeHorizontalTiempo;
    vector<float> ejeHorizontalInf;
    vector<float> ejeHorizontalPV;
    vector<float> ejeHorizontalIndice;
    void getEjeTiempo();
    void getEjeProporcionV();
    void getEjeInfecciones();
    vector<int> aplicarMatrizProteina();
    int calcularVariabilidad(int indice_1, int indice_2);
    void setTable();

    map<char, int> indices
    {
        { 'A', 0 },
        { 'R', 1 },
        { 'N', 2 },
        { 'D', 3 },
        { 'C', 4 },
        { 'Q', 5 },
        { 'E', 6 },
        { 'G', 7 },
        { 'H', 8 },
        { 'I', 9 },
        { 'L', 10 },
        { 'K', 11 },
        { 'M', 12 },
        { 'F', 13 },
        { 'P', 14 },
        { 'S', 15 },
        { 'T', 16 },
        { 'W', 17 },
        { 'Y', 18 },
        { 'V', 19 }
    };

    vector<vector<int>> PAM70={{5},
                                    {-4,8},
                                    {-2,-3,6},
                                    {-1,-6,3,6},
                                    {-4,-5,-7,-9,9},
                                    {-2,0,-1,0,-9,7},
                                    {-1,-5,0,3,-9,2,6},
                                    {0,-6,-1,-1,-6,-4,-2,6},
                                    {-4,0,1,-1,-5,2,-2,-6,8},
                                    {-2,-3,-3,-5,-4,-5,-4,-6,-6,7},
                                    {-4,-6,-5,-8,-10,-3,-6,-7,-4,1,6},
                                    {-4,2,0,-2,-9,-1,-2,-5,-3,-4,-5,6,0},
                                    {-3,-2,-5,-7,-9,-2,-4,-6,-6,1,2,0,10},
                                    {-6,-7,-6,-10,-8,-9,-9,-7,-4,0,-1,-9,-2,8},
                                    {0,-2,-3,-4,-5,-1,-3,-3,-2,-5,-5,-4,-5,-7,7},
                                    {1,-1,1,-1,-1,-3,-2,0,-3,-4,-6,-2,-3,-4,0,5},
                                    {1,-4,0,-2,-5,-3,-3,-3,-4,-1,-4,-1,-2,-6,-2,2,6},
                                    {-9,0,-6,-10,-11,-8,-11,-10,-5,-9,-4,-7,-8,-2,-9,-3,-8,13},
                                    {-5,-7,-3,-7,-2,-8,-6,-9,-1,-4,-4,-7,-7,4,-9,-5,-4,-3,9},
                                    {-1,-5,-5,-5,-4,-4,-4,-3,-4,3,0,-6,0,-5,-3,-3,-1,-10,-5,6}};;

};

#endif // ANALISISVAR_H
