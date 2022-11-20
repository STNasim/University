# -*- coding: utf-8 -*-
mostrados=0
numero=1
while(mostrados<1000):
    primo=True
    i=numero-1
    while i>1:
        if numero%i==0:
            primo=False
        i=i-1
    if primo:
        print(numero)
        mostrados=mostrados+1
    numero=numero+1