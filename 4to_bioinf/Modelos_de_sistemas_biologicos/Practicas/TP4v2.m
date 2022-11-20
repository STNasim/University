
clear all; 
clc;
close all;


bh=1;
yh=0.4;
bm=1;
ym=2;


%punto 1 y 2

inf(1)=0;
vec(1)=0;

h=1/5;
t=75;
for i = 1:t/h
    inf(i+1)=inf(i)+h*(-yh*inf(i)+bh*vec(i)*(1-inf(i)));
    vec(i+1)=vec(i)+h*(-ym*vec(i)+bm*inf(i)*(1-vec(i)));
    
end

figure;
plot (inf,'b*');
title('CASO 1');
xlabel('Tiempo');
ylabel('proporcion');
axis([0 (t+5)/h -0.5 1.5])
hold on;
plot (1-inf,'r*');
legend()
plot (vec,'go');
hold on;
plot (1-vec,'cyo');
legend('infectados','sanos','vectores','agentes')


inf(1)=0.3;
vec(1)=0.4;

for i = 1:t/h
    inf(i+1)=inf(i)+h*(-yh*inf(i)+bh*vec(i)*(1-inf(i)));
    vec(i+1)=vec(i)+h*(-ym*vec(i)+bm*inf(i)*(1-vec(i)));
    
end

figure;
plot (inf,'b');
title('CASO 2');
xlabel('Tiempo');
ylabel('proporcion');
axis([0 (t+5)/h -0.5 1.5])
hold on;
plot (1-inf,'r');
legend()
plot (vec,'g');
hold on;
plot (1-vec,'cy');
legend('infectados','sanos','vectores','agentes')


%punto 5

h=1/5;
t=700;

inf(1)=0.05;
lat(1)=0;
rec(1)=0;
expue(1)=0;
vec(1)=0.05;

th=0.7; %pasaje de latente a infectado
tv=0.1; %pasaje de expuesto a vector
mr=2; %pasaje de recuperado a sano (inmunidad)
bh=1;
yh=0.4;
bm=1;
ym=2;

for i = 1:t/h
    if 150/h<i & i<240/h
        vec(i+1)=0;
        expue(i+1)=0;
    else
        expue(i+1)=expue(i)+h*(bm*inf(i)*(1-expue(i)-vec(i))-(expue(i)*(1/tv)));
        vec(i+1)=vec(i)+h*(expue(i)*(1/tv)-ym*vec(i));
    end
    lat(i+1)=lat(i)+h*(-th*lat(i)+bh*vec(i)*(1-lat(i)-rec(i)-inf(i)));
    rec(i+1)=rec(i)+h*(yh*inf(i)-(1/mr)*rec(i));
    inf(i+1)=inf(i)+h*(lat(i)*(1/th)-yh*inf(i));
end

figure;
title('Ejercicio 5');
xlabel('Tiempo');
ylabel('proporcion');
plot (inf,'b*');
hold on;
plot (lat,'mo');
hold on;
plot (1-inf-rec,'r*');
hold on
plot (rec,'k*');
hold on;
plot (vec,'go');
hold on;
plot (expue,'yo');
hold on;
plot (1-vec-expue,'cyo');
legend('infectados','latentes','sanos','recuperados','vectores','expuestos','agentes')
axis([0 (t+50)/h -0.5 1.5])