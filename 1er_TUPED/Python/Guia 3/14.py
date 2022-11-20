# -*- coding: utf-8 -*-
"""
Created on Sat May  8 17:54:36 2021

@author: PC
"""

def FibonacciHasta(numero, serie):
    tam=len(serie)
    if serie[tam-1]>=numero:
        return
    else:
        serie.append(serie[tam-1]+serie[tam-2])
        FibonacciHasta(numero,serie)   

def PosicionFibonacci(numero):
    if(numero==0):
        return 1
    if(numero==1):
        return 2
    serie=[0,1]
    FibonacciHasta(numero,serie)
    print(serie)
    tam= len(serie)
    if serie[tam-1]==numero:
        return tam
    else:
        return -1
    
print(PosicionFibonacci(532))
    