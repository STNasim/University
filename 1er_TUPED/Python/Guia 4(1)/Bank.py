# -*- coding: utf-8 -*-
"""
Created on Thu May 20 17:19:25 2021

@author: PC
"""

from BankAccount import BankAccount

class Bank(BankAccount):
    cantCuentas=0
    def __init__(self):
        self.__cuentas__=[]
    
    def __str__(self):
        retorno=""
        for cuenta in self.__cuentas__:
            retorno+="["+str(cuenta.getCBU())+","+str(cuenta.getBalance())+"]"
        return retorno
    def consultarMonto(self,CBU):
        aux=0
        i=-1
        while(aux!=CBU and i<Bank.cantCuentas):
            i+=1
            aux=self.__cuentas__[i].getCBU()
        if i<Bank.cantCuentas:
            return self.__cuentas__[i].getBalance()
        else:
            return -1
            
    def agregarCuentas(self,CBU,monto):
        self.__cuentas__.append(BankAccount(CBU,monto))
        Bank.cantCuentas+=1
    
    def transferir(self,CBU1,CBU2,monto):
        cuenta1=-1
        cuenta2=-1
        i=0
        for cuenta in self.__cuentas__:
            if cuenta.getCBU()==CBU1:
                cuenta1=i
            if cuenta.getCBU()==CBU2:
                cuenta2=i    
            i+=1
        if cuenta1!=-1 and cuenta2!=-1:
            if self.__cuentas__[cuenta1].getBalance()>=monto:
                self.__cuentas__[cuenta1].withdraw(monto)
                self.__cuentas__[cuenta2].deposit(monto)
                
    def ordenarCBU(self):
        self.__cuentas__.sort(key=BankAccount.getCBU)
        
    def ordenarMonto(self):
        self.__cuentas__.sort(key=BankAccount.getBalance)
    
if __name__== "__main__":
    banco=Bank()
    banco.agregarCuentas(23, 500)
    banco.agregarCuentas(65, 0)
    banco.transferir(23, 65, 600)
    banco.agregarCuentas(2, 700)
    banco.agregarCuentas(6, 300)
    banco.agregarCuentas(10, 500)
    banco.agregarCuentas(25, 100)
    banco.ordenarCBU()
    print(banco)
    banco.ordenarMonto()
    print(banco)
    print(banco.consultarMonto(2))