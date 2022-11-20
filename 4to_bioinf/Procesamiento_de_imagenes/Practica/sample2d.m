function[m]=sample2d(u,v,n)
m=zeros(n);
du=fix(n/u);
dv=fix(n/v);
for i=1:u,
  for j=1:v,
    m((i-1)*du+1,(j-1)*dv+1)=1;
  end
end
end