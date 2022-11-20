#include "archivos.h"

Archivos::Archivos()
{

}

void Archivos::cargarDatosADN(string nombreArchivo, vector<pair<string,string>> &secuencias)
{
    //ifstream archi;
    string aux;
    //string nombreArchivo="C:/ProgramasQT/OK178092.1 and 9 other sequences.aln"; //LEER POR FUERA
    archi.open(nombreArchivo);
    archi.ignore(1);
    getline(archi,aux,'>');
    while(!archi.eof())
    {
        pair<string,string> parAux;
        getline(archi,aux,'\n');
        parAux.first=aux.substr((aux.find("collection_date=")+16),10);
        if(isalpha(parAux.first[0]))
            parAux.first=formattearFecha(parAux.first);

        getline(archi,aux,'>');
        aux.pop_back();
        aux.pop_back();
        aux.erase(remove(aux.begin(), aux.end(), '\n'), aux.end());
        parAux.second=aux;
        secuencias.push_back(parAux);
    }
    sort(secuencias.begin(),secuencias.end());


}

string Archivos::formattearFecha(string &fecha)
{
    string retorno=fecha.substr(4,4)+"-"+to_string(meses[fecha.substr(0,3)])+"-"+"01";
    return retorno;
}

void Archivos::CargarDatosProteina(string nombreArchivo, vector<pair<string,string>>& secuencias) {
    ifstream archi;
    string aux;
//    vector<pair<string,string>>secuencias;
//    string nombreArchivo="C:/ProgramasQT/QKR84997.1_and_11_other_sequences.aln"; //LEER POR FUERA
    archi.open(nombreArchivo);
    pair<string,string> parAux;
    while(!archi.eof()) {
        getline(archi,aux,'\n');
        parAux.first=aux.substr((aux.find("collection_date=")+16),10);
        if(isalpha(parAux.first[0]))
            parAux.first=formattearFecha(parAux.first);

        getline(archi,aux,'>');
        aux.pop_back();
        aux.pop_back();
        aux.erase(remove(aux.begin(), aux.end(), '\n'), aux.end());
        parAux.second=aux;
        secuencias.push_back(parAux);
    }
    sort(secuencias.begin(),secuencias.end());    
}

void Archivos::cargarCasos(string nombre, string region, string info, vector<pair<string, int> > &vd)
{
    string aux="", f;
    int data=0, fecha=3;
    archi.open(nombre);
    if (archi.is_open()){
        getline(archi,aux,',');
        while (aux!=info){
            ++data;
            getline(archi,aux,',');
        }
        data=data-fecha;
        getline(archi,aux,'\n');
        while(aux[0]!=region[0]||aux[1]!=region[1]||aux[2]!=region[2]){
            getline(archi,aux,'\n');
        }
        while(aux[0]==region[0]&&aux[1]==region[1]&&aux[2]==region[2]){
            f=aux; f.erase(0,f.find('-',0)-4); f.erase(f.find('-',0)+6,f.size());
            aux.erase(0,aux.find('-',0)+7);
            for(int i=0;i<data-1;++i) {aux.erase(0,aux.find(',',0)+1);/*cout<<i<<": "<<aux<<endl;*/}
            aux.erase(aux.find(',',0),aux.size());
            if (aux.size()==0) aux="0";
            vd.push_back(pair<string,int>(f,(int)stoi(aux)));
            getline(archi,aux,'\n');
        }
        //for(int i=0;i<vd.size();++i) cout<<vd[i].first<<", "<<vd[i].second<<endl;
    }
}
