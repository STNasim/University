# -*- coding: utf-8 -*-
"""
Created on Fri Jun 25 16:48:02 2021

@author: PC
"""

def leerDatos(nombre):
    
    datos=[]
    with open(nombre) as f:
        #encabezado=f.readline() Por si se quisiera guardar el encabezado
        f.readline()
        for linea in f:
            datosLinea=linea.split(",") #Se separa cada dato en la coma
            for i in range(2,5):
                datosLinea[i]=int(datosLinea[i]) #Se convierten las cantidad de huertas a
                                                 #variables numericas para operar facilmente
            datos.append(datosLinea) #Se agregan a la lista de datos que será devuelta
            
    return datos

def huertasPorAño(datos):
    cantidadHuertas=[0,0,0]
    
    for dato in datos: #Se acumulan las 3 cantidad de huertas en cada año
                       #para cada dato y se devuelven
        cantidadHuertas[0]+=dato[2]
        cantidadHuertas[1]+=dato[3]
        cantidadHuertas[2]+=dato[4]
        
    return cantidadHuertas

def masHuertas(datos):
    
    provinciasMayores=["","",""]
    cantidadesComparativas=[0,0,0]
    
    for dato in datos:
        #Se compara el dato de cada año y si es mayor se guarda el nombre de la
        #provincia y tambien la cantidad para futuras comparaciones
        if dato[2]>cantidadesComparativas[0]:
            provinciasMayores[0]=dato[1]
            cantidadesComparativas[0]=dato[2]
        if dato[3]>cantidadesComparativas[1]:
            provinciasMayores[1]=dato[1]
            cantidadesComparativas[1]=dato[3]
        if dato[4]>cantidadesComparativas[2]:
            provinciasMayores[2]=dato[1]
            cantidadesComparativas[2]=dato[4]
    return provinciasMayores
        
def menosHuertas(datos):
    provinciasMenores=["","",""]
    cantidadesComparativas=[datos[0][2],datos[0][3],datos[0][4]] #Se establecen como inicial los
                                                                 #datos de la primer provincia
    for dato in datos:
        #Similar a mas huertas solo que esta vez con el menor
        if dato[2]<cantidadesComparativas[0]:
            provinciasMenores[0]=dato[1]
            cantidadesComparativas[0]=dato[2]
        if dato[3]<cantidadesComparativas[1]:
            provinciasMenores[1]=dato[1]
            cantidadesComparativas[1]=dato[3]
        if dato[4]<cantidadesComparativas[2]:
            provinciasMenores[2]=dato[1]
            cantidadesComparativas[2]=dato[4]
    return provinciasMenores

def promedioHuertas(datos):
    
    promedios=[]
    
    for dato in datos:
        promedioProvincia=(dato[2]+dato[3]+dato[4])/3
        promedios.append((dato[1],promedioProvincia))
    
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
            archi.write(str(promedio[0])+": "+str(promedio[1])+"\n")
        
if __name__=="__main__":
    
    datos=leerDatos("huertas-familiares-por-provincia.csv")
    print(datos)
    print()
    print("Las huertas por año son: "+str(huertasPorAño(datos))+"\n")
    print("Provincias con mayores huertas: "+str(masHuertas(datos))+"\n")
    print("Provincias con menores huertas: "+str(menosHuertas(datos))+"\n")
    print("Promedio de huertas por provincia: "+str(promedioHuertas(datos)))
    
    guardarInforme(datos)