# -*- coding: utf-8 -*-

nombre=input("Ingrese nombre: ")
apellido=input("Ingrese apellido: ")
institucion=input("Ingrese institucion: ")

mail=nombre[0].lower()+apellido.lower()+"@"+institucion.lower()+".com"

print("El mail es: "+mail)