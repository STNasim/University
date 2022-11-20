# -*- coding: utf-8 -*-
"""
Created on Thu May 20 16:33:09 2021

@author: PC
"""
from Stock import Stock
from Stock import Producto
    
    
if __name__== "__main__":
    stock=Stock()
    stock.agregarProducto(Producto("4234","ABC","Limpieza","20/05/21","30/07/21",2,15))
    stock.agregarProducto(Producto("444","GXZ","Bebida","25/05/21","05/02/20",41,23))
    stock.agregarProducto(Producto("532","ADE","Comida","21/05/21","20/03/21",534,1))
    print(stock.comprar5())
    print(stock.consultarStock())
    print(stock.informarExcasos())
    print(stock.productosCercaVencer(5))