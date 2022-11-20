# -*- coding: utf-8 -*-
"""
Created on Sat May  8 21:24:46 2021

@author: PC
"""

import random as rd
import time

N = 10000000
a = 0
b = 1000

t1 = time.time()
lista = [rd.randint(a,b)for i in range(N)]
t2 = time.time()

t3 = time.time()
lista1 = []
for i in range(N):
    lista1.append(rd.randint(a,b))
t4 = time.time()

delta_t1 = t2 - t1
delta_t2 = t4 - t3

print('Los tiempos de ejecución son de: ')
print(delta_t1)
print(delta_t2)