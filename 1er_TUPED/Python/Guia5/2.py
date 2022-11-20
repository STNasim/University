# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 11:12:53 2021

@author: PC
"""
lista=[]


def crearLista3(cantidad):
    cantidad*=3
    for i in range(0,cantidad,3):
        lista.append(i)
    return lista

if __name__=="__main__":
    
    lista=crearLista3(60)
    
    print(lista)