clear all
close all

den=0.01;
errores_mse=zeros(30,1);
errores_pixel=zeros(30,1);
imagenorg=imread('cameraman.tif');
for j=1:3
    if j==2 
        den=0.02; 
    end
    if j==3
        den=0.05;
    end
    imagen=imread('cameraman.tif');
    for i=1:10
        imagen2=imnoise(imagen,'salt & pepper',den);
        imagen2=medfilt2(imagen2);

        errores_mse(i+(j-1)*10)=immse(imagenorg,imagen2);

        imagendiff=imabsdiff(imagen,imagen2);
        errores_pixel(i+(j-1)*10)=nnz(imagendiff)*100/numel(imagendiff);
        imagen=imagen2;
    end
end

errores_mse1=errores_mse(1:10);
errores_mse2=errores_mse(11:20);
errores_mse3=errores_mse(21:30);
plot(errores_mse1,'r');
hold on
plot(errores_mse2,'g');
hold on
plot(errores_mse3,'b');
legend('0.01','0.02','0.05')
title('errores MSE')
    
figure

errores_pixel1=errores_pixel(1:10);
errores_pixel2=errores_pixel(11:20);
errores_pixel3=errores_pixel(21:30);
plot(errores_pixel1,'r')
hold on
plot(errores_pixel2,'g')
hold on
plot(errores_pixel3,'b')
legend('0.01','0.02','0.05')
title('errores %pixeles')

