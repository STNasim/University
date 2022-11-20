# -*- coding: utf-8 -*-

print("Ingrese las notas, -1 para finalizar")

ingreso=int(input())
notas=[]
while(ingreso!=-1):
    notas.append(ingreso)
    ingreso=int(input("Ingrese la nota:"))
total=0
for i in notas:
    total=total+notas[i]
print("El promedio es: "+str(total/len(notas)))