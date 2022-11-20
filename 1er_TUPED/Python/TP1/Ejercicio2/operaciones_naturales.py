# -*- coding: utf-8 -*-
"""
Created on Mon May 24 16:23:28 2021

@author: PC
"""

def es_par(numero):
    retorno=False
    if numero%2==0:
        retorno=True
    return retorno

def divisores(numero):
    
    #No contemplamos al 0 como numero natural
    listaDivisores=[]
    
    #Se verifica si todos los numeros desde el 1 hasta el numero recibido
    #dan como resto 0 al dividir el numero por ellos y se agregan a la lista
    for i in range (1,numero+1):
        if numero%i==0:
            listaDivisores.append(i)
    return listaDivisores

def es_primo(numero):
    #No contemplamos al 0 como numero natural
    #No contemplamos el caso del numero 1 el cual no es primo ni compuesto
    primo=True
    i=2
    
    #Se divide el numero por todos los numeros desde el 2 hasta el anterior a el y en el
    #caso de que resulte un resto 0 al dividr, decimos que no es primo y se sale del bucle
    while i<numero:
        if numero%i==0:
            primo=False
            break
        i+=1
    return primo

def factorial(numero):
    
    #Decidimos calcular el factorial de manera iterativa ya que es mas 
    #eficiente al no necesitar hacer multiples llamadas a funciones
    resultado=1
    while numero>1:
        resultado*=numero
        numero-=1
    return resultado

if __name__=="__main__":
    
    print("¿El numero 3 es par?"+str(es_par(3)))
    print("¿El numero 6 es par?"+str(es_par(6)))
    print()
    print("Los divisores de 20 son: ")
    print(divisores(20))
    print("Los divisores de 7 son: ")
    print(divisores(7))
    print()
    print("¿El numero 391 es primo?"+str(es_primo(391)))
    print("¿El numero 23 es primo?"+str(es_primo(23)))
    print()
    print("El factorial de 10 es: ")
    print(factorial(10))
    
    
    
    
    
    
    
    
    
    