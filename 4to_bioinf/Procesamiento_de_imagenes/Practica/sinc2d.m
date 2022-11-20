function[m]=sinc2d(u,v,n)
m=zeros(n);
for i = 1:n,
  for j = 1:n,
    d=2*pi/(n-1)*(u*(i-n/2)+v*(j-n/2));
    if d==0 m(i,j)=1;
    else
      m(i,j) =sin(2*pi/(n-1)*(u*(i-n/2)+v*(j-n/2)))/d;
    end
  end
end