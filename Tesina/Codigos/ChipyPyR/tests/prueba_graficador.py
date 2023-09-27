import pandas as pd

from fabrica_graficos import FabricaGraficos

if __name__ == "__main__":
    graficador = FabricaGraficos()

    #Venn
    
    datos = {'Grupo A': [1, 2, 3, 4, 5],
        'Grupo B': [4, 5, 6, 7, 8],
        'Grupo C': [1, 2, 6, 7, 5]}

    grafico = graficador.crear_grafico("venn", datos, "Titulo prueba","Esto no deberia salir")
    grafico.obtener_figura().savefig("venn.png")
    

    #Barra
    '''
    datos = {'Gen': ["RAS", "2", "s3", "45", "5sc5", "723b"],
        'Alfa': [4, 5, 6, 7, 8, 20],
        'Prueba Beta': [14, 35, None, 27, 86, 100],
        'A': [24, -55, -36, 75, 88, 40],
        'B': [24, -55, -36, 75, 88, 40]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("barra", datos,"Titulo prueba","prueba x","prueba y")
    '''

    #KDE
    '''
    datos = {'Alfa': [4, 5, 6, 7, 8, 20],
        'Prueba Beta': [14, 35, None, 27, 86, 100],
        'A': [24, -55, -36, 75, 88, 40]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("KDE", datos,"titulo prueba","prueba x","prueba y",
                                        ['red', 'blue', 'green'])
    '''

    #Boxplot
    '''
    datos = {'Alfa': [4, 5, 6, 7, 8, 20],
        'Prueba Beta': [14, 35, None, 27, 86, 100],
        'A': [24, -55, -36, 75, 88, 40]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("boxplot", datos,"Titulo prueba","prueba x","prueba y",
                                        ['red', 'blue', 'green'])
    '''

    #Volcan
    '''
    datos = {'log2 fold-change': [1.5, -0.5, 2, -1.2, 3],
             '-log10 p-value': [2, 1, 5, 8, 6]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("volcán", datos, "titulo prueba", "prueba x", "prueba y",
                                       ['red', 'blue', 'green','black','yellow'])
    '''

    #Heatmap
    '''
    datos = {'Gen': ["RAS", "2", "s3", "45", "5sc5", "723b"],
        'Alfa': [4, 5, 6, 7, 8, 20],
        'Prueba Beta': [14, 35, None, 27, 86, 100],
        'A': [24, -55, -36, 75, 88, 40]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("Heatmap", datos,"titulo prueba","prueba_x","prueba_y")
    '''

    #Grafico de componentes principales
    '''
    datos = {'Alfa': [14, 33, 26, 25, 87, 121],
        'Beta': [14, 35, 32, 27, 86, 100],
        'Gamma': [24, -55, -36, 75, 88, 40]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("PCA", datos,"titulo prueba","prueba x",
                                       "prueba y",['red','blue','green'])
    '''

    #Grafico QQ
    '''
    datos = {'Prueba': [0.861848, 1.642459, -1.271178, -0.200834, -2.483085, -0.525864]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("QQ", datos,"titulo prueba","x prueba", "y prueba")
    '''

    #Grafico histograma
    '''
    datos = {'Alfa': [14, 33, 26, 25, 87, 121,14, 35, 32, 27, 86, 100,24, -55, -36, 75, 88, 40]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("Histograma", datos,"Titulo prueba","Eje_x_prueba","Eje_y_prueba")
    '''


    figura = grafico.obtener_figura()
    from mostrar_grafico import mostrar_grafico
    mostrar_grafico(figura) 

if __name__ == "__main__":
    fabrica = FabricaGraficos()
    datos = {'Alfa': [14, 33, 26, 25, 87, 121],
        'Beta': [14, 35, 32, 27, 86, 100],
        'Gamma': [24, -55, -36, 75, 88, 40],
        'Delta': [24, -55, 2, 7, 14, 40]}
    datos = pd.DataFrame(datos)
    grafico = fabrica.crear_grafico("Venn", datos)
    
    figura = grafico.obtener_figura()

    from PyQt5.QtWidgets import QApplication, QMainWindow
    import sys
    from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
    # Create a new PyQt5 application
    qApp = QApplication([])

    # Create the application window
    aw = QMainWindow()
    aw.setWindowTitle("PyQt5 Matplotlib Example")

    # Create the matplotlib figure
    canvas = FigureCanvas(figura)
    aw.setCentralWidget(canvas)
    
    aw.show()

    # Start the PyQt5 event loop
    sys.exit(qApp.exec_())


if __name__ == "__main__":
    fabrica = FabricaGraficos()
    datos = {'Gen': ["RAS", "2", "s3", "45", "5sc5", "723b"],
        'Alfa': [4, 5, 6, 7, 8, 20],
        'Prueba Beta': [14, 35, None, 27, 86, 100],
        'A': [24, -55, -36, 75, 88, 40]}
    datos = pd.DataFrame(datos)
    grafico = graficador.crear_grafico("Heatmap", datos,"titulo prueba","prueba_x","prueba_y")
    
    figura = grafico.obtener_figura()

    from PyQt5.QtWidgets import QApplication, QMainWindow
    import sys
    from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
    # Create a new PyQt5 application
    qApp = QApplication([])

    # Create the application window
    aw = QMainWindow()
    aw.setWindowTitle("PyQt5 Matplotlib Example")

    # Create the matplotlib figure
    canvas = FigureCanvas(figura)
    aw.setCentralWidget(canvas)
    
    aw.show()

    # Start the PyQt5 event loop
    sys.exit(qApp.exec_())