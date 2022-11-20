# -*- coding: utf-8 -*-
"""
Created on Thu Jun 17 15:07:58 2021

@author: PC
"""

def devolverDatosEnListas(diccionario):
    listaLatitud=[]
    listaLongitud=[]
    listaCiudades=[]
    for key in diccionario.keys():  #Para cada clave del diccionario se la busca
                                    #en él, se toman los diferentes datos y se
                                    #los agrega las listas correspondientes
        listaCiudades.append(diccionario[key])
        listaLatitud.append(key[0])
        listaLongitud.append(key[1])
    return [listaLatitud,listaLongitud,listaCiudades]

if __name__=="__main__":
    
    diccionario={(213,423):"Diamante",(532,145):"Oro Verde",
                 (126,368):"Parana",(519,329):"Gualeguay"}

    lista=devolverDatosEnListas(diccionario)
    
    print("\nLatitudes: ")
    print(lista[0])
    
    print("\nLongitudes: ")
    print(lista[1])
    
    print("\nNombres: ")
    print(lista[2])