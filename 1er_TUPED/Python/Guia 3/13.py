# -*- coding: utf-8 -*-
"""
Created on Sun May  2 11:06:18 2021

@author: PC
"""

ingreso=input("Ingrese el nombre de ciudad: ")
dic={}

while(ingreso!="0"):
    aux=int(input("Ingrese codigo postal: "))
    dic[ingreso]=aux
    ingreso=input("Ingrese el nombre de ciudad o 0 para salir: ")

print(dic)
    
for ciudad in sorted(dic):
    print(ciudad+" "+str(dic[ciudad]))

for valor in sorted(dic.items(), key=lambda item: item[1]):
    print(valor[0]+" "+str(valor[1]))