from collections import Counter
from PyQt5 import QtWidgets
import requests

def obtener_tabla_ip(file_path):
    top10 = _top10_ip(file_path)
    tabla_ip = QtWidgets.QTableWidget()
    tabla_ip.setRowCount(10)
    tabla_ip.setColumnCount(3)
    tabla_ip.setHorizontalHeaderLabels(["IP", "Cantidad","Información"])
    tabla_ip.setColumnWidth(0, 200)
    tabla_ip.setColumnWidth(1, 100)
    tabla_ip.setColumnWidth(2, 1000)
    tabla_ip.resize(1300, 500)
    for i in range(10):
        tabla_ip.setItem(i, 0, QtWidgets.QTableWidgetItem(top10[i][0]))
        tabla_ip.setItem(i, 1, QtWidgets.QTableWidgetItem(str(top10[i][1])))
        tabla_ip.setItem(i, 2, QtWidgets.QTableWidgetItem(str(_obtener_informacion_ip(top10[i][0]))))
    return tabla_ip

def _obtener_informacion_ip(ip):
    api_key = "5cc35e697eb644cc99362f9594c87848"
    response = requests.get(f'https://api.ipgeolocation.io/ipgeo?apiKey={api_key}&ip={ip}')
    data = response.json()
    return data

def _top10_ip(file_path):
    counter = Counter()
    with open(file_path, 'r') as file:
        lineas=file.readlines()
        for linea in lineas:
            split_line = linea.split(';',2)[0]
            counter.update({split_line})
    file.close()
    return counter.most_common(10)
            
if __name__=="__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    tabla = obtener_tabla_ip("access_log_edw.csv")
    tabla.show()
    sys.exit(app.exec_())
