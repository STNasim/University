from PyQt5 import QtWidgets
import pyqtgraph
from collections import Counter

def obtener_grafico_hora(file_path):
    conteo_horas=_conteo_por_hora(file_path)
    y = list(conteo_horas.values())
    x = list(conteo_horas.keys())
    grafico_hora = pyqtgraph.PlotWidget()
    grafico_hora.setBackground('w')
    grafico_hora.setLabel('left', 'Cantidad de accesos')
    grafico_hora.setLabel('bottom', 'Hora')
    grafico_hora.plot(x = x, y = y)
    return grafico_hora

def obtener_grafico_dia(file_path):
    conteo_dias=_conteo_por_dia(file_path)
    y = list(conteo_dias.values())
    x = list(conteo_dias.keys())
    grafico_dia = pyqtgraph.PlotWidget()
    grafico_dia.setBackground('w')
    grafico_dia.setLabel('left', 'Cantidad de accesos')
    grafico_dia.setLabel('bottom', 'Dia')
    grafico_dia.plot(x = x, y = y)
    return grafico_dia

def _conteo_por_hora(file_path):
    counter = Counter()
    with open(file_path, 'r') as file:
        lineas=file.readlines()
        for linea in lineas:
            split_line = linea.split(';',2)[1]
            hora = split_line.split(':',2)[1]
            counter.update({int(hora)})
    file.close()

    complete_counter = Counter({hour: 0 for hour in range(24)})
    for hour, count in counter.items():
        complete_counter[hour] = count
    return complete_counter

def _conteo_por_dia(file_path):
    counter = Counter()
    with open(file_path, 'r') as file:
        lineas=file.readlines()
        for linea in lineas:
            split_line = linea.split(';',2)[1]
            dia = split_line.split('/',2)[0]
            counter.update({int(dia)})
    file.close()

    complete_counter = Counter({day: 0 for day in range(1,32)})
    for day, count in counter.items():
        complete_counter[day] = count
    print(complete_counter.keys())
    return complete_counter

if __name__=="__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    grafico = obtener_grafico_dia("access_log_edw.csv")
    grafico.show()
    sys.exit(app.exec_())