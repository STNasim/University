# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 11:47:00 2021

@author: PC
"""

def repetidos(tupla):
    if (tuple(set(tupla)))==tupla:
        return False
    else:
        return True


if __name__=="__main__":
    tupla=(3,2,5,6,3)
    tupla2=(1,2,3,4,5)
    
    if repetidos(tupla):
        print("Hay repetidos en tupla 1")
    else:
        print("No hay repetidos en tupla 1")
        
    if repetidos(tupla2):
        print("Hay repetidos en tupla 2")
    else:
        print("No hay repetidos en tupla 2")