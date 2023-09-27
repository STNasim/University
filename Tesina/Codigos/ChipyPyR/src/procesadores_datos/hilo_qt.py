from PyQt5.QtCore import QThread, pyqtSignal

from procesadores_datos.pipeline import Pipeline

class HiloProcesamiento(QThread):
    """
    Clase que ejecuta el procesamiento de los datos en un hilo.

    :signal progreso: Señal que indica el progreso del procesamiento.
    :signal generar_reporte: Señal que indica que se debe generar un reporte.
    :signal termino_parte: Señal que indica que se terminó una parte del procesamiento.
    :signal terminado: Señal que indica que se terminó el procesamiento.
    :signal candado: Señal que indica si se debe bloquear la interfaz.
    """
    progreso = pyqtSignal(str)
    generar_reporte = pyqtSignal(list, str)
    termino_parte = pyqtSignal(str)
    terminado = pyqtSignal(str)
    error = pyqtSignal(str)
    candado = pyqtSignal(bool)

    def __init__(self, pipeline : Pipeline, reportar_calidad : bool, parte : str) -> None:
        """
        Constructor de la clase

        :param pipeline: Objeto que contiene el pipeline de procesamiento de los datos.
        :type pipeline: Pipeline
        :param reportar_calidad: Indica si se debe reportar la calidad de los datos.
        :type reportar_calidad: bool
        :param parte: Indica la parte del procesamiento que se debe ejecutar.
        :type parte: str        
        """
        super(HiloProcesamiento, self).__init__()
        self.__pipeline = pipeline
        self.__reportar_calidad = reportar_calidad
        self.__parte = parte

    def set_parte(self, parte : str) -> None:
        """
        Establece la parte del procesamiento que se debe ejecutar.

        :param parte: Indica la parte del procesamiento que se debe ejecutar.
        :type parte: str
        """
        self.__parte = parte

    def run(self) -> None:
        """
        Ejecuta el procesamiento de los datos.
        """
        try:
            if self.__parte == "1":
                self.progreso.emit("Cargando muestras...")
                self.__pipeline.cargar_muestras()

                self.progreso.emit("Procesando muestras...")
                self.__pipeline.procesar_muestras()
                
                if self.__reportar_calidad:
                    self.progreso.emit("Generando reporte de calidad de muestras...")
                    self.__pipeline.generar_reporte_muestras()
                    figuras_reporte_muestras = self.__pipeline.obtener_figuras_reporte_muestras()
                    self.generar_reporte.emit(figuras_reporte_muestras, "Reporte muestras")

                self.progreso.emit("Procesando sondas...")
                self.__pipeline.procesar_sondas()

                self.progreso.emit("Procesando genes...")
                self.__pipeline.procesar_genes()
                
                self.termino_parte.emit("Procesamiento finalizado")

            if self.__parte == "2":

                if self.__reportar_calidad:
                    self.progreso.emit("Generando reporte de calidad de limma...")
                    self.__pipeline.generar_reporte_limma()
                    figuras_reporte_muestras = self.__pipeline.obtener_figuras_reporte_limma()
                    self.generar_reporte.emit(figuras_reporte_muestras, "Reporte limma")

                self.progreso.emit("Enriqueciendo datos...")
                self.__pipeline.enriquecer_datos()

                self.__pipeline.guardar_datos()
                self.candado.emit(False)

                mensaje_salida = "Procesamiento finalizado.\n"
                datos_cada_etapa = self.__pipeline.obtener_datos_cada_etapa()
                for etapa, cantidad in datos_cada_etapa.items():
                    mensaje_salida += "{}: {}\n".format(etapa, cantidad)
                self.terminado.emit(mensaje_salida)
        except Exception as e:
            self.error.emit(str(e))
            self.candado.emit(False)
