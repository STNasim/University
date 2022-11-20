# -*- coding: utf-8 -*-
"""
Created on Thu May 20 17:16:04 2021

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
        
class Stock(Producto):
    fechaActual="25/07/21"
    def __init__(self):
        self.productos=[]
        
    def agregarProducto(self,pProducto):
        self.productos.append(pProducto)
    
    def comprar5(self):
        retorno=0
        for producto in self.productos:
            retorno+=producto.getPrecio()*5
        return retorno
    def consultarStock(self):
        retorno=[]
        for producto in self.productos:
            retorno.append((producto.getCodigo(),(producto.getCantidad())))
        return retorno
    def informarExcasos(self):
        retorno=[]
        for producto in self.productos:
            cantidad=producto.getCantidad()
            if cantidad<2:
                retorno.append(producto.getCodigo())
        return retorno
    def productosCercaVencer(self,pDias):
        retorno=[]
        for producto in self.productos:
            dias=producto.vencimiento(Stock.fechaActual)
            if dias<=pDias:
                retorno.append((producto.getCodigo(),dias))
        return retorno
    
    