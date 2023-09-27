import pandas as pd
import numpy as np
from abc import ABC, abstractmethod

import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from matplotlib.figure import Figure
from venn import venn
import seaborn as sns
from sklearn.decomposition import PCA
from scipy import stats

class GraficoBase(ABC):
    """
    Clase base para los gráficos.
    """
    def __init__(self, datos : pd.DataFrame, titulo : str = None, label_x : str = None, label_y : str = None,
                  colores : list = None, ax : Axes = None) -> None:
        """
        Inicializa el gráfico.

        :param datos: Datos a graficar.
        :type datos: pd.DataFrame
        :param titulo: Título del gráfico, defaults to None.
        :type titulo: str, optional
        :param label_x: Label del eje x, defaults to None.
        :type label_x: str, optional
        :param label_y: Label del eje y, defaults to None.
        :type label_y: str, optional
        :param colores: Colores para el gráfico, defaults to None.
        :type colores: list, optional
        :param ax: Axes para el gráfico. Si es None, se crea uno nuevo, defaults to None.
        :type ax: Axes, optional
        """
        self._datos = datos
        self._colores = colores

        if ax is None:
            self._figura = Figure()
            self._ax = self._figura.add_subplot(1,1,1)
        else:
            self._ax = ax
            self._figura = ax.get_figure()

        self._dibujar()

        if titulo:
            self._ax.set_title(titulo)
        if label_x:
            self._ax.set_xlabel(label_x)
        if label_y:
            self._ax.set_ylabel(label_y)

    @abstractmethod
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico.
        """
        pass

    def obtener_figura(self) -> Figure:
        """
        Devuelve la figura.

        :return: Figura.
        :rtype: Figure
        """
        return self._figura

    def obtener_ax(self) -> Axes:
        """
        Devuelve el Axes.

        :return: Axes.
        :rtype: Axes
        """
        return self._ax

class GraficoBoxplot(GraficoBase):
    """
    Clase que representa un gráfico de boxplot.
    """
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico de boxplot.
        """
        for i in range(len(self._datos.columns)):
            self._ax.boxplot(self._datos.iloc[:, i], positions = [i], patch_artist = False,
                    boxprops = dict(color = self._colores[i]),
                    whiskerprops = dict(color = self._colores[i]),
                    capprops = dict (color = self._colores[i]),
                    medianprops = dict(color = self._colores[i]),
                    flierprops = dict(markeredgecolor = self._colores[i])
                    )
            
        self._ax.set_xticks(range(len(self._datos.columns)))
        self._ax.set_xticklabels(self._datos.columns, rotation='vertical')

class GraficoHeatmap(GraficoBase):
    """
    Clase que representa un gráfico de heatmap.
    """
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico de heatmap.
        """
        #Se asume que la primer columna tiene los nombres de las filas
        sns.heatmap(self._datos.iloc[:,1:], yticklabels = False, xticklabels = False, ax = self._ax)
        
        xticks = np.linspace(0, len(self._datos.columns[1:]) - 1, len(self._datos.columns[1:]), dtype=int)
        xticklabels = [self._datos.columns[idx+1] for idx in xticks]

        #si la primer columna no es None, entonces estos son los yticks
        if self._datos.iloc[:,0].notnull().all():
            yticks = np.linspace(0, len(self._datos) - 1, len(self._datos))
            yticklabels = [self._datos.iloc[idx, 0] for idx in yticks.astype(int)]
            self._ax.set_yticks(yticks + 0.5)
            self._ax.set_yticklabels(yticklabels, rotation = 0, fontsize = 6)

        for i in range(self._datos.shape[1]+1):
            self._ax.axvline(i, color='gray', lw=1)

        
        self._ax.set_xticks(xticks + 0.5)
        if len(self._datos.columns) > 5:
            rotacion = 90
        else:
            rotacion = 0
        self._ax.set_xticklabels(xticklabels, rotation = rotacion, fontsize = 6)  

class GraficoHistograma(GraficoBase):
    """
    Clase que representa un gráfico de histograma.
    """
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico de histograma.
        """
        self._datos.hist(ax= self._ax)

class GraficoKDE(GraficoBase):
    """
    Clase que representa un gráfico de KDE.
    """
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico de KDE.
        """
        for i, label in enumerate(self._datos.columns):
            sns.kdeplot(self._datos[label].dropna(), ax = self._ax, color = self._colores[i], label = label)

        self._ax.set_xlabel('')
        self._ax.legend(ncols = 3)

class GraficoPCA(GraficoBase):
    """
    Clase que representa un gráfico de PCA.
    """
    def _dibujar(self):
        """
        Dibuja el gráfico de PCA.
        """
        # Realizar PCA
        pca = PCA(n_components=2)
        pca_data = pca.fit_transform(self._datos.T)

        # Agregar ruido a los datos para evitar que se superpongan
        jitter = 2
        pca_data[:, 0] += np.random.normal(0, jitter, size=pca_data.shape[0])
        pca_data[:, 1] += np.random.normal(0, jitter, size=pca_data.shape[0])

        # Graficar el mapa de similitud
        self._ax.scatter(pca_data[:, 0], pca_data[:, 1], c = self._colores)

        for i, (x, y) in enumerate(pca_data):
            label = self._datos.columns[i]
            self._ax.annotate(label, (x, y))

class GraficoQQ(GraficoBase):
    """
    Clase que representa un gráfico de QQ.
    """
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico de QQ.
        """
        (osm, osr), (slope, intercept, r) = stats.probplot(self._datos.iloc[:,0], dist="norm")

        self._ax.plot(osm, osr, marker='.', linestyle='none')
        self._ax.plot(osm, slope*osm + intercept)

        self._ax.set_xlabel('Quantiles teóricos')
        self._ax.set_ylabel('Valores ordenados')
        self._ax.set_title('Gráfico Q-Q ' + self._datos.columns[0])
        
        xmin, xmax = self._ax.get_xlim()
        ymin, ymax = self._ax.get_ylim()
        self._ax.text((xmin + xmax)/2, (ymin + ymax)/2, 'R = {:.2f}'.format(r), 
                      horizontalalignment='right', verticalalignment='center') 
        
