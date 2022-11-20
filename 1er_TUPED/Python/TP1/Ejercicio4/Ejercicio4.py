# -*- coding: utf-8 -*-
"""
Created on Mon May 24 18:16:28 2021

@author: PC
"""

from random import sample
from time import sleep


if __name__=="__main__":
    frutas=[]
    aux=(input("Ingrese una fruta(ingrese 0 para finzalizar una vez ingresadas al menos 4 frutas): "))
    
    #Se piden frutas hasta que se ingrese el valor 0 
    #y la lista contenga al menos 4 frutas           
    while aux!="0" or len(frutas)<4:
        if aux not in frutas and aux!="0":
            frutas.append(aux)
        aux=(input("Ingrese una fruta: "))
    
    #Hacemos una recomendación de 3 frutas y las mostramos 5 veces
    recomendacion=sample(frutas,3)
    for i in range(5):
        print(recomendacion)
        sleep(1)
