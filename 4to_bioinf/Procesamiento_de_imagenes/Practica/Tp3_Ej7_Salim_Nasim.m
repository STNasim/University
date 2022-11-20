clear all
close all

%%
%Ejercicio1
%https://www.researchgate.net/publication/
%268744893_Filter_banks_system_in_frequency_domain_for_digital_imaging_segmentation_in_controlling_crop_growth
A=im2double(imread('cameraman.tif'));
[F C]=size(A);
AF=fftshift((fft2(A)));
H=zeros(F,C);
m1=F/2;m2=C/2;
for i=1:5
    L1=1+i;
    H(m1-L1: m1+L1 , m2-L1: m2+L1)=1;
    ApbF=AF.*H;
    Apb=ifft2(fftshift(ApbF));
    Apb=(real(Apb));
end

subplot 131
imshow(A)
title('imagen original')
subplot 132
Apa=A-Apb;
imshow(Apb)
title('imagen pasa bajos')
subplot 133
imshow(Apa)
title('imagen pasa altos (A-Apb)')
mean(mean(A))
mean(mean(Apb))
mean(mean(Apa))
%La media de la imagen pasabajeada es la misma pero la pasa alto es mucho
%menor

%%
%Ejercicio2
figure

subplot 121
imshow(Apa)
title('filtro cuadrado')

H2=circulo(256,5); %Funcion al final del archivo
Apb2=AF.*H2;
Apb2=ifft2(fftshift(Apb2));
Apb2=(real(Apb2));
Apa2=A-Apb2;
subplot 122
imshow(Apa2);
title('filtro circular')

figure
%Presionando enter en la figura se ve el cambio al aumentar A
for i=1:4
    Afenf=((i/2)+1)*A-Apb;
    imshow(Afenf)
    title("Enter para aumentar A");
    pause()
end

%%
%Ejercicio3
Factor=2;
Hpa=ones(F,C);
for i=1:5
    L=1+i;
    Hpa(m1-L: m1+L , m2-L: m2+L)=0;
end
Hap =(Factor-1)+ Hpa;
figure

AapF=AF.*Hap;
Aap=abs(ifft2(AapF));
subplot 121
imshow(A)
title('imagen original')
subplot 122
imshow(Aap)
title('imagen alta potencia')

%%
%Ejercicio 4

figure
subplot 121
imshow(Aap)
title("imagen alta potencia")

a=1;
b=2;
subplot 122
Heaf=a+b*Hpa;
AeafF=AF.*Heaf;
Aeaf=abs(ifft2(AeafF));
imshow(Aeaf)
title('imagen enfasis alta frecuencia')





function imagen = circulo(tam,rad)
    imagen=zeros(tam); %Se crea una matriz imagen negra completa
    centro = ceil(tam/2); %se calcula el centro y 
    imagen(centro,centro) = 1; %se establece el valor en 1, un pixel blanco
    imagen = bwdist(imagen) <= rad; %Segun el valor del radio se establece en 1(true) los pixeles circundantes al centro
end