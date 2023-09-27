from typing import List, Tuple

import pandas as pd
import numpy as np

from transformaciones.df import anular_valores_mayores_columna, anular_valores_menores_absoluto_columna
from transformaciones.df import quitar_filas_mayores_columna, quitar_filas_menores_absoluto_columna

class ConversorLog2FC():
    """
    Clase que convierte un DataFrame para luego utilizar los resultados para graficar diagramas que utilicen log2FC.
    """
    @staticmethod
    def convertir(datos : pd.DataFrame, p_value : float, log2FC : float,
                   cantidad_por_figura : int = 50) -> Tuple[List, List]:
        """
        Convierte un DataFrame en una lista de DataFrames con valores de log2FC por cada grupo.

        :param datos: Dataframe a convertir.
        :type datos: pd.DataFrame
        :param p_value: Valor de p-value para filtrar los datos.
        :type p_value: float
        :param log2FC: Valor de log2FC para filtrar los datos.
        :type log2FC: float
        :param cantidad_por_figura: Cantidad de genes por figura.
        :type cantidad_por_figura: int
        :return: Lista de dataframes, lista de colores.
        :rtype: Tuple[List, List]
        """
        datos = quitar_filas_menores_absoluto_columna(datos, "log2FC", log2FC)
        datos = quitar_filas_mayores_columna(datos, "adj-p-value", p_value)

        #se obtienen los valores de las columnas que comiencen con "log2FC" y tambien la columna 0
        columnas = ["symbol"] + [col for col in datos.columns if col.startswith("log2FC")]

        #se reemplazan los valores de la columna symbol con los de gen_id si son "nan"
        datos["symbol"] = np.where(datos["symbol"] == "nan", datos["id_gen"], datos["symbol"])
        
        datos = datos[columnas]

        #quitar log_2FC_ de los nombres de las columnas
        datos.columns = [col.split("_", 1)[1] if col.startswith("log2FC") else col for col in datos.columns]


        separaciones = len(datos)*(len(columnas)-1) // cantidad_por_figura

        #separar los datos en una lista de dataframes
        if separaciones < 2:
            datos = [datos]
        else:
            datos = np.array_split(datos, separaciones)
           
        return datos, None

class ConversorVenn():
    """
    Clase que convierte un DataFrame para luego utilizar los resultados para graficar un diagrama de Venn.
    """
    @staticmethod
    def convertir(datos : pd.DataFrame, p_value : float, log2FC : float) -> Tuple[List, List]:
        """
        Convierte un DataFrame en una lista de DataFrames con genes que pasaron el filtro por cada grupo.

        :param datos: Dataframe a convertir.
        :type datos: pd.DataFrame
        :param p_value: Valor de p-value para filtrar los datos.
        :type p_value: float
        :param log2FC: Valor de log2FC para filtrar los datos.
        :type log2FC: float
        :return: Lista de dataframes, lista de colores.
        :rtype: Tuple[List, List]
        """
        datos = anular_valores_mayores_columna(datos, "adj-p-value", p_value)
        datos = anular_valores_menores_absoluto_columna(datos, "log2FC", log2FC)
        
        #identificar que grupos hay en los datos, los grupos son lo que está despues de adj-p-value_
        columnas = datos.columns
        grupos = set()
        for col in columnas:
            if col.startswith("adj-p-value_"):
                grupos.add(col.split("_", 1)[1])

        #Obtener la lista de genes que cumplen con los criterios de p_value y log2FC para cada grupo
        datos_retorno_dict = {}
        for grupo in grupos:
            columnas_a_chequear = ["adj-p-value_" + grupo, "log2FC_" + grupo]
            datos_aux = datos.dropna(subset = columnas_a_chequear)
            datos_retorno_dict[grupo] = [datos_aux["id_gen"].to_list()]

        datos_retorno = pd.DataFrame(datos_retorno_dict)

        return [datos_retorno], None

