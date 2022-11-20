# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 11:17:30 2021

@author: PC
"""
from random import randint

def filtrarRepetidos(lista):
    return set(lista)


if __name__=="__main__":
    
    lista=[]
    for i in range (15):
        lista.append(randint(0,9))
        
    lista2=filtrarRepetidos(lista)
    
    print(lista)
    print(lista2)
