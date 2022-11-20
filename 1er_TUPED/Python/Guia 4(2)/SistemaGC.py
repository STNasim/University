# -*- coding: utf-8 -*-
"""
Created on Sat May 22 09:05:19 2021

@author: PC
"""
import random
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

class SistemaGC(Curso):
    def __init__(self,pListaCursos):
        self.__listaCursos=[]
        for pCurso in pListaCursos:
            self.__listaCursos.append(Curso(pCurso[0],pCurso[1]))
    
    def __str__(self):
        mostrar=""
        for curso in self.__listaCursos:
            mostrar+=curso.getDatos()+"\n"
        return mostrar
    
    def ubicarCurso(self,pIdentificador):
        aux=-1
        i=0
        tam=len(self.__listaCursos)
        while(True):
            aux=self.__listaCursos[i].getIdentificador()
            if(aux==pIdentificador):
                break
            i+=1
            if(i==tam):
                break
        if(i<tam):
            return i
        else:
            return -1
    
    def docenteDisponible(self,pDocente):
        cargos=0
        for curso in self.__listaCursos:
            if pDocente==curso.getDocente():
                cargos+=1
        if(cargos<2):
            return True
        else:
            return False
        
    def vincularDocente(self,pDocente,pIdentificador):
        index=self.ubicarCurso(pIdentificador)
        if index!=-1 and self.docenteDisponible(pDocente):
            self.__listaCursos[index].setDocente(pDocente)
            return True
        else:
            return False
        
    def vincularEstudiante(self,pEstudiante,pIdentificador):
        index=self.ubicarCurso(pIdentificador)
        if index!=-1:
            self.__listaCursos[index].agregarEstudiante(pEstudiante)
            return True
        else:
            return False
    
    def DatosDocente(self,nombre):
        cursos=[]
        for curso in self.__listaCursos:
            if nombre in curso.getDocente().getDatos():
                cursos.append(curso)
        if not cursos:
            return ("Ninguno",0)
        else:
            if len(cursos)==1:
                return (cursos[0].getNombre(),10000)
            else:
                return (cursos[0].getNombre()+","+cursos[1].getNombre(),20000)
    
    def DatosEstudiante(self,nombre):
        cursos=[]
        for curso in self.__listaCursos:
            for estudiante in curso.getEstudiantes():
                if nombre in estudiante.getDatos():
                    cursos.append(curso.getNombre())
        if not cursos:
            return ("Ninguno",0)
        else:
            inscripciones=""
            for curso in cursos:
                inscripciones+=curso+","
            inscripciones=inscripciones[:-1]
            return (inscripciones,len(cursos*6000))
    
    def DatosCurso(self,pIndicador):
        for curso in self.__listaCursos:
            if curso.getIdentificador()==pIndicador:
                return curso.getDatos()
        return "No existe el curso"
        
if __name__=="__main__":
    estudiante1=Estudiante("Juan","Perez",42142492,"pjuan@gmail.com",21342)
    estudiante2=Estudiante("Pedro","Salim",43252185,"spedro@gmail.com",64353)
    estudiante3=Estudiante("Jose","Villa",53234123,"vjose@gmail.com",663458)
    docente1=Docente("Pepe","Perez",42142492,"ppepe@gmail.com","Matematica")
    docente2=Docente("Fulano","Martinez",43252185,"mfulano@gmail.com","Geografia")
    docente3=Docente("Mengano","Fernandez",53234123,"fmengano@gmail.com","Historia")
    docente4=Docente("Juan","Arjona",53234123,"ajuan@gmail.com","Historia")
    
    lista=[(1,"Informatica Basica"),(2,"Matematica"),(3,"Biologia"),(4,"Geografia")]
    random.shuffle(lista)
    sistema=SistemaGC(lista)

    sistema.vincularDocente(docente1, 2)
    sistema.vincularDocente(docente1, 1)
    sistema.vincularDocente(docente1, 3)
    sistema.vincularEstudiante(estudiante1, 1)
    sistema.vincularEstudiante(estudiante2, 1)
    sistema.vincularEstudiante(estudiante1, 1)
    
    sistema.vincularDocente(docente2,3)
    sistema.vincularDocente(docente3,4)
    #No contempla docentes con mismo nombre    
    tupla1=sistema.DatosDocente("Pepe")
    tupla4=sistema.DatosDocente("Juan")
    tupla3=sistema.DatosDocente("Mengano")
    
    print(tupla1)
    print(tupla3)
    print(tupla4)
    print()
    sistema.vincularEstudiante(estudiante1, 2)
    sistema.vincularEstudiante(estudiante1, 3)
    sistema.vincularEstudiante(estudiante2, 2)
    sistema.vincularEstudiante(estudiante2, 3)
    
    #No contempla estudiantes con mismo nombre    
    tupla1=sistema.DatosEstudiante("Juan")
    tupla4=sistema.DatosEstudiante("Nasim")
    tupla3=sistema.DatosEstudiante("Jose")
    
    print(tupla1)
    print(tupla3)
    print(tupla4)
    
    print(sistema.DatosCurso(3))