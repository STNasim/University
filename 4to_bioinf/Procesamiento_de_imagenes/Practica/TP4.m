clear all
close all

imagen=imread('cameraman.tif');

%%
%Salt and pepper 
figure('name','salt & pepper');
imagensap=imnoise(imagen,'salt & pepper');
subplot 221
imagensap1=spfilt(imagensap, 'amean');
imshow(imagensap1)
errorsap1=immse(imagen,imagensap1);
texto= strcat('aritmetic mean:',num2str(errorsap1));
title(texto);
subplot 222
imagensap2=spfilt(imagensap, 'gmean');
imshow(imagensap2)
errorsap2=immse(imagen,imagensap2);
texto= strcat('geometric mean:',num2str(errorsap2));
title(texto);
subplot 223
imagensap3=spfilt(imagensap, 'hmean');
imshow(imagensap3)
errorsap3=immse(imagen,imagensap3);
texto= strcat('harmonic mean:',num2str(errorsap3));
title(texto);
subplot 224
imagensap4=spfilt(imagensap, 'atrimmed');
imshow(imagensap4)
errorsap4=immse(imagen,imagensap4);
texto= strcat('alpha trimmer:',num2str(errorsap4));
title(texto);

%%
%Gaussian
figure('name','Gaussian');
imageng=imnoise(imagen,'gaussian');
subplot 221
imageng1=spfilt(imageng, 'amean');
imshow(imageng1)
errorg1=immse(imagen,imageng1);
texto= strcat('aritmetic mean:',num2str(errorg1));
title(texto);
subplot 222
imageng2=spfilt(imageng, 'gmean');
imshow(imageng2)
errorg2=immse(imagen,imageng2);
texto= strcat('geometric mean:',num2str(errorg2));
title(texto);
subplot 223
imageng3=spfilt(imageng, 'hmean');
imshow(imageng3)
errorg3=immse(imagen,imageng3);
texto= strcat('harmonic mean:',num2str(errorg3));
title(texto);
subplot 224
imageng4=spfilt(imageng, 'atrimmed');
imshow(imageng4)
errorg4=immse(imagen,imageng4);
texto= strcat('alpha trimmer:',num2str(errorg4));
title(texto);


%%
%Speckle
%Gaussian
figure('name','speckle');
imagens=imnoise(imagen,'speckle');
subplot 221
imagens1=spfilt(imagens, 'amean');
imshow(imagens1)
errors1=immse(imagen,imagens1);
texto= strcat('aritmetic mean:',num2str(errors1));
title(texto);
subplot 222
imagens2=spfilt(imagens, 'gmean');
imshow(imagens2)
errors2=immse(imagen,imagens2);
texto= strcat('geometric mean:',num2str(errors2));
title(texto);
subplot 223
imagens3=spfilt(imagens, 'hmean');
imshow(imagens3)
errors3=immse(imagen,imagens3);
texto= strcat('harmonic mean:',num2str(errors3));
title(texto);
subplot 224
imagens4=spfilt(imagens, 'atrimmed');
imshow(imagens4)
errors4=immse(imagen,imagens4);
texto= strcat('alpha trimmer:',num2str(errors4));
title(texto);

%%
%poligonos
[BW,c,r]=roipoly(imagen);
histo=histroi(imagen,c,r);
figure
plot(histo);
figure
imhist(imagen(BW));