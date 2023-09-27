# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '.\principal.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtWidgets
from ui_parseador import Ui_Parseador
from ui_graficador import Ui_Graficador

class Ui_Menu(object):
    def setupUi(self, Menu):
        Menu.setObjectName("Menu")
        Menu.resize(381, 285)
        self.centralwidget = QtWidgets.QWidget(Menu)
        self.centralwidget.setObjectName("centralwidget")
        self.bot_abrir_parseador = QtWidgets.QPushButton(self.centralwidget)
        self.bot_abrir_parseador.setGeometry(QtCore.QRect(70, 140, 91, 21))
        self.bot_abrir_parseador.setObjectName("bot_abrir_parseador")
        self.bot_abrir_graficador = QtWidgets.QPushButton(self.centralwidget)
        self.bot_abrir_graficador.setGeometry(QtCore.QRect(220, 140, 91, 23))
        self.bot_abrir_graficador.setObjectName("bot_abrir_graficador")
        Menu.setCentralWidget(self.centralwidget)

        self._retranslateUi(Menu)
        self.bot_abrir_parseador.clicked.connect(self._abrir_parseador) # type: ignore
        self.bot_abrir_graficador.clicked.connect(self._abrir_graficador) # type: ignore
        QtCore.QMetaObject.connectSlotsByName(Menu)

    def _retranslateUi(self, Menu):
        _translate = QtCore.QCoreApplication.translate
        Menu.setWindowTitle(_translate("Menu", "Menu"))
        self.bot_abrir_parseador.setText(_translate("Menu", "Abrir parseador"))
        self.bot_abrir_graficador.setText(_translate("Menu", "Abrir graficador"))

    def _abrir_parseador(self):
        self.Parseador = QtWidgets.QDialog()
        self.ui = Ui_Parseador()
        self.ui.setupUi(self.Parseador)
        self.Parseador.show()

    def _abrir_graficador(self):
        self.Graficador = QtWidgets.QDialog()
        self.ui = Ui_Graficador()
        self.ui.setupUi(self.Graficador)
        self.Graficador.show()

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Menu = QtWidgets.QMainWindow()
    ui = Ui_Menu()
    ui.setupUi(Menu)
    Menu.show()
    sys.exit(app.exec_())