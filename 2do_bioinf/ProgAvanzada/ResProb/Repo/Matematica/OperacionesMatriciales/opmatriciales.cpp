#include "opmatriciales.h"

OpMatriciales::OpMatriciales()
{

}

void OpMatriciales::Ingreso()
{
    float Aux;
    cout<<"Ingrese los datos, por filas ";
    for (int Fila=0;Fila<3;Fila++){
        for(int Columna=0;Columna<3;Columna++){
            cin>>Aux;
            Matriz[Fila][Columna]=Aux;
        }
    }
    IngresoDatos=1;
}

float OpMatriciales::Determinante()
{
    if(IngresoDatos==1){
        Det= (Matriz[0][0]*((Matriz[1][1]*Matriz[2][2])-(Matriz[2][1]*Matriz[1][2])));
        Det-= (Matriz[0][1]*((Matriz[1][0]*Matriz[2][2])-(Matriz[1][2]*Matriz[2][0])));
        Det+= (Matriz[0][2]*((Matriz[1][0]*Matriz[2][1])-(Matriz[1][1]*Matriz[2][0])));
        CalDet=1;
    }
    else
        if(Aviso==0){
            cout<<"No se han ingresado los datos";
            Aviso=1;
        }
    return Det;
}

float OpMatriciales::ValorMax()
{
    if(IngresoDatos==1){
        Vmax=Matriz[0][0];
            if(IngresoDatos==1){
                for(int Fila=0;Fila<3;Fila++)
                    for(int Columna=0;Columna<3;Columna++)
                        if(Matriz[Fila][Columna]>Vmax)
                            Vmax=Matriz[Fila][Columna];
                CalVmax=1;
            }
    }
    else
        if(Aviso==0){
            cout<<"No se han ingresado los datos";
            Aviso=1;
        }
    return Vmax;
}

void OpMatriciales::Transpuesta()
{
    if(IngresoDatos==1){
        for(int Fila=0;Fila<3;Fila++)
            for(int Columna=0;Columna<3;Columna++)
                Trans[Columna][Fila]=Matriz[Fila][Columna];
        CalTrans=1;
    }
    else
        if(Aviso==0){
            cout<<"No se han ingresado los datos";
            Aviso=1;
        }
}
void OpMatriciales::MostrarResultados()
{
    if(CalDet==1)
        cout<<"La Determinante de la matriz es "<<Det<<endl;
    if(CalVmax==1)
        cout<<"El valor maximo de la matriz es "<<Vmax<<endl;
    if(CalTrans==1){
        cout<<"La transpuesta es:"<<endl<<"[ ";
        for(int Fila=0;Fila<3;Fila++){
            if(Fila>0)
                cout<<"  ";
            for(int Columna=0;Columna<3;Columna++)
                cout<<Trans[Fila][Columna]<<" ";
            if(Fila==2)
                cout<<"]"<<endl;
            else
                cout<<endl;
        }
    }
}
