# -*- coding: utf-8 -*-

año=int(input("Ingrese el año: "))
mes=int(input("Ingrese el mes: "))
dia=int(input("Ingrese el dia: "))


if 2021-año<16:
    vota=False
if 2021-año>16:
    vota=True
elif mes<10:
    vota=True
elif mes>10:
    vota=False
elif dia<=24:
    vota=True
else:
    vota=False
if vota:
    print("Vota")
else:
    print("No vota")