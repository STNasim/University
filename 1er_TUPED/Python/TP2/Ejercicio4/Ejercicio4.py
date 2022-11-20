# -*- coding: utf-8 -*-
"""
Created on Thu Jun 17 12:12:28 2021

@author: PC
"""

def leerDatos(nombre):
    
    datos=[]
    with open(nombre) as f:
        #titulo=f.readline() Por si se quisiera guardar el titulo
        f.readline()
        horas = (f.readline().split())      #Se leen las lineas con datos y se separan
        temperaturas= (f.readline().split())
        
        horas=[int(elemento) for elemento in horas] #Se convierten los valores a int
        temperaturas=[int(elemento) for elemento in temperaturas]
        
        for i in range(len(horas)): #Se agregar los datos como tuplas a una lista
            datos.append((horas[i],temperaturas[i]))
            
    return datos

def calcularTemperaturaMedia(datos):
    
    sumatoria=0
    for dato in datos:
        sumatoria+=dato[1]

    return sumatoria/len(datos)

def devolverTemperaturaMaxima(datos):
    
    tempMaxima=max(datos,key=lambda x:x[1])[1] #Se guarda el valor de temperatura maxima
    horas=[]
    
    for dato in datos: #Se compara con los valores de temperatura y si coincide
                       #se agrega el valor de la hora a la lista horas
        if dato[1]==tempMaxima:
            horas.append(dato[0])
            
    return (tempMaxima,horas)

def devolverTemperaturaMinima(datos):
    
    tempMinima=min(datos,key=lambda x:x[1])[1]
    horas=[]
    
    for dato in datos:
        if dato[1]==tempMinima:
            horas.append(dato[0])
            
    return (tempMinima,horas)

def cuantasHorasDebajoDe10(datos):
    
    resultado=0
    for dato in datos:
        if dato[1]<10:
            resultado+=1
            
    return resultado

def guardarDatos(datos):
    
    with open("informe.txt", 'tw', encoding='utf_8') as archi:
        archi.write("Resultados obtenidos: \n")
        archi.write("Temperatura media: "+str(calcularTemperaturaMedia(datos))+"\n")
        datosTemperaturaMaxima=devolverTemperaturaMaxima(datos)
        archi.write("Temperatura maxima: "+str(datosTemperaturaMaxima[0])+"ºC"+"\n")
        archi.write("Horas de temperatura maxima: :"+str(datosTemperaturaMaxima[1])+"\n")
        datosTemperaturaMinima=devolverTemperaturaMinima(datos)
        archi.write("Temperatura minima: "+str(datosTemperaturaMinima[0])+"ºC"+"\n")
        archi.write("Horas de temperatura minima: :"+str(datosTemperaturaMinima[1])+"\n")
        archi.write("Cantidad de horas con temperatura menor a 10ºC: "+
                    str(cuantasHorasDebajoDe10(datos)))

if __name__=="__main__":
    
    datos=leerDatos("temperaturas.txt")
    
    print(calcularTemperaturaMedia(datos))
    print(devolverTemperaturaMaxima(datos))
    print(devolverTemperaturaMinima(datos))
    print(cuantasHorasDebajoDe10(datos))
    
    guardarDatos(datos)