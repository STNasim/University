# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 12:09:06 2021

@author: PC
"""


frase="Hola esta es una frase de prueba capo"

vocales=set("aeiou")

print("Hay "+str(len(vocales & set(frase)))+" vocales")