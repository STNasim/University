# -*- coding: utf-8 -*-

print("Ingrese matriz 1: ")
matriz1=[[0,0,0],[0,0,0],[0,0,0]]
matriz2=[[0,0,0],[0,0,0],[0,0,0]]
for f in range(3):
    for c in range(3):
        matriz1[f][c]=int(input("Ingrese "+str(f+1)+'f'+str(c+1)+'c'+": "))

print("Ingrese matriz 2: ")

for f in range(3):
    for c in range(3):
        matriz2[f][c]=int(input("Ingrese "+str(f+1)+'f'+str(c+1)+'c'+": "))

#CALCULO

matrizaux=[0,0,0]
matrizaux[0]=matriz1[0][0]*matriz2[0][0]+matriz1[0][1]*matriz2[1][0]+matriz1[0][2]*matriz2[2][0]
matrizaux[1]=matriz1[0][0]*matriz2[0][1]+matriz1[0][1]*matriz2[1][1]+matriz1[0][2]*matriz2[2][1]
matrizaux[2]=matriz1[0][0]*matriz2[0][2]+matriz1[0][1]*matriz2[1][2]+matriz1[0][2]*matriz2[2][2]

matrizresultado=[[matrizaux.copy()],[0,0,0],[0,0,0]]

matrizaux[0]=matriz1[1][0]*matriz2[0][0]+matriz1[1][1]*matriz2[1][0]+matriz1[1][2]*matriz2[2][0]
matrizaux[1]=matriz1[1][0]*matriz2[0][1]+matriz1[1][1]*matriz2[1][1]+matriz1[1][2]*matriz2[2][1]
matrizaux[2]=matriz1[1][0]*matriz2[0][2]+matriz1[1][1]*matriz2[1][2]+matriz1[1][2]*matriz2[2][2]

matrizresultado[1]=matrizaux.copy()

matrizaux[0]=matriz1[2][0]*matriz2[0][0]+matriz1[2][1]*matriz2[1][0]+matriz1[2][2]*matriz2[2][0]
matrizaux[1]=matriz1[2][0]*matriz2[0][1]+matriz1[2][1]*matriz2[1][1]+matriz1[2][2]*matriz2[2][1]
matrizaux[2]=matriz1[2][0]*matriz2[0][2]+matriz1[2][1]*matriz2[1][2]+matriz1[2][2]*matriz2[2][2]

matrizresultado[2]=matrizaux.copy()

print(matrizresultado)