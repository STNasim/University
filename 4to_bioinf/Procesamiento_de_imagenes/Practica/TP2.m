close all

% berk=uint8(imread('Berkeley.jpg'));
% subplot 121
% imshow(berk)

%LUT LINEAL
% berkmod=LUTlin(berk,1.5,50);
% subplot 122
% imshow(berkmod)

%LUT LOG
% berkmod=LUTlog(berk,126,1);
% subplot 122
% imshow(berkmod)

%instrans
% berkmod=intrans(berk,'neg');
% subplot 122
% imshow(berkmod)

%ruidos
% bnoise=uint8(zeros([768,1024,5]));
% for i = 1:5
%     bnoise(i)=imnoise(berk,'gaussian');
% end
% berkmod=mean(bnoise);
% subplot 122
% imshow(berkmod)

%Histograma escala de grises
% zebra=uint8(imread('cebras2.GIF'));
% subplot 221
% imshow(zebra)
% subplot 222
% imhist(zebra)
% subplot 223
% zebraeq=histeq(zebra);
% imshow(zebraeq)
% subplot 224
% imhist(zebraeq)



%Histograma escala de colores
% figure
% mar=uint8(imread('mariposa1.jpg'));
% rmar = mar(:, :, 1);
% gmar = mar(:, :, 2);
% bmar = mar(:, :, 3);
% subplot 321
% imshow(rmar)
% subplot 322
% imhist(rmar)
% subplot 323
% imshow(gmar)
% subplot 324
% imhist(gmar)
% subplot 325
% imshow(bmar)
% subplot 326
% imhist(bmar)
% 
% figure
% rmareq=histeq(rmar);
% gmareq=histeq(gmar);
% bmareq=histeq(bmar);
% subplot 321
% imshow(rmareq)
% subplot 322
% imhist(rmareq)
% subplot 323
% imshow(gmareq)
% subplot 324
% imhist(gmareq)
% subplot 325
% imshow(bmareq)
% subplot 326
% imhist(bmareq)

%Equalizar Berkeley
% berk=uint8(imread('Berkeley.jpg'));
% subplot 121
% imshow(berk)
% subplot 122
% berkeq=histeq(berk);
% imshow(berkeq)

%Salt and pepper
% berk=uint8(imread('Berkeley.jpg'));
% subplot 121
% imshow(berk)
% subplot 122
% berkr=imnoise(berk,'salt & pepper');
% imshow(berkr)
% subplot 122
% berkrf=medfilt2(berkr);
% imshow(berkrf)

