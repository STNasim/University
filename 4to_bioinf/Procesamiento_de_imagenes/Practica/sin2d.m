function[m]=sin2d(u,v,n)
% Sin2D(u,v,N) Es una función que devuelve una matriz de (N-1)x(N-1)
%              la cual es un seno bidimensional con u ciclos en 
%              dirección x, y v ciclos en dirección y. Los elementos
%              varían entre 0 y 1.						
m=zeros(n);
for i = 1:n,
  for j = 1:n,
    m(i,j) =sin(2*pi/(n-1)*(u*(i-1)+v*(j-1)));
  end
end
