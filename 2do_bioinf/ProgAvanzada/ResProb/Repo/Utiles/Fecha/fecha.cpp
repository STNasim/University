#include "fecha.h"

Fecha::Fecha()
{

}

void Fecha::IngresoFecha(char FechaUsuario[])
{
    std::cout<<"Ingrese la fecha en formato DD/MM/AAAA"<<std::endl;
    std::cin>>FechaUsuario;
    while(FechaUsuario[2]!='/' and FechaUsuario[5]!='/'){
        std::cout<<"Ingrese los datos nuevamente"<<std::endl;
        std::cin>>FechaUsuario;
    }
}

int Fecha::FechaMayorActual(char FechaUsuario[])
{
    CalcularFechaActual();
    int DiaUsuario=(FechaUsuario[0]-'0')*10+(FechaUsuario[1]-'0');
    int MesUsuario=(FechaUsuario[3]-'0')*10+(FechaUsuario[4]-'0');
    int AnioUsuario=(FechaUsuario[6]-'0')*1000+(FechaUsuario[7]-'0')*100+(FechaUsuario[8]-'0')*10+(FechaUsuario[9]-'0');
    int DiaActual=(FechaActual[0]-'0')*10+(FechaActual[1]-'0');
    int MesActual=(FechaActual[3]-'0')*10+(FechaActual[4]-'0');
    int AnioActual=(FechaActual[6]-'0')*1000+(FechaActual[7]-'0')*100+(FechaActual[8]-'0')*10+(FechaActual[9]-'0');

    if(AnioUsuario>AnioActual){
        std::cout<<"La fecha ingresada es mayor"<<std::endl;
        return 1;
    }
    if(AnioUsuario<AnioActual){
        std::cout<<"La fecha actual es mayor"<<std::endl;
        return 2;
    }
    if(AnioUsuario==AnioActual){
        if(MesUsuario>MesActual){
            std::cout<<"La fecha ingresada es mayor"<<std::endl;
            return 1;
        }
        if(MesUsuario<MesActual){
            std::cout<<"La fecha actual es mayor"<<std::endl;
            return 2;
        }
        if(MesUsuario==MesActual){
            if(DiaUsuario>DiaActual){
                std::cout<<"La fecha ingresada es mayor"<<std::endl;
                return 1;
            }
            if(DiaUsuario<DiaActual){
                std::cout<<"La fecha actual es mayor"<<std::endl;
                return 2;
            }
            if(DiaUsuario==DiaActual){
                std::cout<<"Las fechas son iguales"<<std::endl;
                return 0;
            }
        }
    }
return 5;
}

