from PyQt5 import QtCore
from PyQt5.QtWidgets import QInputDialog, QTableWidgetItem, QMainWindow, QTableWidget
from PyQt5.QtGui import QKeyEvent

class ManejadorEventos:
    """ 
    Clase que contiene los metodos para manejar los eventos de la interfaz.
    """

    @staticmethod
    def eventos_tecla_tablas(evento : QKeyEvent, tabla : QTableWidget,
                               VentanaPrincipal : QMainWindow) -> None:
        """ 
        Maneja los eventos de tecla en las tablas de la interfaz

        :param evento: Evento de tecla
        :type evento: QKeyEvent
        :param tabla: Tabla en la que se produjo el evento
        :type tabla: QTableWidget
        :param VentanaPrincipal: Ventana principal de la interfaz
        :type VentanaPrincipal: QMainWindow
        """
        if evento.key() == QtCore.Qt.Key_Backspace or evento.key() == QtCore.Qt.Key_Delete:
            ManejadorEventos.__borrar_filas(tabla)

        elif evento.key() == QtCore.Qt.Key_Right or evento.key() == QtCore.Qt.Key_D:
            ManejadorEventos.__mover_tabla_derecha(tabla)

        elif evento.key() == QtCore.Qt.Key_Left or evento.key() == QtCore.Qt.Key_A:
            ManejadorEventos.__mover_tabla_izquierda(tabla)

        elif evento.key() == QtCore.Qt.Key_Return:
            ManejadorEventos.__reemplazar_valores(tabla, VentanaPrincipal)

    @staticmethod
    def __borrar_filas(tabla : QTableWidget) -> None:
        """ 
        Borra las filas seleccionadas de la tabla.
        
        :param tabla: Tabla en la que se borraran las filas.
        :type tabla: QTableWidget
        """
        filas = set()
        for item in tabla.selectedItems():
            filas.add(item.row())
        for fila in sorted(filas, reverse=True):
            tabla.removeRow(fila)

    @staticmethod
    def __reemplazar_valores(tabla : QTableWidget, VentanaPrincipal : QMainWindow) -> None:
        """ 
        Reemplaza los valores de las celdas seleccionadas por el valor introducido.
        
        :param tabla: Tabla en la que se reemplazaran los valores.
        :type tabla: QTableWidget
        """
        indices = tabla.selectedIndexes()
        texto, ok = QInputDialog.getText(VentanaPrincipal, "Reemplazar",
                                         "Introducir nuevo valor:")
        if ok:
            for index in indices:
                item = tabla.item(index.row(), index.column())
                if item is None:
                    item = QTableWidgetItem(texto)
                    tabla.setItem(index.row(), index.column(), item)
                else:
                    item.setText(texto)
        tabla.resizeColumnsToContents()

    @staticmethod
    def __mover_tabla_derecha(tabla : QTableWidget) -> None:
        """ 
        Mueve las columnas seleccionadas de la tabla hacia la derecha.
        
        :param tabla: Tabla en la que se moveran las columnas.
        :type tabla: QTableWidget
        """
        # Desactivar ordenamiento antes de mover columnas
        tabla.setSortingEnabled(False)

        cols_seleccionadas = set()
        for item in tabla.selectedItems():
            cols_seleccionadas.add(item.column())
        items_seleccionados = tabla.selectedItems()
        
        for col in sorted(cols_seleccionadas, reverse=True):
            if col < tabla.columnCount() - 1:
                header_item = tabla.horizontalHeaderItem(col).clone()
                tabla.setHorizontalHeaderItem(col, tabla.horizontalHeaderItem(col + 1).clone())
                tabla.setHorizontalHeaderItem(col + 1, header_item)
                for row in range(tabla.rowCount()):
                    item = tabla.takeItem(row, col)
                    tabla.setItem(row, col, tabla.takeItem(row, col + 1))
                    tabla.setItem(row, col + 1, item)

        tabla.clearSelection()
        for item in items_seleccionados:
            item.setSelected(True)
        tabla.resizeColumnsToContents()

        # Activar ordenamiento después de mover columnas
        tabla.setSortingEnabled(True)
        
    @staticmethod
    def __mover_tabla_izquierda(tabla : QTableWidget) -> None:
        """ 
        Mueve las columnas seleccionadas de la tabla hacia la izquierda.
        
        :param tabla: Tabla en la que se moveran las columnas.
        :type tabla: QTableWidget
        """
        # Desactivar ordenamiento antes de mover columnas
        tabla.setSortingEnabled(False)
        columnas_seleccionadas = set()
        for item in tabla.selectedItems():
            columnas_seleccionadas.add(item.column())
        items_seleccionados = tabla.selectedItems()
        
        for col in sorted(columnas_seleccionadas):
            if col > 0:
                header_item = tabla.horizontalHeaderItem(col).clone()
                tabla.setHorizontalHeaderItem(col, tabla.horizontalHeaderItem(col - 1).clone())
                tabla.setHorizontalHeaderItem(col - 1, header_item)
                for row in range(tabla.rowCount()):
                    item = tabla.takeItem(row, col)
                    tabla.setItem(row, col, tabla.takeItem(row, col - 1))
                    tabla.setItem(row, col - 1, item)
        
        tabla.clearSelection()
        for item in items_seleccionados:
            item.setSelected(True)
        tabla.resizeColumnsToContents()

        # Activar ordenamiento después de mover columnas
        tabla.setSortingEnabled(True)