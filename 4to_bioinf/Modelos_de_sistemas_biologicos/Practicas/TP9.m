clear all; 
clc;
close all;

agentes = struct('posicion',[0,0],'velocidad',[0,0]);
agentes_futuros=agentes;
wa=0.1; ws=0.1; wc=0.1;
roa=4; ros=0.5; roc=4;
v_max=2;
N=20;
x_max=100; y_max=100;
p=1/1000;
t=5;
for i=1:N
    agentes(i).posicion=[rand()*x_max,rand()*y_max]; %para aque incialice entre cero y la posicion maxima
    agentes(i).velocidad=[rand()*5,rand()*5];
end

for i=2:(t/p)
    %calculo de matriz de distancias
    distancias=zeros(N);
    for j=1:N
        for k=(j+1):N
            distancias(j,k)=sqrt((agentes(j).posicion(1)-agentes(k).posicion(1))^2+(agentes(j).posicion(2)-agentes(k).posicion(2))^2);
            distancias(k,j)=distancias(j,k);
        end
    end
    for j=1:N
        a=[0,0];
        s=[0,0];
        c=[0,0];
        vecindad=-1;
        for k=1:N
           if(k~=j && distancias(k,j)<=roa)
               vecindad=cat(1,vecindad,k);%concatena el indice de los vecinos en fila
           end
        end
        [tam_x,tam_y]=size(vecindad);
        if tam_x>1
            %para calcular promedio de la diferencia de velocidades (calculo de a) a partir de
            %los vecinos
            for k=2:size(vecindad)
               a(1)=a(1)+(agentes(k).velocidad(1)-agentes(j).velocidad(1));
               a(2)=a(2)+(agentes(k).velocidad(2)-agentes(j).velocidad(2));
            end
            a(1)=a(1)/(tam_x-1);
            a(2)=a(2)/(tam_x-1);
        end
        vecindad=-1;
        for k=1:N
           if(k~=j && distancias(k,j)<=roc)
               vecindad=cat(1,vecindad,k);%concatena el indice de los vecinos en fila
           end
        end
        if size(vecindad)>1
            %para calcular el promedio de diferencia la posicion (calculo de c) a partir de
            %los vecinos
            for k=2:size(vecindad)
               c(1)=c(1)+(agentes(k).posicion(1)-agentes(j).posicion(1));
               c(2)=c(2)+(agentes(k).posicion(2)-agentes(j).posicion(2));
            end
            c(1)=c(1)/(size(vecindad)-1);
            c(2)=c(2)/(size(vecindad)-1);
        end
        vecindad=-1;
        for k=1:N
           if(k~=j && distancias(k,j)<=ros)
               vecindad=cat(1,vecindad,k);%concatena el indice de los vecinos en fila
           end
        end
        if size(vecindad)>1
            s=[0,0];
            %para calcular promedio de la diferencia de velocidades (calculo de s) a partir de
            %los vecinos
            for k=2:size(vecindad)
               s(1)=s(1)+(agentes(j).posicion(1)-agentes(k).posicion(1));
               s(2)=s(2)+(agentes(j).posicion(2)-agentes(k).posicion(2));
            end
            s(1)=s(1)/(size(vecindad)-1);
            s(2)=s(2)/(size(vecindad)-1);
        end   
        agentes_futuros(j).velocidad(1)=agentes(j).velocidad(1)+wa*a(1)+ws*s(1)+wc*c(1);
        agentes_futuros(j).velocidad(2)=agentes(j).velocidad(2)+wa*a(2)+ws*s(2)+wc*c(2);
        if agentes_futuros(j).velocidad(1)>v_max 
            agentes_futuros(j).velocidad(1)=v_max;
        end
        if agentes_futuros(j).velocidad(1)<-v_max 
            agentes_futuros(j).velocidad(1)=-v_max;
        end
        if agentes_futuros(j).velocidad(2)>v_max 
            agentes_futuros(j).velocidad(2)=v_max;
        end
        if agentes_futuros(j).velocidad(2)<-v_max 
            agentes_futuros(j).velocidad(2)=-v_max;
        end
        agentes_futuros(j).posicion(1)=agentes(j).posicion(1)+agentes_futuros(j).velocidad(1);
        agentes_futuros(j).posicion(2)=agentes(j).posicion(2)+agentes_futuros(j).velocidad(2);
        if agentes_futuros(j).posicion(1)>x_max
            agentes_futuros(j).posicion(1)=x_max;
            agentes_futuros(j).velocidad(1)= agentes_futuros(j).velocidad(1)*-1;
        end
        if agentes_futuros(j).posicion(2)>y_max
            agentes_futuros(j).posicion(2)=y_max;
            agentes_futuros(j).velocidad(2)= agentes_futuros(j).velocidad(2)*-1;
        end
        if agentes_futuros(j).posicion(1)<0
            agentes_futuros(j).posicion(1)=0;
            agentes_futuros(j).velocidad(1)= agentes_futuros(j).velocidad(1)*-1;
        end
        if agentes_futuros(j).posicion(2)<0
            agentes_futuros(j).posicion(2)=0;
            agentes_futuros(j).velocidad(2)= agentes_futuros(j).velocidad(2)*-1;
        end 

    end
    agentes=agentes_futuros;
    for j=1:N
        plot(agentes(j).posicion(1),agentes(j).posicion(2),'mp');
        hold on
        xlim([0,x_max]);
        ylim([0,y_max]);
    end
    pause(p);
    hold off;
end
