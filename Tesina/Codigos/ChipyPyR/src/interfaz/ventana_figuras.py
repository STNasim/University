from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QTabWidget, QWidget, QVBoxLayout
from PyQt5.QtWebEngineWidgets import QWebEngineView
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar
import matplotlib as mpl

mpl.rcParams['figure.autolayout'] = True

class VentanaFiguras:
    """
    Clase que contiene la interfaz de la ventana de figuras.
    """
    @staticmethod
    def poner_figuras_ventana(figuras : list,
                               titulo_ventana : str = "Figuras") -> QtWidgets.QMainWindow:
        """
        Función que configura la ventana de figuras.

        :param figuras: Lista de figuras a mostrar en la ventana.
        :type figuras: list
        :param titulo_ventana: Título de la ventana.
        :type titulo_ventana: str
        :return: Ventana de figuras.
        :rtype: QtWidgets.QMainWindow
        """
        tabs = QTabWidget()

        for i, figura in enumerate(figuras):
            tab = QWidget()
            tabs.addTab(tab, f"Figura {i + 1}")
            layout = QVBoxLayout()

            if type(figura) == mpl.figure.Figure:
                canvas = FigureCanvas(figura)
                toolbar = NavigationToolbar(canvas, tab)

                layout.addWidget(toolbar)
                layout.addWidget(canvas)

            elif type(figura) == QWebEngineView:
                layout.addWidget(figura)

            else:
                raise ValueError("Tipo de figura no soportado")

            tab.setLayout(layout)
        
        ventana = QtWidgets.QMainWindow()
        ventana.setCentralWidget(tabs)
        
        ventana.setWindowTitle(titulo_ventana)

        return ventana