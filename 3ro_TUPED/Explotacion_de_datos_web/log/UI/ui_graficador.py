# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '.\graficador.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Graficador(object):
    def setupUi(self, Graficador):
        Graficador.setObjectName("Graficador")
        Graficador.resize(319, 265)
        self.line_path_file = QtWidgets.QLineEdit(Graficador)
        self.line_path_file.setGeometry(QtCore.QRect(50, 50, 113, 20))
        self.line_path_file.setObjectName("line_path_file")
        self.bot_select_file = QtWidgets.QPushButton(Graficador)
        self.bot_select_file.setGeometry(QtCore.QRect(180, 50, 71, 21))
        self.bot_select_file.setObjectName("bot_select_file")
        self.bot_ip = QtWidgets.QPushButton(Graficador)
        self.bot_ip.setEnabled(False)
        self.bot_ip.setGeometry(QtCore.QRect(20, 150, 75, 23))
        self.bot_ip.setObjectName("bot_ip")
        self.bot_tiempo = QtWidgets.QPushButton(Graficador)
        self.bot_tiempo.setEnabled(False)
        self.bot_tiempo.setGeometry(QtCore.QRect(120, 150, 75, 23))
        self.bot_tiempo.setObjectName("bot_tiempo")
        self.bot_prot = QtWidgets.QPushButton(Graficador)
        self.bot_prot.setEnabled(False)
        self.bot_prot.setGeometry(QtCore.QRect(220, 150, 75, 23))
        self.bot_prot.setAutoDefault(True)
        self.bot_prot.setObjectName("bot_prot")
        self.bot_metodo = QtWidgets.QPushButton(Graficador)
        self.bot_metodo.setEnabled(False)
        self.bot_metodo.setGeometry(QtCore.QRect(70, 200, 75, 23))
        self.bot_metodo.setObjectName("bot_metodo")
        self.bot_navegador = QtWidgets.QPushButton(Graficador)
        self.bot_navegador.setEnabled(False)
        self.bot_navegador.setGeometry(QtCore.QRect(180, 200, 75, 23))
        self.bot_navegador.setObjectName("bot_navegador")

        self.retranslateUi(Graficador)
        self.bot_select_file.clicked.connect(self.line_path_file.update) # type: ignore
        self.line_path_file.editingFinished.connect(self.bot_ip.showMenu) # type: ignore
        self.line_path_file.editingFinished.connect(self.bot_tiempo.showMenu) # type: ignore
        self.line_path_file.editingFinished.connect(self.bot_prot.showMenu) # type: ignore
        QtCore.QMetaObject.connectSlotsByName(Graficador)
        Graficador.setTabOrder(self.line_path_file, self.bot_select_file)

    def retranslateUi(self, Graficador):
        _translate = QtCore.QCoreApplication.translate
        Graficador.setWindowTitle(_translate("Graficador", "Graficador"))
        self.bot_select_file.setText(_translate("Graficador", "Seleccionar"))
        self.bot_ip.setText(_translate("Graficador", "IP"))
        self.bot_tiempo.setText(_translate("Graficador", "Tiempo"))
        self.bot_prot.setText(_translate("Graficador", "Protocolo"))
        self.bot_metodo.setText(_translate("Graficador", "Método"))
        self.bot_navegador.setText(_translate("Graficador", "Navegador"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Graficador = QtWidgets.QDialog()
    ui = Ui_Graficador()
    ui.setupUi(Graficador)
    Graficador.show()
    sys.exit(app.exec_())
