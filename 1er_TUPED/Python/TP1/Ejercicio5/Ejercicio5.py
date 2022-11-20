# -*- coding: utf-8 -*-
"""
Created on Mon May 24 19:29:12 2021

@author: PC
"""

from random import randint

def tiradaDeDados(): #Se devuelve una tirada con 5 dados de 6 caras
    tirada=[]
    for i in range(5):
        tirada.append(randint(1,6))
    return tirada

def calcularPuntaje(tirada): #Se remueve el elemento mayor y menor de la tirada
    tirada.remove(max(tirada))
    tirada.remove(min(tirada))
    return sum(tirada)
    
def conocerGanador(puntajeCubitus,puntajeHumerus): #Se devuelve el veredicto en base
    if puntajeCubitus>puntajeHumerus:              # a los puntajes de cada uno
        return ("Ha ganado Cubitus")
    elif puntajeCubitus<puntajeHumerus:
        return ("Ha ganada Humerus")
    else:
        return ("Han empatado")
        
if __name__=="__main__":
    
    print("JUEGO DE DADOS\n")
    
    tiradaCubitus=tiradaDeDados()
    print("Tirada de Cubitus: "+str(tiradaCubitus))
    puntajeCubitus=calcularPuntaje(tiradaCubitus)
    print("Cubitus ha sacado "+str(puntajeCubitus)+" puntos\n")   

    tiradaHumerus=tiradaDeDados()
    print("Tirada de Humerus: "+str(tiradaHumerus))
    puntajeHumerus=calcularPuntaje(tiradaHumerus)
    print("Humerus ha sacado "+str(puntajeHumerus)+" puntos\n")
    
    print(conocerGanador(puntajeCubitus,puntajeHumerus))