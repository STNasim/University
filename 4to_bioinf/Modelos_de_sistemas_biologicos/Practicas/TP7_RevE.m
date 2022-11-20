clear all; 
clc;
close all;

GNa=120; GK=36; GL=0.3;
ENa=45; EK=82; EL=59;
Cm=1;
V(1)=-70;
gNa(1)=1; gK(1)=1; gL(1)=1;
p=1/100;
t=100;
m=0; n=0; h=0;
I=zeros(1,t/p);
I(1:100)=15;
I(500:550)=15;
I(700:800)=15;
I(3500:3600)=15;
N=1000;
canales=zeros(4,N);
cont_subunidades=0;
canal_open=zeros(1,N);
% for q=1:N
%         for w=1:4
%             if rand()<m
%                 canales(w,q)=0;
%             else
%                 canales(w,q)=1;
%             end
%         end
% end
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
    canal_open(:)=0;
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
            if (canales(w,q)==1)
                cont_subunidades=cont_subunidades+1;
            end
        end
        if (cont_subunidades==4)
            canal_open(q)=1;
        end
      cont_subunidades=0;
    end
    
    No=sum(canal_open);
    gK(i)=GK*No/N;
%     if i==0.1/p
%         I=0;
%     end
%     if rem(i,(2/p))==0
%         I=0;
%     end
%     if rem(i,(2/p))==(1/p)
%         I=50;
%     end
    V(i+1)=V(i)+p*((I(i)-gK(i)*(V(i)+EK)-gNa(i)*(V(i)-ENa)-gL(i)*(V(i)+EL))/Cm);
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