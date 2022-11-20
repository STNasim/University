# -*- coding: utf-8 -*-
"""
Created on Sun May  2 10:23:20 2021

@author: PC
"""

peso=int(input("Ingrese su peso en kilogramos: "))
estatura=float(input("Ingrese su estatura en metros: "))
IMC=round(peso/estatura**2,2)

print("Tu indice de masa corporal es: "+ str(IMC))
