# -*- coding: utf-8 -*-
"""
Created on Mon May 24 17:06:21 2021

@author: PC
"""
from random import randint

def crearLista():
    lista=[]
    for i in range (1000000):
        lista.append(randint(100,300))
    return lista

def promedioLista(lista):
    return sum(lista)/len(lista)

def mostrarParametrosLista(lista):
    retorno="Tamaño: "+str(len(lista))+"\n"
    retorno+="Primeros 5 valores: "+str(lista[:5])+"\n"
    retorno+="Ultimos 5 valores: "+str(lista[-5:])
    return retorno

def filtrarLista(lista):
    promedio=promedioLista(lista)
    
    #Definimos una funcion anonima utilizada como parametro en filter()
    funcionFiltro= lambda x: abs(x-promedio)<50
    
    return list(filter(funcionFiltro,lista))

def transformarLista(lista):
    
    #Definimos una funcion anonima utilizada como parametro en map()
    funcionMap= lambda numero: numero if numero>200 else 0
    
    return list(map(funcionMap,lista))

if __name__=="__main__":
    
    #Creamos una lista con 1000000 de numero entre 100 y 300, inclusive
    lista=crearLista()
    
    print("Promedio de los valores de la lista: "+str(promedioLista(lista)))
    
    print(mostrarParametrosLista(lista))
    
    print()
    
    #Creamos una copia de la lista, que esta filtrada,
    #la guardamos y mostramos sus parametros
    listaFiltrada=filtrarLista(lista)
    print(mostrarParametrosLista(listaFiltrada))
    
    print()
    
    #Creamos una copia de la lista, esta vez, despues de
    #ser transformada y mostramos sus parametros
    listaTransformada=transformarLista(listaFiltrada)
    print(mostrarParametrosLista(listaTransformada))
    