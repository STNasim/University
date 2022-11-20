# -*- coding: utf-8 -*-
"""
Created on Mon May 24 16:12:30 2021

@author: PC
"""

def calcularPrecio(edad):
    if edad<4:
        precio=0
    elif edad<=18:
        precio=150
    else:
        precio=250
    return precio

if __name__=="__main__":
    
    edad=int(input("Ingrese la edad: "))
    
    print("El precio por esta persona es: "+str(calcularPrecio(edad)))