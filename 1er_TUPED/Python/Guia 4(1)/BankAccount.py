# -*- coding: utf-8 -*-
"""
Created on Thu May 20 14:42:33 2021

@author: PC
"""

class BankAccount:
    
    def __init__(self,pCBU,pBalance):
        self.__CBU__=pCBU
        self.__balance__=pBalance
    def deposit(self,cantidad):
        self.__balance__+=cantidad
    def withdraw(self,cantidad):
        self.__balance__-=cantidad
    def getBalance(self):
        return self.__balance__
    def getCBU(self):
        return self.__CBU__
    
if __name__== "__main__":
    cuenta1=BankAccount(52389, 0)
    cuenta2=BankAccount(89152, 0)
    cuenta3=BankAccount(9423, 0)  
    print(cuenta1.getBalance())
    cuenta1.deposit(324)    
    print(cuenta1.getBalance())
    cuenta1.withdraw(12)
    print(str(cuenta1.getBalance()))  
    print(str(cuenta1.getCBU())+" "+str(cuenta2.getCBU())+" "+str(cuenta3.getCBU()))
    
    