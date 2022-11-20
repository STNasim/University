clear all; 
clc;
close all;

Gn=100;
In=5; 
koi = 0.005; 
kog = 0.0001; 
kp = 0.1; 
kh = 0.1; 
kt = 0.0005;
qg = 0.1; 
qi = 0.1;


Gs(1)=100;
Is(1)=5;


%paciente sano
Iin=0;
for i = 1:1440
    if i==420 | i==720 | i==960 | i==1200
        Gin=100; %ingesta
    else
        Gin=0;
    end
    
    if Gs(i)>Gn
        Is(i+1)=Is(i)+(kp*(Gs(i)-Gn)-koi*Is(i) + qi*Iin);
        Gs(i+1)=Gs(i)+(qg*Gin - kt*Is(i)*Gs(i) - kog* Gs(i));
    
    else
        Is(i+1)=Is(i)+(-koi*Is(i) + qi*Iin);
        Gs(i+1)=Gs(i)+(qg*Gin - kt*Is(i)*Gs(i) + kh*(Gn - Gs(i)));
    end    
end

figure ('Name','Paciente sano');
subplot 121;
plot(Gs);
title('Glucosa');
xlabel('tiempo');
ylabel('mg/dl');

subplot 122;
plot(Is);
title('Insulina');
xlabel('tiempo');
ylabel('µU/ml');

%paciente con diabetes tipo 1

for i = 1:1440
    if i==420 | i==720 | i==960 | i==1200
        Gin=100; %ingesta
    else
        Gin=0;
    end
    
    if i==480
        Iin=15; %inyeccion
    else if i==1200
        Iin=5;
        else
            Iin=0;
        end
    end
    
    if Gs(i)>Gn
        Is(i+1)=Is(i)+(kp/500*(Gs(i)-Gn)-koi*Is(i) + qi*Iin);
        Gs(i+1)=Gs(i)+(qg*Gin - kt*Is(i)*Gs(i) - kog* Gs(i));
    
    else
        Is(i+1)=Is(i)+(-koi*Is(i) + qi*Iin);
        Gs(i+1)=Gs(i)+(qg*Gin - kt*Is(i)*Gs(i) + kh*(Gn - Gs(i)));
    end    
end

figure ('Name','Diabetes tipo 1');

subplot 121;
plot(Gs);
title('Glucosa');
xlabel('tiempo');
ylabel('mg/dl');

subplot 122;
plot(Is);
title('Insulina');
xlabel('tiempo');
ylabel('µU/ml');

%paciente con diabetes tipo 2

for i = 1:1440
    if i==420 | i==720 | i==960 | i==1200
        Gin=100; %ingesta
    else
        Gin=0;
    end
    
    if i==480
        Iin=15; %inyeccion
    else if i==1200
        Iin=5;
        else
            Iin=0;
        end
    end
    
    if Gs(i)>Gn
        Is(i+1)=Is(i)+(kp*(Gs(i)-Gn)-koi*Is(i) + qi*Iin);
        Gs(i+1)=Gs(i)+(qg*Gin - kt/10*Is(i)*Gs(i) - kog* Gs(i));
    
    else
        Is(i+1)=Is(i)+(-koi*Is(i) + qi*Iin);
        Gs(i+1)=Gs(i)+(qg*Gin - kt*Is(i)*Gs(i) + kh*(Gn - Gs(i)));
    end    
end

figure ('Name','Diabetes tipo 2');

subplot 121;
plot(Gs);
title('Glucosa');
xlabel('tiempo');
ylabel('mg/dl');

subplot 122;
plot(Is);
title('Insulina');
xlabel('tiempo');
ylabel('µU/ml');