class ConversorVolcan():
    """
    Clase que convierte un DataFrame para luego utilizar los resultados para graficar un diagrama de Volcán.
    """

    @staticmethod
    def convertir(df : pd.DataFrame, p_value : float, log2FC : float, grupo : str) -> Tuple[List, List]:
        """
        Convierte un DataFrame en una lista de DataFrames con genes que pasaron el filtro por cada grupo y una lista de colores.

        :param df: Dataframe a convertir.
        :type df: pd.DataFrame
        :param p_value: Valor de p-value para filtrar los datos.
        :type p_value: float
        :param log2FC: Valor de log2FC para filtrar los datos.
        :type log2FC: float
        :param grupo: Nombre del grupo.
        :type grupo: str
        :return: Lista de dataframes, lista de colores.
        :rtype: Tuple[List, List]
        """
        lista_colores = []
        #quedarme solamente con las columnas que terminen con grupo
        columnas_a_quitar = [col for col in df.columns if not col.endswith(grupo)]
        df = df.drop(columnas_a_quitar, axis = 1)
        
        #crear una lista de colores, que indicara el color para fila,
        #el color será rojo si el valor de p-value es menor a p_value y el log2FC es mayor a log2FC
        #el color será azul si el valor de p-value es menor a p_value y el log2FC es menor a -log2FC
        #sino será negro
        
        for _, row in df.iterrows():
            if row['adj-p-value_' + grupo] < p_value and row['log2FC_' + grupo] > log2FC:
                lista_colores.append('red')
            elif row['adj-p-value_' + grupo] < p_value and row['log2FC_' + grupo] < -log2FC:
                lista_colores.append('blue')
            else:
                lista_colores.append('black')

        #Verificar si algun valor de la columna adj-p-value es 0 y reemplazarlo por el flotante más chico
        df['adj-p-value_' + grupo] = df['adj-p-value_' + grupo].replace(0, 1e-308)
        

        #convertir la columna adj-p-value a logaritmo negativo
        df["adj-p-value_" + grupo] = -np.log10(df["adj-p-value_" + grupo])

        return [df], lista_colores

class ConversorReactome():
    """
    Clase que convierte un DataFrame para luego utilizar los resultados para graficar una ventana Reactome.
    """

    @staticmethod
    def convertir(df : pd.DataFrame, p_value : float, log2FC : float, grupo = None):
        """
        Convierte un DataFrame en una lista con genes que pasaron el filtro para el grupo.

        :param df: Dataframe a convertir.
        :type df: pd.DataFrame
        :param p_value: Valor de p-value para filtrar los datos.
        :type p_value: float
        :param log2FC: Valor de log2FC para filtrar los datos.
        :type log2FC: float
        :param grupo: Nombre del grupo, defaults to None.
        :type grupo: str
        :return: Lista de dataframes, lista de colores.
        :rtype: Tuple[List, List]
        """
        columnas_a_chequear = ["id_gen"]
        columnas_a_chequear.append("adj-p-value_" + grupo)
        columnas_a_chequear.append("log2FC_" + grupo)

        df = df[columnas_a_chequear]
        
        anular_valores_mayores_columna(df, "adj-p-value", p_value)
        anular_valores_menores_absoluto_columna(df, "log2FC", log2FC)
        df = df.dropna()

        return df['id_gen'].to_list(), None

class ConversorResultados():
    """
    Clase que convierte un DataFrame para luego utilizar los resultados para graficar.
    """
    def __init__(self):
        """
        Inicializa el conversor.
        """
        self.__conversores_admitidos = ["Barras", "Heatmap", "Venn", "Volcán",
                                         "Reactome", "Expression Atlas"]

    def obtener_conversores_admitidos(self):
        """
        Devuelve los conversores admitidos.

        :return: Lista de conversores admitidos.
        :rtype: List
        """
        return self.__conversores_admitidos
    
    def convertir(self, tipo : str, datos : pd.DataFrame,
                   p_value : float = None, log2FC : float = None, grupo : str = None) -> Tuple[List, List]:
        """
        Convierte un DataFrame de datos según el tipo de conversor, el p_value, el log2FC y el grupo.

        :param tipo: Tipo de conversor.
        :type tipo: str
        :param datos: Dataframe a convertir.
        :type datos: pd.DataFrame
        :param p_value: Valor de p-value para filtrar los datos, defaults to None.
        :type p_value: float, optional
        :param log2FC: Valor de log2FC para filtrar los datos, defaults to None.
        :type log2FC: float, optional
        :param grupo: Nombre del grupo, defaults to None.
        :type grupo: str, optional
        :return: Lista de dataframes, lista de colores.
        :rtype: Tuple[List, List]
        """
        tipo = tipo.lower()
        if tipo == "barras":
            return ConversorLog2FC.convertir(datos, p_value, log2FC, 50)
        elif tipo == "heatmap":
            return ConversorLog2FC.convertir(datos, p_value, log2FC, 300)
        elif tipo == "venn":
            return ConversorVenn.convertir(datos, p_value, log2FC)
        elif tipo == "volcan" or tipo == "volcán":
            return ConversorVolcan.convertir(datos, p_value, log2FC, grupo)
        elif tipo == "reactome":
            return ConversorReactome.convertir(datos, p_value, log2FC, grupo)
        elif tipo == "expression atlas":
            return [datos.iloc[0,0]], None
        else:
            raise Exception("Tipo de conversor "+ tipo +" no admitido")
