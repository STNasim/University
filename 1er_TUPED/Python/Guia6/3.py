# -*- coding: utf-8 -*-
"""
Created on Sat Jun 12 16:00:43 2021

@author: PC
"""
import os.path

if os.path.exists("archivo_03.txt"):
   with open("archivo_03.txt", 'tr', encoding='utf_8') as archi:
       print(archi.read())
else:
    with open("archivo_03.txt", 'tw', encoding='utf_8') as archi:
        lista_impares=[]
        for i in range (101,199,2):
            lista_impares.append(str(i)+"\n")
        archi.writelines(lista_impares)