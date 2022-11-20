%%
clear all 
close all
%%
%Ejercicio 3
A=im2double(imread('cameraman.tif'));
imshow(A)
PSF=fspecial('motion',5,2);
Amov=imfilter(A,PSF);
AFmov=fft2(Amov);

subplot 311
imshow(A)
title('imagen original')
subplot 312
imshow(Amov)
title('imagen movida')
OTF=psf2otf(PSF, [256 256]);
AresF=AFmov./OTF;
Ares=ifft2(AresF);
subplot 313
imshow(Ares)
error=immse(A,Ares);
texto= strcat('imagen restaurada. MSE: ',num2str(error));
title(texto)

%%
%Ejercicio 4
figure
subplot 221
imshow(A)
title('imagen original');

PSF = fspecial('motion', 20, 50);
Abor = imfilter(A, PSF, 'conv', 'circular');
Aborruid = imnoise(Abor, 'gaussian',0,0.001);
subplot 222
imshow(Aborruid)
title('imagen borrosa y ruidosa')
  
Aresw1 = deconvwnr(Aborruid, PSF);
subplot 223
imshow(Aresw1)
title('restauración sin estimación')

relsr = 0.001 / var(A(:));
Aresw2= deconvwnr(Aborruid, PSF, relsr);
subplot 224
imshow(Aresw2)
title('restauración con estimación');