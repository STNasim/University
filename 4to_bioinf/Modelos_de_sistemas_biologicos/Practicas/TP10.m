%%
clear all
close all
%Ejercicio1

k=1;
No=0.1;
N=1000;
t=3000;
x=zeros(1000,1);
val=zeros(t,50);
lyapunov=zeros(t,1);
der=zeros(N,1);

for i=1:t
    x(1)=k*No;
    der(1)=0;
    for j=2:N
        x(j)=k*x(j-1)*(1-x(j-1));
        der(j-1)=log(abs(k*(1-2*x(j))));
    end
    lyapunov(i)=mean(der);
    val(i,1:50)=x(951:1:1000);
    k=k+0.001;
end

figure
subplot 211
plot(lyapunov);
hold on
lin0=zeros(size(lyapunov));
plot(lin0);
title('coeficientes de lyapunov');
set(gca,'XTickLabel',1:0.5:4)

subplot 212
plot(val,'.');
title('valores para k');
set(gca,'XTickLabel',1:0.5:4)


%%
clear all
close all
%Ejercicio 2


%y1

y1=load('y1.txt');
figure
subplot 311
plot(y1);

%Salida vs salida anterior y1

tam=size(y1);
z=zeros(tam(2),2);

for i=1:tam(2)-1
    z(i,1)=y1(i);
    z(i,2)=y1(i+1);
end

subplot 312
plot(z(1:900),z(901:1800),'*')
title('salida versus salida anterior de y1');

%correlacion y1

cory1=xcorr(y1);
subplot 313
plot(cory1)
title('correlacion y1')

%y2

y2=load('y2.txt');
figure
subplot 311
plot(y2);

%Salida vs salida anterior y2

tam=size(y2);
z=zeros(tam(2),2);

for i=1:tam(2)-1
    z(i,1)=y2(i);
    z(i,2)=y2(i+1);
end

subplot 312
plot(z(1:900),z(901:1800),'*')
title('salida versus salida anterior de y2');

%correlacion y2

cory2=xcorr(y2);
subplot 313
plot(cory2)
title('correlacion y2')
