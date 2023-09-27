import sys

from PyQt5 import QtWidgets

from interfaz.ventana_principal import Ui___VentanaPrincipal

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    VentanaPrincipal = QtWidgets.QMainWindow()
    ui = Ui___VentanaPrincipal()
    ui.setupUi(VentanaPrincipal)
    ui.setup_adicional(VentanaPrincipal)
    VentanaPrincipal.showMaximized()
    sys.exit(app.exec_())