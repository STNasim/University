# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 18:55:55 2021

@author: PC
"""

def devolverDatos(diccionario):
    listaLatitud=[]
    listaLongitud=[]
    listaCiudades=[]
    for key in diccionario.keys():
        listaCiudades.append(diccionario[key])
        listaLongitud.append(key[0])
        listaLatitud.append(key[1])
    return [listaLatitud,listaLongitud,listaCiudades]

diccionario={(213,423):"Diamante",(532,145):"Oro Verde",(126,368):"Parana",(519,329):"Gualeguay"}

lista=devolverDatos(diccionario)

print(lista)