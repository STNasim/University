#include "analisisvar.h"
#include "ui_AnalisisVar.h"

AnalisisVar::AnalisisVar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalisisVar)
{
    ui->setupUi(this);

}

AnalisisVar::~AnalisisVar()
{
    delete ui;
}

void AnalisisVar::setup(bool proteina, int mat, vector<pair<string, string>> &sec)
{
    this->proteina=proteina;
    matriz=mat;
    secuencias=sec;

    var=aplicarMatrizProteina();
    int min=*min_element(var.begin(),var.end());
    if(min<0){
        min*=-1;
        for(unsigned i=0;i<secuencias.size();++i){
            var[i]+=min;
        }
    }
    //for(unsigned i=0;i<var.size();++i)cout<<var[i]<<endl;

    analizar();
    ejeHorizontalIndice.resize(0);ejeHorizontalIndice.resize(secuencias.size());
    ejeHorizontalTiempo.resize(0);ejeHorizontalTiempo.resize(secuencias.size());
    ejeHorizontalPV.resize(0);ejeHorizontalPV.resize(secuencias.size());
    ejeHorizontalInf.resize(0);ejeHorizontalInf.resize(secuencias.size());
    for(unsigned i=0;i<ejeHorizontalIndice.size();++i) ejeHorizontalIndice[i]=i;
    getEjeTiempo(); getEjeProporcionV(); getEjeInfecciones();
    ui->openGLWidget->setGraficoTipo(0);
    ui->openGLWidget->loadAnalisis(var,ejeHorizontalIndice);

    setTable();
}

void AnalisisVar::analizar()
{
//    var.resize(0);
    switch(ui->comboBoxEjeX->currentIndex()){
    case 0: ui->openGLWidget->loadAnalisis(var,ejeHorizontalIndice);
        ui->comboBoxMarcaVert->setEnabled(false);
        ui->openGLWidget->setMarcaVertical(false);
        break;
    case 1: ui->openGLWidget->loadAnalisis(var,ejeHorizontalTiempo);
        ui->comboBoxMarcaVert->setEnabled(true);
        break;
    case 2: ui->openGLWidget->loadAnalisis(var,ejeHorizontalPV);
        ui->comboBoxMarcaVert->setEnabled(false);
        ui->openGLWidget->setMarcaVertical(false);
        break;
    case 3: ui->openGLWidget->loadAnalisis(var,ejeHorizontalInf);
        ui->comboBoxMarcaVert->setEnabled(false);
        ui->openGLWidget->setMarcaVertical(false);
        break;
    default: break;
    }    
    ui->openGLWidget->repaint();
}

void AnalisisVar::on_comboBoxEjeX_currentIndexChanged(const QString &arg1)
{
    ui->label_ejeX->setText(arg1);
    analizar();
}

void AnalisisVar::getEjeTiempo()
{
    string aux; int val,temp;
    for(unsigned i=0;i<secuencias.size();++i){
        //aux=secuencias[i].first;
        //aux.erase(remove(aux.begin(), aux.end(), '-'), aux.end());
        //ejeHorizontalTiempo[i]=stoi(aux);
        aux=secuencias[i].first.substr(0,4);
        val=stoi(aux);
        temp=(val-1900)*365;
        aux=secuencias[i].first.substr(5,7);
        val=stoi(aux);
        temp+=val*30;
        aux=secuencias[i].first.substr(8,10);
        val=stoi(aux);
        temp+=val;
        ejeHorizontalTiempo[i]=temp;
    }
    int min=ejeHorizontalTiempo[0];
    for(unsigned i=0;i<ejeHorizontalTiempo.size();++i){
        ejeHorizontalTiempo[i]-=min;
    }
//    unsigned min=ejeHorizontalTiempo[0];
//    for(unsigned i=0;i<secuencias.size();++i){
//        ejeHorizontalTiempo[i]=(ejeHorizontalTiempo[i]-min)*1.0/1000;
//    }
}

void AnalisisVar::getEjeProporcionV()
{
    Archivos ar;
    string nombre="..\\owid-covid-data.csv";
    vector<pair<string, int>> fechas;
    ar.cargarCasos(nombre,"ARG","total_vaccinations",fechas);
    vector<string> f;
    for(unsigned i=0;i<secuencias.size();++i) f.push_back(secuencias[i].first);
    unsigned c=0;
    auto it=std::find(f.begin(),f.end(),fechas[0].first);
    for(unsigned i=0;i<fechas.size();++i){
        it=std::find(f.begin(),f.end(),fechas[i].first);
        if (it!=f.end()){
            ejeHorizontalPV[c]=(fechas[i].second==0?(i==0?0:fechas[i-1].second):fechas[i].second);
            ++c;
        }
    }
    for(unsigned i=c;i<ejeHorizontalPV.size();++i) ejeHorizontalPV[i]=ejeHorizontalPV[c-1];
    unsigned min=*min_element(ejeHorizontalPV.begin(),ejeHorizontalPV.end());
    for(unsigned i=0;i<secuencias.size();++i){
        ejeHorizontalPV[i]=(ejeHorizontalPV[i]-min);
    }
}

