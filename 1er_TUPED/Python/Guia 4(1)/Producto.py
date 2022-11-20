# -*- coding: utf-8 -*-
"""
Created on Thu May 20 15:58:31 2021

@author: PC
"""

class Producto:
    def __init__(self,pCodigo="0",pMarca="",pCategoria="",pFechaElaboracion="??/??/??",pFechaVencimiento="??/??/??",pPrecio=0,pCantidad=0):
        self.__codigo__=pCodigo
        self.__marca__=pMarca
        self.__categoria__=pCategoria
        self.__fechaElaboracion__=pFechaElaboracion
        self.__fechaVencimiento__=pFechaVencimiento
        self.__precio__=pPrecio
        self.__cantidad__=pCantidad
    
    def getCodigo(self):
        return self.__codigo__
    def setCodigo(self,pCodigo):
        self.__codigo__=pCodigo
        
    def getMarca(self):
        return self.__marca__
    def setMarca(self,pMarca):
        self.__marca__=pMarca
             
    def getCategoria(self):
        return self.__categoria__
    def setCategoria(self,pCategoria):
        self.__categoria__=pCategoria
    
    def getFechaElaboracion(self):
        return self.__fechaElaboracion__
    def setFechaElaboracion(self,pFechaElaboracion):
        self.__fechaElaboracion__=pFechaElaboracion
        
    def getFechaVencimiento(self):
        return self.__fechaVencimiento__
    def setFechaVencimiento(self,pFechaVencimiento):
        self.__fechaVencimiento__=pFechaVencimiento
        
    def getPrecio(self):
        return self.__precio__
    def setPrecio(self,pPrecio):
        self.__precio__=pPrecio
    
    def getCantidad(self):
        return self.__cantidad__
    def setCantidad(self,pCantidad):
        self.__cantidad__=pCantidad
    
    def vencimiento(self,pFechaActual):
        fechaActual=pFechaActual
        if self.__fechaVencimiento__=="??/??/??":
            return -1.5
        else:
            diaActual=int(fechaActual[0])*10+int(fechaActual[1])
            mesActual=int(fechaActual[3])*10+int(fechaActual[4])
            anioActual=int(fechaActual[6])*10+int(fechaActual[7])
            diaVencimiento=int(self.__fechaVencimiento__[0])*10+int(self.__fechaVencimiento__[1])
            mesVencimiento=int(self.__fechaVencimiento__[3])*10+int(self.__fechaVencimiento__[4])
            anioVencimiento=int(self.__fechaVencimiento__[6])*10+int(self.__fechaVencimiento__[7])
            retorno=(anioVencimiento-anioActual)*365
            retorno+=(mesVencimiento-mesActual)*30
            retorno+=(diaVencimiento-diaActual)
            return retorno
            
if __name__== "__main__":
    producto1=Producto("4234","ABC","Limpieza","20/05/21","30/07/21",43,64)
    print(producto1.vencimiento("25/05/21"))