clear all
close all
clc

%1 Se crea la matriz de datos de imagen con datos uint8 y se muestra con imtool
imagen=uint8(rand(256,256)*255);
imtool(imagen)

%2 Similar al anterior solo se que con otro rango por lo tanto
%  se debe ajustar el rango de valores al mostrarla con imtool
%  de lo contrario la imagen mostrada no será la correcta
imagen2=uint8(rand(100,100)*100);
imtool(imagen2);
imtool(imagen2,[0,100]);

%3 Se crea una imagen y se binariza para luego mostrarse
%imagen3=im2bw(rand(100,100)); 
imagen3=imbinarize(rand(100,100)); %Cambiado por imbinarize por recomendación de Matlab
imtool(imagen3);

%4 Se crea la imagen requerida con la función creacionImagen()
%   con parametros aleatorios y se muestra

imagen4=creacionImagen(800,400);
imtool(imagen4)


function imagen = creacionImagen(tam,rad)
    imagen=zeros(tam); %Se crea una matriz imagen negra completa
    centro = ceil(tam/2); %se calcula el centro y 
    imagen(centro,centro) = 1; %se establece el valor en 1, un pixel blanco
    imagen = bwdist(imagen) <= rad; %Segun el valor del radio se establece en 1(true) los pixeles circundantes al centro
end