void Fecha::DifFechaActual(char FechaUsuario[])
{
    CalcularFechaActual();
    int DiaUsuario=(FechaUsuario[0]-'0')*10+(FechaUsuario[1]-'0');
    int MesUsuario=(FechaUsuario[3]-'0')*10+(FechaUsuario[4]-'0');
    int AnioUsuario=(FechaUsuario[6]-'0')*1000+(FechaUsuario[7]-'0')*100+(FechaUsuario[8]-'0')*10+(FechaUsuario[9]-'0');
    int DiaActual=(FechaActual[0]-'0')*10+(FechaActual[1]-'0');
    int MesActual=(FechaActual[3]-'0')*10+(FechaActual[4]-'0');
    int AnioActual=(FechaActual[6]-'0')*1000+(FechaActual[7]-'0')*100+(FechaActual[8]-'0')*10+(FechaActual[9]-'0');

    int Ingreso;
    std::cout<<"Ingrese 1 para mostar diferencia en anios,meses,dias o 0 para mostar en dias"<<std::endl;
    std::cin>>Ingreso;
    while(Ingreso!=1 and Ingreso!=0){
        std::cout<<"Ingrese el valor nuevamente"<<std::endl;
        std::cin>>Ingreso;
    }
    int AnioMayor;
    int MesMayor;
    int DiaMayor;
    int AnioMenor;
    int MesMenor;
    int DiaMenor;
    int Aux=FechaMayorActualReturn(FechaUsuario);
    if(Aux==0){
            std::cout<<"No hay diferencia entre las fechas"<<std::endl;
    }
    if(Aux==1){
        AnioMayor=AnioUsuario;
        MesMayor=MesUsuario;
        DiaMayor=DiaUsuario;
        AnioMenor=AnioActual;
        MesMenor=MesActual;
        DiaMenor=DiaActual;
    }
    if(Aux==2){
        AnioMayor=AnioActual;
        MesMayor=MesActual;
        DiaMayor=DiaActual;
        AnioMenor=AnioUsuario;
        MesMenor=MesUsuario;
        DiaMenor=DiaUsuario;
    }
    if(Aux!=0 or Aux!=5){
        int DifAnios=AnioMayor-AnioMenor;
        int DifMeses=MesMayor-MesMenor;
        int DifDias=DiaMayor-DiaMenor;
        if (DifDias<0){
            DifMeses--;
            if(MesMayor!=1)
                DifDias+=DiasMes[MesMayor-2];
            else
                DifDias+=DiasMes[11];
        }
        if(DifMeses<0){
            DifAnios--;
            DifMeses+=12;
        }
        if(Ingreso==1){
            //DifDias+=DifAnios/4;
            std::cout<<"La diferencia es de "<<DifAnios<<" anios "<<DifMeses<<" meses "<<DifDias<<" dias"<<std::endl;
        }
        if(Ingreso==0){
            int DifTotal=(365*3+366)*(DifAnios/4);
            DifTotal+=(DifAnios%4)*365;

            if((MesMayor>MesMenor and (DiaMayor-DiaMenor)>=0) or (MesMayor>MesMenor+1)){
                for(int z=0;z<DifMeses;z++)
                    DifTotal+=DiasMes[MesMenor-1+z];
            }
            if((MesMayor<MesMenor) or ((MesMayor==MesMenor) and (DiaMayor<DiaMenor))){
                for(int z=MesMenor;z<13;z++)
                    DifTotal+=DiasMes[z-1];
                if(MesMayor==1)
                    DifTotal-=DiasMes[0];
                for (int z=1;z<MesMayor-1;z++)
                    DifTotal+=DiasMes[z-1];
            }
            DifTotal+=DifDias;
            std::cout<<"La diferencia en dias es de "<<DifTotal;
        }
    }
}

void Fecha::CalcularFechaActual()
{
    time_t Aux;
    tm TiempoActual;
    time (&Aux);
    TiempoActual = *localtime(&Aux);
    std::strftime (FechaActual,11,"%d/%m/%Y",&TiempoActual);
}

int Fecha::FechaMayorActualReturn(char FechaUsuario[])
{
        int DiaUsuario=(FechaUsuario[0]-'0')*10+(FechaUsuario[1]-'0');
        int MesUsuario=(FechaUsuario[3]-'0')*10+(FechaUsuario[4]-'0');
        int AnioUsuario=(FechaUsuario[6]-'0')*1000+(FechaUsuario[7]-'0')*100+(FechaUsuario[8]-'0')*10+(FechaUsuario[9]-'0');
        int DiaActual=(FechaActual[0]-'0')*10+(FechaActual[1]-'0');
        int MesActual=(FechaActual[3]-'0')*10+(FechaActual[4]-'0');
        int AnioActual=(FechaActual[6]-'0')*1000+(FechaActual[7]-'0')*100+(FechaActual[8]-'0')*10+(FechaActual[9]-'0');

        if(AnioUsuario>AnioActual)
            return 1;
        if(AnioUsuario<AnioActual)
            return 2;
        if(AnioUsuario==AnioActual){
            if(MesUsuario>MesActual)
                return 1;
            if(MesUsuario<MesActual)
                return 2;
            if(MesUsuario==MesActual){
                if(DiaUsuario>DiaActual)
                    return 1;
                if(DiaUsuario<DiaActual)
                    return 2;
                if(DiaUsuario==DiaActual)
                    return 0;
            }
        }
    return 5;
}
