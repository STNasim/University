import pandas as pd

from visualizacion.conversores_resultados import ConversorResultados
from visualizacion.graficos import FabricaGraficos
from visualizacion.paginas_web import FabricaPaginas

class Graficador():
    """
    Clase que se encarga de crear las figuras a partir de los datos.

    :var __conversor: Conversor de datos.
    :vartype __conversor: ConversorResultados
    :var __fabrica_graficos: Fabrica de graficos.
    :vartype __fabrica_graficos: FabricaGraficos
    :var __fabrica_paginas: Fabrica de paginas.
    :vartype __fabrica_paginas: FabricaPaginas
    """
    def __init__(self):
        """
        Inicializa el graficador.
        """
        self.__conversor = ConversorResultados()
        self.__fabrica_graficos = FabricaGraficos()
        self.__fabrica_paginas = FabricaPaginas()
        #Los graficos permitidos serán los que se permitan tanto en el conversor como en graficos o en 
        # el conversor y las paginas
        self.__graficos_permitidos = set(self.__conversor.obtener_conversores_admitidos()) & \
                                        set(self.__fabrica_graficos.obtener_graficos_admitidos()) | \
                                        set(self.__conversor.obtener_conversores_admitidos()) & \
                                        set(self.__fabrica_paginas.obtener_paginas_admitidas())
        
    def obtener_graficos_permitidos(self):
        """
        Devuelve los graficos permitidos.

        :return: Set de graficos permitidos.
        :rtype: Set
        """
        return self.__graficos_permitidos
    
    def obtener_figura(self, tipo_grafico: str,  datos : pd.DataFrame,
                        p_value : float, log2FC : float, grupo: str):
        """
        Devuelve la figura correspondiente al tipo de grafico, los datos, el p_value, el log2FC y el grupo.

        :param tipo_grafico: Tipo de grafico.
        :type tipo_grafico: str
        :param datos: Datos a graficar.
        :type datos: pd.DataFrame
        :param p_value: Valor de p_value para filtrar los datos.
        :type p_value: float
        :param log2FC: Valor de log2FC para filtrar los datos.
        :type log2FC: float
        :param grupo: Nombre del grupo.
        :type grupo: str
        :return: Figura.
        :rtype: Figure
        """
        datos_convertidos, colores = self.__conversor.convertir(tipo_grafico, datos, p_value, log2FC, grupo)

        figuras = []

        if tipo_grafico in self.__fabrica_paginas.obtener_paginas_admitidas():
            pagina = self.__fabrica_paginas.crear_pagina(tipo_grafico, datos_convertidos)
            figuras.append(pagina.obtener_vista())
        
        if tipo_grafico in self.__fabrica_graficos.obtener_graficos_admitidos():
            for dato in datos_convertidos:
                grafico = self.__fabrica_graficos.crear_grafico(tipo_grafico, dato,
                                                                colores = colores)
                figuras.append(grafico.obtener_figura())

        return figuras

