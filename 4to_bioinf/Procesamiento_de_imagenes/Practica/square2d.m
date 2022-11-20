function[m]=square2d(xl,xh,yl,yh,n)
m=zeros(n);
for x=1:n,
  for y=1:n,
    if (x>=xl)&(x<=xh)&(y>=yl)&(y<=yh) m(x,y)=1;
  end
end
end