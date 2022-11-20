# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 11:53:31 2021

@author: PC
"""

from random import randint

lista1=[]
lista2=[]
lista3=[]

for i in range (10):
    lista1.append(randint(0,9))
    lista2.append(randint(0,9))
    lista3.append(randint(0,9))

tupla=(lista1,lista2,lista3)

print(tupla)

for lista in tupla:
    lista.sort()

print(tupla)