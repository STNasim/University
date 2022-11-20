#include "hotspots.h"
#include "ui_Hotspots.h"

Hotspots::Hotspots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hotspots)
{
    ui->setupUi(this);
}

void Hotspots::setup(string f1, string f2, vector<pair<string,string>> &hs)
{
    fechaIni=f1; fechaFin=f2;
    secuencias=hs;
    reng=9;
    ui->labelFechaIni->setText(QString::fromStdString(fechaIni));
    ui->labelFechaFin->setText(QString::fromStdString(fechaFin));
    ui->openGLWidget->setGraficoTipo(1);
}

vector<float> Hotspots::calcularHotspots(vector<pair<string,string>> sec)
{
    vector<float> res;
    res.resize(sec[0].second.size());
    set<char> aux;
    for(unsigned int i=0;i<sec[0].second.size();i++) {
        for(unsigned int j=0;j<sec.size();j++)
            if(sec[j].second[i]!='N') aux.insert(sec[j].second[i]);
        res[i]=(aux.size()==1)?(0):(aux.size()*1.0/(float)5);
        aux.clear();
    }
    return res;
}

void Hotspots::analizar()
{
    //analisis

    unsigned j,k, i2=0;
    findFecha(j,k);
    vector<pair<string,string>> secFecha;
    secFecha.resize(k-j);
    for(unsigned i=j;i<k;++i) {secFecha[i2]=secuencias[i]; ++i2;}
    vector<float> hs=calcularHotspots(secFecha);
    //reng=ui->spinBoxReng->value();
    ui->openGLWidget->loadHotspots(hs,reng);
    ui->openGLWidget->repaint();

    // Set TXT
    string txtL,txtR;
    int length=hs.size()/reng;
    txtL=""; txtR=txtL;
    for(int i=0;i<reng;++i){
        txtL+=to_string((i)*length)+'\n';
        txtR+=to_string((i+1)*length-1)+'\n';
    }
    if ((hs.size()%reng)!=0) {
        txtL+=to_string(reng*length);
        txtR+=to_string(hs.size());
    }
    ui->textInfoL->setText(QString::fromStdString(txtL));
    ui->textInfoR->setText(QString::fromStdString(txtR));
    QTextBlockFormat tb;
    tb.setLineHeight(100*ui->textInfoL->height()/(reng),QTextBlockFormat::ProportionalHeight);
    QTextCursor c=ui->textInfoR->textCursor();
    c.clearSelection();
    c.select(QTextCursor::Document);
    c.mergeBlockFormat(tb);
    c=ui->textInfoL->textCursor();
    c.clearSelection();
    c.select(QTextCursor::Document);
    tb.setAlignment(Qt::AlignRight);
    c.mergeBlockFormat(tb);

    int sum=0;
    for(unsigned i=0;i<hs.size();++i) {
        if (hs[i]>0) ++sum;
    }
    ui->labelTotalN->setText(QString::fromStdString(to_string(sum)));
}

Hotspots::~Hotspots()
{
    delete ui;
}

void Hotspots::findFecha(unsigned &j, unsigned &k)
{
    j=0; k=0;
    while(secuencias[j].first<fechaIni && j<secuencias.size()-1) ++j;
    while(secuencias[k].first<fechaFin && k<secuencias.size()-1) ++k;    
}

//void Hotspots::on_spinBoxReng_valueChanged(int arg1)
//{
//    reng=arg1;
//    cout<<arg1<<endl;
//    analizar();
//}
