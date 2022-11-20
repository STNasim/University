clear all
close all
clc

patron=imread('patron.tif');

subplot 221
imshow(patron)
subplot 222
imshow(patron(:,:,1))
subplot 223
imshow(patron(:,:,2))
subplot 224
imshow(patron(:,:,3))

figure
patron_hsv=rgb2hsv(patron);

subplot 221
imshow(patron)
subplot 222
imshow(patron_hsv(:,:,1))
subplot 223
imshow(patron_hsv(:,:,2))
subplot 224
imshow(patron_hsv(:,:,3))

%Invertir colores
patron_hsv1=patron_hsv;
%patron_hsv(:,:,1)=imcomplement(patron_hsv(:,:,1));
patron_hsv1(:,:,1)=fliplr(patron_hsv(:,:,1));

figure
subplot 221
imshow(hsv2rgb(patron_hsv1))
subplot 222
imshow(patron_hsv1(:,:,1))
subplot 223
imshow(patron_hsv1(:,:,2))
subplot 224
imshow(patron_hsv1(:,:,3))

patron_hsv2=patron_hsv;
%Degrade saturacion
for i=1:64
    patron_hsv2(i,:,2)=i/64;
end

figure
subplot 221
imshow(hsv2rgb(patron_hsv2))
subplot 222
imshow(patron_hsv2(:,:,1))
subplot 223
imshow(patron_hsv2(:,:,2))
subplot 224
imshow(patron_hsv2(:,:,3))

%Brillo maximo
patron_hsv3=patron_hsv;
patron_hsv3(:,:,3)=1;

figure
subplot 221
imshow(hsv2rgb(patron_hsv3))
subplot 222
imshow(patron_hsv3(:,:,1))
subplot 223
imshow(patron_hsv3(:,:,2))
subplot 224
imshow(patron_hsv3(:,:,3))


%Ejercicio2

figure
rio=im2double(imread('rio.jpg'));
imshow(rio)
figure
imhist(rio)

riocolor(:,:,1)=rio;
riocolor(:,:,2)=rio;
riocolor(:,:,3)=rio;

for i=1:512
    for j=1:513
        for k=1:3
            if k~=3 && riocolor(i,j,k)<0.1
                riocolor(i,j,k)=1;
            else
                riocolor(i,j,k)=rio(i,j);
            end
        end
    end
end

figure
imshow(riocolor);

%Ejercicio 3

marosc=im2double(imread('mariposaoscura.jpg'));
maroscR=histeq(marosc(:,:,1));
maroscG=histeq(marosc(:,:,2));
maroscB=histeq(marosc(:,:,3));

figure

subplot 211
imshow(marosc)

subplot 212
maroscaux=marosc;
maroscaux(:,:,1)=maroscR;
maroscaux(:,:,2)=maroscG;
maroscaux(:,:,3)=maroscB;
imshow(maroscaux)

maroschsv=rgb2hsv(marosc);
maroschsv(:,:,3)=histeq(maroschsv(:,:,3));

figure
imshow(hsv2rgb(maroschsv))

%Ejercicio 4

camino=im2double(imread('camino.tif'));
imshow(camino)

masc=[-0.5,-0.5,-0.5;-0.5,5,-0.5;-0.5,-0.5,-0.5];

caminofil=imfilter(camino,masc);
figure
imshow(caminofil)