void AnalisisVar::getEjeInfecciones()
{
    Archivos ar;
    string nombre="..\\owid-covid-data.csv";
    vector<pair<string, int>> fechas;
    ar.cargarCasos(nombre,"ARG","total_cases",fechas);
    vector<string> f;
    for(unsigned i=0;i<secuencias.size();++i) f.push_back(secuencias[i].first);
    unsigned c=0;
    auto it=std::find(f.begin(),f.end(),fechas[0].first);
    for(unsigned i=0;i<fechas.size();++i){
        it=std::find(f.begin(),f.end(),fechas[i].first);
        if (it!=f.end()){
            ejeHorizontalInf[c]=(fechas[i].second==0?(i==0?0:fechas[i-1].second):fechas[i].second);
            //cout<<"I: "<<ejeHorizontal[c]<<endl;
            ++c;
        }
    }
    for(unsigned i=c;i<ejeHorizontalInf.size();++i) ejeHorizontalInf[i]=ejeHorizontalInf[c-1];
    unsigned min=*min_element(ejeHorizontalInf.begin(),ejeHorizontalInf.end());
    for(unsigned i=0;i<secuencias.size();++i){
        ejeHorizontalInf[i]=(ejeHorizontalInf[i]-min);
    }
}


vector<int> AnalisisVar::aplicarMatrizProteina(/*vector<pair<string,string>> secuencias*/)
{
    vector<int> variabilidad;
    variabilidad.resize(secuencias.size(),0);
    for(unsigned int i=0;i<secuencias[0].second.size();i++)
        for(unsigned int j=1;j<secuencias.size();j++)
            if(secuencias[j].second[i]!=secuencias[0].second[i]
                    and secuencias[j].second[i]!='X') {
                //cout<<"Sec: "+to_string(j)+" lugar: "+to_string(i)+"\n";
                variabilidad[j]+=calcularVariabilidad(indices[secuencias[j].second[i]],indices[secuencias[0].second[i]]);
            }

    return variabilidad;
}

int AnalisisVar::calcularVariabilidad(int indice_1, int indice_2)
{
    if (indice_2>indice_1)
        swap(indice_1,indice_2);
    if (matriz==0)
        return (indice_1==indice_2?0:1);
    else if(matriz==1)
        return PAM70[indice_1][indice_2];
    else return 0;
}

void AnalisisVar::setTable()
{
    for(unsigned i=0;i<secuencias.size();++i){
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        QTableWidgetItem *it1 = new QTableWidgetItem(QString::fromStdString(to_string(var[i])));
        it1->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,0,it1);
        QTableWidgetItem *it2 = new QTableWidgetItem(QString::fromStdString(secuencias[i].first));
        it2->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,1,it2);
        QTableWidgetItem *it3 = new QTableWidgetItem(QString::fromStdString(to_string((int)ejeHorizontalInf[i])));
        it3->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,2,it3);
        QTableWidgetItem *it4 = new QTableWidgetItem(QString::fromStdString(to_string((int)ejeHorizontalPV[i])));
        it4->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,3,it4);
    }
}

void AnalisisVar::on_comboBoxMarcaVert_currentIndexChanged(int index)
{
    Archivos ar;
    string nombre="..\\owid-covid-data.csv";
    vector<pair<string, int>> fechas;
    if(index==1) ar.cargarCasos(nombre,"ARG","total_vaccinations",fechas);
    else if (index==2) ar.cargarCasos(nombre,"ARG","total_cases",fechas);
    if (index!=0){
        string aux; int val,temp,c=100;
        vector<float> v;
        for(unsigned i=1;i<fechas.size();++i){
            if (fechas[i].second > c){
                c*=10;
//                aux=fechas[i].first;
//                aux.erase(remove(aux.begin(), aux.end(), '-'), aux.end());
//                v.push_back(stoi(aux));
                aux=fechas[i].first.substr(0,4);
                val=stoi(aux);
                temp=(val-1900)*365;
                aux=fechas[i].first.substr(5,7);
                val=stoi(aux);
                temp+=val*30;
                aux=fechas[i].first.substr(8,10);
                val=stoi(aux);
                temp+=val;
                v.push_back(temp);
            }
        }
        //cout<<v.size()<<endl;
        if (v.size()>0){
            int min=v[0];
            for(unsigned i=0;i<v.size();++i){
                v[i]-=min;
            }
    //        aux=secuencias[0].first;
    //        aux.erase(remove(aux.begin(), aux.end(), '-'), aux.end());
    //        float min=stoi(aux);
    //        for(unsigned i=0;i<v.size();++i){
    //            v[i]=(v[i]-min)*1.0/1000;
    //        }
            ui->openGLWidget->loadMarcaVertical(v);
            ui->openGLWidget->setMarcaVertical(true);
            ui->openGLWidget->repaint();
        }
    }
}
