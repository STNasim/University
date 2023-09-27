from abc import ABC, abstractmethod

from matplotlib.figure import Figure
import pandas as pd

from transformaciones.lista import grupos2color
from visualizacion.graficos import FabricaGraficos

class ReporteBase(ABC):
    """
    Clase abstracta que representa un reporte.
    """
    def __init__(self, datos : pd.DataFrame, grupos : list = None) -> None:
        """
        Inicializa el reporte.

        :param datos: Datos a mostrar en el reporte.
        :type datos: pd.DataFrame
        :param grupos: Grupos de los datos, defaults to None
        :type grupos: list, optional
        """
        self._datos = datos.copy()
        self._grupos = grupos
        self._fabrica_graficos = FabricaGraficos()
        self._figuras = []
        self._armar_reporte()            

    @abstractmethod
    def _armar_reporte(self) -> None:
        """
        Arma el reporte.
        """
        pass
    
    def obtener_lista_figuras(self) -> list:
        """
        Devuelve la lista de figuras del reporte.

        :return: Lista de figuras del reporte.
        :rtype: list
        """
        return self._figuras

class ReporteSondas(ReporteBase):
    """
    Clase que representa un reporte de sondas.
    """
    def _armar_reporte(self) -> None:
        """
        Arma el reporte.
        """
        colores = grupos2color(self._grupos)
        
        fig_pca = Figure()
        grafico_pca = self._fabrica_graficos.crear_grafico("PCA", self._datos.iloc[:,1:],
                                                            ax = fig_pca.add_subplot(),
                                                              colores = colores)
        self._figuras.append(fig_pca)
        
        fig_heatmap = Figure()
        #hacer nula la primer columna de self.__datos, ya que es la columna de id_sonda
        #y no se desean mostrar en el heatmap
        self._datos.iloc[:,0] = None
        grafico_heatmap = self._fabrica_graficos.crear_grafico("Heatmap", self._datos,
                                                                ax = fig_heatmap.add_subplot())
        self._figuras.append(fig_heatmap)

        fig_boxplot = Figure()
        grafico_boxplot = self._fabrica_graficos.crear_grafico("Boxplot", self._datos.iloc[:,1:],
                                                                ax = fig_boxplot.add_subplot(),
                                                                  colores = colores)
        self._figuras.append(fig_boxplot)
        
        fig_kde = Figure()
        grafico_kde = self._fabrica_graficos.crear_grafico("KDE", self._datos.iloc[:,1:],
                                                            ax = fig_kde.add_subplot(),
                                                              colores = colores)
        self._figuras.append(fig_kde)

class ReporteLimma(ReporteBase):
    """
    Clase que representa un reporte de limma.
    """
    def _armar_reporte(self) -> None:
        """
        Arma el reporte.
        """
        num_columnas = self._datos.shape[1]
        
        for i in range(0, num_columnas, 3):
            if i + 2 >= num_columnas:
                break
            
            fig_hist_logfc = Figure()
            grafico_histograma_p_value = self._fabrica_graficos.crear_grafico(
                "Histograma", self._datos.iloc[:, i:i+1], ax = fig_hist_logfc.add_subplot())
            self._figuras.append(fig_hist_logfc)

            fig_hist_p = Figure()
            grafico_histograma_p_value = self._fabrica_graficos.crear_grafico(
                "Histograma", self._datos.iloc[:, i+1:i+2], ax = fig_hist_p.add_subplot())
            self._figuras.append(fig_hist_p)

            fig_qq = Figure()
            grafico_qq = self._fabrica_graficos.crear_grafico(
                "QQ", self._datos.iloc[:, i+2:i+3], ax = fig_qq.add_subplot())
            self._figuras.append(fig_qq)

class FabricaReportes:
    """
    Clase que se encarga de crear reportes.
    """
    def crear_reporte(tipo_de_reporte : str, datos : pd.DataFrame, grupos = None) -> ReporteBase:
        """
        Crea un reporte del tipo indicado.

        :param tipo_de_reporte: Tipo de reporte
        :type tipo_de_reporte: str
        :param datos: Datos a mostrar en el reporte
        :type datos: pd.DataFrame
        :param grupos: Grupos de los datos, defaults to None
        :type grupos: list, optional
        :return: Reporte
        :rtype: ReporteBase
        """
        tipo_de_reporte = tipo_de_reporte.lower()
        if tipo_de_reporte == 'limma':
            return ReporteLimma(datos, grupos)
        elif tipo_de_reporte == 'sondas':
            return ReporteSondas(datos, grupos)
        else:
            raise ValueError(f"Tipo de reporte no soportado: {tipo_de_reporte}")