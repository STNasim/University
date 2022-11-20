# -*- coding: utf-8 -*-
"""
Created on Thu Jun 17 16:16:48 2021

@author: PC
"""

class Vehiculo:
   
    def __init__(self,pPatente="",pMarca="",pModelo=""):
        self.__patente=pPatente
        self.__marca=pMarca
        self.__modelo=pModelo
   
    def __str__(self):
        return (self.__patente+","+self.__marca+","+self.__modelo)
    
    def getModelo(self):
        return self.__modelo

class Auto(Vehiculo):
   
    def __init__(self,pPatente="",pMarca="",pModelo="", pPlazas=0, pVolumenBaul=0, pAirbags=0):
        super().__init__(pPatente,pMarca,pModelo)
        self.__plazas=pPlazas
        self.__volumenBaul=pVolumenBaul
        self.__airbags=pAirbags
   
    def __str__(self):
        return ("["+super().__str__()+","+str(self.__plazas)+","+str(self.__volumenBaul)+","+
                str(self.__airbags)+"]")
    
    def getModelo(self):
        return super().getModelo()
        
class Moto(Vehiculo):
    def __init__(self,pPatente="",pMarca="",pModelo="", pCilindrada=0, pTablero=""):
        super().__init__(pPatente,pMarca,pModelo)
        self.__cilindrada=pCilindrada
        self.__tablero=pTablero
        
    def __str__(self):
        return ("["+super().__str__()+","+str(self.__cilindrada)+","+self.__tablero+"]")
    
    def getCilindrada(self):
        return self.__cilindrada