class GraficoVenn(GraficoBase):
    """
    Clase que representa un gráfico de Venn.
    """
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico de Venn.
        """
        # Guardar el Axes actual
        ax_actual = plt.gca()

        sets = {}
        #Convertir cada columna del dataframe en set

        for columna in self._datos.columns:
            flattened_list = [item for sublist in self._datos.loc[:, columna] for item in sublist]
            sets[columna] = set(flattened_list)

        num_sets = len(sets)
        
        if num_sets <= 6 and num_sets >= 2:
            venn(sets)
        else:
            raise ValueError(f"El número de conjuntos no es soportado: {num_sets}")
        
        self._ax = plt.gca()
        self._figura = plt.gcf()
        
        # Restablecer el Axes actual
        plt.sca(ax_actual)

class GraficoVolcan(GraficoBase):
    """
    Clase que representa un gráfico de Volcán.
    """
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico de Volcán.
        """
        self._ax.scatter(self._datos.iloc[:, 0], self._datos.iloc[:, 1], c = self._colores)

        self._ax.set_title('Volcano plot')
        self._ax.set_xlabel('log2FC')
        self._ax.set_ylabel('-log10(p-value)')

class GraficoBarra(GraficoBase):
    """
    Clase que representa un gráfico de barras.
    """
    def _dibujar(self) -> None:
        """
        Dibuja el gráfico de barras.
        """
        #Se asume que la columna 0 tiene los nombres de las filas
        ancho = 1/self._datos.shape[0]
        if ancho < 0.1:
            ancho = 0.1
        #fix the calculation of x so it even if ancho is set manually, it works
        x = np.arange(self._datos.shape[0]) - (ancho * (self._datos.shape[1] - 1))/2
        
        for i, columna in enumerate(self._datos.columns[1:]):
            self._ax.bar(x + (i * ancho), self._datos[columna], ancho, label = columna)
        
        self._ax.set_xticks(x + (ancho * (self._datos.shape[1] - 1))/2)
        self._ax.set_xticklabels(self._datos.iloc[:,0], rotation='vertical')
        self._ax.legend()


class FabricaGraficos():
    """
    Clase que crea los gráficos.
    """
    def __init__(self) -> None: 
        """
        Inicializa la clase.
        """       
        self.__nombres_graficos = ["Barras", "Heatmap", "Boxplot", "Volcán", "Venn",
                                   "KDE", "PCA", "QQ", "Histograma"]

    def obtener_graficos_admitidos(self) -> list:
        """
        Devuelve los gráficos admitidos.

        :return: Lista de gráficos admitidos.
        :rtype: list
        """
        return self.__nombres_graficos
    
    def crear_grafico(self, nombre_grafico : str, datos : pd.DataFrame, titulo = None,
                       label_x = None, label_y = None, colores = None, ax = None ) -> GraficoBase:
        """
        Crea un gráfico

        :param nombre_grafico: Nombre del gráfico.
        :type nombre_grafico: str
        :param datos: Datos a graficar.
        :type datos: pd.DataFrame
        :param titulo: Título del gráfico, defaults to None.
        :type titulo: str, optional
        :param label_x: Label del eje x, defaults to None.
        :type label_x: str, optional
        :param label_y: Label del eje y, defaults to None.
        :type label_y: str, optional
        :param colores: Colores para el gráfico, defaults to None.
        :type colores: list, optional
        :param ax: Axes para el gráfico, defaults to None.
        :type ax: Axes, optional
        :return: Gráfico.
        :rtype: GraficoBase
        """
        nombre_grafico = nombre_grafico.lower()
        if nombre_grafico == "venn":
            return GraficoVenn(datos, titulo, label_x, label_y, colores, ax)
        elif nombre_grafico == "barras":
            return GraficoBarra(datos, titulo, label_x, label_y, colores, ax)
        elif nombre_grafico == "boxplot":
            return GraficoBoxplot(datos, titulo, label_x, label_y, colores, ax)
        elif nombre_grafico == "volcan" or nombre_grafico == "volcán":
            return GraficoVolcan(datos, titulo, label_x, label_y, colores, ax)
        elif nombre_grafico == "heatmap":
            return GraficoHeatmap(datos, titulo, label_x, label_y, colores, ax)
        elif nombre_grafico == "kde":
            return GraficoKDE(datos, titulo, label_x, label_y, colores, ax)
        elif nombre_grafico == "pca":
            return GraficoPCA(datos, titulo, label_x, label_y, colores, ax)
        elif nombre_grafico == "qq":
            return GraficoQQ(datos, titulo, label_x, label_y, colores, ax)
        elif nombre_grafico == "histograma":
            return GraficoHistograma(datos, titulo, label_x, label_y, colores, ax)
        else:
            raise ValueError(f"Tipo de gráfico no soportado: {nombre_grafico}")