# -*- coding: utf-8 -*-
"""
Created on Fri Jun 25 17:37:02 2021

@author: PC
"""

def leerDatos(nombre):
    
    ids=[]
    provincias=[]
    datosAño1=[]
    datosAño2=[]
    datosAño3=[]
    with open(nombre) as f:
        #encabezado=f.readline() Por si se quisiera guardar el encabezado
        f.readline()
        for linea in f:
            datosLinea=linea.split(",") #Se separa cada dato en la coma
            ids.append(datosLinea[0])
            provincias.append(datosLinea[1])
            datosAño1.append(int(datosLinea[2]))
            datosAño2.append(int(datosLinea[3]))
            datosAño3.append(int(datosLinea[4]))
            
    return [ids,provincias,datosAño1,datosAño2,datosAño3]
        
def huertasPorAño(datos):
    #Se hace la sumatoria de todos los datos de cada año y se devuelven
    cantidadHuertas=[sum(datos[2]),sum(datos[3]),sum(datos[4])]
        
    return cantidadHuertas

def masHuertas(datos):
    #Se encuentran las cantidades mayores de huertas de cada año
    cantidadesMayores=[max(datos[2]),max(datos[3]),max(datos[4])]
    
    #Se encuentra que lugar ocupa la provincia con la mayor cantidad de huertas
    indiceProvinciasMayores=[datos[2].index(cantidadesMayores[0]),
                             datos[3].index(cantidadesMayores[1]),
                             datos[4].index(cantidadesMayores[2])]
    
    #Se guarda el nombre correspondiente a la provincia en ese lugar
    nombreProvinciasMayores=[datos[1][indiceProvinciasMayores[0]],
                             datos[1][indiceProvinciasMayores[1]],
                             datos[1][indiceProvinciasMayores[2]]]
    
    return nombreProvinciasMayores
        
def menosHuertas(datos):
    
    #Similar a masHuertas solo que con las cantidades menores
    cantidadesMenores=[min(datos[2]),min(datos[3]),min(datos[4])]
    
    indiceProvinciasMenores=[datos[2].index(cantidadesMenores[0]),
                             datos[3].index(cantidadesMenores[1]),
                             datos[4].index(cantidadesMenores[2])]
    
    nombreProvinciasMenores=[datos[1][indiceProvinciasMenores[0]],
                             datos[1][indiceProvinciasMenores[1]],
                             datos[1][indiceProvinciasMenores[2]]]
    
    return nombreProvinciasMenores

def promedioHuertas(datos):
    
    promedios=[]
    
    #Se ejecuta en cada provincia, midiendo la cantidad de ids guardadas
    for i in range(len(datos[0])):
        #Se guarda el nombre de la provincia y se calcula el promedio de las 
        #cantidades en los 3 años
        nombre=datos[1][i]
        promedio=(datos[2][i]+datos[3][i]+datos[4][i])/3
        promedios.append((nombre,promedio))
    
    return promedios

def guardarInforme(datos):
    with open("informe.txt", 'tw', encoding='utf_8') as archi:
        archi.write("Informe: \n")
        
        archi.write("Cantidad total de huertas por año: "+str(huertasPorAño(datos))+"\n")
        
        archi.write("Provincias con mayores huertas en cada año: "+
                    str(masHuertas(datos))+"\n")
        
        archi.write("Provincias con menores huertas en cada año: "+
                    str(menosHuertas(datos))+"\n")
        
        auxPromedioHuertas=promedioHuertas(datos)
        
        archi.write("Promedio de huertas por provincia:\n")
        
        for promedio in auxPromedioHuertas:
            archi.write(str(promedio[0])+": "+str(round(promedio[1],2))+"\n")
        
if __name__=="__main__":
    
    datos=leerDatos("huertas-familiares-por-provincia.csv")
    print(datos)
    print()
    print("Las huertas por año son: "+str(huertasPorAño(datos))+"\n")
    print("Provincias con mayores huertas: "+str(masHuertas(datos))+"\n")
    print("Provincias con menores huertas: "+str(menosHuertas(datos))+"\n")
    print("Promedio de huertas por provincia: "+str(promedioHuertas(datos)))
    
    guardarInforme(datos)