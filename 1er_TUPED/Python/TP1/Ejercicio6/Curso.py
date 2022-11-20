# -*- coding: utf-8 -*-
"""
Created on Mon May 24 20:05:41 2021

@author: PC
"""
from EstudiantesYDocentes import Estudiante
from EstudiantesYDocentes import Docente

class Curso(Docente,Estudiante):
    
    def __init__(self,pIdentificador,pNombre,pDocente=Docente()):
        self.__identificador=pIdentificador
        self.__nombre=pNombre
        self.__docenteACargo=pDocente
        self.__listaEstudiantes=[]
        
    def __str__(self):
        
        mostrar=("["+str(self.__identificador)+","+self.__nombre+",")
        
        mostrar+=self.__docenteACargo.getDatos()
        
        for estudiante in self.__listaEstudiantes:
            mostrar+=(","+"\n"+estudiante.getDatos())
            
        mostrar+="]"
        return mostrar
    
    def agregarEstudiante(self,pEstudiante):
        if pEstudiante not in self.__listaEstudiantes:
            self.__listaEstudiantes.append(pEstudiante)
            
    def getNombre(self):
        return self.__nombre
    
    def getDatos(self):
        return self.__str__()
    
    def getIdentificador(self):
        return self.__identificador
    
    def setDocente(self,pDocente):
        self.__docenteACargo=pDocente
    def getDocente(self):
        return self.__docenteACargo
    
    def getEstudiantes(self):
        return self.__listaEstudiantes