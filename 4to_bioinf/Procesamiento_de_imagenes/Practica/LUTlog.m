function out =LUTlog(imagen,m,E)
    out= 1./(1+(m./(double(imagen)+ eps)).^E);
end