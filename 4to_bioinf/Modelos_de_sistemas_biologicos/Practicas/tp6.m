clear all; 
clc;
close all;

fases=ones(40)*4;
voltajes=ones(40)*-90;
voltajesaux=ones(40)*-90;


for k=1:10000
    for j=1:40
        for i=1:40
                if rem(k,100)==1
                    fases(10,10)=0;
                    voltajes(10,10)=-90;
                end
            switch fases(i,j)
                case 0
                    voltajesaux(i,j)=voltajes(i,j)+60;
                    if voltajesaux(i,j)>30
                        fases(i,j)=1;
                    end
                case 1
                    voltajesaux(i,j)=voltajes(i,j)*0.8;
                    if voltajesaux(i,j)<=10
                        fases(i,j)=2;
                    end
                case 2
                    voltajesaux(i,j)=voltajes(i,j)-6;
                    if voltajesaux(i,j)<=-70
                        fases(i,j)=4;
                        voltajesaux(i,j)=-90;
                    end
                case 4
                    voltajeprueba=-90;
                    if i==1
                        voltajeprueba=voltajeprueba+voltajes(2,j)*2;
                    else
                        if i==40
                            voltajeprueba=voltajeprueba+voltajes(39,j)*2;
                        else
                            voltajeprueba=voltajeprueba+voltajes(i+1,j)+voltajes(i-1,j);
                        end
                    end
                    if j==1
                        voltajeprueba=voltajeprueba+voltajes(i,2)+voltajes(i,40);
                    else
                        if j==40
                            voltajeprueba=voltajeprueba+voltajes(i,39)+voltajes(i,1);
                        else
                            voltajeprueba=voltajeprueba+voltajes(i,j-1)+voltajes(i,j+1);
                        end
                    end
                    if voltajeprueba>-271
                        fases(i,j)=0;                    
                    end
            end
        end
    end
    pcolor(voltajes);
    %plot(voltajes);
    pause(0.1);
    voltajes=voltajesaux;
end










