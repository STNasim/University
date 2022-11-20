#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonCargar_clicked()
{
    Archivos ar;
    string nombre=ui->lineNArchivo->text().toStdString();
    ar.cargarDatosADN(nombre,secuencias);
    string info;
    info="Cantidad de Secuencias: ";
    info+=to_string((secuencias.begin()==secuencias.end()?(0):(secuencias.size())))+'\n';
    info+="Tamaño: ";
    info+=to_string(secuencias[0].second.size())+" pb\n";
    info+="\nInformación por Secuencia: \n\n\tFecha\n";
    for(unsigned i=0;i<secuencias.size();++i){
        info+=to_string(i+1)+":\t"+secuencias[i].first+'\n';
    }

    ui->textBrowserInfo->setText(QString::fromStdString(info));
}

void MainWindow::on_pushButtonAnalizarVar_clicked()
{
    Archivos ar;
    ar.CargarDatosProteina(ui->lineNArchivo_2->text().toStdString(),secuenciasP);
    AnalisisVar av;
    av.setup(ui->radioButtonTraducir->isChecked(),ui->comboBoxMatriz->currentIndex(),
              secuenciasP);
    av.exec();
}

void MainWindow::on_pushButtonHotSpots_clicked()
{
    Hotspots hs;
    string f_ini=ui->lineEditFechaIni->text().toStdString()
            , f_fin = ui->lineEditFechaFin->text().toStdString();
    vector<string> sec;
    //auto itb=find(secuencias.begin(),secuencias.end(),f_ini);
    //copy(secuencias.find(f_ini));
    hs.setup(f_ini,f_fin,secuencias);
    hs.analizar();
    hs.exec();
}
