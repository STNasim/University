# -*- coding: utf-8 -*-
"""
Created on Sat Jun 12 15:46:34 2021

@author: PC
"""


with open("archivo_02.txt", 'ta', encoding='utf_8') as archi:
    archi.write("Linea\n")
    
with open("archivo_02.txt", 'rt', encoding='utf_8') as archi:
    print(archi.read())