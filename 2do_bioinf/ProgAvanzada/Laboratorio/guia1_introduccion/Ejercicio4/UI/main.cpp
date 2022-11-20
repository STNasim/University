#include <QCoreApplication>
#include <iostream>
#include <promydesv.h>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int b=0;
    bool v=0;
    PromyDesv op;
    while(b!=99){
        cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl<<"::::::::::::::::::::::: BIENVENIDO :::::::::::::::::::::::"<<endl<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        cout<<"::"<<" "<<"OPCIONES"<<" "<<"::"<<endl;
        cout<<"  "<<"1: Ingresar los datos a procesar."<<endl;
        cout<<"  "<<"2: Encontrar el promedio de los valores."<<endl;
        cout<<"  "<<"3: Encontrar el desvio estandar."<<endl;
        cout<<"  "<<"4: Borrar todos los datos."<<endl;
        cout<<" "<<"99: Salir"<<endl;
        cin>>b;
        float *m;
        int p=5;
        float prom=0;
        float desv=0;
        if (b==1){
        if(v==0){
//            cout<<"Ingrese la cantidad de datos"<<endl;
//            cin>>p;
            m= new float[p];
            cout<<"Ingrese los datos"<<endl;
            for(int k=0;k<p;k++){
                float h;
                cin>>h;
                m[k]=h;
            }
            v=1;
        }
            else{
                cout<<"Ya se han ingresado datos"<<endl;
            }
        }

        if (b==2){
            if(v==1){
        prom=op.P(m,p);
        cout<<"El promedio de los valores es: "<<prom<<endl;
        }
        else
            cout<<"No hay datos ingresados"<<endl;
        }
        if (b==3){
            if(v==1){
            desv=op.DP(m,p);
            cout<<"El desvio es de: "<<desv<<endl;
            }
        else
            cout<<"No hay datos ingresados"<<endl;
        }
        if (b==4){
            if(v==1){
                delete m;
                v=0;
            }
            else{
                cout<<"No se han ingresado datos"<<endl;
            }
        }

        if (b==99){
            delete m;
            cout<<"El programa ha finalizado"<<endl;
        }

        if (b!=1 and b!=2 and b!=3 and b!=4 and b!=99){
            cout<<"Numero invalido, ingrese nuevamente"<<endl;
        }
    }
    return a.exec();
}
