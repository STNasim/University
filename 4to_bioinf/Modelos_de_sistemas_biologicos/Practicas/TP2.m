clear all; 
clc;
close all;

a = 0.25; 
b = 50; 
c = 0.25; 
d = 10; 
e = 0.01; 
f = 0.0045;
Va (1) = 0.001;
CD4a(1) = 1000; 
CD8a(1) = 550;
CD4n = 1000; 
CD8n = 550;

%sin droga
h=1/100;
for i = 1:1000
    CD4a(i+1)=CD4a(i)+h*(-a*CD4a(i)-b*CD4a(i)*Va(i)+a*CD4n);
    CD8a(i+1)=CD8a(i)+h*(-c*CD8a(i)+d*CD8a(i)*Va(i)+c*CD8n);
    Va(i+1)= Va(i)+h*(e*CD4a(i)*Va(i)-f*CD8a(i)*Va(i));
    
end

figure;
plot (CD4a,'b');
title('sin droga');
xlabel('Tiempo');
ylabel('Evolución del sistema');
hold on;
plot (CD8a,'g');
hold on;
plot (Va*10000,'r');


V (1) = 0.001;
CD4(1) = 1000; 
CD8(1) = 550;


h=1/100;
for i = 1:1000
    CD4(i+1)=CD4(i)+h*(-a*CD4(i)-b*CD4(i)*V(i)+a*CD4n);
    CD8(i+1)=CD8(i)+h*(-c*CD8(i)+d*CD8(i)*V(i)+c*CD8n);
    
    if i>100
        V(i+1)= V(i)+h*(e*CD4(i)*V(i)-f*CD8(i)*V(i)-e*CD4n*V(i));
    else 
        V(i+1)= V(i)+h*(e*CD4a(i)*V(i)-f*CD8a(i)*V(i));
    end
end

figure;
plot (CD4,'b');
title('con droga');
xlabel('Tiempo');
ylabel('Evolución del sistema');
hold on;
plot (CD8,'g');
hold on;
plot (V*10000,'r');