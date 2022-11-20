# -*- coding: utf-8 -*-
"""
Created on Thu Jun 17 15:20:48 2021

@author: PC
"""


def combinarDiccionarios(listaDiccionarios):
     
    diccionarioCombinado=dict()
    
    #Se busca en cada diccionario de la lista y se verifica si el nombre del
    #objeto de dicho diccionario ya se encuentra en el diccionario combinado,
    #en caso de no estarlo se agrega y se establece la cantidad de dicho objeto
    #segun el valor de la cantidad, si se encuentra ya en el diccionario
    #combinado, simplemente se suma la cantidad al mismo
    for diccionario in listaDiccionarios:
        if diccionario["objeto"] not in diccionarioCombinado:
            diccionarioCombinado[diccionario["objeto"]]=diccionario["cantidad"]
        else:
            diccionarioCombinado[diccionario["objeto"]]+=diccionario["cantidad"]  
    
    return diccionarioCombinado
    
if __name__=="__main__":
    
    listaDiccionarios=[{'objeto': "arroz", 'cantidad': 40},{'objeto': "fideos", 'cantidad': 30},
            {'objeto': "arroz", 'cantidad': 7},{'objeto': "fideos", 'cantidad': 13},
            {'objeto': "arroz", 'cantidad': 13},{'objeto': "ñoquis", 'cantidad': 12},
            {'objeto': "ñoquis", 'cantidad': 3},{'objeto': "ravioles", 'cantidad': 34},
            {'objeto': "ñoquis", 'cantidad': 0},{'objeto': "ravioles", 'cantidad': 64}]
    
    diccionarioCombinado=combinarDiccionarios(listaDiccionarios)
    
    print(diccionarioCombinado)