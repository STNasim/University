from PyQt5 import QtCore, QtGui, QtWidgets

import pandas as pd

from interfaz.selector_opcion import Ui_SelectorOpcion
from interfaz.avisos import Avisos
from interfaz.eventos import ManejadorEventos
from interfaz.ventana_figuras import VentanaFiguras
from manejadores_archivos.cargadores_archivos import FabricaCargadoresArchivos
from manejadores_archivos.guardador_archivos import GuardadorArchivos
from procesadores_datos.pipeline import Pipeline
from procesadores_datos.validadores_datos import ValidadorDatos
from procesadores_datos.hilo_qt import HiloProcesamiento
from visualizacion.graficador import Graficador
from transformaciones.df import quitar_filas_mayores_columna, quitar_filas_menores_absoluto_columna

class Ui___VentanaPrincipal(object):
    #Modificar desde QtDesigner
    def setupUi(self, __VentanaPrincipal):
        __VentanaPrincipal.setObjectName("__VentanaPrincipal")
        __VentanaPrincipal.resize(624, 405)
        self.__centralwidget = QtWidgets.QWidget(__VentanaPrincipal)
        self.__centralwidget.setObjectName("__centralwidget")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.__centralwidget)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.__tabWidget = QtWidgets.QTabWidget(self.__centralwidget)
        self.__tabWidget.setObjectName("__tabWidget")
        self.__procesamiento_de_muestras = QtWidgets.QWidget()
        self.__procesamiento_de_muestras.setObjectName("__procesamiento_de_muestras")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.__procesamiento_de_muestras)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.__verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.__verticalLayout_3.setSpacing(10)
        self.__verticalLayout_3.setObjectName("__verticalLayout_3")
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_3.addItem(spacerItem)
        self.__but_cargar_metadatos = QtWidgets.QPushButton(self.__procesamiento_de_muestras)
        self.__but_cargar_metadatos.setObjectName("__but_cargar_metadatos")
        self.__verticalLayout_3.addWidget(self.__but_cargar_metadatos)
        spacerItem1 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_3.addItem(spacerItem1)
        self.__formLayout = QtWidgets.QFormLayout()
        self.__formLayout.setLabelAlignment(QtCore.Qt.AlignCenter)
        self.__formLayout.setFormAlignment(QtCore.Qt.AlignJustify|QtCore.Qt.AlignVCenter)
        self.__formLayout.setVerticalSpacing(20)
        self.__formLayout.setObjectName("__formLayout")
        self.__lab_error_sondas = QtWidgets.QLabel(self.__procesamiento_de_muestras)
        self.__lab_error_sondas.setAlignment(QtCore.Qt.AlignCenter)
        self.__lab_error_sondas.setObjectName("__lab_error_sondas")
        self.__formLayout.setWidget(3, QtWidgets.QFormLayout.LabelRole, self.__lab_error_sondas)
        self.__dsbox_error_sondas = QtWidgets.QDoubleSpinBox(self.__procesamiento_de_muestras)
        self.__dsbox_error_sondas.setMaximumSize(QtCore.QSize(100, 16777215))
        self.__dsbox_error_sondas.setMaximum(9999.99)
        self.__dsbox_error_sondas.setProperty("value", 20.0)
        self.__dsbox_error_sondas.setObjectName("__dsbox_error_sondas")
        self.__formLayout.setWidget(3, QtWidgets.QFormLayout.FieldRole, self.__dsbox_error_sondas)
        self.__lab_error_genes = QtWidgets.QLabel(self.__procesamiento_de_muestras)
        self.__lab_error_genes.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.__lab_error_genes.setAlignment(QtCore.Qt.AlignCenter)
        self.__lab_error_genes.setObjectName("__lab_error_genes")
        self.__formLayout.setWidget(4, QtWidgets.QFormLayout.LabelRole, self.__lab_error_genes)
        self.__dsbox_error_genes = QtWidgets.QDoubleSpinBox(self.__procesamiento_de_muestras)
        self.__dsbox_error_genes.setMaximumSize(QtCore.QSize(100, 16777215))
        self.__dsbox_error_genes.setSuffix("")
        self.__dsbox_error_genes.setMaximum(9999.99)
        self.__dsbox_error_genes.setProperty("value", 20.0)
        self.__dsbox_error_genes.setObjectName("__dsbox_error_genes")
        self.__formLayout.setWidget(4, QtWidgets.QFormLayout.FieldRole, self.__dsbox_error_genes)
        self.__lab_multimappers = QtWidgets.QLabel(self.__procesamiento_de_muestras)
        self.__lab_multimappers.setObjectName("__lab_multimappers")
        self.__formLayout.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.__lab_multimappers)
        self.__check_multimappers = QtWidgets.QCheckBox(self.__procesamiento_de_muestras)
        self.__check_multimappers.setMinimumSize(QtCore.QSize(0, 25))
        font = QtGui.QFont()
        font.setPointSize(6)
        self.__check_multimappers.setFont(font)
        self.__check_multimappers.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.__check_multimappers.setText("")
        self.__check_multimappers.setObjectName("__check_multimappers")
        self.__formLayout.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.__check_multimappers)
        self.__lab_reportes_calidad = QtWidgets.QLabel(self.__procesamiento_de_muestras)
        self.__lab_reportes_calidad.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.__lab_reportes_calidad.setAlignment(QtCore.Qt.AlignCenter)
        self.__lab_reportes_calidad.setObjectName("__lab_reportes_calidad")
        self.__formLayout.setWidget(2, QtWidgets.QFormLayout.LabelRole, self.__lab_reportes_calidad)
        self.__check_reporte_calidad = QtWidgets.QCheckBox(self.__procesamiento_de_muestras)
        self.__check_reporte_calidad.setText("")
        self.__check_reporte_calidad.setObjectName("__check_reporte_calidad")
        self.__formLayout.setWidget(2, QtWidgets.QFormLayout.FieldRole, self.__check_reporte_calidad)
        self.__lab_espacio_numerico = QtWidgets.QLabel(self.__procesamiento_de_muestras)
        self.__lab_espacio_numerico.setAlignment(QtCore.Qt.AlignCenter)
        self.__lab_espacio_numerico.setObjectName("__lab_espacio_numerico")
        self.__formLayout.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.__lab_espacio_numerico)
        self.__combox_espacio_numerico = QtWidgets.QComboBox(self.__procesamiento_de_muestras)
        self.__combox_espacio_numerico.setObjectName("__combox_espacio_numerico")
        self.__combox_espacio_numerico.addItem("")
        self.__combox_espacio_numerico.addItem("")
        self.__combox_espacio_numerico.addItem("")
        self.__combox_espacio_numerico.addItem("")
        self.__formLayout.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.__combox_espacio_numerico)
        self.__verticalLayout_3.addLayout(self.__formLayout)
        spacerItem2 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_3.addItem(spacerItem2)
        self.__but_procesar_datos = QtWidgets.QPushButton(self.__procesamiento_de_muestras)
        self.__but_procesar_datos.setEnabled(False)
        self.__but_procesar_datos.setObjectName("__but_procesar_datos")
        self.__verticalLayout_3.addWidget(self.__but_procesar_datos)
        spacerItem3 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_3.addItem(spacerItem3)
        self.horizontalLayout.addLayout(self.__verticalLayout_3)
        self.__tabla_muestras = QtWidgets.QTableWidget(self.__procesamiento_de_muestras)
        self.__tabla_muestras.setEnabled(False)
        self.__tabla_muestras.setAutoScroll(True)
        self.__tabla_muestras.setSelectionBehavior(QtWidgets.QAbstractItemView.SelectItems)
        self.__tabla_muestras.setVerticalScrollMode(QtWidgets.QAbstractItemView.ScrollPerPixel)
        self.__tabla_muestras.setHorizontalScrollMode(QtWidgets.QAbstractItemView.ScrollPerPixel)
        self.__tabla_muestras.setRowCount(0)
        self.__tabla_muestras.setObjectName("__tabla_muestras")
        self.__tabla_muestras.setColumnCount(0)
        self.horizontalLayout.addWidget(self.__tabla_muestras)
        self.__tabWidget.addTab(self.__procesamiento_de_muestras, "")
        self.__procesamiento_de_resultados = QtWidgets.QWidget()
        self.__procesamiento_de_resultados.setObjectName("__procesamiento_de_resultados")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.__procesamiento_de_resultados)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.__verticalLayout_6 = QtWidgets.QVBoxLayout()
        self.__verticalLayout_6.setObjectName("__verticalLayout_6")
        spacerItem4 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_6.addItem(spacerItem4)
        self.__but_cargar_resultados = QtWidgets.QPushButton(self.__procesamiento_de_resultados)
        self.__but_cargar_resultados.setObjectName("__but_cargar_resultados")
        self.__verticalLayout_6.addWidget(self.__but_cargar_resultados)
        spacerItem5 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_6.addItem(spacerItem5)
        self.__formLayout_2 = QtWidgets.QFormLayout()
        self.__formLayout_2.setObjectName("__formLayout_2")
        self.__lab_grupo = QtWidgets.QLabel(self.__procesamiento_de_resultados)
        self.__lab_grupo.setObjectName("__lab_grupo")
        self.__formLayout_2.setWidget(2, QtWidgets.QFormLayout.LabelRole, self.__lab_grupo)
        self.__lab_p = QtWidgets.QLabel(self.__procesamiento_de_resultados)
        self.__lab_p.setObjectName("__lab_p")
        self.__formLayout_2.setWidget(3, QtWidgets.QFormLayout.LabelRole, self.__lab_p)
        self.__lab_log2fc = QtWidgets.QLabel(self.__procesamiento_de_resultados)
        self.__lab_log2fc.setObjectName("__lab_log2fc")
        self.__formLayout_2.setWidget(4, QtWidgets.QFormLayout.LabelRole, self.__lab_log2fc)
        self.__dsbox_log2fc = QtWidgets.QDoubleSpinBox(self.__procesamiento_de_resultados)
        self.__dsbox_log2fc.setSingleStep(0.1)
        self.__dsbox_log2fc.setProperty("value", 1.0)
        self.__dsbox_log2fc.setObjectName("__dsbox_log2fc")
        self.__formLayout_2.setWidget(4, QtWidgets.QFormLayout.FieldRole, self.__dsbox_log2fc)
        self.__lab_grafico = QtWidgets.QLabel(self.__procesamiento_de_resultados)
        self.__lab_grafico.setObjectName("__lab_grafico")
        self.__formLayout_2.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.__lab_grafico)
        self.__combox_grupo = QtWidgets.QComboBox(self.__procesamiento_de_resultados)
        self.__combox_grupo.setObjectName("__combox_grupo")
        self.__formLayout_2.setWidget(2, QtWidgets.QFormLayout.FieldRole, self.__combox_grupo)
        self.__combox_grafico = QtWidgets.QComboBox(self.__procesamiento_de_resultados)
        self.__combox_grafico.setObjectName("__combox_grafico")
        self.__formLayout_2.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.__combox_grafico)
        self.__dsbox_p = QtWidgets.QDoubleSpinBox(self.__procesamiento_de_resultados)
        self.__dsbox_p.setMaximum(1.0)
        self.__dsbox_p.setSingleStep(0.01)
        self.__dsbox_p.setProperty("value", 0.05)
        self.__dsbox_p.setObjectName("__dsbox_p")
        self.__formLayout_2.setWidget(3, QtWidgets.QFormLayout.FieldRole, self.__dsbox_p)
        self.__verticalLayout_6.addLayout(self.__formLayout_2)
        spacerItem6 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_6.addItem(spacerItem6)
        self.__but_filtrar_tabla = QtWidgets.QPushButton(self.__procesamiento_de_resultados)
        self.__but_filtrar_tabla.setEnabled(False)
        self.__but_filtrar_tabla.setObjectName("__but_filtrar_tabla")
        self.__verticalLayout_6.addWidget(self.__but_filtrar_tabla)
        spacerItem7 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_6.addItem(spacerItem7)
        self.__but_guardar_tabla = QtWidgets.QPushButton(self.__procesamiento_de_resultados)
        self.__but_guardar_tabla.setEnabled(False)
        self.__but_guardar_tabla.setObjectName("__but_guardar_tabla")
        self.__verticalLayout_6.addWidget(self.__but_guardar_tabla)
        spacerItem8 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_6.addItem(spacerItem8)
        self.__but_graficar = QtWidgets.QPushButton(self.__procesamiento_de_resultados)
        self.__but_graficar.setEnabled(False)
        self.__but_graficar.setObjectName("__but_graficar")
        self.__verticalLayout_6.addWidget(self.__but_graficar)
        spacerItem9 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.__verticalLayout_6.addItem(spacerItem9)
        self.horizontalLayout_3.addLayout(self.__verticalLayout_6)
        self.__tabla_resultados = QtWidgets.QTableWidget(self.__procesamiento_de_resultados)
        self.__tabla_resultados.setEnabled(False)
        self.__tabla_resultados.setAutoScroll(True)
        self.__tabla_resultados.setVerticalScrollMode(QtWidgets.QAbstractItemView.ScrollPerPixel)
        self.__tabla_resultados.setHorizontalScrollMode(QtWidgets.QAbstractItemView.ScrollPerPixel)
        self.__tabla_resultados.setRowCount(0)
        self.__tabla_resultados.setColumnCount(0)
        self.__tabla_resultados.setObjectName("__tabla_resultados")
        self.horizontalLayout_3.addWidget(self.__tabla_resultados)
        self.__tabWidget.addTab(self.__procesamiento_de_resultados, "")
        self.verticalLayout_5.addWidget(self.__tabWidget)
        __VentanaPrincipal.setCentralWidget(self.__centralwidget)

        self.retranslateUi(__VentanaPrincipal)
        self.__tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(__VentanaPrincipal)
    #Modificar desde QtDesigner
    def retranslateUi(self, __VentanaPrincipal):
        _translate = QtCore.QCoreApplication.translate
        __VentanaPrincipal.setWindowTitle(_translate("__VentanaPrincipal", "ChipyPyR"))
        self.__but_cargar_metadatos.setText(_translate("__VentanaPrincipal", "Cargar\n"
" metadatos"))
        self.__lab_error_sondas.setText(_translate("__VentanaPrincipal", "Error estándar\n"
" máximo sondas (%)"))
        self.__lab_error_genes.setText(_translate("__VentanaPrincipal", "Error estándar\n"
" máximo genes (%)"))
        self.__lab_multimappers.setText(_translate("__VentanaPrincipal", "Quitar sondas\n"
" multimappers"))
        self.__lab_reportes_calidad.setText(_translate("__VentanaPrincipal", "Generar reportes\n"
" de calidad"))
        self.__lab_espacio_numerico.setText(_translate("__VentanaPrincipal", "Espacio númerico\n"
" de sondas"))
        self.__combox_espacio_numerico.setItemText(0, _translate("__VentanaPrincipal", "AFFY_HUEX_1_0_ST_V2"))
        self.__combox_espacio_numerico.setItemText(1, _translate("__VentanaPrincipal", "AFFY_HUGENE_1_0_ST_V1"))
        self.__combox_espacio_numerico.setItemText(2, _translate("__VentanaPrincipal", "AFFY_HUGENE_2_0_ST_V1"))
        self.__combox_espacio_numerico.setItemText(3, _translate("__VentanaPrincipal", "AFFY_HUGENE_2_1_ST_V1"))
        self.__but_procesar_datos.setText(_translate("__VentanaPrincipal", "Procesar\n"
" datos"))
        self.__tabWidget.setTabText(self.__tabWidget.indexOf(self.__procesamiento_de_muestras), _translate("__VentanaPrincipal", "Procesamiento de muestras"))
        self.__but_cargar_resultados.setText(_translate("__VentanaPrincipal", "Cargar\n"
" resultados"))
        self.__lab_grupo.setText(_translate("__VentanaPrincipal", "Grupo"))
        self.__lab_p.setText(_translate("__VentanaPrincipal", "p-value"))
        self.__lab_log2fc.setText(_translate("__VentanaPrincipal", "Log2FC"))
        self.__lab_grafico.setText(_translate("__VentanaPrincipal", "Gráfico"))
        self.__but_filtrar_tabla.setText(_translate("__VentanaPrincipal", "Filtrar tabla"))
        self.__but_guardar_tabla.setText(_translate("__VentanaPrincipal", "Guardar tabla"))
        self.__but_graficar.setText(_translate("__VentanaPrincipal", "Graficar"))
        self.__tabWidget.setTabText(self.__tabWidget.indexOf(self.__procesamiento_de_resultados), _translate("__VentanaPrincipal", "Procesamiento de resultados y graficación"))

    def setup_adicional(self, VentanaPrincipal : QtWidgets.QMainWindow) -> None:
        """
        Función que configura la ventana principal.

        :param VentanaPrincipal: Ventana principal.
        :type VentanaPrincipal: QtWidgets.QMainWindow
        """
        #Eventos de teclas en tablas
        self.__tabla_muestras.keyPressEvent = lambda event: ManejadorEventos.eventos_tecla_tablas(event, self.__tabla_muestras, VentanaPrincipal)
        self.__tabla_resultados.keyPressEvent = lambda event: ManejadorEventos.eventos_tecla_tablas(event, self.__tabla_resultados, VentanaPrincipal)
        
        #Señales
        self.__but_cargar_metadatos.clicked.connect(self.__cargar_metadatos)
        self.__but_procesar_datos.clicked.connect(self.__procesar_datos_interfaz)
        self.__but_cargar_resultados.clicked.connect(self.__cargar_resultados)
        self.__but_graficar.clicked.connect(self.__graficar)
        self.__but_guardar_tabla.clicked.connect(self.__guardar_tabla)
        self.__but_filtrar_tabla.clicked.connect(self.__filtrar_tabla)

        self.__graficador = Graficador()
        Avisos.parent = VentanaPrincipal
        Avisos.avisar_procesando("Leer manual antes de usar", 7)

        #setear los graficos permitidos en el combobox
        self.__combox_grafico.addItems(sorted(self.__graficador.obtener_graficos_permitidos()))

    def __obtener_opcion(self, opciones : list, titulo : str = "Opción") -> str:
        """
        Función que muestra una ventana de selección de opción.

        :param opciones: Lista de opciones a mostrar.
        :type opciones: list
        :param titulo: Título de la ventana.
        :type titulo: str
        :return: Opción seleccionada.
        :rtype: str        
        """
        selector_opcion = QtWidgets.QDialog()
        ui = Ui_SelectorOpcion()
        ui.setupUi(selector_opcion)
        ui.setup_adicional(selector_opcion, opciones, titulo)
        if selector_opcion.exec_():
            return ui.combox_opciones.currentText()
        else:
            return None

