clear all;
clc;
close all;
load('G:\Mi unidad\Facultad\4to anio\Modelos de sistemas biologicos\Practicas\secuencias.mat');

%%
%Ejercicio 1

sec=sec_decodificacion{1, 1}.salidas;
be1=[0.3,0.3,0.2,0.2];
be2=[0.1,0.1,0.4,0.4];
prob=zeros(2,1000);
cam=zeros(2,1000);
prob(1,1)=be1(sec(1))*0.57;
prob(2,1)=be2(sec(1))*0.43;

for k=2:1000
    
    [valmax,indmax]=max([prob(1,k-1)*0.995,prob(2,k-1)*0.005]);
    prob(1,k)=be1(sec(k))*valmax;
    cam(1,k)=indmax;
    
    [valmax,indmax]=max([prob(1,k-1)*0.01,prob(2,k-1)*0.99]);
    prob(2,k)=be2(sec(k))*valmax;
    cam(2,k)=indmax;
    %En caso de que la probabilidad baje mucho
    if prob(1,k)<10^-300 || prob(2,k)<10^-300
        prob(2,k)=prob(2,k)*10^300;
        prob(1,k)=prob(1,k)*10^300;
    end
end

%backtracking
camino_probable=zeros(1,1000);
[probabilidad_final,camino_probable(1000)]=max([prob(1,1000),prob(2,1000)]);
for i=999:-1:1
    camino_probable(i)=cam(camino_probable(i+1),i);
end

%%
sec=sec_aprendizaje{1, 1}.salidas;
est=sec_aprendizaje{1, 1}.estados;

%Estimar A

be1=[0.3,0.3,0.2,0.2];
be2=[0.1,0.1,0.4,0.4];
prob=zeros(2,1000);
cam=zeros(2,1000);
prob(1,1)=be1(sec(1))*0.57;
prob(2,1)=be2(sec(1))*0.43;

%Calculo de transiciones totales
% trans_totales_11=0;
% trans_totales_12=0;
% trans_totales_21=0;
% trans_totales_22=0;
% 
% for j=2:999
%     if est1(j)==1
%         if est1(j+1)==1
%             trans_totales_11=trans_totales11+1;
%         else
%         trans_totales_12=trans_totales12+1;
%         end
%     else
%         if est1(j+1)==1
%             trans_totales_21=trans_totales21+1;
%         else
%         trans_totales_22=trans_totales22+1;
%         end
%     end
% end       

a11=0.5;
a12=1-a11;
a21=0.5;
a22=1-a21;

error=1;

while 1
    for k=2:1000

        [valmax,indmax]=max([prob(1,k-1)*a11,prob(2,k-1)*a12]);
        prob(1,k)=be1(sec(k))*valmax;
        cam(1,k)=indmax;

        [valmax,indmax]=max([prob(1,k-1)*a21,prob(2,k-1)*a22]);
        prob(2,k)=be2(sec(k))*valmax;
        cam(2,k)=indmax;
        %En caso de que la probabilidad baje mucho
        if prob(1,k)<10^-300 || prob(2,k)<10^-300
            prob(2,k)=prob(2,k)*10^300;
            prob(1,k)=prob(1,k)*10^300;
        end
    end

    %backtracking
    camino_probable=zeros(1,1000);
    [probabilidad_final,camino_probable(1000)]=max([prob(1,1000),prob(2,1000)]);
    for i=999:-1:1
        camino_probable(i)=cam(camino_probable(i+1),i);
    end
    
    %calculo de error
    cant_1=0;
    cant_2=0;
    trans_11=0;
    trans_12=0;
    trans_21=0;
    trans_22=0;
    
    for j=2:999        
        if camino_probable(j)==1
            if camino_probable(j+1)==1
                trans_11=trans_11+1;
            else
            trans_12=trans_12+1;
            end
            cant_1=cant_1+1;
        else
            if camino_probable(j+1)==1
                trans_21=trans_21+1;
            else
            trans_22=trans_22+1;
            end
            cant_2=cant_2+1;
        end
    end
    nuevo_a11=trans_11/cant_1;
    nuevo_a12=trans_12/cant_1;
    nuevo_a21=trans_21/cant_2;
    nuevo_a22=trans_22/cant_2;
    
    error=abs(nuevo_a11-a11)+abs(nuevo_a12-a12)+abs(nuevo_a21-a21)+abs(nuevo_a22-a22);
    if error<0.1
        break
    else
        a11=nuevo_a11;
        a12=nuevo_a12;
        a21=nuevo_a21;
        a22=nuevo_a22;
    end
end

