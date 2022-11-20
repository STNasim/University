# -*- coding: utf-8 -*-
"""
Created on Thu Jun 17 10:19:50 2021

@author: PC
"""

from random import randint,sample

def devolverListaDesordenada(lista): #Consideramos devolver una copia asi la
    return sample(lista,len(lista))  #lista original sigue siendo igual

if __name__=="__main__":
    
    lista=[]
    for i in range (50):
        lista.append(randint(0,100))
        
    print("La lista original es: ")
    print(lista)
    print()
    
    print("La lista ordenada de manera aleatoria es: ")
    print(devolverListaDesordenada(lista))
    print()

    print("La lista original sigue siendo igual: ")
    print(lista)