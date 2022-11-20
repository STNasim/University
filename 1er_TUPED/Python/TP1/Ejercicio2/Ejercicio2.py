# -*- coding: utf-8 -*-
"""
Created on Mon May 24 16:22:10 2021

@author: PC
"""

from operaciones_naturales import es_par,divisores,es_primo,factorial

if __name__=="__main__":
    
    numero=int(input("Ingrese el numero: "))
    
    print("¿El numero es par?"+str(es_par(numero)))
    print()
    print("Los divisores del numero son: ")
    print(divisores(numero))
    print()
    print("¿El numero es primo?"+str(es_primo(numero)))
    print()
    print("El factorial de el numero es: ")
    print(factorial(numero))