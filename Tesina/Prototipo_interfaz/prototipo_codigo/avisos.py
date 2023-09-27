from PyQt5.QtWidgets import QMessageBox

def avisar_precaucion(mensaje):
    msg = QMessageBox()
    msg.setIcon(QMessageBox.Warning)
    msg.setText(mensaje)
    msg.setWindowTitle("Error")
    msg.exec_()