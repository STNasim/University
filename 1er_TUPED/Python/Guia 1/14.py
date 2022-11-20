# -*- coding: utf-8 -*-

kilometrajeInicial=500
kilometrajeFinal=1000
naftaPorKilometro=3
PrecioNafta=100

descuento=50

consumo=(kilometrajeFinal-kilometrajeInicial)*naftaPorKilometro*(PrecioNafta*(1-descuento/100))

print("El costo es: "+ str(consumo))