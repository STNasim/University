# -*- coding: utf-8 -*-
"""
Created on Sat May 22 08:26:13 2021

@author: PC
"""

from Persona import Persona

class Paciente(Persona):
    def __init__(self,pNombre,pApellido,pDNI,pEmail,pMasa,pAltura):
        super().__init__(pNombre,pApellido,pDNI,pEmail)
        self.__masa=pMasa
        self.__altura=pAltura
    def __str__(self):
        return ("["+super().__str__()+","+str(self.__masa)+"Kg,"+str(self.__altura)+"m]")
    def calcularIMC(self):
        return (self.__masa/self.__altura**2)
    def  __lt__(self, pPaciente):
        if self.calcularIMC()<pPaciente.calcularIMC():
            return True
        else:
            return False
    
if __name__=="__main__":
    lista=[Paciente("Juan","Perez",42142492,"pjuan@gmail.com",80,1.80)]
    lista.append(Paciente("Pedro","Salim",43252185,"spedro@gmail.com",90,1.90))
    lista.append(Paciente("Jorge","Benitez",98324195,"bjorge@gmail.com",40,1.20))
    lista.append(Paciente("Agustin","Schneider",52343232,"sagus@gmail.com",50,1.50))
    lista.append(Paciente("Martin","Dodera",43245987,"dmartin@gmail.com",70,1.60))
    lista.append(Paciente("Jose","Villa",53234123,"vjose@gmail.com",100,1.70))
    
    for paciente in lista:
        print(paciente)
    print("\n")
    lista.sort(key=Paciente.calcularIMC)
    for paciente in lista:
        print(paciente)
    for paciente in lista:
        print(paciente.calcularIMC())
    print(str(max(lista))+str(max(lista).calcularIMC()))