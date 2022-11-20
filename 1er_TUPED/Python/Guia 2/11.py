# -*- coding: utf-8 -*-
"""
Created on Sun May  2 10:27:53 2021

@author: PC
"""

peso=int(input("Ingrese su peso en kilogramos: "))
estatura=float(input("Ingrese su estatura en metros: "))
IMC=round(peso/estatura**2,2)

if(IMC<18.5):
    estado="infrapeso"
elif(IMC<=25):
    estado="peso normal"
elif(IMC<=30):
    estado="sobrepeso"
else:
    estado="obesidad"
print("El estado de salud de la persona es: "+estado)