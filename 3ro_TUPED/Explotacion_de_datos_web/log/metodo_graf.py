from PyQt5 import QtWidgets, QtChart
from collections import Counter

def obtener_grafico_metodo(file_path):
    conteo_metodo=_conteo_por_metodo(file_path)
    series = QtChart.QPieSeries()
    for key, value in conteo_metodo.items():
        _slice = QtChart.QPieSlice(key, value)
        #_slice.setBrush(QtGui.QColor(randint(0,255), randint(0,255), randint(0,255)))
        series.append(_slice)

    grafico_metodo = QtChart.QChart()
    grafico_metodo.addSeries(series)

    grafico_metodo.legend().detachFromChart()
    grafico_metodo.legend().setMinimumSize(1000, 500)

    return grafico_metodo

def _conteo_por_metodo(file_path):
    counter = Counter()
    with open(file_path, 'r') as file:
        lineas=file.readlines()
        for linea in lineas:
            metodo = linea.split(';',4)[2]
            counter.update({metodo:1})
    file.close()
    return counter


if __name__=="__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    grafico = obtener_grafico_metodo("access_log_edw.csv")
    view = QtChart.QChartView(grafico)
    view.show()
    sys.exit(app.exec_())