# -*- coding: utf-8 -*-

"""numero=float(input("Ingrese el numero"))"""
numero=float(11)

primo=True
i=numero-1
while i>1:
    if numero%i==0:
        primo=False
    i=i-1
if(primo):
    print("Numero primo")
else:
    print("Numero no primo")