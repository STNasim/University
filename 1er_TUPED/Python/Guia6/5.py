# -*- coding: utf-8 -*-
"""
Created on Sat Jun 12 17:35:13 2021

@author: PC
"""

ingreso=str(input("Ingrese la información: "))

palabras=ingreso.split()

print(palabras)

palabras.sort()

print(palabras)

with open("archivo_05.txt", 'tw', encoding='utf_8') as archi:
    for palabra in palabras:
        archi.write(palabra+"\n")

with open("archivo_05.txt", 'rt', encoding='utf_8') as archi:
    contenido=archi.read()
    print(contenido)
    print(str(len(contenido.split())))