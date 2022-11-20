clear all; 
clc;
close all;

GNa=120; GK=36; GL=0.3;
ENa=45; EK=82; EL=59;
Cm=1;
V(1)=-70;
gNa(1)=1; gK(1)=1; gL(1)=1;
p=1/100;
t=50;
m=0; n=0; h=0;
I=zeros(1,t/p);
I(1:t/p)=50;
N=1000;
canales=zeros(4,N);
for q=1:N
        for w=1:4
            if rand()<0.5
                canales(w,q)=0;
            else
                canales(w,q)=1;
            end
        end
end
for i=1:t/p
%     if i==5/p
%         V(i)=V(i)+15;
%     end
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
        canales=rand(4,N)< n; %Se inicializan los canales en abierto/cerrado
    else
        m = m+p*(am*(1-m)-bm*m);
        h=h+p*(ah*(1-h)-bh*h);
        n=n+p*(an*(1-n)-bn*n);
    end
    
    gNa(i)=GNa*m^3*h;
    gL(i)=GL;
    for q=1:N
        for w=1:4
            r=rand();
            if canales(w,q)==1
                if r<bn*p
                    canales(w,q)=0;
                end
            else
                if r<an*p
                    canales(w,q)=1;
                end
            end
        end
    end
    No=0;
    aux=sum(canales);
    for q=1:N
        if aux(q)==4
            No=No+1;
        end
    end
    gK(i)=GK*No/N;
    if i~=t/p
        V(i+1)=V(i)+p*((I(i)-gK(i)*(V(i)+EK)-gNa(i)*(V(i)-ENa)-gL(i)*(V(i)+EL))/Cm);
    end
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
set(gca,'XTickLabel',0:t/10:t)
legend('voltaje','conductancia sodio','conductancia potasio')