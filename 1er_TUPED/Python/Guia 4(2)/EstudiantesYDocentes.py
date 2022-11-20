# -*- coding: utf-8 -*-
"""
Created on Sat May 22 08:02:42 2021

@author: PC
"""

from Persona import Persona

class Estudiante(Persona):
    def __init__(self,pNombre="",pApellido="",pDNI=-1,pEmail="",pMatricula=-1):
        super().__init__(pNombre,pApellido,pDNI,pEmail)
        self.__matricula=pMatricula
    def __str__(self):
        return ("["+super().__str__()+","+str(self.__matricula)+"]")
    def getDatos(self):
        return self.__str__()
    
class Docente(Persona):
    def __init__(self,pNombre="",pApellido="",pDNI=-1,pEmail="",pTitulo=""):
        super().__init__(pNombre,pApellido,pDNI,pEmail)
        self.__titulo=pTitulo
    def __str__(self):
        return ("["+super().__str__()+","+str(self.__titulo)+"]")
    def getDatos(self):
        return self.__str__()
    
if __name__=="__main__":
    estudiante1=Estudiante("Juan","Perez",42142492,"pjuan@gmail.com",21342)
    estudiante2=Estudiante("Pedro","Salim",43252185,"spedro@gmail.com",64353)
    estudiante3=Estudiante("Jose","Villa",53234123,"vjose@gmail.com",663458)
    print(estudiante1)
    print(estudiante2)
    print(estudiante3)
    docente1=Docente("Pepe","Perez",42142492,"ppepe@gmail.com","Matematica")
    docente2=Docente("Fulano","Martinez",43252185,"mfulano@gmail.com","Geografia")
    docente3=Docente("Mengano","Fernandez",53234123,"fmengano@gmail.com","Historia")
    print(docente1)
    print(docente2)
    print(docente3)
    print(issubclass(Docente,Persona))
    
    print(docente1.getNombre())