#Pestaña 1

    def __crear_hilo(self) -> None:
        """
        Función que crea un hilo de procesamiento de datos.
        """
        self.__hilo = HiloProcesamiento(self._pipeline, self.__check_reporte_calidad.isChecked(), "1")
        self.__hilo.error.connect(Avisos.avisar_precaucion)
        self.__hilo.progreso.connect(Avisos.avisar_procesando)
        self.__hilo.generar_reporte.connect(self.__generar_ventana_reporte)
        self.__hilo.termino_parte.connect(self.__segunda_parte_procesamiento)
        self.__hilo.terminado.connect(Avisos.avisar_finalizado)
        self.__hilo.candado.connect(self.__candado)

    def __candado(self, estado) -> None:
        """
        Función que bloquea o desbloquea la interfaz.

        :param estado: True para bloquear.
        :type estado: bool
        """
        self.__but_procesar_datos.setEnabled(not estado)

    def __cargar_metadatos(self) -> None:
        """
        Función que carga los metadatos de las muestras.
        """
        #Abrir una ventana de selección de archivo de Windows para seleccionar la ruta del archivo
        ruta_MAGE, _ = QtWidgets.QFileDialog.getOpenFileName(None, "Seleccionar archivo", "",
                                                              "Archivos de texto (*.txt);Archivos tsv (*.tsv);Todos los archivos (*.*)")
        
        if ruta_MAGE:
            cargador_archivos_MAGE = FabricaCargadoresArchivos.crear_cargador_de_archivo("MAGETAB")
            try:
                datos_MAGE = cargador_archivos_MAGE.cargar_lista_archivos([ruta_MAGE])
            except ValueError as error:
                Avisos.avisar_precaucion(str(error))
            except Exception as error:
                Avisos.avisar_precaucion("Error desconocido: " + str(error))
            else:
                self.__colocar_meta_datos_muestras(datos_MAGE)

    def __colocar_meta_datos_muestras(self, datos_MAGE : pd.DataFrame) -> None:
        """
        Función que coloca los metadatos de las muestras en la tabla.

        :param datos_MAGE: Datos de las muestras.
        :type datos_MAGE: pd.DataFrame
        """
        self.__tabla_muestras.setSortingEnabled(False)
        numero_filas, numero_columnas = len(datos_MAGE), len(datos_MAGE.columns)

        self.__but_procesar_datos.setEnabled(True)
        self.__tabla_muestras.setEnabled(True)
        self.__tabla_muestras.clear()
        
        # Incrementar el recuento de columnas en uno para agregar la nueva columna
        self.__tabla_muestras.setColumnCount(numero_columnas + 1)
        
        # Crear etiquetas de encabezado para todas las columnas
        column_headers = ['Grupo'] + list(datos_MAGE.columns)
        self.__tabla_muestras.setHorizontalHeaderLabels(column_headers)
        
        self.__tabla_muestras.setRowCount(numero_filas)
        
        # Inicializar la nueva columna 'grupo' con celdas vacías o None
        for i in range(numero_filas):
            self.__tabla_muestras.setItem(i, 0, QtWidgets.QTableWidgetItem(""))
        
        # Filling the remaining columns with data from datos_MAGE
        for i, row_values in enumerate(datos_MAGE.values):
            for j, value in enumerate(row_values, start=1):
                self.__tabla_muestras.setItem(i, j, QtWidgets.QTableWidgetItem(str(value)))

        self.__tabla_muestras.resizeColumnsToContents()
        self.__tabla_muestras.resizeRowsToContents()
        self.__tabla_muestras.setSortingEnabled(True)

    def __procesar_datos_interfaz(self):
        """
        Función que procesa los datos de interfaz y comienza con el procesamiento de los datos.
        """
        try:
            self.__grupos = self.__cargar_grupos()
            self.__muestras = self.__cargar_muestras()
        except ValueError as error:
            Avisos.avisar_precaucion(str(error))
        else:
            #preguntar al usuario dónde sea
            self.__ruta = QtWidgets.QFileDialog.getExistingDirectory(None,"Seleccionar carpeta de muestras", "")
            if self.__ruta:
                #Preguntar al usuario cual de los grupos utilizar como grupo control
                self.__grupo_control = self.__obtener_opcion(set(self.__grupos), "Grupo control")
                if self.__grupo_control:
                    try:
                        self.__procesar_y_avisar_progreso_multi_hilo()
                    except ValueError as error:
                        Avisos.avisar_precaucion(str(error))
                    #except Exception as error:
                    #    Avisos.avisar_precaucion("Error desconocido: " + str(error))

    def __cargar_grupos(self) -> list:
        """
        Función que carga los grupos de la tabla de muestras
        :return: Lista de grupos
        :rtype: list
        """
        #Se leen las columnas de la tabla de muestras y se ubica el indice de la columna 'grupo'
        columnas = [self.__tabla_muestras.horizontalHeaderItem(i).text() for i in range(self.__tabla_muestras.columnCount())]
        indice_grupo = columnas.index('Grupo')

        #se guardan los datos de grupos en una lista
        grupos = []
        for i in range(self.__tabla_muestras.rowCount()):
            grupos.append(self.__tabla_muestras.item(i, indice_grupo).text())

        #Se valida la lista de grupos
        ValidadorDatos.validar_datos("grupos", grupos)
        return grupos
    
    def __cargar_muestras(self) -> list:
        """
        Función que carga los nombres de las muestras de la tabla de muestras
        :return: Lista de muestras
        :rtype: list
        """
        #Se leen las columnas de la tabla de muestras, teniendo en cuenta que son case insensitive y
        #space insensitive y se ubica el indice de la columna 'sourcename'

        columnas = [self.__tabla_muestras.horizontalHeaderItem(i).text().lower().replace(' ', '')
                    for i in range(self.__tabla_muestras.columnCount())]
        indice_sourcename = columnas.index('sourcename')

        #se guardan los datos de sourcename en una lista
        muestras = []
        for i in range(self.__tabla_muestras.rowCount()):
            muestras.append(self.__tabla_muestras.item(i, indice_sourcename).text())
        
        #Se corta de los nombres lo que haya despues del primer espacio
        muestras = [nombre.split(' ')[0] for nombre in muestras]

        #Se valida la lista de muestras
        ValidadorDatos.validar_datos("muestras", muestras)

        return muestras

    def __procesar_y_avisar_progreso_multi_hilo(self) -> None:
        """
        Función que inicia el procesamiento de datos creando un pipeline y un hilo de procesamiento.
        """
        self.__candado(True)
        self._pipeline = Pipeline(self.__ruta, self.__muestras, self.__grupos, self.__grupo_control,
                  self.__dsbox_error_sondas.value(), self.__dsbox_error_genes.value(),
                   self.__check_multimappers.isChecked(), self.__combox_espacio_numerico.currentText())
        
        self.__crear_hilo()
        
        self.__hilo.start()
        
    def __segunda_parte_procesamiento(self) -> None:
        """
        Función que inicia la segunda parte del procesamiento de datos.
        """
        Avisos.avisar_procesando("Calculando expresión...")
        self._pipeline.calcular_expresion()
        
        self.__hilo.set_parte("2")
        self.__hilo.start()

    def __generar_ventana_reporte(self, figuras : list, nombre_ventana : str) -> None:
        """
        Función que genera una ventana de reporte.
        :param figuras: Lista de figuras.
        :type figuras: list
        :param nombre_ventana: Nombre de la ventana.
        :type nombre_ventana: str
        """
        if nombre_ventana == "Reporte muestras":
            self.__ventana_reporte_muestras = \
            VentanaFiguras.poner_figuras_ventana(figuras, nombre_ventana)
            self.__ventana_reporte_muestras.showMaximized()
        
        elif nombre_ventana == "Reporte limma":
            self.__ventana_reporte_limma = \
            VentanaFiguras.poner_figuras_ventana(figuras, nombre_ventana)
            self.__ventana_reporte_limma.showMaximized()            

