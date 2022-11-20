# -*- coding: utf-8 -*-
"""
Created on Sun May  2 10:53:01 2021

@author: PC
"""

def calcular_IMC(peso, estatura):
    return round(peso/estatura**2,2)

def devolverEstado(IMC):
    if(IMC<18.5):
        estado="infrapeso"
    elif(IMC<=25):
        estado="peso normal"
    elif(IMC<=30):
        estado="sobrepeso"
    else:
        estado="obesidad"
    return estado

peso=int(input("Ingrese su peso en kilogramos: "))
estatura=float(input("Ingrese su estatura en metros: "))

estado=devolverEstado(calcular_IMC(peso,estatura))

print("El estado de salud de la persona es: "+estado)