# -*- coding: utf-8 -*-
"""
Created on Sun May  2 11:00:29 2021

@author: PC
"""

def contar_letra(frase, letra):
    return frase.count(letra)

frase=input("Ingrese la frase: ")
letra=input("Ingrese la letra: ")

print("Hay "+str(contar_letra(frase, letra))+" ocurrencias")