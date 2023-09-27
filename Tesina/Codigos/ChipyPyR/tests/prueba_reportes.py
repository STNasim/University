import pandas as pd

from fabrica_reportes import FabricaReportes
from mostrar_grafico import mostrar_grafico

if __name__ == "__main__":
    fabrica_reportes = FabricaReportes()
    '''
    datos = {'p-value': [1.5, -0.5, 2, -1.2, 3],
             't': [2, 1, 5, 8, 6]}
    datos = pd.DataFrame(datos)
    reportador = fabrica_reportes.crear_reporte("Limma",datos)
    mostrar_grafico(reportador.obtener_figura())
    '''

    datos = {'Alfa': [4, 5, 6, 7, 8, 20],
        'Prueba Beta': [14, 35, 87, 27, 86, 100],
        'A': [24, -55, -36, 75, 88, 40],
        'B': [12, -32, -86, 75, 75, 23]}
    grupos = ['Control','Tratamiento','Control','Tratamiento']
    datos = pd.DataFrame(datos)
    reportador = fabrica_reportes.crear_reporte("sondas", datos, grupos)
    mostrar_grafico(reportador.obtener_figura())