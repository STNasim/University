clear all; 
clc;
close all;
r=10;
K=1000;
syms P(t);
ode=diff(P(t),t)==r*P(t)*(1-P(t)/K);
cond=P(0)==10;
Psol(t)=dsolve(ode,cond);

%METODO DE EULER
%paso de 1 mes
v_e(1)=10;
vec_error1(1)=0;
h=1/12;
for i = 1:48
    v_e(i+1)=v_e(i)+h*r*v_e(i)*(1-v_e(i)/K);
    vec_error1(i)=Psol(i/12)-v_e(i+1);
end

%paso de 2 meses
vec_error2(1)=0;
h=1/6;
for i = 1:24
    v_e(i+1)=v_e(i)+h*r*v_e(i)*(1-v_e(i)/K);
    vec_error2(i*2)=abs(Psol(i/12)-v_e(i+1));
    vec_error2(i*2-1)=abs(Psol(i/12)-v_e(i+1));
end

%paso de 12 meses
vec_error3(1)=0;
h=1;
for i = 1:4
    
    v_e(i+1)=v_e(i)+h*r*v_e(i)*(1-v_e(i)/K);
    
    for j= 0:11
        vec_error3(i*12-j)=abs(Psol(i/12)-v_e(i+1));
    end
    
end

figure;
plot (vec_error1,'b');
hold on;
plot (vec_error2,'g');
hold on;
plot (vec_error3,'r');
ylim([0 1000])
title('Euler');

%METODO DE TAYLOR
%derivada segunda
d2=diff(r*P(t)*(1-P(t)/K));
d2p=diff(r*P(t)*(1-P(t)/K),P);
d2t=diff(r*P(t)*(1-P(t)/K),t);
tv_e(1)=10;
%paso de 1 mes
tvec_error1(1)=0;
h=1/12;
for i = 1:48
    tv_e(i+1)=tv_e(i)+h*r*tv_e(i)*(1-tv_e(i)/K)+(h^2/2)*(subs(d2t,P(t),tv_e(i))+subs(r*P(t)*(1-P(t)/K)*d2p,P(t),tv_e(i)));
    tvec_error1(i)=Psol(i/12)-tv_e(i+1);
end

%paso de 2 meses
tvec_error2(1)=0;
h=1/6;
for i = 1:24
    tv_e(i+1)=tv_e(i)+h*r*tv_e(i)*(1-tv_e(i)/K)+(h^2/2)*(subs(d2p,P(t),tv_e(i))+subs(r*P(t)*(1-P(t)/K)*d2p,P(t),tv_e(i)));
    tvec_error2(i*2)=abs(Psol(i/12)-tv_e(i+1));
    tvec_error2(i*2-1)=abs(Psol(i/12)-tv_e(i+1));
end

%paso de 12 meses
tvec_error3(1)=0;
h=1;
for i = 1:4
    
   tv_e(i+1)=tv_e(i)+h*r*tv_e(i)*(1-tv_e(i)/K)+(h^2/2)*(subs(d2p,P(t),tv_e(i))+subs(r*P(t)*(1-P(t)/K)*d2p,P(t),tv_e(i)));
    
    for j= 0:11
        tvec_error3(i*12-j)=abs(Psol(i/12)-tv_e(i+1));
    end
    
end

figure;
plot (tvec_error1,'b');
hold on;
plot (tvec_error2,'g');
hold on;
plot (vec_error3,'r');
ylim([0 1000])
title('TAYLOR');

%METODO DE RUNGE-KUTTA: ORDEN 2

%paso de 1 mes
vec_error1(1)=0;
h=1/12;
for i = 1:48
    pendiente1=h*r*v_e(i)*(1-v_e(i)/K);
    aux_y1=v_e(i)+pendiente1/2;
    pendiente2=h*r*aux_y1*(1-aux_y1/K);
    v_e(i+1)=v_e(i)+pendiente2;
    vec_error1(i)=abs(Psol(i/12)-v_e(i+1));
end

%paso de 2 meses
vec_error2(1)=0;
h=1/6;
for i = 1:24
    pendiente1=h*r*v_e(i)*(1-v_e(i)/K);
    aux_y1=v_e(i)+pendiente1/2;
    pendiente2=h*r*aux_y1*(1-aux_y1/K);
    v_e(i+1)=v_e(i)+pendiente2;
    vec_error2(i*2)=abs(Psol(i/12)-v_e(i+1));
    vec_error2(i*2-1)=abs(Psol(i/12)-v_e(i+1));
