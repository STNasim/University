#include <QCoreApplication>
#include "../../../Repo/Algoritmos/AlgoritmosDeOrdenamientoBasico/OrdenamientosBasicos.h"
#include "../../Ejer08/GenDatosAleatorios/GeneradorDatosAleatorios.h"
#include "../../../Ejemplos/Ejemplo_medicion_tiempos_ejecucion/cronometro.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Parametros
    unsigned int repeticiones=1000;
    double t_burbuja_total=0;
    double t_seleccion_total=0;
    double t_insercion_total=0;
    unsigned int cantidad=10;
    vector <long> datos;
    fstream escritura;
    ifstream lectura;
    Cronometro tiempo;

    escritura.open("../Resultados.csv", ios::trunc|ios::out);

    for(int w=0;w<3;w++)
    {
        if(w==0)
        {
            escritura<<";;Tiempos de ordenamiento en segundos";
            escritura<<"\nCaracteristicas de los datos;Cantidad de datos a ordenar;Burbuja;Seleccion;Insercion";
            escritura<<"\n1) Desordenados con distribucion uniforme";
        }
        if(w==1)
            escritura<<"2) Desordenados con distribucion normal";
        if(w==2)
            escritura<<"3) Casi-ordenados";
        for(;cantidad<=100000;cantidad*=10)
        {
            t_burbuja_total=0;
            t_seleccion_total=0;
            t_insercion_total=0;
            string auxiliar;
            auxiliar.clear();

            if(cantidad==10)
                repeticiones=100000;
            if(cantidad==100)
                repeticiones=5000;
            if(cantidad==1000)
                repeticiones=1000;
            if(cantidad==10000)
                repeticiones=15;
            if(cantidad==100000)
                repeticiones=1;
            datos.resize(cantidad);
            for(unsigned int i=0;i<repeticiones;i++)
            {
                if(w==0)
                    GenerarDesordenadosUniforme(cantidad);
                if(w==1)
                    GenerarDesordenadosNormal(cantidad);
                if(w==2)
                    GenerarQuasiOrdenados(cantidad);
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

                vector<long> datosBurbuja=datos;
                tiempo.iniciarCronometro();
                ord_burbuja(datosBurbuja);
                tiempo.pararCronometro();
                t_burbuja_total+=tiempo.getDuracionEnSegundos();

                vector<long> datosSeleccion=datos;
                tiempo.iniciarCronometro();
                ord_seleccion(datosSeleccion);
                tiempo.pararCronometro();
                t_seleccion_total+=tiempo.getDuracionEnSegundos();

                tiempo.iniciarCronometro();
                ord_insercion(datos);
                tiempo.pararCronometro();
                t_insercion_total+=tiempo.getDuracionEnSegundos();
            }
            t_burbuja_total/=repeticiones;
            t_seleccion_total/=repeticiones;
            t_insercion_total/=repeticiones;

            auxiliar=";"+(to_string(cantidad))+";"+(to_string(t_burbuja_total))+";"+(to_string(t_seleccion_total))+
                     ";"+(to_string(t_insercion_total))+"\n";
            while(auxiliar.find('.')!=string::npos)
            {
                auxiliar.replace(auxiliar.find('.'),1,",");
            }
            escritura<<auxiliar;
        }
        cantidad=10;
    }
    cout<<"Finalizado";
    escritura.close();
    return a.exec();
}
