import sys
import os

def resource_path(relative_path):
    """ Get absolute path to resource, works for dev and for PyInstaller.
    Funcion extraida de https://stackoverflow.com/questions/7674790/bundling-data-files-with-pyinstaller-onefile/7675014#7675014 
    para establecer la ruta a los archivos adicionales de pyqt_toast.
    
    :param relative_path: Ruta relativa a recursos.
    :type relative_path: str
    :return: Ruta absoluta al directorio de recursos.
    :rtype: str
    """
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except AttributeError:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)

from PyQt5.QtWidgets import QMessageBox
import pyqt_toast

class Avisos:
    """ 
    Clase que contiene los metodos para mostrar avisos en la interfaz.
    
    :param parent: Ventana padre de los avisos.
    :type parent: QtWidgets.QMainWindow
    """
    __mensaje_actual = None
    os.environ['PATH'] += os.pathsep + resource_path('pyqt_toast')
    @staticmethod
    def avisar_precaucion(mensaje) -> None:
        """ 
        Muestra un aviso de precaucion en la interfaz.

        :param mensaje: Mensaje a mostrar en el aviso.
        :type mensaje: str
        """
        if Avisos.__mensaje_actual:
            Avisos.__mensaje_actual.close()
        Avisos.__mensaje_actual = QMessageBox()
        Avisos.__mensaje_actual.setIcon(QMessageBox.Warning)
        Avisos.__mensaje_actual.setText(mensaje)
        Avisos.__mensaje_actual.setWindowTitle("Error")
        Avisos.__mensaje_actual.exec_()

    @staticmethod
    def avisar_procesando(mensaje, duracion = 10000) -> None:
        """ 
        Muestra un aviso de procesando en la interfaz.

        :param mensaje: Mensaje a mostrar en el aviso.
        :type mensaje: str
        :param duracion: Duracion del aviso en milisegundos, defaults to 10000.
        :type duracion: int, optional
        """
        if Avisos.__mensaje_actual:
            Avisos.__mensaje_actual.close()
        Avisos.__mensaje_actual = pyqt_toast.Toast(text = mensaje,
                                                    duration = duracion,
                                                      parent = Avisos.parent)
        Avisos.__mensaje_actual.show()
        
    @staticmethod
    def avisar_finalizado(mensaje) -> None:
        """ 
        Muestra un aviso de finalizado en la interfaz.
        
        :param mensaje: Mensaje a mostrar en el aviso.
        :type mensaje: str
        """
        if Avisos.__mensaje_actual:
            Avisos.__mensaje_actual.close()
        Avisos.__mensaje_actual = QMessageBox()
        Avisos.__mensaje_actual.setIcon(QMessageBox.Information)
        Avisos.__mensaje_actual.setText(mensaje)
        Avisos.__mensaje_actual.setWindowTitle("Finalizado")
        Avisos.__mensaje_actual.exec_()