#Pestaña 2

    def __obtener_dataframe_resultados(self) -> pd.DataFrame:
        """
        Función que obtiene los datos de la tabla de resultados y los devuelve en forma de df.
        :return: Datos de la tabla de resultados.
        :rtype: pd.DataFrame
        """
        #obtener los datos de la tabla de resultados y devolverlos en forma de df
        columnas = [self.__tabla_resultados.horizontalHeaderItem(i).text() for i in range(self.__tabla_resultados.columnCount())]

        #obtener los datos numericos de la tabla
        datos = []
        for i in range(self.__tabla_resultados.rowCount()):
            datos.append([self.__tabla_resultados.item(i, j).text() for j in range(self.__tabla_resultados.columnCount())])

        #crear el df
        df = pd.DataFrame(datos, columns = columnas)

        # Convertir las columnas que contienen 'adj-p-value' o 'log2FC' en su nombre a float
        for col in df.columns:
            if 'adj-p-value' in col or 'log2FC' in col:
                df[col] = df[col].astype(float)

        #Reemplazar de los datos los "\n" por ","
        df = df.replace('\n', ', ', regex = True)

        return df

    def __obtener_columna_resultados(self, nombre_columna : str) -> list:
        """
        Función que obtiene los datos de una columna de la tabla de resultados.
        :param nombre_columna: Nombre de la columna.
        :type nombre_columna: str
        :return: Datos de la columna.
        :rtype: list
        """
        indice_columna = 0
        for i in range(self.__tabla_resultados.columnCount()):
            if self.__tabla_resultados.horizontalHeaderItem(i).text() == nombre_columna:
                indice_columna = i
                break
        
        datos = []
        for i in range(self.__tabla_resultados.rowCount()):
            item = self.__tabla_resultados.item(i, indice_columna)
            if item is not None:
                datos.append(item.text())
                
        return datos

    def __cargar_resultados(self) -> None:
        """
        Función que carga los resultados.
        """
        #Se le pide al usuario que seleccione uno o varios archivos
        rutas_resultados, _ = QtWidgets.QFileDialog.getOpenFileNames(None, "Seleccionar archivos","",
                                                                        "Archivos de texto (*.txt);Todos los archivos (*.*)")
        
        if rutas_resultados:
            cargador_archivos_resultados = FabricaCargadoresArchivos.crear_cargador_de_archivo("resultados")
            try:
                datos_resultados = cargador_archivos_resultados.cargar_lista_archivos(list(rutas_resultados))
            except ValueError as error:
                Avisos.avisar_precaucion(str(error))
            except Exception as error:
                Avisos.avisar_precaucion("Error desconocido: " + str(error))
            else:
                self.__colocar_datos_resultados(datos_resultados)
                #colocar grupos, los grupos son los nombres de las columnas despues del primer _ y que contengan vs
                self.__combox_grupo.clear()
                self.__combox_grupo.addItems(sorted(set([columna.split('_', 1)[1] for columna in datos_resultados.columns if 'vs' in columna])))
                self.__combox_grupo.setCurrentIndex(0)
                self.__but_graficar.setEnabled(True)
                self.__but_filtrar_tabla.setEnabled(True)
                self.__but_guardar_tabla.setEnabled(True)

    def __colocar_datos_resultados(self, datos_resultados : pd.DataFrame) -> None:
        """
        Función que coloca los datos de los resultados en la tabla.

        :param datos_resultados: Datos de los resultados.
        :type datos_resultados: pd.DataFrame
        """
        self.__tabla_resultados.setSortingEnabled(False)
        numero_filas, numero_columnas = len(datos_resultados), len(datos_resultados.columns)
        self.__but_graficar.setEnabled(True)
        self.__tabla_resultados.setEnabled(True)
        self.__tabla_resultados.clear()
        
        # Incrementar el recuento de columnas en uno para agregar la nueva columna
        self.__tabla_resultados.setColumnCount(numero_columnas)
        
        # Crear etiquetas de encabezado para todas las columnas
        self.__tabla_resultados.setHorizontalHeaderLabels(list(datos_resultados.columns))
        
        self.__tabla_resultados.setRowCount(numero_filas)
        
        # Filling the remaining columns with data from datos_resultados
        for i, row_values in enumerate(datos_resultados.values):
            for j, value in enumerate(row_values):
                item = QtWidgets.QTableWidgetItem()
                if isinstance(value, (int, float)):  # check if value is numeric
                    item.setData(QtCore.Qt.DisplayRole, value)
                else:  # if value is not numeric, add it as a string
                    item.setText(str(value.replace(', ', '\n')))
                self.__tabla_resultados.setItem(i, j, item)

        self.__tabla_resultados.resizeColumnsToContents()
        self.__tabla_resultados.resizeRowsToContents()
        self.__tabla_resultados.setSortingEnabled(True)

    def __filtrar_tabla(self) -> None:
        """
        Función que filtra los datos de la tabla de resultados.
        """
        try:
            datos = self.__obtener_dataframe_resultados()
            if not datos.empty:
                datos = quitar_filas_menores_absoluto_columna(datos, "log2FC", self.__dsbox_log2fc.value())
                datos = quitar_filas_mayores_columna(datos, "adj-p-value", self.__dsbox_p.value())
                self.__colocar_datos_resultados(datos)
        except ValueError as error:
            Avisos.avisar_precaucion(str(error))
        except Exception as error:
            Avisos.avisar_precaucion("Error desconocido: " + str(error))

    def __guardar_tabla(self) -> None:
        """
        Función que guarda los datos de la tabla de resultados en un archivo tsv.
        """
        ruta, _ = QtWidgets.QFileDialog.getSaveFileName(None, "Guardar tabla", "", "Archivos tsv (*.tsv)")
        if ruta:
            try:
                datos = self.__obtener_dataframe_resultados()
                GuardadorArchivos.guardar_pandas(datos, ruta)
            except ValueError as error:
                Avisos.avisar_precaucion(str(error))
            except Exception as error:
                Avisos.avisar_precaucion("Error desconocido: " + str(error))

    def __graficar(self) -> None:
        """
        Función que grafica los datos de la tabla de resultados
        """
        try:
            if self.__combox_grafico.currentText() == "Expression Atlas":
                #obtener los datos de la columna id_gen de la tabla de resultados
                datos = self.__obtener_opcion(self.__obtener_columna_resultados("id_gen"), "Gen")
                if datos:
                    datos = pd.DataFrame({"id_gen":[datos]})
                else:
                    datos = pd.DataFrame()
            else:
                datos = self.__obtener_dataframe_resultados()
        
            if not datos.empty:
                figuras = self.__graficador.obtener_figura(self.__combox_grafico.currentText(), datos, self.__dsbox_p.value(),
                                                self.__dsbox_log2fc.value(), self.__combox_grupo.currentText())
                
                self.__ventana_grafico = VentanaFiguras.poner_figuras_ventana(figuras, "Gráfico")
                self.__ventana_grafico.showMaximized()

        except ValueError as error:
            Avisos.avisar_precaucion(str(error))
        except Exception as error:
            Avisos.avisar_precaucion("Error desconocido: " + str(error))
