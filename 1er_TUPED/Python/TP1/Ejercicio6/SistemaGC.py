# -*- coding: utf-8 -*-
"""
Created on Sat May 22 09:05:19 2021

@author: PC
"""
import random
from EstudiantesYDocentes import Estudiante
from EstudiantesYDocentes import Docente
from Curso import Curso

class SistemaGC(Curso):
    
    def __init__(self,pListaCursos):
        #Al inicializar se recibe como parametro una lista de tuplas que contienen
        #en el primer elemento el identificador del curso y en el segundo el nombre,
        #entonces se crea una lista y en cada elemento se crea un objeto Curso con los
        #parametros proveidos de la lista de tuplas
        self.__listaCursos=[]
        for pCurso in pListaCursos:
            self.__listaCursos.append(Curso(pCurso[0],pCurso[1]))
    
    def __str__(self):
        mostrar=""
        for curso in self.__listaCursos:
            mostrar+=curso.getDatos()+"\n"
        return mostrar
    
    def __ubicarCurso__(self,pIdentificador): #Metodo que sirve para saber si un curso
        aux=-1                                #Se encuentra registrado en el sistema
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
    
    def __docenteDisponible__(self,pDocente): #Metodo que se utiliza para saber si un
        cargos=0                              #docente esta disponible a aceptar cargos
        for curso in self.__listaCursos:
            if pDocente==curso.getDocente():
                cargos+=1
        if(cargos<2):
            return True
        else:
            return False
        
    def vincularDocente(self,pDocente,pIdentificador):
        index=self.__ubicarCurso__(pIdentificador)
        if index!=-1 and self.__docenteDisponible__(pDocente):
            self.__listaCursos[index].setDocente(pDocente)
            return True
        else:
            return False
        
    def vincularEstudiante(self,pEstudiante,pIdentificador):
        index=self.__ubicarCurso__(pIdentificador)
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
        cursosCursados=[]
        for curso in self.__listaCursos:
            for estudiante in curso.getEstudiantes():
                if nombre in estudiante.getDatos():
                    cursosCursados.append(curso.getNombre())
        if not cursosCursados:
            return ("Ninguno",0)
        else:
            inscripciones=""
            for curso in cursosCursados:
                inscripciones+=curso+","
            inscripciones=inscripciones[:-1]
            return (inscripciones,len(cursosCursados*6000))
    
    def DatosCurso(self,pIndicador):
        for curso in self.__listaCursos:
            if curso.getIdentificador()==pIndicador:
                return curso.getDatos()
        return "No existe el curso"
        
if __name__=="__main__":
    
    #Punto a 
    lista=[(1,"Informatica Basica"),(2,"Matematica"),(3,"Biologia"),(4,"Geografia")]
    random.shuffle(lista)
    sistema=SistemaGC(lista)
    
    #Punto b   
    docente1=Docente("Pepe","Perez",42142492,"ppepe@gmail.com","Matematica")
    docente2=Docente("Fulano","Martinez",43252185,"mfulano@gmail.com","Geografia")
    docente3=Docente("Mengano","Fernandez",53234123,"fmengano@gmail.com","Historia")
    docente4=Docente("Juan","Arjona",53234123,"ajuan@gmail.com","Historia")
    
    sistema.vincularDocente(docente1, 2)
    sistema.vincularDocente(docente1, 1)
    sistema.vincularDocente(docente1, 3)
    sistema.vincularDocente(docente2,3)
    sistema.vincularDocente(docente3,4)
    
    #Punto c
    estudiante1=Estudiante("Juan","Perez",42142492,"pjuan@gmail.com",21342)
    estudiante2=Estudiante("Pedro","Mendoza",43252185,"mpedro@gmail.com",64353)
    estudiante3=Estudiante("Jose","Villa",53234123,"vjose@gmail.com",663458)
    
    sistema.vincularEstudiante(estudiante1, 1)
    sistema.vincularEstudiante(estudiante2, 1)
    sistema.vincularEstudiante(estudiante1, 1)
    sistema.vincularEstudiante(estudiante1, 2)
    sistema.vincularEstudiante(estudiante1, 3)
    sistema.vincularEstudiante(estudiante2, 2)
    sistema.vincularEstudiante(estudiante2, 3)
    
    #Punto d    
    #No contempla docentes con mismo nombre    
    
    print("Datos de docentes:\n")
    print("Datos de Pepe: "+str(sistema.DatosDocente("Pepe")))
    print("Datos de Juan: "+str(sistema.DatosDocente("Juan")))
    print("Datos de Mengano: "+str(sistema.DatosDocente("Mengano")))
    
    print()
    
    #Punto e
    #No contempla estudiantes con mismo nombre 
    print("Datos de estudiantes:\n")
    print("Datos Juan: "+str(sistema.DatosEstudiante("Juan")))
    print("Datos Federico: "+str(sistema.DatosEstudiante("Federico")))
    print("Datos Jose: "+str(sistema.DatosEstudiante("Jose")))
    
    print()
    
    #Punto f
    print("Datos del curso 3:\n"+sistema.DatosCurso(3))