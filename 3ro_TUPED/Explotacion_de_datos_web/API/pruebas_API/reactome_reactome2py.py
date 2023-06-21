from reactome2py import analysis
from PyQt5 import QtCore, QtWidgets, QtWebEngineWidgets
import sys

ensembl_ids = {
    "TP53": "ENSG00000141510",
    "BRCA1": "ENSG00000012048",
    "EGFR": "ENSG00000146648",
    "TNF": "ENSG00000232810",
    "APOE": "ENSG00000130203",
    "IL6": "ENSG00000136244",
    "AKT1": "ENSG00000142208",
    "VEGFA": "ENSG00000112715",
    "MTHFR": "ENSG00000177000",
    "ESR1": "ENSG00000091831"
}

ensembl_id_str = ",".join(ensembl_ids.values())
result = analysis.identifiers(ids=ensembl_id_str)
token = result['summary']['token']

url = f"https://reactome.org/PathwayBrowser/#/DTAB=AN&ANALYSIS={token}"

app = QtWidgets.QApplication(sys.argv)

window = QtWidgets.QWidget()
window.setWindowTitle('Reactome Pathway Diagram')

layout = QtWidgets.QVBoxLayout()
window.setLayout(layout)

web_view = QtWebEngineWidgets.QWebEngineView()
web_view.load(QtCore.QUrl(url))
layout.addWidget(web_view)

window.show()

sys.exit(app.exec_())