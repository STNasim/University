#include "hora.h"

Hora::Hora()
{

}

void Hora::IngresoHora(char HoraUsuario[])
{
    std::cout<<"Ingrese la hora en formato HH:MM:SS"<<std::endl;
    std::cin>>HoraUsuario;
}

int Hora::HoraMayorActual(char HoraUsuario[])
{
    CalcularHoraActual();
    int HorasUsuario=(HoraUsuario[0]-'0')*10+(HoraUsuario[1]-'0');
    int MinutosUsuario=(HoraUsuario[3]-'0')*10+(HoraUsuario[4]-'0');
    int SegundosUsuario=(HoraUsuario[6]-'0')*10+(HoraUsuario[7]-'0');
    int HorasActual=(HoraActual[0]-'0')*10+(HoraActual[1]-'0');
    int MinutosActual=(HoraActual[3]-'0')*10+(HoraActual[4]-'0');
    int SegundosActual=(HoraActual[6]-'0')*10+(HoraActual[7]-'0');

    if(HorasUsuario>HorasActual){
        std::cout<<"La Hora ingresada es mayor"<<std::endl;
        return 1;
    }
    if(HorasUsuario<HorasActual){
        std::cout<<"La Hora actual es mayor"<<std::endl;
        return 2;
    }
    if(HorasUsuario==HorasActual){
        if(MinutosUsuario>MinutosActual){
            std::cout<<"La Hora ingresada es mayor"<<std::endl;
            return 1;
        }
        if(MinutosUsuario<MinutosActual){
            std::cout<<"La Hora actual es mayor"<<std::endl;
            return 2;
        }
        if(MinutosUsuario==MinutosActual){
            if(SegundosUsuario>SegundosActual){
                std::cout<<"La Hora ingresada es mayor"<<std::endl;
                return 1;
            }
            if(SegundosUsuario<SegundosActual){
                std::cout<<"La Hora actual es mayor"<<std::endl;
                return 2;
            }
            if(MinutosUsuario==SegundosActual){
                std::cout<<"Las Hora son iguales"<<std::endl;
                return 0;
            }
        }
    }
return 5;
}

void Hora::DifHoraActual(char HoraUsuario[])
{
    CalcularHoraActual();
    int HorasUsuario=(HoraUsuario[0]-'0')*10+(HoraUsuario[1]-'0');
    int MinutosUsuario=(HoraUsuario[3]-'0')*10+(HoraUsuario[4]-'0');
    int SegundosUsuario=(HoraUsuario[6]-'0')*10+(HoraUsuario[7]-'0');
    int HorasActual=(HoraActual[0]-'0')*10+(HoraActual[1]-'0');
    int MinutosActual=(HoraActual[3]-'0')*10+(HoraActual[4]-'0');
    int SegundosActual=(HoraActual[6]-'0')*10+(HoraActual[7]-'0');
    int Ingreso;
    std::cout<<"Ingrese 1 para mostar diferencia en minutos o 0 para mostar en segundos"<<std::endl;
    std::cin>>Ingreso;
    while(Ingreso!=1 and Ingreso!=0){
        std::cout<<"Ingrese el valor nuevamente";
        std::cin>>Ingreso;
    }
    int HorasMayor;
    int MinutosMayor;
    int SegundosMayor;
    int HorasMenor;
    int MinutosMenor;
    int SegundosMenor;
    int Aux=HoraMayorActual(HoraUsuario);
    if(Aux==0){
            std::cout<<"No hay diferencia entre las horas";
            std::exit(0);
    }
    if(Aux==1){
        HorasMayor=HorasUsuario;
        MinutosMayor=MinutosUsuario;
        SegundosMayor=SegundosUsuario;
        HorasMenor=HorasActual;
        MinutosMenor=MinutosActual;
        SegundosMenor=SegundosActual;
    }
    if(Aux==2){
        HorasMayor=HorasActual;
        MinutosMayor=MinutosActual;
        SegundosMayor=SegundosActual;
        HorasMenor=HorasUsuario;
        MinutosMenor=MinutosUsuario;
        SegundosMenor=SegundosUsuario;
    }
    int DifHoras=HorasMayor-HorasMenor;
    int DifMinutos=MinutosMayor-MinutosMenor;
    int DifSegundos=SegundosMayor-SegundosMenor;
    if (DifSegundos<0){
        DifMinutos--;
        DifSegundos+=60;
    }
    if(DifMinutos<0){
        DifHoras--;
        DifMinutos+=60;
    }
    if(Ingreso==1)
        std::cout<<"La diferencia es de "<<DifMinutos+DifHoras*60<<" minutos"<<std::endl;
    if(Ingreso==0)
        std::cout<<"La diferencia es de "<<DifSegundos+DifMinutos*60+DifHoras*360<<std::endl;
}

void Hora::CalcularHoraActual()
{
    time_t Aux;
    tm TiempoActual;
    time (&Aux);
    TiempoActual = *localtime(&Aux);
    std::strftime (HoraActual,10,"%H:%M:%S",&TiempoActual);
}
