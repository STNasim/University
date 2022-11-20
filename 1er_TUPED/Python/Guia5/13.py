# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 11:59:27 2021

@author: PC
"""

def repetidos(lista1,lista2):
    set1=set(lista1)
    set2=set(lista2)
    
    if set1 & set2:
        return True
    else:
        return False
        

from random import randint

lista1=[]
lista2=[]

for i in range (5):
    lista1.append(randint(0,9))
    lista2.append(randint(0,9))

print(lista1)
print(lista2)
if repetidos(lista1,lista2):
    print("Hay elementos repetidos")
else:
    print("No hay elementos repetidos")