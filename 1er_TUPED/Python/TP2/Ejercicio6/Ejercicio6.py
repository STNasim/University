# -*- coding: utf-8 -*-
"""
Created on Thu Jun 17 16:06:30 2021

@author: PC
"""

def ordenarVehiculos(registro):
    listaAutos=[]
    listaMotos=[]
    
    for vehiculo in registro:
        if isinstance(vehiculo, Moto):
            listaMotos.append(vehiculo)
        elif isinstance(vehiculo,Auto):
            listaAutos.append(vehiculo)
            
    #Despues de separar autos y motos en 2 listas, se ordenan cada uno
    #en base al criterio correspondiente a cada tipo de vehiculo
    return sorted(listaAutos,key=lambda x: x.getModelo())+sorted(listaMotos,key=lambda x: x.getCilindrada())

from Vehiculos import Moto,Auto

if __name__=="__main__":
    
    registroVehiculos=[Moto("312FDA","Kawasaki","sport",400,"Digital"),
                       Moto("534FAS","BMW","turismo",300,"Digital"),
                       Moto("123HGF","Kawasaki","turismo",100,"Analogico"),
                       Moto("536NVD","BMW","sport",300,"Digital"),
                       Moto("623BVC","Honda","sport",400,"Digital"),
                       Moto("126BVR","Honda","turismo",200,"Analogico"),
                       Auto("432GTA","BMW","X6",4,500,2),
                       Auto("231GHC","BMW","X4",4,700,2),
                       Auto("523VUJ","Tesla","S",5,700,4),
                       Auto("163BTE","Tesla","X",3,400,3),
                       Auto("528BJY","Chevrolet","Camaro",2,200,2),
                       Auto("905VYR","Chevrolet","Tracker",5,700,5),]
   
    print("\nRegistroAntesDeOrdenar: ")
    for vehiculo in registroVehiculos:
        print(vehiculo)
    
    registroOrdenado=ordenarVehiculos(registroVehiculos)
    
    print("\nRegistroOrdenado: ")
    for vehiculo in registroOrdenado:
        print(vehiculo)
    