# -*- coding: utf-8 -*-
"""
Created on Sat May 22 08:00:07 2021

@author: PC
"""

class Persona():
    def __init__(self,pNombre="",pApellido="",pDNI=-1,pEmail=""):
        self.__nombre=pNombre
        self.__apellido=pApellido
        self.__DNI=pDNI
        self.__email=pEmail
    def __str__(self):
        return (self.__nombre+","+self.__apellido+","+str(self.__DNI)+","+self.__email)
