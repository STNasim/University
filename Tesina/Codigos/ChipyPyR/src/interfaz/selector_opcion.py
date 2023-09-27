from PyQt5 import QtCore, QtWidgets


class Ui_SelectorOpcion(object):
    """
    Clase que contiene la interfaz de la ventana de selección de opción
    
    """
    #Modificar a traves de QtDesigner
    def setupUi(self, SelectorOpcion : QtWidgets.QDialog) -> None:
        """
        Función que configura la interfaz de la ventana

        :param SelectorOpcion: Ventana de selección de opción
        :type SelectorOpcion: QtWidgets.QDialog
        """
        SelectorOpcion.setObjectName("SelectorOpcion")
        SelectorOpcion.resize(285, 169)
        self.gridLayout = QtWidgets.QGridLayout(SelectorOpcion)
        self.gridLayout.setObjectName("gridLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setSizeConstraint(QtWidgets.QLayout.SetDefaultConstraint)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_opcion = QtWidgets.QLabel(SelectorOpcion)
        self.label_opcion.setAlignment(QtCore.Qt.AlignCenter)
        self.label_opcion.setObjectName("label_opcion")
        self.horizontalLayout.addWidget(self.label_opcion)
        self.combox_opciones = QtWidgets.QComboBox(SelectorOpcion)
        self.combox_opciones.setEnabled(True)
        self.combox_opciones.setObjectName("combox_opciones")
        self.combox_opciones.addItem("")
        self.combox_opciones.setItemText(0, "")
        self.horizontalLayout.addWidget(self.combox_opciones)
        self.gridLayout.addLayout(self.horizontalLayout, 1, 2, 1, 1)
        self.bbox = QtWidgets.QDialogButtonBox(SelectorOpcion)
        self.bbox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.bbox.setObjectName("bbox")
        self.gridLayout.addWidget(self.bbox, 2, 2, 1, 1)

        self.retranslateUi(SelectorOpcion)
        QtCore.QMetaObject.connectSlotsByName(SelectorOpcion)
    
    #Modificar a traves de QtDesigner
    def retranslateUi(self, SelectorOpcion : QtWidgets.QDialog) -> None:
        """
        Función que traduce los textos de la ventana

        :param SelectorOpcion: Ventana de selección de opción
        :type SelectorOpcion: QtWidgets.QDialog
        """
        _translate = QtCore.QCoreApplication.translate
        SelectorOpcion.setWindowTitle(_translate("SelectorOpcion", "Selector"))
        self.label_opcion.setText(_translate("SelectorOpcion", "Opción"))

    def setup_adicional(self, SelectorOpcion : QtWidgets.QDialog,
                         opciones : list, nombre_opcion : str = "Opción") -> None:
        """
        Función que configura la ventana de selección de opción
        
        :param SelectorOpcion: Ventana de selección de opción
        :type SelectorOpcion: QtWidgets.QDialog
        :param opciones: Lista de opciones a mostrar
        :type opciones: list
        :param nombre_opcion: Nombre de la opción a seleccionar
        :type nombre_opcion: str
        """
        self.bbox.accepted.connect(SelectorOpcion.accept)
        self.bbox.rejected.connect(SelectorOpcion.reject)

        self.combox_opciones.addItems(sorted(opciones))

        #Borrar opcion vacia
        self.combox_opciones.removeItem(0)

        self.combox_opciones.setCurrentIndex(0)

        #Establecer nombre de la opción
        self.label_opcion.setText(nombre_opcion)  