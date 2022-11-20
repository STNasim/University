# -*- coding: utf-8 -*-
"""
Created on Sat May  8 19:28:33 2021

@author: PC
"""
import random

numeros=[random.randint(0, 100) for numero in range(0,25)]
print(numeros)
numeros_pares=list(filter(lambda a: a%2==0,numeros))
print(numeros_pares)
numeros_triple=list(map(lambda a: a*3,numeros_pares))
print(numeros_triple)