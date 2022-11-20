# -*- coding: utf-8 -*-
"""
Created on Sat Jun 12 14:45:12 2021

@author: PC
"""

lista=[]
for i in range (20):
    lista.append("Linea"+str(i+1))
with open("archivo_01_01.txt", 'tw', encoding='utf_8') as archi:
    archi.write("Archivo de texto\n")
    for elemento in lista:
        archi.write(elemento+"\n")
    archi.write("Fin")
    
with open("archivo_01_01.txt", 'rt', encoding='utf_8') as archi:
    print(archi.read())
    print()
    archi.seek(0)
    print(archi.read(5))
    print()
    archi.seek(0)
    mostrar=archi.readlines()
    for elemento in mostrar:
        print(elemento+" tam: "+str(len(elemento)))
    with open("archivo_01_02.txt", 'tw', encoding='utf_8') as archi2:
        archi.seek(0)
        contenido=archi.read()
        archi2.write(contenido+"\n"+str(len(contenido)))
with open("archivo_01_02.txt", 'rt', encoding='utf_8') as archi:
    print(archi.read())