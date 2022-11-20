# -*- coding: utf-8 -*-
"""
Created on Mon May 24 20:39:46 2021

@author: PC
"""

import random
from EstudiantesYDocentes import Estudiante
from EstudiantesYDocentes import Docente
from SistemaGC import SistemaGC

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