import sys

from PyQt5 import QtWidgets

from fabrica_paginas import FabricaPaginas

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    fabrica = FabricaPaginas()
    window = QtWidgets.QWidget()
    layout = QtWidgets.QVBoxLayout()
    window.setLayout(layout)

    #Reactome
    '''
    reactome = fabrica.crear_pagina("Reactome", ["ENSG00000142208"])
    vista = reactome.obtener_vista_pagina()
    window.setWindowTitle('Reactome Pathway Diagram')
    '''
    #Expression Atlas
    
    expression_atlas = fabrica.crear_pagina("Expression Atlas", ["ENSG00000142208"])
    vista = expression_atlas.obtener_vista_pagina()
    window.setWindowTitle('Expression Atlas')
    
    layout.addWidget(vista)

    window.show()

    sys.exit(app.exec_())