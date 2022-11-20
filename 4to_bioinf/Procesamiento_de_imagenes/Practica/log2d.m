function[m]=log2d(a1,a2,n)
%Funcion Log Natural Bidimensional
%[m]=log2d(a1,a2,n)
% a1 coef. exponencial en X,
% a2 coef. exponencial en Y,
% n tamaño de la matriz digital cuadrada,
%
%IMPORTANTE: a1 y a2 deben ser menores a cero
%porque de lo contrario, la renderizacion se va
%de rango.-
%Los valores que devuelve la funcion se encuentran escalados
%entre 0 y 1.
m=zeros(n);
if ((a1>=1)|(a2>=1)) disp('ingrese coeficientes menores a 1....'); 
else
  for x = 1:n,
    for y = 1:n,
      m(x,y) =log((a1*(x-1))+a2*(y-1));
    end
  end
end  
maximo=max(max(m));
m= m./maximo;

return