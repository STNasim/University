from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg, NavigationToolbar2QT
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget

def mostrar_grafico(fig):

        # Create a new PyQt5 application
        app = QApplication([])

        # Create a new QMainWindow
        main = QMainWindow()

        # Create a QWidget to be set as the central widget of the main window
        central_widget = QWidget()
        main.setCentralWidget(central_widget)

        # Create a QVBoxLayout for the central widget
        layout = QVBoxLayout(central_widget)

        # Create a FigureCanvasQTAgg object with the figure as argument
        canvas = FigureCanvasQTAgg(fig)

        # Create a NavigationToolbar2QT object with the canvas and the main window as arguments
        toolbar = NavigationToolbar2QT(canvas, main)

        # Add the toolbar and the canvas to the layout
        layout.addWidget(toolbar)
        layout.addWidget(canvas)

        # Show the main window
        main.show()

        # Start the PyQt5 event loop to display the window
        app.exec_()