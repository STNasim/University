#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hotspots.h"
#include "analisisvar.h"
#include "archivos.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAnalizarVar_clicked();

    void on_pushButtonHotSpots_clicked();

    void on_pushButtonCargar_clicked();

private:
    Ui::MainWindow *ui;
    vector<pair<string,string>> secuencias;
    vector<pair<string,string>> secuenciasP;
};
#endif // MAINWINDOW_H
