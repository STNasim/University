# -*- coding: utf-8 -*-
"""
Created on Thu May 20 17:18:44 2021

@author: PC
"""
import random
from Bank import Bank

banco=Bank()
for i in range(1,10):
    banco.agregarCuentas(random.randint(0,100000), random.randint(0,1000000))
print(banco)
banco.ordenarCBU()
print(banco)
banco.ordenarMonto()
print(banco)