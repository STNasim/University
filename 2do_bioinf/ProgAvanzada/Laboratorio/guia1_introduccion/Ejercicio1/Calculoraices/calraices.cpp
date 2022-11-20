#include "calraices.h"

using namespace std;
calraices::calraices()
{

}

void calraices::LeerDatos()
{

    cout<<"Ingrese a, b y c"<<endl;
    cin>>a>>b>>c;
}

void calraices::CalculoRaices()
{
    float Dis=(b*b)-(4*a*c);
    if(Dis<0){
        Imaginarias=1;
        ParteReal2=ParteReal1=(-b)/(2*a);
        ParteImaginaria1=((sqrt(-Dis))/(2*a));
        ParteImaginaria2=(ParteImaginaria1*(-1));
    }
    else{
        Dis=sqrt(Dis);
        ParteReal1=(-b+Dis)/(2*a);
        ParteReal2=(-b-Dis)/(2*a);
    }
}

void calraices::MostrarDatos()
{
    if(Imaginarias==1){
        cout<<"Las raices son "<<ParteReal1<<"+";
        if(ParteImaginaria1>0)
            cout<<ParteImaginaria1<<"i "<<" y "<<ParteReal1<<ParteImaginaria2<<"i";
        else
            cout<<ParteImaginaria2<<"i "<<" y "<<ParteReal1<<ParteImaginaria1<<"i";
    }
    else{
        if(ParteReal1==ParteReal2)
            cout<<"La raiz es "<<ParteReal2<<" de orden 2";
        else
            cout<<"Las raices son: "<<ParteReal1<<" "<<ParteReal2;
    }

}
