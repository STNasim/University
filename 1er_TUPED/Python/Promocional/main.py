# -*- coding: utf-8 -*-
"""
Created on Fri Jun 25 16:42:03 2021

@author: PC
"""

from GeneradorDeInformes2 import leerDatos,guardarInforme

datos=leerDatos("huertas-familiares-por-provincia.csv")
guardarInforme(datos)