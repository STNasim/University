function[m]=diente2d(a,b,n)
m=zeros(n);
for x=1:n,
  for y=1:n,
    if (x+y)<=n m(x,y)=a*(x-1)+b*(y-1);
    else m(x,y)=a*(x-n)+b*(y-n)+n;
  end
end
end