end

%paso de 12 meses
vec_error3(1)=0;
h=1;
for i = 1:4
    
    pendiente1=h*r*v_e(i)*(1-v_e(i)/K);
    aux_y1=v_e(i)+pendiente1/2;
    pendiente2=h*r*aux_y1*(1-aux_y1/K);
    v_e(i+1)=v_e(i)+pendiente2;
    for j= 0:11
        vec_error3(i*12-j)=abs(Psol(i/12)-v_e(i+1));
    end
    
end

figure;

plot (vec_error1,'b');
hold on;
plot (vec_error2,'g');
hold on;
plot (vec_error3,'r');
ylim([0 1000])
title('RUNGE-KUTTA: ORDEN 2');

%METODO DE RUNGE-KUTTA: ORDEN 4

%paso de 1 mes
vec_error1(1)=0;
vec_error1s(1)=single(0);
h=1/12;
for i = 1:48
    pendiente1=h*r*v_e(i)*(1-v_e(i)/K);
    aux_y1=v_e(i)+pendiente1/2;
    pendiente2=h*r*aux_y1*(1-aux_y1/K);
    aux_y2=v_e(i)+pendiente2/2;
    pendiente3=h*r*aux_y2*(1-aux_y2/K);
    aux_y3=v_e(i)+pendiente3/2;
    pendiente4=h*r*aux_y3*(1-aux_y3/K);
    pendientefinal=(pendiente1+2*pendiente2+2*pendiente3+pendiente4)/6;
    v_e(i+1)=v_e(i)+pendientefinal;
    vec_error1(i)=abs(Psol(i/12)-v_e(i+1));
    vec_error1s(i)=abs(Psol(i/12)-v_e(i+1));
end

%paso de 2 meses
vec_error2(1)=0;
vec_error2s(1)=single(0);
h=1/6;
for i = 1:24
    pendiente1=h*r*v_e(i)*(1-v_e(i)/K);
    aux_y1=v_e(i)+pendiente1/2;
    pendiente2=h*r*aux_y1*(1-aux_y1/K);
    aux_y2=v_e(i)+pendiente2/2;
    pendiente3=h*r*aux_y2*(1-aux_y2/K);
    aux_y3=v_e(i)+pendiente3/2;
    pendiente4=h*r*aux_y3*(1-aux_y3/K);
    pendientefinal=(pendiente1+2*pendiente2+2*pendiente3+pendiente4)/6;
    v_e(i+1)=v_e(i)+pendientefinal;
    vec_error2(i*2)=abs(Psol(i/12)-v_e(i+1));
    vec_error2(i*2-1)=abs(Psol(i/12)-v_e(i+1));
    vec_error2s(i*2)=abs(Psol(i/12)-v_e(i+1));
    vec_error2s(i*2-1)=abs(Psol(i/12)-v_e(i+1));
end

%paso de 12 meses
vec_error3(1)=0;
vec_error3s(1)=single(0);
h=1;
for i = 1:4
    
    pendiente1=h*r*v_e(i)*(1-v_e(i)/K);
    aux_y1=v_e(i)+pendiente1/2;
    pendiente2=h*r*aux_y1*(1-aux_y1/K);
    aux_y2=v_e(i)+pendiente2/2;
    pendiente3=h*r*aux_y2*(1-aux_y2/K);
    aux_y3=v_e(i)+pendiente3/2;
    pendiente4=h*r*aux_y3*(1-aux_y3/K);
    pendientefinal=(pendiente1+2*pendiente2+2*pendiente3+pendiente4)/6;
    v_e(i+1)=v_e(i)+pendientefinal;
    for j= 0:11
        vec_error3(i*12-j)=abs(Psol(i/12)-v_e(i+1));
    end
    for j= 0:11
        vec_error3s(i*12-j)=abs(Psol(i/12)-v_e(i+1));
    end
    
end

figure;

plot (vec_error1,'b');
hold on;
plot (vec_error2,'g');
hold on;
plot (vec_error3,'r');
ylim([0 1000])
title('RUNGE-KUTTA: ORDEN 4');

%A menor paso y mayor cantidad de términos mayor precisión

vec_error1s-vec_error1
