#include <QCoreApplication>
#include "../../../Repo/Algoritmos/BusquedaDicotomica/BusquedaDicotomica.h"
#include "../../Ejer08/GenDatosAleatorios/GeneradorDatosAleatorios.h"
#include "../../../Ejemplos/Ejemplo_medicion_tiempos_ejecucion/cronometro.h"
#include <random>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Parametros
    unsigned int repeticiones=1000000;
    double t_lin_total=0;
    double t_dic_total=0;
    unsigned int cantidad=10;
    vector <long> datos;
    fstream escritura;
    ifstream lectura;
    Cronometro tiempo;
    default_random_engine generador(time(0));
    normal_distribution<double> dist_norm(0,500000000);

    escritura.open("../Resultados.csv", ios::trunc|ios::out);

    escritura<<";;Tiempos de busqueda\n";
    escritura<<"Caracteristicas de los datos;Cantidad N de datos a ordenar;Lineal;Dicotomica\n";
    escritura<<"Ordenados de mayor a menor;";

    for(;cantidad<=1000000;cantidad*=10)
    {
        t_lin_total=0;
        t_dic_total=0;
        GenerarOrdenados(cantidad);
        string auxiliar;
        auxiliar.clear();

        bool optimizar=true;
        if(cantidad<10000)
            optimizar=false;
        if(optimizar)
            repeticiones/=10;
        else
            optimizar=true;

        datos.resize(cantidad);

        lectura.open("../Datos.bin",ios::binary);
        if(lectura.is_open())
        {
            char car;

            lectura.read(&car,sizeof(char));
            if(car==1)
            {
                cout<<"Existen datos repetidos"<<endl;
            }
            else
                cout<<"No hay datos repetidos"<<endl;

            lectura.read(&car,sizeof(char));

            int lec;
            lectura.read((char*)&lec,sizeof(lec));

            cout<<"Hay "<<lec<<" datos"<<endl;
            long extraccion;
            for(int i=0;i<lec;i++)
            {
                lectura.read((char*)&extraccion,sizeof(extraccion));
                datos[i]=extraccion;
            }
        }
        lectura.close();

        for(unsigned i=0;i<repeticiones;i++)
        {
            long objetivo=dist_norm(generador);
            bool encontrado=false;
            tiempo.iniciarCronometro();
            for(unsigned int j=0;j<cantidad && !encontrado;j++)
            {
                if(datos[j]==objetivo)
                    encontrado=true;
            }
            tiempo.pararCronometro();
            t_lin_total+=tiempo.getDuracionEnSegundos();
        }
        t_lin_total=(t_lin_total*1000)/(double)repeticiones;

        for(unsigned i=0;i<repeticiones;i++)
        {
            long objetivo=dist_norm(generador);
            tiempo.iniciarCronometro();
            busqueda_dicotomica_Vector(datos,objetivo);
            tiempo.pararCronometro();
            t_dic_total+=tiempo.getDuracionEnSegundos();
        }
        t_dic_total=(t_dic_total*1000)/(double)repeticiones;

        auxiliar=(to_string(cantidad))+";"+(to_string(t_lin_total))+";"+(to_string(t_dic_total))+"\n;";
        while(auxiliar.find('.')!=string::npos)
        {
            auxiliar.replace(auxiliar.find('.'),1,",");
        }
        escritura<<auxiliar;
    }
    escritura.close();
    cout<<"Finalizado";
    return a.exec();
}
