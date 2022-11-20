# -*- coding: utf-8 -*-
"""
Created on Thu Jun 17 10:32:31 2021

@author: PC
"""
def ordenarPorNombre(diccionarioOriginal):
    #La funcion devuelve un diccionario ordenado por el segundo item que compone
    #al mismo, es decir su valor el cual representa el nombre
    return dict(sorted(diccionarioOriginal.items(), key=lambda x: x[1]))
    
def ordenarPorApellido(diccionarioOriginal):
    #En este caso en el ordenamiento se usa el primer item, la clave la cual 
    #es una tupla, por eso es que se utiliza el segundo componente, el apellido
    return dict(sorted(diccionarioOriginal.items(), key=lambda x: x[0][1]))

def ordenarPorEdad(diccionarioOriginal):
    #En este caso se utiliza el primer componente de la tupla, la edad
    return dict(sorted(diccionarioOriginal.items(), key=lambda x: x[0][0]))

def ordenarPorEdadYApellido(diccionarioOriginal):
    #En este caso se utiliza la tupla completa, ordenando
    #primero por edad y luego por apellido
    return dict(sorted(diccionarioOriginal.items(), key=lambda x: x[0]))

if __name__=="__main__":
    
    listaDiccionarios=[]
    listaDiccionarios.append({(43, "Perez"): "Juan",(43, "Fernandez"): "Pedro",
                              (43, "Gomez"): "Pablo",(43, "Dodera"): "Franco"})
    
    listaDiccionarios.append({(54, "Claure"): "Marco",(34, "Pogba"): "Pol",
                              (20, "Pascal"): "Kayn",(24, "Werner"): "Marco"})
    
    listaDiccionarios.append({(24, "Mbappe"): "Kylian",(15, "Mbappe"): "Cristiano",
                              (43, "Ramos"): "Sergio", (60, "Fabregas"): "Francesc"})
    
    print("\nDiccionarios originales: ")
    i=1
    for elemento in listaDiccionarios:
        print("\nEl diccionario "+str(i)+" es: ")
        print(elemento)
        i+=1
    
    print("\nOrdenar los diccionarios por nombre: ")
    i=1
    for elemento in listaDiccionarios:
        print("\nEl diccionario "+str(i)+" es: ")
        print(ordenarPorNombre(elemento))
        i+=1
    
    print("\nOrdenar los diccionarios por apellido: ")
    i=1
    for elemento in listaDiccionarios:
        print("\nEl diccionario "+str(i)+" es: ")
        print(ordenarPorApellido(elemento))
        i+=1
    
    print("\nOrdenar los diccionarios por edad: ")
    i=1
    for elemento in listaDiccionarios:
        print("\nEl diccionario "+str(i)+" es: ")
        print(ordenarPorEdad(elemento))
        i+=1
    
    print("\nOrdenar los diccionarios por edad y apellido:")
    i=1
    for elemento in listaDiccionarios:
        print("\nEl diccionario "+str(i)+" es: ")
        print(ordenarPorEdadYApellido(elemento))
        i+=1
    
    #No se modifican los diccionarios originales
    print("\nDiccionarios originales: ")
    i=1
    for elemento in listaDiccionarios:
        print("\nEl diccionario "+str(i)+" es: ")
        print(elemento)
        i+=1
    