# -*- coding: utf-8 -*-

palabra=input("Ingrese la palabra: ")
palindromo=True
i=0
while palindromo:
    if(palabra[0+i]!=palabra[len(palabra)-1-i]):
        palindromo=False
    i=i+1
    if(i>len(palabra)/2):
        break

if(palindromo):
    print("Es palindromo")
else:
    print("No es palindromo")