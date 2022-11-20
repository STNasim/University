clear all
close all

%delta dirac

deltadirac=zeros(400,1);
deltadirac(200)=1;
subplot 221
plot(deltadirac);

subplot 222
deltadiracfft=fft((deltadirac));
plot(abs(deltadiracfft));

deltadirac2=zeros(800);
deltadirac2(400,400)=1;

subplot 223
imshow(deltadirac2)

dirac2fft=fftshift(fft2(deltadirac2));
subplot 224
mesh(abs(dirac2fft));


saturno=im2double(imread('saturn.tif'));
figure
imshow(saturno);

satufft=fftshift(fft2(saturno));
figure
imshow(abs(satufft))

recup=ifft2(satufft);
figure
imshow(recup)
%%

figure

seno=sin2d(4,3,500);
subplot 231
imshow(seno);

senobri=sin2d(4,3,500)+0.4;
subplot 232
imshow(senobri);

senocon=sin2d(4,3,500)*2;
subplot 233
imshow(senocon);

senofft=abs(fftshift(fft2(seno)));
subplot 234
imshow(senofft);

senobrifft=abs(fftshift(fft2(senobri)));
subplot 235
imshow(senobrifft);

senocon=abs(fftshift(fft2(senocon)));
subplot 236
imshow(senocon);

%%
figure
subplot 221
cuad1=square2d(100,300,100,400,800);
imshow(cuad1);

subplot 222
cuad2=square2d(300,500,400,700,800);
imshow(cuad2);

subplot 223
cuad1fft=fftshift(fft2(cuad1));
imshow(abs(cuad1fft))

subplot 224
cuad2fft=fftshift(fft2(cuad2));
imshow(abs(cuad2fft))

figure
subplot 121
imshow(angle(cuad1fft))

subplot 122
imshow(angle(cuad2fft))

%%
figure

subplot 221
sen=sin2d(5,5,800);
comsen=imcomplement(sen);

imshow(sen)
subplot 222
imshow(comsen)

senfft=fftshift(fft2(sen));
comsenfft=fftshift(fft2(sen));

subplot 223
imshow((abs(senfft)))
subplot 224
imshow(abs(comsenfft))

%%

came=im2double(imread('cameraman.tif'));
camefft=fft2(came);
maximo=max(max(camefft));

came2fft=camefft;
came2fft(128,128)=0;
came2=ifft2(came2fft);
subplot 221
imshow(came2)

subplot 222
came3fft=camefft;
came3fft(1,1)=0;
came3=ifft2(came3fft);
imshow(came3);

subplot 223
came4fft=camefft;
came4fft(1,128)=0;
came4=ifft2(came4fft);
imshow(came4);

subplot 224
came5fft=camefft;
came5fft(128,1)=0;
came5=ifft2(came5fft);
imshow(came5);
