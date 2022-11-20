%potencial de reposo= -70mV a 40
%0,01ms

clear all; 
clc;
close all;
GNa=120; GK=36; GL=0.3;
ENa=45; EK=82; EL=59;
Cm=1;
V(1)=-80;
gNa(1)=1; gK(1)=1; gL(1)=1;
p=1/100;
t=25;
m=0; n=0; h=0;
I=0;
J(1)=0;
for i=1:t/p
    am =((V(i) + 45)/10)/(1-exp(-((V(i)+45)/10)));
    ah = 0.07*exp((-(V(i)+70)/20));
    an =((V(i) + 60)/100)/(1-exp(-((V(i)+60)/10)));
    bm = 4*exp((-(V(i)+70)/18));
    bh =1/(1+exp(-((V(i)+40)/10)));
    bn = 0.125*exp((-(V(i)+70)/80));
    
    if i==1
        m=am/(am+bm);
        h=ah/(ah+bh);
        n=an/(an+bn);
    else
        m = m+p*(am*(1-m)-bm*m);
        h=h+p*(ah*(1-h)-bh*h);
        n=n+p*(an*(1-n)-bn*n);
    end
    
    gNa(i)=GNa*m^3*h;
    gK(i)=GK*n^4;
    gL(i)=GL;
    
%     if i==0.1/p
%         I=0;
%     end
    if rem(i,(2/p))==0
        I=0;
    end
    if rem(i,(2/p))==(1/p)
        I=50;
    end
    V(i+1)=V(i)+p*((I-gK(i)*(V(i)+EK)-gNa(i)*(V(i)-ENa)-gL(i)*(V(i)+EL))/Cm);
    J(i)=I;
end

plot (V,'b');
title('EJERCICIO 2');
xlabel('Tiempo');
ylabel('voltaje y conductancias');
%axis([0 (t+5)/p -0.5 1.5])
hold on;
plot (gNa,'r');
hold on;
plot (gK,'g');

legend('voltaje','conductancia sodio','conductancia potasio')
figure
plot (J);
title('I(t)')
