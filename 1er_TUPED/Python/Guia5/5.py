# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 11:22:53 2021

@author: PC
"""

from itertools import permutations

def obtenerCombinaciones(digito1,digito2,digito3):
    return permutations([digito1, digito2, digito3], 3)

if __name__=="__main__":
    
    digito1=3
    digito2=6
    digito3=1
    
    lista=list(obtenerCombinaciones(digito1,digito2,digito3))
    
    print(lista)